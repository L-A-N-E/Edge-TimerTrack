<h1 align="center">:zap: TRacer Project - TimerTrack 🏎</h1> 

![banner](https://github.com/L-A-N-E/CP2_Edge_1SEM/assets/153787379/132308ff-27a0-45e7-8323-80d9103f2390)

<h1 align="center"> :speaking_head: Read this in other languages:exclamation:</h1>

<p align="center">
<a href="README-en.md" align="center">English</a> •
<a href="README.md" align="center">Portuguese</a> 
</p>
  
## Index :memo:

* [Project Description](#project-description-memo)
   * [Introduction](#introduction-1st_place_medal)
   * [TimeTracker](#timetracker-2nd_place_medal)
   * [Future of the Project](#future-of-the-project-3rd_place_medal)
* [Access to the Project](#access-to-the-project-file_folder)
* [Tools Used](#tools-used-hammer_and_wrench)
* [Libraries Used](#libraries-used-books)
* [Required Components](#required-components-toolbox)
* [Assembly](#assembly-wrench)
   * [Assembly Precautions](#assembly-precautions-warning)
* [Reproduction](#reproduction-gear)
* [Project Developers](#project-developers-globe_with_meridians)

# Project Description :memo:

<h3>Introduction :1st_place_medal:</h3>
<p>
The TRacer project is an innovative initiative aimed at creating an active and friendly community around Formula E.
This project consists of a comprehensive website, offering detailed information on all aspects of Formula E,
and an interactive application that is fully integrated with the website. One of the main features of this
application is the ranking table, also known as the points table, which will be fed by data collected through
our prototype, the TimeTracker. The ranking table will be updated in real-time, ensuring competitiveness 
and continuous engagement of the Formula E fan community. Our goal is to provide a rich and dynamic experience,
allowing users to track the performance of their favorite drivers and participate in friendly competitions within
the application.
</p>

<h3>TimeTracker :2nd_place_medal:</h3>
<p>
The TimeTracker is a crucial component of the TRacer project, acting as a prototype for future improvements
and expansions. This device is designed to record and calculate the travel time of a car between two points.
Using a Real-Time Clock (RTC) and input buttons, the TimeTracker accurately measures the elapsed time between
button presses, which represent the car passing through two checkpoints.
  
Upon pressing the first button, the time is recorded, and the blue LED briefly lights up to indicate the car's passage.
When the second button is pressed, the elapsed time is calculated and displayed on an LCD, along with the yellow
LED lighting up to signal the completion of the journey. This time is also stored in EEPROM for future analysis and
can be displayed on the serial monitor for real-time monitoring. Additionally, the TimeTracker includes a visual
animation of a car on the LCD display, creating an interactive experience for users.
</p>

<h3>Future of the Project :3rd_place_medal:</h3>
<p>
In the future development of the TRacer project, we have several improvements and expansions planned. One of the main
goals is to replace the Arduino UNO with the ESP32, which will allow for greater connectivity and efficiency in data
collection and transmission. This change will be crucial for the evolution of the TimeTracker and other system
functionalities.
  
Furthermore, we plan to enhance the Python software, ensuring a more robust and efficient integration with the
application and the database. With this improvement, the data collected in real-time by the TimeTracker will be
processed and displayed instantly on the application's ranking table, maintaining competitiveness and information
accuracy. 

Another important step will be to link the ranking table with the application, allowing users to view 
real-time information directly in the app. This not only improves the user experience but also facilitates
decision-making and performance analysis. With these improvements, the TRACER project will be even more prepared
to provide an interactive and informative platform, connecting the community and encouraging active 
participation in Formula E.

</p>

## Access to the Project :file_folder:

You can access the [project code](code/timer_tracker_en.cpp) or the [simulation done on Wookwi](https://wokwi.com/projects/400350008278588417).

## Tools Used :hammer_and_wrench:

- `Arduino IDE`

## Libraries Used :books:

- ``LiquidCrystal_I2C``
- ``EEPROM``
- ``Wire``
- ``RTClib``

## Required Components :toolbox:

|   Component    |  Quantity  |
|:--------------:|:----------:|
|      Wires     |     20     |
|   Blue Button   |     1      |
| Yellow Button  |     1      |
| Arduino - UNO  |     1      |
| LCD 16x2 with I2C module |     1      |
| Real Time Clock - RTC |     1     |
|    Blue LED    |     1     |
|  Yellow LED   |     1     |
| 220Ω Resistors |     2     |
|   USB Cable    |     1     |

## Assembly :wrench:

<details>
  <summary>Assembly Image</summary>
  <img src="https://github.com/L-A-N-E/Edge-TimerTrack/assets/163866552/934638a8-2f9f-4f49-be11-f24e9d5d6e1d"
    alt="assembly-image">
</details>

<h3>Assembly Precautions :warning:</h3>

- ``1.`` Connecting the LEDs:
   - ``1.1.`` Connect the blue LED to pin 6, and the yellow LED to pin 5.
   - ``1.2.`` Both have polarity, so we need to be careful when connecting them to the cables;
   - ``1.3.`` The LED has a longer terminal, which has positive polarity, and the side of the smaller
      terminal has negative polarity. Therefore, we connect the Arduino connection to the positive terminal
      (Anode) and the GND to the negative terminal (Cathode);

- ``2.`` Connecting the LCD:
  - ``2.1.`` **Attention!** We are using a 16x2 LCD with an I2C module!;
  - ``2.2.`` Connect the VCC to the positive terminal (5V), GND to the negative terminal (GND),
     SDA to Arduino pin A4.2, and SCL to A5.2;
  - ``2.3.`` Test to see if the display is working. If you encounter problems with the display,
     it may be due to some of these possibilities: the LCD is broken, has poor contact, or the contrast is low;
    - ``2.3.1.`` To increase the display contrast, simply turn the contrast adjustment trim potentiometer
       counterclockwise. Conversely, to decrease the contrast, turn it clockwise.

      <details>
        <summary>Image of the contrast adjustment trim potentiometer location</summary>
        <img src="https://github.com/L-A-N-E/CP2_Edge_1SEM/assets/101829188/50648d65-2402-4508-a47d-1d38bbf663e5"
          alt="DHT11 Terminals">
      </details>

  - ``3.`` Connecting the Buttons:
  - ``3.1`` Connect one wire to the blue button and connect it to pin 4, and another wire to the blue button connecting
    it to the negative terminal. For the yellow button, connect one wire to it and to pin 3,
    and another wire to it and to the negative terminal. 
  - ``3.2.`` Make sure the polarity of the buttons is correct when connecting them.
     Incorrect connection can damage the buttons or the circuit.
  - ``3.3.`` Check if all buttons are firmly connected and if there is no slack in the wires.
  - ``3.4.``Always test the buttons before using the circuit in a real application.
     This can help identify and fix issues beforehand.

  - ``4.`` Connecting the RTC:
  - ``4.1.`` Connect the SCL to Arduino's A5, the SCA to A4, the 5V to the positive terminal of the breadboard,
     and the GND to the negative terminal of the breadboard.
  - ``4.2.`` The RTC is a delicate component. Handle with care to avoid damage.
  - ``4.3.`` Make sure the RTC is configured with the correct time. Incorrect configuration can lead to errors
     in your project's operation.
  - ``4.4.`` Check if the RTC is receiving adequate power. Insufficient or excessive power can damage the RTC
     or affect its operation.

## Reproduction :gear:

- ``1.`` After assembling the project, you need to insert the code through a computer that has the Arduino IDE
   program installed;
- ``2.`` Download the [required libraries in the Arduino IDE](#libraries-used-books); 
- ``3.`` Transfer the code from the computer to the Arduino using the USB cable;
- ``4.`` Test to see if it's working;
- ``5.``With everything assembled and ready, you need to take it to the environment where it will be implemented
   and connect it to a power source;

## Project Developers :globe_with_meridians:

| [<img src="https://avatars.githubusercontent.com/u/101829188?v=4" width=115><br><sub>Alice Santos Bulhões</sub>](https://github.com/AliceSBulhoes) |  [<img src="https://avatars.githubusercontent.com/u/163866552?v=4" width=115><br><sub>Eduardo Oliveira Cardoso Madid</sub>](https://github.com/EduardoMadid) |  [<img src="https://media.licdn.com/dms/image/D5603AQF59776BVSUSg/profile-displayphoto-shrink_800_800/0/1697337839569?e=1723680000&v=beta&t=YkJsytMw1CG6PAHW1B371ZOdpjAAh0rWPrXhXnDMCw4" width=115><br><sub>Lucas Henzo Ide Yuki</sub>](https://github.com/LucasYuki1) | [<img src="https://avatars.githubusercontent.com/u/153787379?v=4" width=115><br><sub>Nicolas Haubricht Hainfellner</sub>](https://github.com/NicolasHaubricht) |
| :---: | :---: | :---: | :---: |
| RM:554499 | RM:556349 | RM:554865 | RM:556259 |

