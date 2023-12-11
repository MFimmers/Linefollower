# start/stop interrupt proof of concept
minimale hard- en software die de correcte werking van een start/stop drukknop aantoont, gebruik makend van een hardware interrupt
// Define pin numbers
const int buttonPin = 2;  // Pin waarop de drukknop is aangesloten
const int ledPin = 13;    // Pin waarop de LED is aangesloten

// Variabelen om de knopstatus en de start/stop-status bij te houden
volatile int buttonState = LOW;
volatile bool isRunning = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  // Configureer de interrupt voor de drukknop
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, CHANGE);
}

void loop() {
  // Voer de hoofdlogica uit
  if (isRunning) {
    // Uitvoeren van de "start" -logica (bijvoorbeeld LED aan)
    digitalWrite(ledPin, HIGH);
  } else {
    // Uitvoeren van de "stop" -logica (bijvoorbeeld LED uit)
    digitalWrite(ledPin, LOW);
  }
  // Voeg eventueel andere code toe die continu moet worden uitgevoerd
}

// Onderbreekfunctie voor de drukknop
void buttonInterrupt() {
  // Lees de huidige status van de knop
  int currentState = digitalRead(buttonPin);

  // Controleer of de knop is ingedrukt (afhankelijk van de bedrading kan het HIGH of LOW zijn)
  if (currentState == LOW) {
    // Wissel de start/stop-status om
    isRunning = !isRunning;
  }

  // Wacht kort om debounce-effecten te verminderen
  delay(50);
}

