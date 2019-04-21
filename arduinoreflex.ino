#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int startLedPin = 13;
const int player1LedPin = 9;
const int player2LedPin = 10;
const int button1Pin = 8;
const int button2Pin = 11;

int button1State = 0;
int button2State = 0;
bool listenToButtons = false;
bool somebodyWon = false;

long unsigned randomMillis(){
  unsigned randomN;
  unsigned randomMillis;
  randomSeed(analogRead(A0));
  randomN = random(2,6);
  randomMillis = randomN*1000;
  return randomMillis;
}

int randomDelay = randomMillis();

void setup() {
  pinMode(player1LedPin, OUTPUT);
  pinMode(player2LedPin, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Ready...");
}

void loop() {
  
  if(millis() > randomDelay && !somebodyWon){
    digitalWrite(startLedPin, HIGH);
    lcd.clear();
    lcd.print("GO!");
    listenToButtons = true;
  }

  if(listenToButtons){
    
    button1State = digitalRead(button1Pin);
    if (button1State == HIGH && !somebodyWon) {
      somebodyWon = true;
      digitalWrite(player1LedPin, HIGH);
      lcd.clear();
      lcd.print("Player 1 wins!");
      lcd.setCursor(0,1);
      lcd.print(millis() - randomDelay);
      lcd.print(" ms");
    }
    button2State = digitalRead(button2Pin);
    if (button2State == HIGH && !somebodyWon) {
      somebodyWon = true;
      digitalWrite(player2LedPin, HIGH);
      lcd.clear();
      lcd.print("Player 2 wins!");
      lcd.setCursor(0,1);
      lcd.print(millis() - randomDelay);
      lcd.print(" ms");
    }
  }
  if(somebodyWon){
    digitalWrite(startLedPin, LOW);
  }
}
