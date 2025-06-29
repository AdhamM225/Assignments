const int buz=3;
const int pot=A0;
const int minAdc=0;
const int maxAdc=1023;
const int minNote=31;
const int maxNote=4978;

void setup() {
 pinMode(buz,OUTPUT);
 pinMode(pot,INPUT);
}

void loop() {
 int buzNote = map (analogRead(pot),minAdc,maxAdc,minNote,maxNote);
 tone(buz,buzNote);
}
