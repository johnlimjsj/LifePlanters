#include <ESPert.h>

ESPert espert;

const char *host = "api.thingspeak.com";
String apiKey = "ZYAOSMPHJDPFLOFV"; //replace with your channel's thingspeak API key
float temperature = 0.0f, humidity = 0.0f;

void setup()
{
  espert.init();
  espert.dht.init();
  espert.oled.init();
  delay(2000);

  espert.oled.clear();
  espert.oled.println(espert.info.getId());
  espert.oled.println();

  int mode = espert.wifi.init();

  if (mode == ESPERT_WIFI_MODE_CONNECT)
  {
    espert.println(">>> WiFi mode: connected.");
    espert.oled.println("WiFi: connected.");
    espert.oled.print("IP..: ");
    espert.oled.println(espert.wifi.getLocalIP());
  }
  else if (mode == ESPERT_WIFI_MODE_DISCONNECT)
  {
    espert.println(">>> WiFi mode: disconnected.");
    espert.oled.println("WiFi: not connected.");
  }
  else if (mode == ESPERT_WIFI_MODE_SMARTCONFIG)
  {
    espert.println(">>> WiFi mode: smart config.");
  }
  else if (mode == ESPERT_WIFI_MODE_SETTINGAP)
  {
    espert.println(">>> WiFi mode: access point.");
  }
  delay(2000);
}

void loop()
{
  espert.loop();

  float t = espert.dht.getTemperature();
  float h = espert.dht.getHumidity();
  if(!isnan(t) && !isnan(h))
  {
    temperature = t;
    humidity = h;
  }
  
  String path = "/update?api_key=" + apiKey + "&field1=" + (String)(temperature) + "&field2=" + (String)(humidity);
  espert.wifi.getHTTP(host, path.c_str());
  espert.oled.clear();
  espert.oled.println("Temperature=" + (String)(temperature) + "C");
  espert.oled.println("Humidity=" + (String)(humidity) + "%");

  delay(8000);
}

