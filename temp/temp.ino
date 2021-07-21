int val =0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=analogRead(A0);
  double av = (val/1024.)*5000;
  double c= av/10.;
  Serial.print("Temperatura:");
  Serial.println(c);
  delay(100);

}
