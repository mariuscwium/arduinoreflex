const int startLedPin = 13;
const int playerLedPin = 9;
const int buttonPin = 8;

int buttonState = 0;
bool listenToButton = false;

void setup() {
  pinMode(playerLedPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  
  if(millis() > randomMillis()){
    digitalWrite(startLedPin, HIGH);
    listenToButton = true;
  }

  if(listenToButton){
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      digitalWrite(playerLedPin, HIGH);
    } else {
      digitalWrite(playerLedPin, LOW);
    }
  }

}

long unsigned randomMillis(){
  unsigned randomN;
  unsigned randomMillis;
  randomSeed(analogRead(A0));
  randomN = random(2,6);
  randomMillis = randomN*1000;
  return randomMillis;
}
