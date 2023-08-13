# Connecting Two Arduino UNOs using I2C Communication
In the realm of IoT, devices communicate and share data to create intelligent systems. I set up communication between two Arduino boards using the I2C protocol. One board is the transmitter and the other is the receiver. The transmitter reads the status of a digital button connected to pin A0 and transmits its state to the receiver. The receiver controls an LED connected to pin 11 based on the received button status.

## Step-by-Step to connect two Arduino using I2C:

**Step 1: Open Tinkercad**
- Open your web browser and navigate to Tinkercad [This link](https://www.tinkercad.com/).

**Step 2: Create a New Project**
  
- Log in to your Tinkercad account or create one if needed.
- Click on "Create New Project" to start a new project.

**Step 3: Add Components**
- Click on "Circuits" in the top menu.
- Search for "Arduino" in the components panel and add two Arduino boards to the workspace.
- Add a push button component to Arduino (Transmitter) by searching for "Button" and adding it.
- Connect one leg of the push button to the GND of the Arduino (Transmitter).
- Connect the other leg of the push button to the 5V pin of the Arduino (Transmitter).
- Connect the other leg of the push button to pin A0 of the Arduino (Transmitter).
- Add an LED component to the Arduino (Receiver) by searching for "LED" and adding it.
- Connect the LED's anode (longer leg) to pin 11 on the Arduino (Receiver).
- Connect the LED's cathode (shorter leg) to a current-limiting resistor and then to the GND (ground) pin on the Arduino (Receiver).
- Connect the SDA (A4) pin of the first Arduino (Transmitter) to the SDA (A4) pin of the second Arduino (Receiver).
- Connect the SCL (A5) pin of the first Arduino (Transmitter) to the SCL (A5) pin of the second Arduino (Receiver).

**Step 4: Write The Code**
- Click on the first Arduino (with the push button) and navigate to the "Code" section and write this code:
```cpp
//Transmitter

#include <Wire.h>
int pushButton = A0;
int x = 0;
void setup()
{
  Wire.begin();
  pinMode(pushButton, INPUT);
}

void loop()
{
   Wire.beginTransmission(1);
   x = digitalRead(pushButton);
   Wire.write(x);
   Wire.endTransmission();
   delay(100);
}
```
In the transmitter code:
1. Include the Wire library for I2C communication.
2. Declare the pushButton variable to hold the pin number of the digital button.
3. Initialize x to store the button state (0 or 1).
4. In the `setup()` function, begin the I2C communication and set the pushButton pin as an input.
5. In the `loop()` function:
   - Start an I2C transmission to the receiver using the address 1.
   - Read the state of the digital button and store it in x.
   - Write the button state to the I2C bus.
   - End the I2C transmission.
   - Add a delay for stability.


- Click on the second Arduino (with the LED) and go to the "Code" section and write this code:
```cpp
//Receiver

#include <Wire.h>
int pinLed=11;
int x =0;

void setup()
{
  Wire.begin(1);
  Wire.onReceive(receiveEvent); 
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  delay(100);
}

void receiveEvent(int howMany){

x = Wire.read();
  
  if (x == 1){
  
        digitalWrite(pinLed,HIGH);
  }
  else{
        digitalWrite(pinLed,LOW);
  }
}
```
In the receiver code:
1. Include the Wire library for I2C communication.
2. Declare the pinLed variable to hold the pin number of the LED.
3. Initialize x to store the received button state (0 or 1).
4. In the `setup()` function:
   - Begin I2C communication with address 1.
   - Set up the `receiveEvent` function as the handler for incoming data.
   - Set the pinLed as an output.
5. In the `loop()` function, add a delay for stability.
6. Define the `receiveEvent` function to read the received data:
   - Read the button state from the I2C bus.
   - If the received state is 1, turn on the LED; otherwise, turn it off.
  
**Step 5: Test and Simulate**
- Click the "Start Simulation" button in the top right corner of the Tinkercad interface.
- Observe the simulation as the two Arduino boards communicate.
- Simulate pressing and releasing the push button to see the LED on the second Arduino light up and turn off accordingly.

Tinkercad link : (https://www.tinkercad.com/things/6yIMJVrAAku)

<img width="960" alt="image" src="https://github.com/LatifahAbuhamamah/Connecting-Two-ArduinoUNOs-Using-I2C-Communication/assets/139233344/1370735e-1d38-435d-a89e-61bef4993dd1">


By following these steps, created a Tinkercad simulation that effectively demonstrates the I2C-based communication between two Arduino boards, where the state of a push button controls the illumination of an LED on the other board.
