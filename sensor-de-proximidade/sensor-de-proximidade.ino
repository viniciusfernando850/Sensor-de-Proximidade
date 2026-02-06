// Portas dos LEDs
const int LED_R = 13;
const int LED_Y1 = 12;
const int LED_Y2 = 11;
const int LED_G1 = 10;
const int LED_G2 = 9;
const int LED_G3 = 8;

// Porta do Buzzer
const int BUZZER = 6;

// Portas do Sensor
const int TRIG = 4;
const int ECHO = 2;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_Y1, OUTPUT);
  pinMode(LED_Y2, OUTPUT);
  pinMode(LED_G1, OUTPUT);
  pinMode(LED_G2, OUTPUT);
  pinMode(LED_G3, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

int medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  return pulseIn(ECHO, HIGH, 30000) / 58;
}

void acionarLED(bool led1, bool led2, bool led3, bool led4, bool led5, bool led6) {
  digitalWrite(LED_R, led1);
  digitalWrite(LED_Y1, led2);
  digitalWrite(LED_Y2, led3);
  digitalWrite(LED_G1, led4);
  digitalWrite(LED_G2, led5);
  digitalWrite(LED_G3, led6);
}

void acionarAlarmeSonoro(int intervalo) {
  tone(BUZZER, 1750);
  delay(intervalo);
  noTone(BUZZER);
  delay(intervalo);
}

void loop() {
  int intervalo_sonoro = -1;
  int distancia = medirDistancia();

  if (distancia > 60) {
    acionarLED(LOW, LOW, LOW, LOW, LOW, LOW);
    noTone(BUZZER);
  } else if (distancia > 50) {
    intervalo_sonoro = 350;
    acionarLED(LOW, LOW, LOW, LOW, LOW, HIGH);
  } else if (distancia > 40) {
    intervalo_sonoro = 300;
    acionarLED(LOW, LOW, LOW, LOW, HIGH, HIGH);
  } else if (distancia > 30) {
    intervalo_sonoro = 250;
    acionarLED(LOW, LOW, LOW, HIGH, HIGH, HIGH);
  } else if (distancia > 20) {
    intervalo_sonoro = 150;
    acionarLED(LOW, LOW, HIGH, HIGH, HIGH, HIGH);
  } else if (distancia > 10) {
    intervalo_sonoro = 100;
    acionarLED(LOW, HIGH, HIGH, HIGH, HIGH, HIGH);
  } else if (distancia > 0) {
    intervalo_sonoro = 60;
    acionarLED(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH);
  }

  if (intervalo_sonoro != -1)
    acionarAlarmeSonoro(intervalo_sonoro);

}
