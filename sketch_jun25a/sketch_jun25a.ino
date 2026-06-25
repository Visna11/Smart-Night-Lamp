// Pin Configurations 
const int ldrPin = A0;  // Analog pin connected to the LDR divider 
const int ledPin = 13;  // Digital pin connected to the LED 
  
// Threshold value to determine "Darkness" 
// Sensor values range from 0 (pitch black) to 1023 (very bright) 
const int threshold = 400; 
  
void setup() { 
  // Initialize pin modes 
  pinMode(ledPin, OUTPUT); 
  pinMode(ldrPin, INPUT); 
  
  // Start serial communication for monitoring light levels 
  Serial.begin(9600); 
} 
  
void loop() { 
  // Read the analog value from the LDR 
  int ldrValue = analogRead(ldrPin); 
  
  // Print the value to the Serial Monitor (useful for debugging) 
  Serial.print("Light Level: "); 
  Serial.println(ldrValue); 
  
  // Check if it is dark enough to turn the lamp on 
  if (ldrValue < threshold) { 
    digitalWrite(ledPin, HIGH); // Turn LED ON 
  } else { 
    digitalWrite(ledPin, LOW);  // Turn LED OFF 
  } 
  
  delay(100); // Small delay to stabilize readings 
}
