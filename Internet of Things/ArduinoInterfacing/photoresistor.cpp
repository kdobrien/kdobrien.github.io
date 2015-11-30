void setup() {
  pinMode(6,OUTPUT);

  Serial.begin(9600);       // Initialize serial
  Serial.println("Hello");  // Confirm startup on monitor
}

int maxV = -1;
int minV = 2048;

void loop() {
    int voltage = analogRead(A0);

    // Set min and max so that the ciruit works
    // in both bright and dim rooms.  We record the
    // min and max voltage seen and light the led
    // when the light is lower than half brightness.
    if ( voltage > maxV )
      maxV = voltage;
    if ( voltage < minV )
      minV = voltage;
      
    if ( voltage < (maxV + minV) / 2 )
      digitalWrite(6,HIGH);
    else
      digitalWrite(6,LOW);
      
    delay(100);
    // Write the value to the serial monitor
    // for debugging
    Serial.println(voltage);
}