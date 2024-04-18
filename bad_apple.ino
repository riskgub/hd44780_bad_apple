#include <LiquidCrystal.h>
#include "frames.h"

const int rs = 25, en = 26, d4 = 18, d5 = 21, d6 = 23, d7 = 22;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int frame;

void setup() {
  lcd.begin(20,4);
  lcd.clear();
  lcd.noAutoscroll();
  frame = 0;
}

void loop() {
  if ( frame == 2190 ) {
    lcd.clear();
    while (1) {
      lcd.setCursor(6,0);
      lcd.write("krisbug");
      lcd.setCursor(6,1);
      lcd.write("--2024--");
      delay(1000);
    }
  } else {
    for( byte i = 0; i < 4; i++ ) {
      lcd.setCursor(6,(i-1)&3);
      for( byte j = 0; j < 8; j++ ) {
        lcd.write(' ');
      }
      for( byte j = 0; j < 8; j++ ) {
       lcd.createChar(j,(byte*)&frames[frame][(i<<3)+j]);
      }
      lcd.setCursor(6,i);
      for( byte j = 0; j < 8; j++ ) {
        lcd.write(j);
      }
      delay(16);
    }
    frame++;
  }
}
