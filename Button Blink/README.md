# Functionality

The function of this code was to allow one of the buttons on the Launchpad to toggle one of the LED's on the launchpad. This was achieved through polling. An infinite while loop would continuously check if the button was pressed, and when it was the LED would toggle. Each button needed to be configured with a pullup resistor to act corrctly, as the buttons created a short to ground.

# Resources used
The resource explorer was used to first implement this code. The code was observed, and modified to fit the needs of the project. Additionally, the class lab lecture notes were used to implement the code for this project.

# Difficulties

The main difficulty for this project was figuring out the small syntax errors that were popping up, and not with the actual MSP430 register functionality.  

# Differences between boards

The only differences between the boards were the pins that were mapped to the buttons, as the first LED's are all mapped to P1.0. 