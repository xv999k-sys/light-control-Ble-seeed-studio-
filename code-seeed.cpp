#include <bluefruit.h>
#include <Servo.h>


#define SERVICE_UUID        "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"

BLEService uartService(SERVICE_UUID);
BLECharacteristic rxCharacteristic(CHARACTERISTIC_UUID);


const int ledPin = 5; 
const int led_green = 6;

void setup() {
  Serial.begin(115200);
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  pinMode(led_green, OUTPUT);
  digitalWrite(led_green, LOW);

  Serial.println("Initializing BLE...");

  
  Bluefruit.begin();
  Bluefruit.setName("Karam"); 

  
  uartService.begin();

  
  rxCharacteristic.setProperties(CHR_PROPS_WRITE | CHR_PROPS_WRITE_WO_RESP);
  rxCharacteristic.setPermission(SECMODE_OPEN, SECMODE_OPEN);
  rxCharacteristic.setWriteCallback(rx_callback);
  rxCharacteristic.begin();

  
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE); 
  Bluefruit.Advertising.addTxPower(); 
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_GENERIC_TAG); 
  Bluefruit.Advertising.addName();      
  Bluefruit.Advertising.start(0);      

  Serial.println("BLE initialized. Device is now discoverable as 'Karam'.");
}

void loop() {
  
}

int lastGreenPWM = 255;
int lastRedPWM   = 255;

void rx_callback(uint16_t conn_handle, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
  if (len == 0) return;

  int cmd = data[0];
  Serial.println(cmd);

  // ===== GREEN PWM (100–199) =====
  if (cmd >= 100 && cmd < 200) {
    int val = map(cmd - 100, 0, 100, 0, 255);
    lastGreenPWM = val;
    analogWrite(led_green, val);   
    return;
  }

  // ===== RED PWM (200–299) =====
  if (cmd >= 200 && cmd < 300) {
    int val = map(cmd - 200, 0, 100, 0, 255);
    lastRedPWM = val;
    analogWrite(ledPin, val);     
    return;
  }

  // ===== ON / OFF =====
  switch (cmd) {
    case 1: // GREEN ON
      analogWrite(led_green, lastGreenPWM);  
      break;

    case 0: // GREEN OFF
      analogWrite(led_green, 0);             
      break;

    case 4: // RED ON
      analogWrite(ledPin, lastRedPWM);       
      break;

    case 5: // RED OFF
      analogWrite(ledPin, 0);                
      break;
  }
}
