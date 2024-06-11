// Includes the necessary libraries
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <EEPROM.h>

// Creates an RTC object
RTC_DS1307 rtc;

// Defines the button pins
#define BUTTON_PIN1 4
#define BUTTON_PIN2 3

// Initializes the object to control the I2C LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Defines the special characters
byte car8[8] = { B10000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
byte car1[8] = { B00000, B01110, B10001, B01111, B10000, B10000, B10000, B01111 };
byte car2[8] = { B00000, B00000, B01111, B10000, B00110, B01111, B00110, B10000 };
byte car3[8] = { B00000, B00011, B00100, B11111, B00000, B00000, B00000, B11111 };
byte car4[8] = { B00000, B00000, B10000, B00000, B10000, B01000, B10000, B00000 };
byte car5[8] = { B10001, B01110, B00000, B00000, B00000, B00000, B00000, B00000 };
byte car6[8] = { B01111, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
byte car7[8] = { B00100, B00011, B00000, B00000, B00000, B00000, B00000, B00000 };

// Defines the LED pins
int ledB = 6;
int ledY = 5;

// Initializes the variables to store the button press time
unsigned long pressButton1 = 0;
unsigned long pressButton2 = 0;

// Creates the variable for the animation
int position = 0;

void setup() {
  // Starts serial communication
  Serial.begin(115200);
  
  // Configures the button pins as input
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);

  // Defines ledB as output pin;
  pinMode(ledB, OUTPUT);
  // Defines ledY as output pin;
  pinMode(ledY, OUTPUT);

  // Initializes the LCD display
  lcd.init();
  lcd.backlight();

  // Starts the RTC and checks if it is working correctly
  if (! rtc.begin()) {
    Serial.println("Could not find the RTC!");
    Serial.flush();
    abort();
  }
}

void loop() {
  // Reads the state of the buttons
  int button1State = digitalRead(BUTTON_PIN1);
  int button2State = digitalRead(BUTTON_PIN2);

  // If button 1 is pressed and has not yet been registered, records the current time
  if(button1State == LOW && pressButton1 == 0){
    DateTime now = rtc.now();
    pressButton1 = now.unixtime();

    digitalWrite(ledB, HIGH); // Turns on the Blue LED
    // Prints that the car passed point 1!
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Car Passed    ");
    lcd.setCursor(2, 1);
    lcd.print("By Point 1!   ");
    delay(500);
    digitalWrite(ledB, LOW); // Turns off the Blue LED

    lcd.clear();
  }

  // If button 2 is pressed and button 1 has already been pressed, records the current time
  if(button2State == LOW && pressButton1 != 0){
    DateTime now = rtc.now();
    pressButton2 = now.unixtime();
    
    // Calculates the duration between button presses
    unsigned long pressDurationSeconds = pressButton2 - pressButton1;

    digitalWrite(ledY, HIGH); // Turns on the Yellow LED
    // Prints the car's travel time
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Travel Time  ");
    lcd.setCursor(3, 1);
    lcd.print(pressDurationSeconds);
    lcd.print(" seconds");
    delay(1000);
    digitalWrite(ledY, LOW); // Turns off the Yellow LED

    // Stores the duration in EEPROM
    int address = 0; // EEPROM memory address where we will store
    EEPROM.put(address, pressDurationSeconds);
    lcd.clear();

    // Prints the duration on the serial monitor
    Serial.print("Time between buttons: ");
    Serial.print(pressDurationSeconds);
    Serial.println(" seconds");

    // Resets the variables for the next cycle
    pressButton1 = 0;
    pressButton2 = 0;
    position = 0;
  }

  // Updates the car animation
  if (millis() % 500 == 0) { // Updates the car's position every 500ms
    lcd.clear(); // Clears the LCD for the next iteration
    displayCustomCharacter(car1, position, 0, 1);
    displayCustomCharacter(car2, position + 1, 0, 2);
    displayCustomCharacter(car3, position + 2, 0, 3);
    displayCustomCharacter(car4, position + 3, 0, 4);
    displayCustomCharacter(car5, position, 1, 5);
    displayCustomCharacter(car6, position + 1, 1, 6);
    displayCustomCharacter(car7, position + 2, 1, 7);
    displayCustomCharacter(car8, position + 3, 1, 0);
    
    // When the position is greater than 15 the animation will restart
    if (position >= 15) {
      position = 0;
    } else {
      position++;
    }
  }
  
}
// Function to display a custom character on the LCD display
void displayCustomCharacter(byte character[], int row, int column, int byt) {
  // Loads the custom character into the LCD display memory
  lcd.createChar(byt, character);
  // Writes the custom character at the position (row, column) of the display
  lcd.setCursor(row, column);
  lcd.write(byte(byt)); // Writes the custom character
}
