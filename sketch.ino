#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#include <ESP32Servo.h>

#define TRIGGER_PIN 18
#define ECHO_PIN 19
#define MAX_DISTANCE 450
#define OBJECT_DETECTION_THRESHOLD 10  // Cisim tespiti için eşik mesafe (cm)
#define UPDATE_INTERVAL 1500           // LCD güncelleme aralığı (milisaniye)

// LCD ekran adresi genellikle 0x27 veya 0x3F olabilir
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD adresi, sütun sayısı, satır sayısı

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo RadarServo;

int distance;
unsigned long lastUpdateTime = 0;

void setup() {
  Serial.begin(115200);
  RadarServo.attach(26);
  
  // I2C pinlerini tanımla
  Wire.begin(21, 22);  // SDA, SCL pinleri

  lcd.begin(16, 2);  // LCD ekranı başlat: sütun sayısı ve satır sayısı
  lcd.backlight();  // LCD arka ışığını aç

  delay(3000);
}

void loop() {
  unsigned long currentMillis = millis();

  for(int i = 0; i <= 180; i++) {
    RadarServo.write(i);
    delay(10);  // Servo motorun hızını artırmak için delay süresini kısaltın
    
    distance = sonar.ping_cm();
    
    // Mesafe sınırını kontrol edin
    if (distance > MAX_DISTANCE || distance == 0) {
      distance = 0;
    }

    // LCD ekranında mesafeyi göster (3 saniyede bir güncelle)
    if (currentMillis - lastUpdateTime >= UPDATE_INTERVAL) {
      lcd.clear();  // Ekranı temizle
      lcd.setCursor(0, 0);  // Satır ve sütun ayarla
      lcd.print("Angle: ");
      lcd.print(i);
      lcd.print(" degrees");
      
      lcd.setCursor(0, 1);  // İkinci satıra geç
      lcd.print("Distance: ");
      lcd.print(distance);
      lcd.print(" cm");

      lastUpdateTime = currentMillis;  // Son güncelleme zamanını güncelle
    }

    // Mesafe tespiti
    if (distance > 0 && distance < OBJECT_DETECTION_THRESHOLD) {
      Serial.print("Angle: ");
      Serial.print(i);
      Serial.print(" degrees, Distance: ");
      Serial.println(distance);
      Serial.println("Object detected!");
    } else {
      Serial.print("Angle: ");
      Serial.print(i);
      Serial.print(" degrees, Distance: ");
      Serial.println(distance);
    }
  }

  for(int i = 180; i >= 0; i--) {
    RadarServo.write(i);
    delay(10);  // Servo motorun hızını artırmak için delay süresini kısaltın
    
    distance = sonar.ping_cm();
    
    // Mesafe sınırını kontrol edin
    if (distance > MAX_DISTANCE || distance == 0) {
      distance = 0;
    }

    // LCD ekranında mesafeyi göster (3 saniyede bir güncelle)
    if (currentMillis - lastUpdateTime >= UPDATE_INTERVAL) {
      lcd.clear();  // Ekranı temizle
      lcd.setCursor(0, 0);  // Satır ve sütun ayarla
      lcd.print("Angle: ");
      lcd.print(i);
      lcd.print(" degrees");
      
      lcd.setCursor(0, 1);  // İkinci satıra geç
      lcd.print("Distance: ");
      lcd.print(distance);
      lcd.print(" cm");

      lastUpdateTime = currentMillis;  // Son güncelleme zamanını güncelle
    }

    // Mesafe tespiti
    if (distance > 0 && distance < OBJECT_DETECTION_THRESHOLD) {
      Serial.print("Angle: ");
      Serial.print(i);
      Serial.print(" degrees, Distance: ");
      Serial.println(distance);
      Serial.println("Object detected!");
    } else {
      Serial.print("Angle: ");
      Serial.print(i);
      Serial.print(" degrees, Distance: ");
      Serial.println(distance);
    }
  }
}
