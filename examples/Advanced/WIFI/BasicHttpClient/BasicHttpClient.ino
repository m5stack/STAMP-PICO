/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with STAMP-PICO sample source code
*                          配套  STAMP-PICO 示例源代码
* Visit the website for more information：https://docs.m5stack.com/en/core/stamp_pico
* 获取更多资料请访问：https://docs.m5stack.com/zh_CN/core/stamp_pico
*
* describe：BasicHTTPClient.
* date：2021/10/1
******************************************************************************
*/
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

WiFiMulti wifiMulti;
HTTPClient http;

void setup() {
  Serial.begin(115200);
  wifiMulti.addAP("Explore-F", "xingchentansuo123");  //Storage wifi configuration information.  存储wifi配置信息
  Serial.print("\nConnecting Wifi...\n"); //print format output string on lcd.  串口格式化输出字符串
}

void loop() {
  if((wifiMulti.run() == WL_CONNECTED)) { // wait for WiFi connection.  等待连接至wifi
    Serial.print("[HTTP] begin...\n");
    http.begin("http://example.com/index.html");  // configure traged server and url.  配置被跟踪的服务器和URL
    Serial.print("[HTTP] GET...\n");
    int httpCode = http.GET();  // start connection and send HTTP header.  开始连接服务器并发送HTTP的标头
    if(httpCode > 0) {  // httpCode will be negative on error.  出错时httpCode将为负值
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
      Serial.print("Please see Serial.");
      if(httpCode == HTTP_CODE_OK) {  // file found at server.  在服务器上找到文件
        String payload = http.getString();
        Serial.println(payload);  //打印在服务器上读取的文件.  Print files read on the server
      }
    }else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }else{
    Serial.print("connect failed");
  }
  delay(5000);
}
