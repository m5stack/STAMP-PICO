/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with STAMP-PICO sample source code
*                          配套  STAMP-PICO 示例源代码
* Visit the website for more information：https://docs.m5stack.com/en/core/stamp_pico
* 获取更多资料请访问：https://docs.m5stack.com/zh_CN/core/stamp_pico
*
* describe：announcing & finding services.  广播&查找服务
* date：2021/10/1
*******************************************************************************
*/

#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>

// Set the name and password of the wifi to be connected.  配置所连接wifi的名称和密码
const char* ssid     = "Explore-F";
const char* password = "xingchentansuo123";

void browseService(const char * service, const char * proto){ //find devices.  查找设备
  Serial.printf("Browsing for _%s._%s.local ", service, proto);
  int n = MDNS.queryService(service, proto);  //Store the number of devices found in n.  将找到的设备数存储在n中
  if (n == 0) { //if don't have any devices.  如果没有任何设备
    Serial.println("no services found");
  } else {
    Serial.printf("%d service(s) found\n",n);
    for (int i = 0; i < n; ++i) { // Print details for each service found.  打印每个找到的设备
      Serial.printf(" %d: ",i + 1);
      Serial.print(MDNS.hostname(i)); //output the devies name.  输出设备名称
      Serial.print("  ");
      Serial.print(MDNS.IP(i)); //Output the devices IP Address.  输出设备的IP地址
      Serial.printf(":%d\n",MDNS.port(i));  //output the devices port.  输出设备的端口号
    }
  }
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password); //Connect wifi and return connection status.  连接wifi并返回连接状态
  Serial.print("Connected to ");
  Serial.print(ssid); //Output Network name.  输出网络名称
  while (WiFi.status() != WL_CONNECTED) { //If the wifi connection fails.  若wifi未连接成功
    delay(500); //delay 0.5s.  延迟0.5s
    Serial.print(".");
  }
  Serial.print("Success!\nIP address: ");
  Serial.println(WiFi.localIP()); //Output IP Address.  输出IP地址

  if (!MDNS.begin("ESP32_Browser")) { //if init error.  如果初始化错误
    Serial.println("Error setting up MDNS responder!");
    while(1){
      delay(1000);
    }
  }
}

void loop() {
  browseService("http", "tcp");
  delay(1000);
  browseService("arduino", "tcp");
  delay(1000);
  browseService("workstation", "tcp");
  delay(3000);
  browseService("smb", "tcp");
  delay(1000);
  browseService("afpovertcp", "tcp");
  delay(1000);
  browseService("ftp", "tcp");
  delay(1000);
  browseService("ipp", "tcp");
  delay(1000);
  browseService("printer", "tcp");
  delay(10000);
}