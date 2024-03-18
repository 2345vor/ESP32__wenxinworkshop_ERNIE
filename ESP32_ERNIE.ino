#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// 1. Replace with your network credentials
const char* ssid = "J09 502";
const char* password = "qwertyuiop111";

// Replace with your OpenAI API key
// const char* apiKey = "1CeoUoYgnfc6s5liNR2uoQrk";
// const char* secret_Key = "G3n9aHVerzGqr0EWsLnca0fVkiXI9BVz";
//const char* access_token = "24.01bb97173188a1a22d6a6991918f6508.2592000.1706880634.282335-46332156";
// Send request to OpenAI API
String inputText = "你好，文心一言";
// 2. Replace with your access_token
String apiUrl = "https://aip.baidubce.com/rpc/2.0/ai_custom/v1/wenxinworkshop/chat/completions?access_token=24.23087285c9ab53cbfd7aad5c032ae371.2592000.1706878581.282335-46332156";

String answer;
String getGPTAnswer(String inputText) {
  HTTPClient http;
  http.setTimeout(10000);
  http.begin(apiUrl);
  http.addHeader("Content-Type", "application/json");
  // http.addHeader("access_token", String(access_token));
  String payload = "{\"messages\":[{\"role\": \"user\",\"content\": \"" + inputText + "\"}],\"disable_search\": false,\"enable_citation\": false}";
  int httpResponseCode = http.POST(payload);
  if (httpResponseCode == 200) {
    String response = http.getString();
    http.end();
    Serial.println(response);

    // Parse JSON response
    DynamicJsonDocument jsonDoc(1024);
    deserializeJson(jsonDoc, response);
    String outputText = jsonDoc["result"];
    return outputText;
    // Serial.println(outputText);
  } else {
    http.end();
    Serial.printf("Error %i \n", httpResponseCode);
    return "<error>";
  }
}

void setup() {
  // Initialize Serial
  Serial.begin(115200);

  // Connect to Wi-Fi network
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  answer = getGPTAnswer(inputText);
  Serial.println("Answer: " + answer);
  Serial.println("Enter a prompt:");

}

void loop() {
  // do nothing
  if (Serial.available()) {
    inputText = Serial.readStringUntil('\n');
    // inputText.trim();
    Serial.println("\n Input:"+inputText);

    answer = getGPTAnswer(inputText);
    Serial.println("Answer: " + answer);
    Serial.println("Enter a prompt:");
  }
  // delay(2);
}

