# VEX-Navigation-Robot

<!-- Showcase GIF at the top -->
![Robot in Action](images/vex-line-sensor.gif)

## Features
- Follows a black line automatically
- Stops and backs up if it sees an obstacle
- Manual drive mode for the arm and claw
- Shows sensor data on the robot screen

<!-- First image of the robot -->
![Robot Photo](images/IMG_2141.png)

## Hardware Used
- VEX V5 Brain & Controller
- 4 V5 Smart Motors (Drive, Arm, and Claw)
- V5 Distance Sensor (Laser)
- V5 Line Tracker (Underneath)
- V5 Clawbot Metal Kit

## How It Works
1. The line tracker looks at the floor. If it sees black, it goes straight. If it sees white, it turns to find the line.
2. The distance sensor constantly checks for objects in front.

<!-- Second image or setup photo -->
![Robot Overview](images/IMG_png)

## What I Learned
- How to reverse a motor in code because it was facing the wrong way
- Using if/else logic to make sure the robot doesn't hit a wall while following a line
- How to keep the arm from falling down using "hold" settings
- Printing text to the Brain screen for easier testing

## Setup Instructions
1. Connect motors: Left (Port 1), Right (Port 10), Arm (Port 8), Claw (Port 3).
2. Connect sensors: Distance (Port 5), Line Tracker (3-Wire Port A).
3. Upload the C++ code using VEXcode V5.
4. To drive it yourself, just swap the code from `autonomousMode` to `usercontrol` in the main file.
