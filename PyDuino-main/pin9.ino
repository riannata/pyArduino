/*
#define sensorPin A0

void setup() {
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  // Get the voltage reading from the TMP36
  int reading = analogRead(sensorPin);

  // Convert that reading into voltage
  // Replace 5.0 with 3.3, if you are using a 3.3V Arduino
  float voltage = reading * (5.0 / 1024.0);

  // Convert the voltage into the temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100;

  // Print the temperature in Celsius
  digitalWrite(9, HIGH);
  Serial.println(temperatureC);


  delay(300); // wait a second between readings
}
*/

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);  // Inisialisasi komunikasi serial
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Hapus spasi/kosong

    if (command == "ON") {
      digitalWrite(13, HIGH);  // Nyalakan LED
    } else if (command == "OFF") {
      digitalWrite(13, LOW);   // Matikan LED
    }
  }
}
