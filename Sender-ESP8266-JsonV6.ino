#include <ArduinoJson.h>

long interval = 1000;
unsigned long lastTime = 0;

float dataFloat;
int dataInt;
String dataString = "Hello world";

void setup()
{
    Serial.begin(9600);
    while (!Serial)
        continue;
}

void loop()
{
    if ((millis() - lastTime) > interval)
    {
        dataFloat = random(0, 1000);
        dataInt = random(0, 1000);

        StaticJsonDocument<1024> doc;
        doc["data1"] = dataString;
        doc["data2"] = dataFloat;
        doc["data3"] = dataInt;
        serializeJson(doc, Serial);
        lastTime = millis();
    }
}