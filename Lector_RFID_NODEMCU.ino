/*//////////////////////// CONEXION///////////////////////////////////
  
      Nodemcu       //     RFID-RC522 
       D3 [1*]      GPIO-0      //     RST/Reset RST
       D8 [2*]      GPIO-15     //     SPI SS  SDA[3] 
       D7           GPIO-13     //     SPI MOSI MOSI
       D6           GPIO-12     //     SPI MISO MISO
       D5           GPIO-14     //     SPI SCK SCK       

/////////////////////////////////////////////////////////////////////*/


#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN    D3    
#define SS_PIN     D8   
#define LED        D1

MFRC522 mfrc522(SS_PIN, RST_PIN); 
 String contenido= "";
 byte letra;

void setup() { 
              Serial.begin(9600);   
              SPI.begin();     
              mfrc522.PCD_Init();   
              Serial.println("Aproxime su tarjeta al Lector...");
              Serial.println();
              digitalWrite(D1,LOW);
              pinMode(D1, OUTPUT); 
             } // FIN SETUP

void loop() {   if (mfrc522.PICC_IsNewCardPresent()) {
                if (mfrc522.PICC_ReadCardSerial()) {
                                                    Serial.print("Numero de Tarjeta :");
                                                    printArray(mfrc522.uid.uidByte, mfrc522.uid.size);
                                                    Serial.println();
                                                    mfrc522.PICC_HaltA();
                                                   }
                                                    }
              delay(250);
              }// FIN LOOP



void printArray(byte *buffer, byte bufferSize) {
                                                
                                                 for (byte i = 0; i < bufferSize; i++) {
                                                                                        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
                                                                                        Serial.print(buffer[i], HEX);
                                                                                        contenido.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
                                                                                        contenido.concat(String(mfrc522.uid.uidByte[i], HEX));
                                                                                        contenido.toUpperCase();
                                            }
                        } //FIN PRINT ARRAY



