const int redPin = 4;
const int bluePin = 3;
const int greenPin = 2;
const int sensorPin = A0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Serial.begin(9600);  // For debugging
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Light level: ");
  Serial.println(sensorValue);

  if (sensorValue < 450) {
    setColor(200, 0, 0);  // Red for dark
  } else if (sensorValue > 800) {
    setColor(0, 0, 200);  // Green for bright
  } else if (sensorValue >= 500 && sensorValue <= 600) {
    setColor(0, 0, 0);    // OFF for moderate light
  } else {
    setColor(0, 200, 0);  // Blue for ambient
  }

  delay(200);
}

void setColor(int r, int b, int g) {
  analogWrite(redPin, r);
  analogWrite(bluePin, b);
  analogWrite(greenPin, g);
}

/*
code to test LDR thresholds in 3 lighting conditions:

const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("LDR Value: ");
  Serial.println(sensorValue);
  delay(200);
}
*/
