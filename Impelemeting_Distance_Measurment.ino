const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;

void setup()
{
  pinMode(TRIG_PIN, OUTPUT);

  pinMode(ECHO_PIN, INPUT);

  pinMode(LED1, OUTPUT);

  pinMode(LED2, OUTPUT);

  pinMode(LED3, OUTPUT);

  pinMode(LED4, OUTPUT);

  Serial.begin(9600); }

void loop()
{
 
  long duration;

  int distance;

  digitalWrite(TRIG_PIN, LOW);

  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);

  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;


 if (distance < 10) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
} else if (distance < 20) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
} else if (distance < 40) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
} else {
    digitalWrite(LED1, 

LOW );
    digitalWrite(LED2, 

LOW );
    digitalWrite(LED3, 

LOW );
    digitalWrite(LED4, HIGH);
}

Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
delay(500);

}
