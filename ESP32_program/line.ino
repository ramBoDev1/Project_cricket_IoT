void Line_Notify1(String message) {
  WiFiClientSecure lineclient;
  lineclient.setInsecure();           //
  if (!lineclient.connect("notify-api.line.me", 443)) {
    delay(2000);
    return;
  }
  
  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + String(LINE_TOKEN_PIR) + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: ESP8266\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
  req += "\r\n";
  req += "message=" + message;
  lineclient.print(req);

  delay(20);

  while (lineclient.connected()) {
    String line = lineclient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
}
