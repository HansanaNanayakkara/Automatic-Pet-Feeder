#define BLYNK_TEMPLATE_ID "TMPL6y5vBDE-Y"
#define BLYNK_TEMPLATE_NAME "Pet Feeder"
#define BLYNK_AUTH_TOKEN "TLxPnOpQeanP0QAGWRgAdfFIVvsbcjS6"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

char auth[] = BLYNK_AUTH_TOKEN; // Blynk authentication token
char ssid[] = "Udi's NetWorK"; // Your WiFi SSID
char pass[] = "udii2000"; // Your WiFi password

Servo servo1;
BlynkTimer timer;

bool manualControl = false; // Flag to indicate manual control is active

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  servo1.attach(2); // Attach servo 1 to GPIO 2

  // Set a timer to open the lid every 5h
  timer.setInterval(18000000L, openLid);
}

void loop()
{
  Blynk.run();
  timer.run(); // Run the timer
}

void openLid()
{
  if (!manualControl) // Only open the lid automatically if not under manual control
  {
    servo1.write(180); // Open the lid by moving the servo to 180 degrees (adjust as needed)
    delay(1000); // Wait 1 second (adjust if needed)
    servo1.write(90); // Close the lid by moving the servo back to 90 degrees
  }
}

BLYNK_WRITE(V0) // Slider Widget for Servo 1 on V0
{
  int pos1 = param.asInt(); // Get value from slider
  manualControl = true; // Enable manual control
  servo1.write(pos1); // Set servo 1 position
  Blynk.virtualWrite(V2, pos1);
}

BLYNK_WRITE(V1) // Button Widget to disable manual control
{
  int state = param.asInt();
  if (state == 0) // Button released
  {
    manualControl = false; // Disable manual control
  }
}
