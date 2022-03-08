#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN);
String rfidCard;
int count = 0;
bool RFID_STATUS = false;
unsigned long pt = 0, ct, S;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8,INPUT);//PIR 

  SPI.begin();
  rfid.init();
}

void loop() {

  //LDR MODULE SENSOR CODE
  // Serial.println(digitalRead(A0));
  if (digitalRead(A0) == 0)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);

  }
  else if (digitalRead(A0) == 1)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
  }

  //soil moisture code
  //  Serial.println(analogRead(A1));
  analogWrite(7, HIGH);
  if (analogRead(A1) <= 1000)
  {
    digitalWrite(7, LOW);
  }
  else
  {
    digitalWrite(7, HIGH);
  }

  //RFID
  if (count != 4)
  {
//    Serial.println(count);
    if (rfid.isCard()) {
      if (rfid.readCardSerial()) {
        rfidCard = String(rfid.serNum[0]) + " " + String(rfid.serNum[1]) + " " + String(rfid.serNum[2]) + " " + String(rfid.serNum[3]);
        //Serial.println(rfidCard);
        if (rfidCard == "25 55 115 229")
        {
          noTone(A5);
          Serial.println(rfidCard);
          RFID_STATUS = true;
          count = 4;
          S = 0;
          digitalWrite(6,LOW);
          digitalWrite(4,HIGH);
          digitalWrite(5, HIGH);
          delay(1000);
          digitalWrite(5, LOW);
        }
        else
        {
          if (count == 0)
          {
            digitalWrite(6, HIGH);
            delay(1000);
            tone(A5, 10);
            delay(1000);
            noTone(A5);
            count++;
            digitalWrite(6, LOW);

          }
          else if (count == 1)
          {
            digitalWrite(6, HIGH);
            delay(800);
            tone(A5, 10);
            delay(800);
            noTone(A5);

            delay(800);
            tone(A5, 10);
            delay(800);
            noTone(A5);
            count++;
            digitalWrite(6, LOW);
          }

          else if (count == 2)
          {
            digitalWrite(6, HIGH);
            delay(600);
            tone(A5, 10);
            delay(600);
            noTone(A5);

            delay(600);
            tone(A5, 10);
            delay(600);
            noTone(A5);

            delay(600);
            tone(A5, 10);
            delay(600);
            noTone(A5);
            count++;
             digitalWrite(6, LOW);
          }

          else if (count == 3)
          {
             digitalWrite(6, HIGH);
            delay(400);
            tone(A5, 10);
            delay(400);
            noTone(A5);

            delay(400);
            tone(A5, 10);
            delay(400);
            noTone(A5);

            delay(400);
            tone(A5, 10);
            delay(400);
            noTone(A5);

            delay(400);
            tone(A5, 10);
            delay(400);
            count++;
          }
        }
      }
      rfid.halt();
    }
  }
  else
  {
    ct = millis();
    if ((ct - pt) >= 1000)
    {
      S++;
      pt = ct;
      Serial.println(S);

      if (S >= 10)
      {
        noTone(A5);
        count = 0;
        S = 0;
        RFID_STATUS = false;
         digitalWrite(6, LOW);
      }
    }
  }
  // PIR
  if(RFID_STATUS!=true)
  {
    if(digitalRead(8)==HIGH)
    {
      tone(A5, 10);
      digitalWrite(6,HIGH);
      delay(100);
    }
     else
    {
      noTone(A5);
      digitalWrite(6,LOW);
    }
    delay(100);
  }
  


}
