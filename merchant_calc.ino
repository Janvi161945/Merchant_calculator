#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

// LCD Setup (I2C)
Adafruit_LiquidCrystal lcd(0);

// Keypad Setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'}, // A = Next
    {'4', '5', '6', 'B'}, // B = Back
    {'7', '8', '9', 'C'}, // C = Clear / Restart
    {'.', '0', '=', '+'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Variables
String input = "";
float quintal = 0, rate = 0;
int step = 0;
bool showResults = false;
bool decimalEntered = false;

// Function to get user input
float getNumberInput(String prompt) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(prompt);
    input = "";
    decimalEntered = false;
    while (true) {
        char key = keypad.getKey();
        if (key) {
            if (isdigit(key)) {
                input += key;
                lcd.setCursor(0, 1);
                lcd.print(input);
            } else if (key == '.' && !decimalEntered) {
                input += key;
                decimalEntered = true;
                lcd.setCursor(0, 1);
                lcd.print(input);
            } else if (key == 'C') {
                input = "";
                decimalEntered = false;
                lcd.setCursor(0, 1);
                lcd.print("                ");
            } else if (key == '=') {
                if (input.length() > 0 && input != ".") {
                    return input.toFloat();
                }
            }
        }
    }
}

// Function to display current step result
void displayStep(int step) {
    lcd.clear();
    switch (step) {
        case 0:
            lcd.print("Hamal: ");
            lcd.print(quintal * 10.30, 2);
            break;
        case 1:
            lcd.print("Tulai: ");
            lcd.print(quintal * 7.0, 2);
            break;
        case 2:
            lcd.print("H+T: ");
            lcd.print((quintal * 10.30) + (quintal * 7.0), 2);
            break;
        case 3:
            lcd.print("Q*R: ");
            lcd.print(quintal * rate, 2);
            break;
        case 4:
            lcd.print("Total: ");
            lcd.print((quintal * rate) - (quintal * 10.30) - (quintal * 7.0), 2);
            break;
        case 5:
            lcd.print("Press C to Reset");
            break;
    }
}

// Function to reset and restart process
void resetProcess() {
    step = 0;
    showResults = false;
    quintal = getNumberInput("Enter Quintal:");
    rate = getNumberInput("Enter Rate:");
    showResults = true;

    lcd.clear();
    lcd.print("A Next B Back");
    delay(1500); // Allow user to read instructions
    displayStep(step); // Start by showing Hamal
}

void setup() {
    lcd.begin(16, 2);
    lcd.setBacklight(1);
    resetProcess(); // Begin input process
}

void loop() {
    if (showResults) {
        char key = keypad.getKey();
        if (key) {
            if (key == 'A') { // Next
                if (step < 5) step++;
                displayStep(step);
            } else if (key == 'B') { // Back
                if (step > 0) step--;
                displayStep(step);
            } else if (key == 'C') { // Clear & Restart
                resetProcess();
            }
        }
    }
}
