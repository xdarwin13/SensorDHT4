#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <DHT.h>

// Definir pines de los cuatro sensores DHT11
#define DHTPIN1 5
#define DHTPIN2 18
#define DHTPIN3 19
#define DHTPIN4 21
#define DHTTYPE DHT11

// Crear instancias para cada sensor
DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);
DHT dht4(DHTPIN4, DHTTYPE);

AsyncWebServer server(80);

// Credenciales WiFi
const char* ssid = "Darwin";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);
  
  // Inicializar los sensores DHT
  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }

  Serial.println("Conectado a la red WiFi");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  // Configurar rutas API para cada sensor
  server.on("/temperature1", HTTP_GET, [](AsyncWebServerRequest *request){
    float temperature = dht1.readTemperature();
    String response = String("{\"temperature\":") + temperature + "}";
    AsyncResponseStream *responseStream = request->beginResponseStream("application/json");
    responseStream->print(response);
    responseStream->addHeader("Access-Control-Allow-Origin", "*");
    request->send(responseStream);
  });

  server.on("/humidity1", HTTP_GET, [](AsyncWebServerRequest *request){
    float humidity = dht1.readHumidity();
    String response = String("{\"humidity\":") + humidity + "}";
    AsyncResponseStream *responseStream = request->beginResponseStream("application/json");
    responseStream->print(response);
    responseStream->addHeader("Access-Control-Allow-Origin", "*");
    request->send(responseStream);
  });

  server.on("/temperature2", HTTP_GET, [](AsyncWebServerRequest *request){
    float temperature = dht2.readTemperature();
    String response = String("{\"temperature\":") + temperature + "}";
    AsyncResponseStream *responseStream = request->beginResponseStream("application/json");
    responseStream->print(response);
    responseStream->addHeader("Access-Control-Allow-Origin", "*");
    request->send(responseStream);
  });

  server.on("/humidity2", HTTP_GET, [](AsyncWebServerRequest *request){
    float humidity = dht2.readHumidity();
    String response = String("{\"humidity\":") + humidity + "}";
    AsyncResponseStream *responseStream = request->beginResponseStream("application/json");
    responseStream->print(response);
    responseStream->addHeader("Access-Control-Allow-Origin", "*");
    request->send(responseStream);
  });

  server.on("/temperature3", HTTP_GET, [](AsyncWebServerRequest *request){
    float temperature = dht3.readTemperature();
    String response = String("{\"temperature\":") + temperature + "}";
    AsyncResponseStream *responseStream = request->beginResponseStream("application/json");
    responseStream->print(response);
    responseStream->addHeader("Access-Control-Allow-Origin", "*");
    request->send(responseStream);
  });

  server.on("/humidity3", HTTP_GET, [](AsyncWebServerRequest *request){
    float humidity = dht3.readHumidity();
    String response = String("{\"humidity\":") + humidity + "}";
    AsyncResponseStream *responseStream = request->beginResponseStream("application/json");
    responseStream->print(response);
    responseStream->addHeader("Access-Control-Allow-Origin", "*");
    request->send(responseStream);
  });

  server.on("/temperature4", HTTP_GET, [](AsyncWebServerRequest *request){
    float temperature = dht4.readTemperature();
    String response = String("{\"temperature\":") + temperature + "}";
    AsyncResponseStream *responseStream = request->beginResponseStream("application/json");
    responseStream->print(response);
    responseStream->addHeader("Access-Control-Allow-Origin", "*");
    request->send(responseStream);
  });

  server.on("/humidity4", HTTP_GET, [](AsyncWebServerRequest *request){
    float humidity = dht4.readHumidity();
    String response = String("{\"humidity\":") + humidity + "}";
    AsyncResponseStream *responseStream = request->beginResponseStream("application/json");
    responseStream->print(response);
    responseStream->addHeader("Access-Control-Allow-Origin", "*");
    request->send(responseStream);
  });

  server.begin();
}

void loop() {}
