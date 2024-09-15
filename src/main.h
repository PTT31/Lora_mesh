#pragma once

#include <Arduino.h>
#include <RadioLib.h>

// Chân kết nối giữa ESP32S3 và SX1280 (cần phải tùy chỉnh dựa trên mạch của bạn)
#define PIN_NSS    5     // Chân chọn chip (NSS)
#define PIN_DIO1   4     // Chân DIO1 (ngắt)
#define PIN_RST    18    // Chân reset SX1280
#define PIN_BUSY   19    // Chân busy (bận)
#define PIN_MISO   12    // Chân MISO của SPI
#define PIN_MOSI   13    // Chân MOSI của SPI
#define PIN_SCK    14    // Chân SCK của SPI

// Khởi tạo đối tượng SX1280
SX1280 radio = new Module(PIN_NSS, PIN_DIO1, PIN_RST, PIN_BUSY);

// Hàm khởi tạo kết nối với SX1280
void initSX1280() {
    // Thiết lập SPI
    SPI.begin(PIN_SCK, PIN_MISO, PIN_MOSI, PIN_NSS);

    // Khởi tạo module SX1280 với thông số mặc định
    Serial.print(F("[SX1280] Initializing ... "));

    int state = radio.begin();
    if (state == RADIOLIB_ERR_NONE) {
        Serial.println(F("success!"));
    } else {
        Serial.print(F("failed, code "));
        Serial.println(state);
        while (true);  // Dừng chương trình nếu không kết nối được
    }

    // Cấu hình thêm các tham số (tùy theo yêu cầu cụ thể của bạn)
    radio.setFrequency(2400.0);       // Thiết lập tần số 2400 MHz
    radio.setBandwidth(1600.0);       // Băng thông
    radio.setSpreadingFactor(7);      // Hệ số trải phổ
    radio.setCodingRate(5);           // Tỷ lệ mã hóa
    radio.setOutputPower(10);         // Công suất phát 10 dBm
}

