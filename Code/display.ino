const int delayTime = 350;
const char* title;
const char* message; 

void showTitle(int cols){
  int len = strlen(title);

  lcd.setCursor((cols - len) / 2, 0);
  lcd.print(title);
};

void setDisplay(const char* newTitle, const char* newMessage){
  title = newTitle;
  message = newMessage;
}

void leftRotateString(char* str, int d) {
  int n = strlen(str);
  d %= n;
        
  for (int i = 0; i < d; i++) {
    char first_char = str[0];
    for (int j = 0; j < n - 1; j++) {
      str[j] = str[j + 1];
    }
    str[n - 1] = first_char;
  }
}

void display(const char* newTitle, const char* newMessage) {
  int cols = 16;

  setDisplay(newTitle, newMessage);
  showTitle(cols);

  lcd.setCursor((cols - strlen(newMessage)) / 2, 0);
  lcd.setCursor(0, 1);
  lcd.print(newMessage);
}

void scrollMessage(int row, int cols) {
  char displayText[cols];
  strncpy(displayText, message, cols - 1);

  int len = strlen(displayText);
  if (len >= cols) return;

  for (int i = len; i < cols - 1; ++i) displayText[i] = ' ';

  displayText[cols - 1] = '\0';

  while (true) {
    lcd.setCursor(0, row);
    lcd.print(displayText);
    delay(delayTime);

    leftRotateString(displayText, 1);

    if (IrReceiver.decode()) {
      long command = IrReceiver.decodedIRData.command;
      String key = decodeKeyValue(command);

      if(key != "ERROR") {
        action(key);
        break;
      }

      IrReceiver.resume();
    }
  }
}

void animateText() {
  
  int cols = 16;

  lcd.setCursor(0, 0);
  showTitle(cols);
  scrollMessage(1, cols);
}