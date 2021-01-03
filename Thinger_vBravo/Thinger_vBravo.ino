int angle = 0, fall_trigger = 0;
int ind1;
int ind2;
String datas = "";
String Angles;
String Fall="Safe";
#include <ThingerESP8266.h>

#define USERNAME "BillionW"
#define DEVICE_ID "NodeMCU"
#define DEVICE_CREDENTIAL "Pranay@123"

#define SSID "BillionWords"
#define SSID_PASSWORD "Pranay1000..."

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  thing.add_wifi(SSID, SSID_PASSWORD);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["led"] << digitalPin(LED_BUILTIN);

  // resource output example (i.e. reading a sensor value)
  thing["Angle"] >> outputValue(Angles);
  thing["Fall"] >> outputValue(Fall);
}

// more details at http://docs.thinger.io/arduino/

void loop() {
  storeval();
  thing.handle();
}

void storeval()
{
  datas = Serial.readString();
  ind1 = datas.indexOf(',');  //finds location of first ,
  Angles = datas.substring(0, ind1);   //captures first data String
  Serial.println(Angles);
  ind2 = datas.indexOf(',', ind1 + 1 ); //finds location of second ,
  Fall = datas.substring(ind1+1, ind2);
  Serial.println(Fall);

}
