// The Threshold that the sensors will trigger at.
const int threshold = 200;

// These are the digital pins conencted to the lights Change these to whatever pins you connect the lights to.
const int light1 = 0;
const int light2 = 0;
const int light3 = 0;
const int light4 = 0;

// These are the analog pins that are connected to the sensors. Change them to whatever pins your sensors are connected to
// For clarity, Sensor 1 will correspond to Light 1 (unless you change it).
const int sensor1 = A0;
const int sensor2 = A0;
const int sensor3 = A0;
const int sensor4 = A0;

const int pins[4] = {light1, light2, light3, light4};
const int size = sizeOf(pins) / sizeOf(pins[0]);

//Setting up the pinModes for the output.
void setup(void) {
    Serial.begin(9600);
    pinMode(light1, OUTPUT);
    pinMode(light2, OUTPUT);
    pinMode(light3, OUTPUT);
    pinMode(light4, OUTPUT);
	
	for(int i = 0; i < 3; i++)
	{
		bootflash();
	}
    
}

void bootFlash()
{
    for(int i = 0; i < size; i++)
    {
    	digitalWrite(pins[i], HIGH);
    }
    delay(250);
    for(int i = 0; i < size); i++){
    	digitalWrite(pins[i], LOW);
    }
    delay(250);
}
// This is a function that reads the pressure sensor, and in turn pulls the Pin for the light HIGH.
// This runs continuously, so it will Set the light pin to HIGH every loop of the arduino.
// I have no idea if that will affect the hardware. Might be fine, might not, dunno.
void checkSensorContinuous(int sensorPin, int lightPin)
{
     int sensorRead = analogRead(sensorPin);
     if (sensorRead > threshold)
     {
         digitalWrite(lightPin, HIGH);
     } else {
         digitalWrite(lightPin, LOW);
     }
}

// This function only writes the light pin when something has changed, this means no writing of the light pin
// when someone is continuously standing on a sensor, or no one is standing on a sensor. I think this might be
// better for the hardware overall, but it may introduce bugs to the program.
void checkSensorOnChange(int sensorPin, int lightPin)
{
    static bool lastSensorState = false;
    static bool sensorState = false;

    int sensorRead = analogRead(sensorPin);

    if (sensorRead > threshold)
    {
        sensorState = true;
    } else {
        sensorState = false;
    }

    if (sensorState != lastSensorState)
    {
        if (sensorState == true)
        {
            digitalWrite(lightPin, HIGH);
        } else {
            digitalWrite(lightPin, LOW);
        }

        lastSensorState = sensorState;
    }

    delay(1);
    lastSensorState = sensorState;
}

void loop(void)
{
    // Functions to check each sensor and apply changes to lights
    // continuously. Make sure you change the constants at the start
    // to make sure you're reading/writing the right pins

    checkSensorContinuous(sensor1, light1);
    checkSensorContinuous(sensor2, light2);
    checkSensorContinuous(sensor3, light3);
    checkSensorContinuous(sensor4, light4);



    // Comment out the above functions, and uncomment these if you want to try the "update lights only
    // when something changes" functions.
    // This is closer to the function that I used for my sensor plates, but I specifically needed them only
    // to act when something changed and ONLY when something changed.

    // checkSensorOnChange(sensor1, light1);
    // checkSensorOnChange(sensor2, light2);
    // checkSensorOnChange(sensor3, light3);
    // checkSensorOnChange(sensor4, light4);
}


