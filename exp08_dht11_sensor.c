/* Experiment No: 08
   Interface the DHT11 Sensor with Arduino and write a program to send temperature and humidity values.
   Aim: Read the sensor data to measure Temperature and Relative Humidity value.
   Objective: To study the Temperature and Receive Humidity value of sensor data.
   Components Required:
     1) Arduino UNO
     2) DHT11 Temperature & Humidity sensor data
   Connections:
     Arduino Pin | DHT11 Sensor
     5V          | +VE
     A0          | OUT
     GND         | -VE
   Procedure:
     1. Set up pin connection DHT11 Humidity Temperature sensor and Arduino UNO as shown in figure.
     2. Open the Arduino UNO IDE and create and save a sketch source code as follows.
     3. Compile sketch.
     4. Upload sketch onto Arduino UNO.
*/

#include <DHT.h>            /* Library to interface DHT11 temperature and humidity sensor */

#define DHTPIN 7            /* Digital PIN where DHT11 data pin is connected */
#define DHTTYPE DHT11       /* Define the sensor type (DHT11) */

DHT dht(DHTPIN, DHTTYPE);  /* Create DHT sensor object */

void setup()
{
    Serial.begin(9600);     /* Serial communication at 9600 baud rate */
    dht.begin();            /* Initialize the DHT11 sensor */
}

void loop()
{
    /* Read humidity from sensor */
    float humidity = dht.readHumidity();

    /* Read temperature from sensor */
    float temperature = dht.readTemperature();

    /* Check if sensor reading failed (NaN = not a number) */
    if (isnan(humidity) || isnan(temperature))
    {
        Serial.println("Sensor error!");    /* Print error message */
        delay(2000);                        /* Wait 2 seconds before retrying */
        return;                             /* Exit loop to entry */
    }

    /* Print temperature & humidity to serial monitor */
    Serial.print("Temperature: ");
    Serial.print(temperature, 1);   /* Display temperature with 1 decimal value */

    Serial.print("  Humidity: ");
    Serial.print(humidity, 1);      /* Display humidity with 1 decimal value */

    Serial.println(" %");
    delay(2000);                    /* Wait 2 seconds before taking the next reading */
}

/* Applications:
   A humidity sensor senses, measures and reports both moisture and air temperature.
   The ratio of moisture in the air to the highest amount of moisture at a particular
   air temperature is called relative humidity. Relative humidity becomes an important
   factor when looking for comfort. Automated humidity control systems use humidity
   sensors to test humidity levels and can control processes, such as chemical dryers,
   required to maintain a specific relative humidity in industries.
*/
