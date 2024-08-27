// Definir los pines para los LEDs
#define LED_GREEN 11    // Pin para el LED verde
#define LED_RED 12      // Pin para el LED rojo
#define LED_YELLOW 13   // Pin para el LED amarillo

// Variable para el modo intermitente
bool intermittentMode = false;

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);

  Serial.begin(9600);

  Serial.println("main menu");
  Serial.println("[1]. Turn on LED green");
  Serial.println("[2]. Turn off LED green");
  Serial.println("[3]. Turn on LED red");
  Serial.println("[4]. Turn off LED red");
  Serial.println("[5]. Turn on LED yellow");
  Serial.println("[6]. Turn off LED yellow");
  Serial.println("[7]. Turn on all LEDs");
  Serial.println("[8]. Turn off all LEDs");
  Serial.println("[9]. Toggle all LEDs (intermittent mode)");
}

void loop() {
  if (Serial.available() > 0) {
    char opt = Serial.read();
    
    switch (opt) {
      case '1':
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, LOW);
        Serial.println("LED green is now ON");
        break;
        
      case '2':
        digitalWrite(LED_GREEN, LOW);
        Serial.println("LED green is now OFF");
        break;
        
      case '3':
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, LOW);
        Serial.println("LED red is now ON");
        break;
        
      case '4':
        digitalWrite(LED_RED, LOW);
        Serial.println("LED red is now OFF");
        break;
        
      case '5':
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_RED, LOW);
        Serial.println("LED yellow is now ON");
        break;
        
      case '6':
        digitalWrite(LED_YELLOW, LOW);
        Serial.println("LED yellow is now OFF");
        break;
        
      case '7':
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_YELLOW, HIGH);
        Serial.println("All LEDs are now ON");
        break;
        
      case '8':
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, LOW);
        Serial.println("All LEDs are now OFF");
        break;
        
      case '9':
        intermittentMode = !intermittentMode;
        if (intermittentMode) {
          Serial.println("Intermittent mode ON");
        } else {
          Serial.println("Intermittent mode OFF");
          digitalWrite(LED_GREEN, LOW);
          digitalWrite(LED_RED, LOW);
          digitalWrite(LED_YELLOW, LOW);
        }
        break;
        
      default:
        Serial.println("Invalid command");
        break;
    }
  }

  if (intermittentMode) {
    // Toggle the state of all LEDs
    digitalWrite(LED_GREEN, !digitalRead(LED_GREEN));
    digitalWrite(LED_RED, !digitalRead(LED_RED));
    digitalWrite(LED_YELLOW, !digitalRead(LED_YELLOW));
    delay(250);  
  }
}
