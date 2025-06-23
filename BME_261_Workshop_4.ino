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

  // Adjust the thresholds to fit room/lighting conditions
  if (sensorValue < 400) {
    // DARK → Red
    setColor(200, 0, 0);
  } else if (sensorValue > 800) {
    // BRIGHT → Green (for real circuit replace 200 with 50)
    setColor(0, 0, 50);
  } else {
    // Ambient → Blue
    setColor(0, 200, 0);
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
