/* BE102 Project

Submitted by:
  Akshay Raj PB
  Akshay S Kumar
  Gokul K
  Reuben Thomas Peter
  Nithin PS
  Nived PS
*/

#define trigpin 7 /* Trigger Pin of HC-SR04 */
#define echopin 6 /* Echo Pin of HC-SR04 */

#define depth 70 /* The depth of the tank */

int led1 = A0; /* LED1 */
int led2 = A1; /* LED2 */
int led3 = A2; /* LED3 */
int led4 = A3; /* LED4 */
int led5 = A4; /* LED5 */

void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

  delay(1000);
}

void loop() {
  int duration, distance;

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.println("Centimeter: ");
  Serial.println(distance);

  if (distance <= (depth / 7)) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
  } else if (distance <= (2 * depth / 7)) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
  } else if (distance <= (3 * depth / 7)) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
  } else if (distance <= (4 * depth / 7)) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
  } else if (distance <= (5 * depth / 7)) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
  } else if (distance <= (6 * depth / 7)) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
  
}