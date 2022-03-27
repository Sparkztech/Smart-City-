#define ER 11
#define EY 12
#define EG 13

#define WR 7
#define WY 6
#define WG 5

#define SR 8
#define SY 9
#define SG 10

#define NR 2
#define NY 3
#define NG 4
void setup()
{
  
  Serial.begin(9600);

  pinMode(ER, OUTPUT);
  pinMode(EY, OUTPUT);
  pinMode(EG, OUTPUT);

  pinMode(WR, OUTPUT);
  pinMode(WY, OUTPUT);
  pinMode(WG, OUTPUT);

  pinMode(NR, OUTPUT);
  pinMode(NY, OUTPUT);
  pinMode(NG, OUTPUT);

  pinMode(SR, OUTPUT);
  pinMode(SY, OUTPUT);
  pinMode(SG, OUTPUT);
  
  pinMode(A0, INPUT);//W
  pinMode(A1, INPUT);//N
  pinMode(A2, INPUT);//E
  pinMode(A3, INPUT);//S
  
  //  NORTH
  digitalWrite(NR, HIGH); //R
  digitalWrite(NY, HIGH); //Y
  digitalWrite(NG, HIGH); //G

  //  SOUTH
  digitalWrite(SR, HIGH); //R
  digitalWrite(SY, HIGH); //Y
  digitalWrite(SG, HIGH); //G

  //  EAST
  digitalWrite(ER, HIGH); //R
  digitalWrite(EY, HIGH); //Y
  digitalWrite(EG, HIGH); //G

  //  WEST
  digitalWrite(WR, HIGH); //G
  digitalWrite(WY, HIGH); //y
  digitalWrite(WG, HIGH); //R

  delay(3000);

  //  NORTH
  digitalWrite(NR, LOW); //R
  digitalWrite(NY, LOW); //Y
  digitalWrite(NG, LOW); //G

  //  SOUTH
  digitalWrite(SR, LOW); //R
  digitalWrite(SY, LOW); //Y
  digitalWrite(SG, LOW); //G

  //  EAST
  digitalWrite(ER, LOW); //R
  digitalWrite(EY, LOW); //Y
  digitalWrite(EG, LOW); //G

  //  WEST
  digitalWrite(WR, LOW); //G
  digitalWrite(WY, LOW); //y
  digitalWrite(WG, LOW); //R
  Serial.begin(9600);
}
void loop()
{
  Signal();
//Serial.println(digitalRead(A0));//W
//Serial.println(digitalRead(A1));//N
//Serial.println(digitalRead(A2));//E
//Serial.println(digitalRead(A3));//S
//delay(5000);
  

}
void Signal()
{
  digitalWrite(ER,LOW);
  digitalWrite(EY,LOW);
  digitalWrite(EG,HIGH);

  digitalWrite(WR,HIGH);
  digitalWrite(WY,LOW);
  digitalWrite(WG,LOW);

  digitalWrite(NR,HIGH);
  digitalWrite(NY,LOW);
  digitalWrite(NG,LOW);

  digitalWrite(SR,HIGH);
  digitalWrite(SY,LOW);
  digitalWrite(SG,LOW);

  delay_();

  digitalWrite(ER,LOW);
  digitalWrite(EY,HIGH);
  digitalWrite(EG,LOW);

  digitalWrite(WR,LOW);
  digitalWrite(WY,HIGH);
  digitalWrite(WG,LOW);

  digitalWrite(NR,HIGH);
  digitalWrite(NY,LOW);
  digitalWrite(NG,LOW);

  digitalWrite(SR,HIGH);
  digitalWrite(SY,LOW);
  digitalWrite(SG,LOW);

  delay_();

  digitalWrite(ER,HIGH);
  digitalWrite(EY,LOW);
  digitalWrite(EG,LOW);

  digitalWrite(WR,LOW);
  digitalWrite(WY,LOW);
  digitalWrite(WG,HIGH);

  digitalWrite(NR,HIGH);
  digitalWrite(NY,LOW);
  digitalWrite(NG,LOW);

  digitalWrite(SR,HIGH);
  digitalWrite(SY,LOW);
  digitalWrite(SG,LOW);
  
  delay_();

  digitalWrite(ER,HIGH);
  digitalWrite(EY,LOW);
  digitalWrite(EG,LOW);

  digitalWrite(WR,LOW);
  digitalWrite(WY,HIGH);
  digitalWrite(WG,LOW);

  digitalWrite(NR,LOW);
  digitalWrite(NY,HIGH);
  digitalWrite(NG,LOW);

  digitalWrite(SR,HIGH);
  digitalWrite(SY,LOW);
  digitalWrite(SG,LOW);

  delay_();

  digitalWrite(ER,HIGH);
  digitalWrite(EY,LOW);
  digitalWrite(EG,LOW);

  digitalWrite(WR,HIGH);
  digitalWrite(WY,LOW);
  digitalWrite(WG,LOW);

  digitalWrite(NR,LOW);
  digitalWrite(NY,LOW);
  digitalWrite(NG,HIGH);

  digitalWrite(SR,HIGH);
  digitalWrite(SY,LOW);
  digitalWrite(SG,LOW);

  delay_();

  digitalWrite(ER,HIGH);
  digitalWrite(EY,LOW);
  digitalWrite(EG,LOW);

  digitalWrite(WR,HIGH);
  digitalWrite(WY,LOW);
  digitalWrite(WG,LOW);

  digitalWrite(NR,LOW);
  digitalWrite(NY,HIGH);
  digitalWrite(NG,LOW);

  digitalWrite(SR,LOW);
  digitalWrite(SY,HIGH);
  digitalWrite(SG,LOW);

  delay_();

  digitalWrite(ER,HIGH);
  digitalWrite(EY,LOW);
  digitalWrite(EG,LOW);

  digitalWrite(WR,HIGH);
  digitalWrite(WY,LOW);
  digitalWrite(WG,LOW);

  digitalWrite(NR,HIGH);
  digitalWrite(NY,LOW);
  digitalWrite(NG,LOW);

  digitalWrite(SR,LOW);
  digitalWrite(SY,LOW);
  digitalWrite(SG,HIGH);

  delay_();
}
void delay_()
{
  long double a;
  for(a=0 ; a<100000;a++)
  {
     if(digitalRead(A2)==0)//E
     {

      digitalWrite(ER,LOW);
      digitalWrite(EY,LOW);
      digitalWrite(EG,HIGH);

      digitalWrite(WR,HIGH);
      digitalWrite(WY,LOW);
      digitalWrite(WG,LOW);

      digitalWrite(NR,HIGH);
      digitalWrite(NY,LOW);
      digitalWrite(NG,LOW);

      digitalWrite(SR,LOW);
      digitalWrite(SY,HIGH);
      digitalWrite(SG,LOW);

      delay(10000);
     }
     if(digitalRead(A0)==0)//W
     {
      digitalWrite(ER,HIGH);
      digitalWrite(EY,LOW);
      digitalWrite(EG,LOW);

      digitalWrite(WR,LOW);
      digitalWrite(WY,LOW);
      digitalWrite(WG,HIGH);

      digitalWrite(NR,HIGH);
      digitalWrite(NY,LOW);
      digitalWrite(NG,LOW);

      digitalWrite(SR,LOW);
      digitalWrite(SY,HIGH);
      digitalWrite(SG,LOW);

      delay(10000);
     }
     if(digitalRead(A1)==0)//N
     {
      digitalWrite(ER,HIGH);
      digitalWrite(EY,LOW);
      digitalWrite(EG,LOW);

      digitalWrite(WR,HIGH);
      digitalWrite(WY,LOW);
      digitalWrite(WG,LOW);

      digitalWrite(NR,LOW);
      digitalWrite(NY,LOW);
      digitalWrite(NG,HIGH);

      digitalWrite(SR,LOW);
      digitalWrite(SY,HIGH);
      digitalWrite(SG,LOW);

      delay(10000);
     }
     if(digitalRead(A3)==0)//S
     {
      digitalWrite(ER,HIGH);
      digitalWrite(EY,LOW);
      digitalWrite(EG,LOW);

      digitalWrite(WR,HIGH);
      digitalWrite(WY,LOW);
      digitalWrite(WG,LOW);

      digitalWrite(NR,HIGH);
      digitalWrite(NY,LOW);
      digitalWrite(NG,LOW);

      digitalWrite(SR,LOW);
      digitalWrite(SY,LOW);
      digitalWrite(SG,HIGH);

      delay(10000);
     }
  }
  
}
