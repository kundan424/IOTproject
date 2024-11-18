# IOTproject
### **Gas Detection IoT Project Using ESP8266, MQ-6 Sensor, and Blynk Cloud**

#### **Description**  
This project is designed to detect the presence of combustible gases, such as LPG, butane, or methane, and alert users both locally and remotely. The system employs the ESP8266 microcontroller for IoT functionality, the MQ-6 sensor for gas detection, and a buzzer for audible alerts. Using Blynk Cloud, the project sends real-time gas data and notifications to a mobile app, ensuring enhanced safety in residential and industrial environments.

---

#### **Components Used**  

1. **ESP8266 Microcontroller (NodeMCU):**  
   - Provides Wi-Fi connectivity and processes sensor data.  

2. **MQ-6 Gas Sensor:**  
   - Detects combustible gases and outputs an analog signal proportional to gas levels.  

3. **Buzzer:**  
   - Emits an alarm when gas levels exceed the predefined threshold.  

4. **Resistors and Capacitors:**  
   - For biasing and filtering in the circuit.  

5. **Power Supply (5V):**  
   - Powers the ESP8266 and other components.  

6. **LEDs :**  
   - Indicate system status (e.g., power ON or warning).  

7. **Connecting Wires:**  
   - For electrical connections between components.  

8. **Breadboard :**  
   - For prototyping and assembling the circuit.  

---

#### **Connections**  

1. **MQ-6 Gas Sensor:**  
   - **VCC** → Connect to 3.3V pin of ESP8266.  
   - **GND** → Connect to GND of ESP8266.  
   - **OUT (Analog Output)** → Connect to the ADC pin (A0) of ESP8266.  

2. **Buzzer:**  
   - **Positive Terminal** → Connect to GPIO pin (D8) of ESP8266.  
   - **Negative Terminal** → Connect to GND through a resistor.  

3. **ESP8266 (NodeMCU):**  
   - **VCC and GND** → Connected to a 5V power supply.  
   - **Wi-Fi Antenna:** For internet connectivity.  
 4. ** LEd **
  - positive terminal is connected to D7 of nodeMcu.
  - Negative terminal is connected to ground of nodemcu.
---

#### **Working**

1. **Initialization:**  
   - The ESP8266 initializes and sets up the MQ-6 sensor and Wi-Fi connection during startup.  

2. **Gas Detection:**  
   - The MQ-6 sensor detects gas levels and outputs an analog voltage to the ESP8266's ADC pin.  

3. **Threshold Comparison:**  
   - The ESP8266 compares the gas level to a predefined threshold.  
   - If the gas level exceeds the threshold, it identifies a gas leak.  

4. **Local Alert:**  
   - The buzzer is activated to emit an audible warning.  

5. **IoT Integration:**  
   - The ESP8266 sends real-time gas level data to Blynk Cloud.  
   - Alerts are sent to a mobile app for remote monitoring.  

6. **Reset or Continuous Monitoring:**  
   - The system resets when gas levels drop below the threshold or continues monitoring for further changes.  

---

#### **Blynk Cloud Integration**

1. **Setup in Blynk App:**  
   - Create a project and get the **Auth Token**.  
   - Add widgets (e.g., labels, graphs, notifications) for monitoring and controlling the system.  

2. **Code Implementation:**  
   - Include the Blynk library and configure the ESP8266 using the **Blynk.begin()** function with the Auth Token, Wi-Fi credentials, and server details.  

3. **Sending Notifications:**  
   - Use `Blynk.notify("Gas Leak Detected!")` in the code to send instant alerts when gas levels exceed the threshold.  

4. **Real-time Data Monitoring:**  
   - Send gas level data to a virtual pin using `Blynk.virtualWrite(V1, gasLevel)`.  
   - Display gas levels on the app through widgets.  

5. **Remote Control Features:**  
   - Add a button widget to remotely turn off the buzzer or reset the system.  

---

#### **Features of the System**

1. **Local Alerts:**  
   - Buzzer alarm for immediate notification of gas leaks.  

2. **Remote Monitoring:**  
   - View real-time gas levels on the Blynk app from anywhere.  

3. **Push Notifications:**  
   - Instant alerts on a smartphone for critical gas levels.  

4. **Data Visualization:**  
   - Graphs and gauges in the Blynk app for tracking gas concentration trends.  

5. **Two-way Communication:**  
   - Control system functions (e.g., silencing the alarm) via the app.  
6. **History Logs:**  
   - Access past gas data for analysis via the Blynk Cloud.  

---

This project combines efficient gas detection with IoT functionality, ensuring local and remote safety measures for combustible gas monitoring.
