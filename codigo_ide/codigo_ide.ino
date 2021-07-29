#include <math.h>

unsigned long current = 0;
unsigned long previous = 0; 
int rr = 0;
int Nt = 100;
float tiempos[100];

int v1 =0;
int v2 =0;
int v3 =0;

void setup() {
  pinMode(2,INPUT);
  pinMode(4,INPUT);
  attachInterrupt(digitalPinToInterrupt(2), timediff, FALLING);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void timediff() {
  float segundo;
  previous = current;
  current=millis();
  segundo = float(current)/1000;
  tiempos[rr] = segundo;
  rr = rr+1;
}

void loop() {
  double Vo=50;
  double V;
  unsigned long t=millis();
  if(digitalRead(4)==HIGH){
      V=Vo*sin(10*t);
      analogWrite(3, V);
    }
  else{
      analogWrite(3,Vo);
    }
  
  v1=analogRead(A0);
  v2=analogRead(A1);
  v3=analogRead(A2);
  
  double t1 = (v1/1024.)*5000*1/10.;
  double t2 = (v2/1024.)*5000*1/10.;
  double t3 = (v3/1024.)*5000*1/10.;
  
  if(rr <= Nt){
    Serial.print(tiempos[rr-1]);
    Serial.print(' ');
    Serial.print(t1);
    Serial.print(' ');
    Serial.print(t2);
    Serial.print(' ');
    Serial.println(t3); 
    delay(1000);
  }
} 
