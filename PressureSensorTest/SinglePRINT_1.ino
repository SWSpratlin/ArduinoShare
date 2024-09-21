#include "esp_log.h"

public void setup(void)
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

int Sens0 = 0;
int Sens1 = 0;
int Sens2 = 0;
int Sens3 = 0;
// Setting up Sens# variables to be read against "Threshold" later

int threshold = 200; // Threshold for how much pressure is applied to trigger a controller print

int pressure0 = 0; // False
int pressure1 = 0; // False
int pressure2 = 0; // False
int pressure3 = 0; // False
// Changing variables to trigger the "A-D" controller order

int Sensor0State = 0;     // Current state of Sensor 0
int lastSensor0State = 0; // Last Recorded state of sensor 0

int Sensor1State = 0;     // Current state of Sensor 1
int lastSensor1State = 0; // Last Recorded state of sensor 1

int Sensor2State = 0;     // Current state of Sensor 2
int lastSensor2State = 0; // Last Recorded state of sensor 2

int Sensor3State = 0;     // Current state of Sensor 3
int lastSensor3State = 0; // Last Recorded state of sensor 3
// Defining current and previous state variables

void loop(void)
{
  // Start the Loop, and begin reading sensor values

  Sens0 = analogRead(A0);
  Sens1 = analogRead(A1);
  Sens2 = analogRead(A2);
  Sens3 = analogRead(A3);
  // Read each sensor value, and apply the value to Sens# to be checked against Threshold

  //////////////////////////////////////////////////////////////////////////////////////
  // SENSOR 0 PRESSURE PRINT CODE
  if (Sens0 > threshold)
  {
    pressure0 = 1;
  }
  else
  {
    pressure0 = 0;
  }
  // Set pressure0 variable to "true" if the sensor is reading higher than the threshold
  // Means someone/something is applying enough pressure to the sensor

  Sensor0State = pressure0; // Set Sensor state to the current state of the pressure0 variable

  if (Sensor0State != lastSensor0State)
  {
    // Check the sensor state against the last previous state
    if (Sensor0State == 1)
    {
      // Check if the Sensor is reading more than 300
      Serial.print(" A ");
      // Print the "A" controller Order to Isadora
    }
  }
  delay(1);
  // Set a delay to avoid tripping over itself

  lastSensor0State = Sensor0State;
  // Save current state to previous state

  //////////////////////////////////////////////////////////////////////////////////////
  // SENSOR 1 PRESSURE PRINT CODE

  if (Sens1 > threshold)
  {
    pressure1 = 1;
  }
  else
  {
    pressure1 = 0;
  }
  // Set pressure1 variable to "true" if the sensor is reading higher than the threshold
  // Means someone/something is applying enough pressure to the sensor

  Sensor1State = pressure1; // Set Sensor state to the current state of the pressure1 variable

  if (Sensor1State != lastSensor1State)
  {
    // Check the sensor state against the last previous state
    if (Sensor1State == 1)
    {
      // Check if the Sensor is reading more than 300
      Serial.print(" D ");
      // Print the "D" Controller Order to Isadora
    }
  }
  delay(1);
  // Set a delay to avoid tripping over itself

  lastSensor1State = Sensor1State;
  // Save current state to previous state

  //////////////////////////////////////////////////////////////////////////////////////
  // SENSOR 2 PRESSURE PRINT CODE

  if (Sens2 > threshold)
  {
    pressure2 = 1;
  }
  else
  {
    pressure2 = 0;
  }
  // Set pressure2 variable to "true" if the sensor is reading higher than the threshold
  // Means someone/something is applying enough pressure to the sensor

  Sensor2State = pressure2; // Set Sensor state to the current state of the pressure2 variable

  if (Sensor2State != lastSensor2State)
  {
    // Check the sensor state against the last previous state
    if (Sensor2State == 1)
    {
      // Check if the Sensor is reading more than 300
      Serial.print(" C ");
      // Print the "C" Controller Order to Isadora
    }
  }
  delay(1);
  // Set a delay to avoid tripping over itself

  lastSensor2State = Sensor2State;
  // Save current state to previous state

  //////////////////////////////////////////////////////////////////////////////////////
  // SENSOR 3 PRESSURE PRINT CODE

  if (Sens3 > threshold)
  {
    pressure3 = 1;
  }
  else
  {
    pressure3 = 0;
  }
  // Set pressure3 variable to "true" if the sensor is reading higher than the threshold
  // Means someone/something is applying enough pressure to the sensor

  Sensor3State = pressure3; // Set Sensor state to the current state of the pressure3 variable

  if (Sensor3State != lastSensor3State)
  {
    // Check the sensor state against the last previous state
    if (Sensor3State == 1)
    {
      // Check if the Sensor is reading more than 300
      Serial.print(" B ");
      // Print the "B" Controller Order to Isadora
    }
  }
  delay(1);
  // Set a delay to avoid tripping over itself

  lastSensor3State = Sensor3State;
  // Save current state to previous state
}