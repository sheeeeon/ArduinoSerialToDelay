int ledPin = 13;
unsigned long value = 1000; //기본값

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char buf[30] = "";
  
  int i = 0;
  while (Serial.available()) {
    buf[i] += Serial.read();
    i++;
  }
  
  value = atol(buf);
  Serial.println(buf);
  
  while (1) {
    if (Serial.available()) {
      break;
    }
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(value);
    digitalWrite(ledPin, LOW);
    delayMicroseconds(value);
  }
  delay(100);
}
