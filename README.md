# VEX-Navigation-Robot

## Robot in Action
<img src="images/image.png" width="600">

A VEX V5 robot that can follow a black line on the floor, stop if it's about to hit something, and can also be driven manually with a controller.

## Features
- Follows a black line automatically
- Stops and backs up if it sees an obstacle
- Manual drive mode for the arm and claw
- Shows sensor data on the robot screen

## Hardware Used
- VEX V5 Brain & Controller
- 4 V5 Smart Motors (Drive, Arm, and Claw)
- V5 Distance Sensor (Laser)
- V5 Line Tracker (Underneath)

<img src="images/image_1.png" width="600">

## How It Works
1. The line tracker looks at the floor. If it sees black, it goes straight. If it sees white, it turns to find the line.
2. The distance sensor constantly checks for objects in front.

<img src="images/image_2.png" width="600">

## What I Learned
- How to reverse a motor in code because it was facing the wrong way
- Using if/else logic to make sure the robot doesn't hit a wall while following a line
- Printing text to the Brain screen for easier testing

## Setup Instructions
1. Connect motors: Left (Port 1), Right (Port 10), Arm (Port 8), Claw (Port 3).
2. Connect sensors: Distance (Port 5), Line Tracker (3-Wire Port A).
3. Upload the C++ code using VEXcode V5.
