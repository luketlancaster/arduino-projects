int d = 2;

void setup(){
  pinMode(2,INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  d = digitalRead(2);
  if (d == 0) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}
