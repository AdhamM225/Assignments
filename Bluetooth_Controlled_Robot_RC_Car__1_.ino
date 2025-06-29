char Val;
 
void setup() {
  pinMode(5,OUTPUT);   //EnA
  pinMode(6,OUTPUT);   //EnB
  pinMode(8,OUTPUT);   //left motors forward
  pinMode(9,OUTPUT);   //left motors backward
  pinMode(10,OUTPUT);  //right motors forward
  pinMode(11,OUTPUT);  //right motors backward
  Serial.begin(9600);
}
 
void loop() {
  if(Serial.available()){
    Val = Serial.read();
    Serial.println(Val);
  }
 
  if(Val == 'F'){            //move forward(all motors rotate in forward direction)
    analogWrite(5, 180);
    digitalWrite(8, 1);
    digitalWrite(9, 0);
    analogWrite(6, 180);
    digitalWrite(10, 1);
    digitalWrite(11, 0);
  }
 
  else if(Val == 'B'){      //move backward (all motors rotate in reverse direction)
    analogWrite(5, 180);
    digitalWrite(8, 0);
    digitalWrite(9, 1);
    analogWrite(6, 180);
    digitalWrite(10, 0);
    digitalWrite(11, 1);
  }
 
  else if(Val == 'L'){  
    analogWrite(5, 180);
    digitalWrite(8, 1);
    digitalWrite(9, 0);
    analogWrite(6, 180);
    digitalWrite(10, 0);
    digitalWrite(11, 1);
  }
 
  else if(Val == 'R'){  
    analogWrite(5, 180);
    digitalWrite(8, 0);
    digitalWrite(9, 1);
    analogWrite(6, 180);
    digitalWrite(10, 1);
    digitalWrite(11, 0);
  }
 
  else if(Val == 'S'){      //STOP (all motors stop)
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
}
