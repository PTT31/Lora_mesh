#include "main.h"

void setup() {
    // Khởi động cổng Serial
  Serial.begin(115200);
  while (!Serial);

  // Gọi hàm khởi tạo SX1280
  initSX1280();
}

void loop() {
  // put your main code here, to run repeatedly:
}


