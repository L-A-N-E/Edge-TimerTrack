// Inclui as bibliotecas necessárias
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <EEPROM.h>

// Cria um objeto RTC
RTC_DS1307 rtc;

// Define os pinos dos botões
#define BUTTON_PIN1 4
#define BUTTON_PIN2 3

// Inicializa o objeto para controlar o display LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define os caracteres especiais
byte car8[8] = { B10000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
byte car1[8] = { B00000, B01110, B10001, B01111, B10000, B10000, B10000, B01111 };
byte car2[8] = { B00000, B00000, B01111, B10000, B00110, B01111, B00110, B10000 };
byte car3[8] = { B00000, B00011, B00100, B11111, B00000, B00000, B00000, B11111 };
byte car4[8] = { B00000, B00000, B10000, B00000, B10000, B01000, B10000, B00000 };
byte car5[8] = { B10001, B01110, B00000, B00000, B00000, B00000, B00000, B00000 };
byte car6[8] = { B01111, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
byte car7[8] = { B00100, B00011, B00000, B00000, B00000, B00000, B00000, B00000 };

// Define os pinos dos LEDS
int ledB = 6;
int ledY = 5;

// Inicializa as variáveis para armazenar o tempo de pressionamento dos botões
unsigned long pressButton1 = 0;
unsigned long pressButton2 = 0;

// Cria a variável para a animação
int position = 0;

void setup() {
  // Inicia a comunicação serial
  Serial.begin(115200);
  
  // Configura os pinos dos botões como entrada
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);

  // Define o ledB como pino de saída;
  pinMode(ledB, OUTPUT);
  // Define o ledY como pino de saída;
  pinMode(ledY, OUTPUT);

  // Inicializa o display LCD
  lcd.init();
  lcd.backlight();

  // Inicia o RTC e verifica se ele está funcionando corretamente
  if (! rtc.begin()) {
    Serial.println("Não foi possivel achar o RTC!");
    Serial.flush();
    abort();
  }
}

void loop() {
  // Lê o estado dos botões
  int button1State = digitalRead(BUTTON_PIN1);
  int button2State = digitalRead(BUTTON_PIN2);

  // Se o botão 1 for pressionado e ainda não tiver sido registrado, registra o tempo atual
  if(button1State == LOW && pressButton1 == 0){
    DateTime now = rtc.now();
    pressButton1 = now.unixtime();

    digitalWrite(ledB, HIGH); // Liga o LED Azul
    // Imprime que o carro passou pelo ponto 1!
    lcd.clear();
    lcd.print("Carro Passou    ");
    lcd.setCursor(0, 1);
    lcd.print("Pelo Ponto 1!   ");
    delay(500);
    digitalWrite(ledB, LOW); // Desliga o LED Azul

    lcd.clear();
  }

  // Se o botão 2 for pressionado e o botão 1 já tiver sido pressionado, registra o tempo atual
  if(button2State == LOW && pressButton1 != 0){
    DateTime now = rtc.now();
    pressButton2 = now.unixtime();
    
    // Calcula a duração entre os pressionamentos dos botões
    unsigned long pressDurationSeconds = pressButton2 - pressButton1;

    digitalWrite(ledY, HIGH); // Liga o LED Amarelo
    // Imprime o tempo do percurso do carro
    lcd.clear();
    lcd.print("Tempo Percurso  ");
    lcd.setCursor(2, 1);
    lcd.print(pressDurationSeconds);
    lcd.print(" segundos");
    delay(1000);
    digitalWrite(ledY, LOW); // Desliga o LED Amarelo

    // Armazena a duração na EEPROM
    int address = 0; // Endereço de memória EEPROM onde vamos armazenar
    EEPROM.put(address, pressDurationSeconds);
    lcd.clear();

    // Imprime a duração no monitor serial
    Serial.print("Tempo entre botões: ");
    Serial.print(pressDurationSeconds);
    Serial.println(" segundos");

    // Reseta as variáveis para o próximo ciclo
    pressButton1 = 0;
    pressButton2 = 0;
    position = 0;
  }

  // Atualiza a animação do carro
  if (millis() % 500 == 0) { // Atualiza a posição do carro a cada 500ms
    lcd.clear(); // Limpa o LCD para a próxima iteração
    exibirCaracterePersonalizado(car1, position, 0, 1);
    exibirCaracterePersonalizado(car2, position + 1, 0, 2);
    exibirCaracterePersonalizado(car3, position + 2, 0, 3);
    exibirCaracterePersonalizado(car4, position + 3, 0, 4);
    exibirCaracterePersonalizado(car5, position, 1, 5);
    exibirCaracterePersonalizado(car6, position + 1, 1, 6);
    exibirCaracterePersonalizado(car7, position + 2, 1, 7);
    exibirCaracterePersonalizado(car8, position + 3, 1, 0);
    
    // Quando a position for maior que 15 a animação reiniciará
    if (position >= 15) {
      position = 0;
    } else {
      position++;
    }
  }
  
}
// Função para exibir um caractere personalizado no display LCD
void exibirCaracterePersonalizado(byte caractere[],int linha, int coluna, int byt) {
  // Carrega o caractere personalizado na memória do display LCD
  lcd.createChar(byt, caractere);
  // Escreve o caractere personalizado na posição (linha, coluna) do display
  lcd.setCursor(linha, coluna);
  lcd.write(byte(byt)); // Escreve o caractere personalizado
}