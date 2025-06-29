#define ENA 9   // Enable/speed pin for motor A
#define IN1 8   // Control pin 1 for motor A
#define IN2 7   // Control pin 2 for motor A
#define ENB 10  // Enable/speed pin for motor B
#define IN3 6   // Control pin 1 for motor B
#define IN4 5   // Control pin 2 for motor B

// Define IR sensor pins (now using D2 and D3)
#define leftSensor 2   // Left IR sensor D0 connected to D2
#define rightSensor 3  // Right IR sensor D0 connected to D3

void setup() {
    Serial.begin(9600); // For debugging
    pinMode(leftSensor, INPUT);
    pinMode(rightSensor, INPUT);
   
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    stopMotors(); // Ensure the car is stopped at startup
}

void loop() {
    int leftValue = digitalRead(leftSensor);
    int rightValue = digitalRead(rightSensor);

    Serial.print("Left: ");
    Serial.print(leftValue);
    Serial.print(" | Right: ");
    Serial.println(rightValue);

   if (leftValue == 1 && rightValue == 1) {
        moveForward();
    }
    else if (leftValue == 0 && rightValue == 1) {
        turnLeft();
    }
    else if (leftValue == 1 && rightValue == 0) {
        turnRight();
    }
    else {
      stopMotors();
     
  }

}

void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 180);  // Adjust speed as needed
    analogWrite(ENB, 180);
}

void turnLeft() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 180);
    analogWrite(ENB, 180);
}

void turnRight() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 180);
    analogWrite(ENB, 180);
}

void stopMotors() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

