// FSM-Based Operator Skill Detection System

enum State {
  INIT,
  WAIT_SEQUENCE,
  SKILL_ACTIVE,
  SEQUENCE_ERROR
};

State currentState = INIT;

const int BTN1 = 2;
const int BTN2 = 3;
const int BTN3 = 4;

const int W1 = 5;
const int W2 = 6;
const int W3 = 7;

const int LED_RED = 8;
const int LED_YELLOW = 9;
const int LED_GREEN = 10;

const int POT = A0;

int sequenceStep = 0;
int lastPot = 0;
int confidence = 50;

void setup() {
  Serial.begin(9600);

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);

  pinMode(W1, OUTPUT);
  pinMode(W2, OUTPUT);
  pinMode(W3, OUTPUT);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}

void loop() {

  switch (currentState) {

    case INIT:
      digitalWrite(W1, LOW);
      digitalWrite(W2, LOW);
      digitalWrite(W3, LOW);
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);

      sequenceStep = 0;
      confidence = 50;
      lastPot = analogRead(POT);

      currentState = WAIT_SEQUENCE;
      break;

    case WAIT_SEQUENCE: {
      bool b1 = digitalRead(BTN1) == LOW;
      bool b2 = digitalRead(BTN2) == LOW;
      bool b3 = digitalRead(BTN3) == LOW;

      if (sequenceStep == 0 && b1) {
        digitalWrite(W1, HIGH);
        sequenceStep = 1;
        delay(250);
      }
      else if (sequenceStep == 1 && b2) {
        digitalWrite(W2, HIGH);
        sequenceStep = 2;
        delay(250);
      }
      else if (sequenceStep == 2 && b3) {
        digitalWrite(W3, HIGH);
        delay(250);
        currentState = SKILL_ACTIVE;
      }
      else if (b1 || b2 || b3) {
        currentState = SEQUENCE_ERROR;
      }
      break;
    }

    case SKILL_ACTIVE: {
      int pot = analogRead(POT);
      int diff = abs(pot - lastPot);

      if (diff < 20) confidence += 2;
      else confidence -= 3;

      confidence = constrain(confidence, 0, 100);

      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_YELLOW, LOW);

      if (confidence >= 70) digitalWrite(LED_GREEN, HIGH);
      else if (confidence >= 30) digitalWrite(LED_YELLOW, HIGH);

      lastPot = pot;
      delay(200);
      break;
    }

    case SEQUENCE_ERROR:
      digitalWrite(LED_RED, HIGH);
      while (1);
  }
}
