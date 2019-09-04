int PUL=7; //define Pulse pin
int DIR=6; //define Direction pin
int ENA=5; //define Enable Pin
#define bau 57600
#define Angle 36
#define delaytimeMS 2000
int step=(Angle/9)*160;
bool is_Enable=false;
bool is_CCW=false;
void setup() {
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);
  digitalWrite(ENA,LOW);
  digitalWrite(DIR,LOW);
  Serial.begin(bau);
}

void loop() { 
  if(Serial.available() > 0)
  {
    char cmd=Serial.read();
    if(cmd=='s')
      is_Enable=false;
    if(cmd=='w')
     is_Enable=true;
    if(cmd=='a')
    {
      is_CCW=true;
      digitalWrite(DIR,HIGH);
    }
    if(cmd=='d')
    {
      is_CCW=false;
      digitalWrite(DIR,LOW);
    }
  }
  /************************************************************/
  if(is_Enable)
  { 
      digitalWrite(ENA,HIGH);
      for(int i=0;i<step;i++)
      {
        digitalWrite(PUL,HIGH);
        delayMicroseconds(delaytimeMS);
        digitalWrite(PUL,LOW);
        delayMicroseconds(delaytimeMS);
      }
      is_Enable=false;
      digitalWrite(ENA,LOW);
      Serial.println("Done"); 
  }
  else
  { 
    is_Enable=false;
    digitalWrite(ENA,LOW);
  }
/**********************************************************/
 
  
}
