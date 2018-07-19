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

void setup(){
                Serial.begin(9600);   
                SPI.begin();      
                mfrc522.PCD_Init();   
               Serial.println("Aproxime La Tarjeta al Lector...");
               Serial.println();
               digitalWrite(D1,LOW);
                pinMode(D1, OUTPUT);
            }// FIN SETUP

void loop(){ 
     
      if (mfrc522.PICC_IsNewCardPresent()){if (mfrc522.PICC_ReadCardSerial()) { manejo_tarjeta();  } }
      
      } //FIN LOOP
      
    
void manejo_tarjeta(){
                      String contenido= "";
                      Serial.print("Codigo de Tarjeta :");
                      for (byte i = 0; i < mfrc522.uid.size; i++) {
                                                                    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                                                                    Serial.print(mfrc522.uid.uidByte[i], HEX);
                                                                    contenido.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
                                                                    contenido.concat(String(mfrc522.uid.uidByte[i], HEX));
                                                                  }
                   Serial.println();
                   Serial.print("Mensaje : ");
                   contenido.toUpperCase();
                   if (contenido.substring(1) == "XX XX XX XX" ||
                       contenido.substring(1) == "XX XX XX XX" ) {
                                                  Serial.println("Abiertoo--------------- Bienvenido !!!!");
                                                  Serial.println();
                                                  digitalWrite(D1, HIGH);    
                                                  delay(1000);             
                                                  digitalWrite(D1, LOW); 
                                                                } 
                   else{
                         Serial.println("Juiira Gatooo");
                         Serial.println();             
                         digitalWrite(D1, HIGH);
                         delay(100);           
                         digitalWrite(D1, LOW); 
                         delay(100);
                         digitalWrite(D1, HIGH);
                         delay(100);           
                         digitalWrite(D1, LOW); 
                         delay(100);
                         digitalWrite(D1, HIGH);
                         delay(100);           
                         digitalWrite(D1, LOW); 
                        }

}   // FIN MANEJO TARJETA
