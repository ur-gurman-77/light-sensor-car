#define leftSensor 2
#define rightSensor 3
#define ena 4
#define in1 5
#define in2 6
#define in3 7
#define in4 8
#define enb 9

int speedA = 200;
int speedB = 200;

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int l = digitalRead(leftSensor);
  int r = digitalRead(rightSensor);
   if (l == 0 && r == 1) {
  
    analogWrite(ena, speedA);
    analogWrite(enb, speedB);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("left");
  } else if (r == 0 && l == 1) {
    
    analogWrite(ena, speedA);
    analogWrite(enb, speedB);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("right");
  } else {
    
    analogWrite(ena, 0);
    analogWrite(enb, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.println("stop");
  }
}