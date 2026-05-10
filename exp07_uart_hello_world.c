/* Experiment No: 07
   Display "Hello World" message using UART with IoT
   Aim: UART (Universal Asynchronous Receiver Transmitter) main purpose is to 
        transmit and receive serial string data using serial communication.
   Objective: To learn how serial communication is achieved using UART (serial string data).
   Components Required:
     1) Arduino UNO
     2) Arduino UNO USB cable (Type A to Type B)
   Connections: Arduino UNO connected to computer through USB cable.
   Procedure:
     1. Open the Arduino IDE and create and save a sketch source code as follows.
     2. Compile sketch.
     3. Upload sketch onto Arduino UNO.
*/

void setup()
{
    Serial.begin(9600);     /* Initialize UART at 9600 baud rate */
}

void loop()
{
    Serial.println("Hello world");  /* Send message */
    delay(1000);                    /* 1 second delay */
}
