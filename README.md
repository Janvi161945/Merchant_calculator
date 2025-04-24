# Merchant Calculator

A simple merchant calculator built using Arduino and Python, designed to assist shopkeepers in calculating totals(hamal charge , weighage charge), applying discounts, and managing basic inventory tasks.
There are 2 versions of this i have tried 1 folder is of flask app & secounf the for physical device with aurdino 

## Features

- **Total Calculation**: Computes the total amount based on item prices and quantities.
- **Discount Application**: Allows the application of percentage-based discounts.
- **Inventory Management**: Keeps track of available stock and updates quantities after sales.
- **User-Friendly Interface**: Simple interface for ease of use in a retail environment.

## Hardware Requirements

- Arduino Uno or compatible board
- LCD Display (16x2)
- Keypad (4x4 matrix)
- Breadboard and jumper wires
- Power supply (USB or external)

## Software Requirements

- Arduino IDE
- Python 3.x
- Required Python libraries:
  - `pyserial` for serial communication between Arduino and Python

## Setup Instructions

1. **Hardware Setup**:
   - Connect the LCD display and keypad to the Arduino as per the schematic provided in the `hardware_setup` folder.
   - Ensure all connections are secure and the Arduino is powered.

2. **Arduino Code**:
   - Open the `merchant_calculator.ino` file in the Arduino IDE.
   - Upload the code to the Arduino board.

3. **Python Script**:
   - Install the required Python libraries:
     ```bash
     pip install pyserial
     ```
   - Run the `merchant_calculator.py` script to start the calculator interface.

## Usage

- Use the keypad to input item prices and quantities.
- The LCD will display the current total.
- Press the designated key to apply discounts.
- The final amount will be displayed after calculations.


