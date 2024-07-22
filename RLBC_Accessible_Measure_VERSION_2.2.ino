#include <TFT_eSPI.h>
#include <TJpg_Decoder.h>
#include "dial_3.h"
#include "Final_Frontier_28.h"

TFT_eSPI tft = TFT_eSPI();

bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap) {
  if (y >= tft.height()) return false;
  tft.pushImage(x, y, w, h, bitmap);
  return true;
}

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.fillScreen(TFT_WHITE);
  tft.setRotation(0);
  TJpgDec.setSwapBytes(true);
  TJpgDec.setCallback(tft_output);
}

void loop() {
  TJpgDec.drawJpg(0, 0, dial_3, sizeof(dial_3));
  tft.setTextWrap(true, true);
  Serial.println(tfDist);

  tft.loadFont(Final_Frontier_28);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(115, 52);
  tft.print("48.2");
  tft.println(" cm");
  tft.unloadFont();
}

delay(5000);
}