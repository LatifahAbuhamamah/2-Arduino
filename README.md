# Connecting Two Arduino UNOs using I2C Communication
This Arduino code demonstrates an communication setup using the I2C protocol between two Arduino boards: one acting as a transmitter (sender) and the other as a receiver. The transmitter reads the state of a digital button (connected to pin A0) and sends its state (pressed or not pressed) to the receiver. The receiver, in turn, controls an LED (connected to pin 11) based on the received button state.



Step-by-Step to connect two Arduino UNOs using I2C:

Step 1: Open Tinkercad

Open your web browser and navigate to Tinkercad (https://www.tinkercad.com/).
Step 2: Create a New Project

Log in to your Tinkercad account or create one if needed.
Click on "Create New Project" to start a new project.
Step 3: Add Components

Click on "Circuits" in the top menu.
Search for "Arduino" in the components panel and add two Arduino boards to the workspace.
Add a push button component to one Arduino by searching for "Button" and adding it.
Connect the push button's one leg to GND and the other to pin A0 on the first Arduino.
Add an LED component to the second Arduino by searching for "LED" and adding it.
Connect the LED's anode (longer leg) to a current-limiting resistor and then to pin 11 on the second Arduino.
Connect the LED's cathode (shorter leg) to the GND (ground) pin on the second Arduino.
Add two 10k ohm resistors to the workspace and connect them from pin A0 on the first Arduino to 5V (VCC).
Connect the SDA (A4) pin of the first Arduino to the SDA (A4) pin of the second Arduino.
Connect the SCL (A5) pin of the first Arduino to the SCL (A5) pin of the second Arduino.
Step 4: Add and Edit Code

Click on the first Arduino (with the push button) and navigate to the "Code" section.
Paste the transmitter code you provided earlier into the code editor.
Click on the second Arduino (with the LED) and go to the "Code" section.
Paste the receiver code you provided earlier into the code editor.
