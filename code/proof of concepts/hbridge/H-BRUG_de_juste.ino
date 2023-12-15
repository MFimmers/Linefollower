// Aansluitingen
#define MOT_A1_PIN 10
#define MOT_A2_PIN 9
#define MOT_B1_PIN 6
#define MOT_B2_PIN 5

const int StartKnop = 3;
const int Led = 4;
bool StatusLed = false;

void setup(void)
{
  // Pin functies
  pinMode(MOT_A1_PIN, OUTPUT);
  pinMode(MOT_A2_PIN, OUTPUT);
  pinMode(MOT_B1_PIN, OUTPUT);
  pinMode(MOT_B2_PIN, OUTPUT);

  // Starten met alle motoren af
  digitalWrite(MOT_A1_PIN, LOW);
  digitalWrite(MOT_A2_PIN, LOW);
  digitalWrite(MOT_B1_PIN, LOW);
  digitalWrite(MOT_B2_PIN, LOW);

  
  Serial.begin(9600);
}

void loop(void)
{
  
  //opbouwen
  for(int i = 0; i <= 255; i++) 
      {
        analogWrite(MOT_A1_PIN, i);
        analogWrite(MOT_A2_PIN , 0);
        analogWrite(MOT_B1_PIN , i);
        analogWrite(MOT_B2_PIN, 0);
        delay(5);
      }

    analogWrite(MOT_A1_PIN, 255);
    analogWrite(MOT_A2_PIN , 0);
    analogWrite(MOT_B1_PIN , 255);
    analogWrite(MOT_B2_PIN, 0);
    delay ( 2000);

    }
    
