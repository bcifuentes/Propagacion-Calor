#include <math.h>
double Vo= 125;
double t=0;
double V;
//frecuencia
double w=5;
//desfase
double p=1.5;
void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  V=Vo+Vo*sin(w*t+p);
  analogWrite(3,V);
  
  int v1=analogRead(A0);
  int v2=analogRead(A1);
  int v3=analogRead(A2);

  double T1 = (v1/1024.)*5000*1/10.;
  double T2 = (v2/1024.)*5000*1/10.;
  double T3 = (v3/1024.)*5000*1/10.;
  
  Serial.print(t);
  Serial.print(' ');
  Serial.print(T1);
  Serial.print(' ');
  Serial.print(T2);
  Serial.print(' ');
  Serial.println(T3); 
  delay(100);
  t=t+0.1;
}
