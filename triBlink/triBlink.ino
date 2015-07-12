int redPin = 12;
int greenPin = 11;
int bluePin = 10;

int time = 250;

int redSwitchPin = 7;
int greenSwitchPin = 6;
int blueSwitchPin = 5;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redSwitchPin, INPUT_PULLUP);
  pinMode(blueSwitchPin, INPUT_PULLUP);
  pinMode(greenSwitchPin, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(redSwitchPin) == LOW)
  {
    red ++;
    if (red > 255) red = 0;
  }
  if (digitalRead(blueSwitchPin) == LOW)
  {
    blue ++;
    if (blue > 255) blue = 0;
  }
  if (digitalRead(greenSwitchPin) == LOW)
  {
    green ++;
    if (green > 255) green = 0;
  }
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(grenPin, green);
  delay(10);
}
//
//void red()
//{
//  digitalWrite(redPin, HIGH);
//  digitalWrite(greenPin, LOW);
//  digitalWrite(bluePin, LOW);
//  delay(time);
//}
//
//void green()
//{
//  digitalWrite(redPin, LOW);
//  digitalWrite(greenPin, HIGH);
//  digitalWrite(bluePin, LOW);
//  delay(time);
//}
//
//void blue()
//{
//  digitalWrite(redPin, LOW);
//  digitalWrite(greenPin, LOW);
//  digitalWrite(bluePin, HIGH);
//  delay(time);
//}
//
//void violet()
//{
//  digitalWrite(redPin, HIGH);
//  digitalWrite(greenPin, LOW);
//  digitalWrite(bluePin, HIGH);
//  delay(time);
//}
//
//void turquoise()
//{
//  digitalWrite(redPin, HIGH);
//  digitalWrite(greenPin, HIGH);
//  digitalWrite(bluePin, LOW);
//  delay(time);
//}
//
//void yellow()
//{
//  digitalWrite(redPin, LOW);
//  digitalWrite(greenPin, HIGH);
//  digitalWrite(bluePin, HIGH);
//  delay(time);
//}
