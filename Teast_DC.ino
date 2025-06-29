#define ENA 9   // Enable/speed pin for motor A
#define IN1 8   // Control pin 1 for motor A
#define IN2 7   // Control pin 2 for motor A
#define ENB 10  // Enable/speed pin for motor B
#define IN3 6   // Control pin 1 for motor B
#define IN4 5   // Control pin 2 for motor B

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop() {
    moveForward();
    delay(2000);
    moveBackward();
    delay(2000);
    turnLeft();
    delay(2000);
    turnRight();
    delay(2000);
    stopMotors();
    delay(2000);
}

void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 255);  // Full speed
    analogWrite(ENB, 255);
}

void moveBackward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
}

void turnLeft() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
}

void turnRight() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
}

void stopMotors() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

