int pb=6;
int counter=0;
int lastButtonState=LOW;

void setup(){
{pinMode(pb,INPUT);}
Serial.begin(9600);
}

void loop(){
int pushButtonState=digitalRead(pb);
if (pushButtonState==HIGH  && lastButtonState==LOW)
{Serial.println(counter++);}
delay(150);
}
    
      

