#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ESP8266WiFi.h>         // tạo kết nối với wifi
#include <ESP8266HTTPClient.h>   // tạo kết nối client tới web server
#include <WiFiClientSecure.h>     // lớp bảo mật
#include <CertStoreBearSSL.h>     // Bạn cần thêm để đọc được gói CA đã lưu trong flash
#include <LiquidCrystal_I2C.h>    // Hiển thị màn hình LCD I2C
#include <FS.h>                   // thư viện SPIFFS cho esp8266
#include <String>                 // xử lý data
void printResult(String s);
CertStore certStore;
LiquidCrystal_I2C lcd(0x27,16,2);
char *ssid = "Hung_Manh";       // tên wifi
char *pass = "hm22112000";  // mật khẩu
// Set the LCD address to 0x27 for a 16 chars and 2 line display

char HOST_NCOV[] = "https://api.covid19api.com/summary";
String TOTAL_STRING = "TotalConfirmed";
String DEATH_STRING = "TotalDeaths";
String RECOVER_STRING = "TotalRecovered";

String Totals = "";
String Deaths = "";
String Recovers = "";

void setClock() {
  configTime(7 * 3600, 0, "pool.ntp.org", "time.nist.gov");
//configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  Serial.print("Waiting for NTP time sync: ");
  time_t now = time(nullptr);  
  while (now < 8 * 3600 * 2) {  // while (!time(nullptr))
    delay(500);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println("");
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);     
  Serial.print("Current time: ");
  Serial.print(asctime(&timeinfo));
}

void setup(){
  Wire.begin(2, 0);  
  lcd.init();
  lcd.backlight();
  lcd.display();
  WiFi.begin(ssid,pass);

  
  
  while(WiFi.status()!= WL_CONNECTED){
    lcd.print(".");
    delay(400);
    lcd.clear();
  }
  lcd.print("Connect to ");
  lcd.print(ssid);
  delay(500);
  Serial.println("");
  Serial.print("IP : ");
  Serial.print(WiFi.localIP());

  lcd.clear();
  
  SPIFFS.begin();  // bật SPIFFS
  int numCerts = certStore.initCertStore(SPIFFS, PSTR("/certs.idx"), PSTR("/certs.ar"));
  lcd.print(F("CA : "));
  lcd.println(numCerts);
  if (numCerts == 0) {
    lcd.println(F("FAIL"));
    return; // Can't connect to anything w/o certs!
  }
}
void loop(){
  
 
  setClock();   // đồng bộ thời gian   
  
  HTTPClient http;  // khởi tạo kết nối Client-> web server
  BearSSL::WiFiClientSecure *client = new BearSSL::WiFiClientSecure(); // biến client kế thừa lớp WiFiClientSecure
  client->setCertStore(&certStore); // lưu các CA
  http.begin(dynamic_cast<WiFiClient&>(*client), HOST_NCOV); // kết nối HTTPS
  int httpCode = http.GET();  // đọc mã trạng thái
  if (httpCode > 0)
 {
     String s = http.getString();
     Serial.print("Data length: ");
     Serial.println(s.length());
     int n = s.length();
     printResult(s);
 }
 delay(20*60*1000);
} 



void printResult(String s)
{
  //Serial.println(s.indexOf(TOTAL_STRING));
  
  for(int i=s.indexOf(TOTAL_STRING)+TOTAL_STRING.length();i<s.indexOf(TOTAL_STRING)+30;i++)
  {
    if (s[i] != '"')
      Totals += s[i];
    if (s[i] == ',')
    {
      break;
    }
  }
  
//  Serial.println(s.indexOf(DEATH_STRING));
  for(int i=s.indexOf(DEATH_STRING)+DEATH_STRING.length();i<s.indexOf(DEATH_STRING)+30;i++)
  {
    if (s[i] != '"')
      Deaths+= s[i];
    if (s[i] == ',')
    {
      break;
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Totals");
  lcd.print(Totals);
  lcd.setCursor(0, 1);
  lcd.print("Deaths");
  lcd.print(Deaths);
  lcd.display();
}
