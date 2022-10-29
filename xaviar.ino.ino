#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const unsigned int MAX_MESSAGE_LENGTH = 34;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2); 
}

void loop() {
  while (Serial.available() > 0)
  {
    static char message[MAX_MESSAGE_LENGTH];
    static unsigned int message_pos = 0;

    char inByte = Serial.read();

    if (inByte == ';')
    {
      lcd.clear();
      message[message_pos] = '\0';
      Serial.print(message);
      lcd.print(message);
      lcd.setCursor(0, 1);
      message_pos = 0;
    }
    else if(inByte != '\n')
    {
      message[message_pos] = inByte;
      message_pos++;
    }
    else{
      message[message_pos] = '\0';
      Serial.print(message);
      lcd.print(message);
      lcd.setCursor(0, 0);
      message_pos = 0;
    }
  }
}
