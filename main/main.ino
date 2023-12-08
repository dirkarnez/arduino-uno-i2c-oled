int a = 0;
int ledPin13 = 13;
int ledPin12 = 12;
int ledPin11 = 11;
int ledPin10 = 10;
int ledPin9 = 9;
int ledPin8 = 8;
 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin13, OUTPUT);
  pinMode(ledPin12, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin8, OUTPUT);
}

void loop() {
    Serial.println(a);
    digitalWrite(ledPin13, ((a & 0b100000) == 0b100000) ? HIGH : LOW);
    digitalWrite(ledPin12, ((a & 0b10000) == 0b10000) ? HIGH : LOW);
    digitalWrite(ledPin11, ((a & 0b1000) == 0b1000) ? HIGH : LOW);
    digitalWrite(ledPin10, ((a & 0b100) == 0b100) ? HIGH : LOW);
    digitalWrite(ledPin9, ((a & 0b10) == 0b10) ? HIGH : LOW);
    digitalWrite(ledPin8, ((a & 0b1) == 0b1) ? HIGH : LOW);
    delay(1000); 
    a++;
}
