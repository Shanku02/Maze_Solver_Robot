# Maze_Solver_Robot

Welcome to the Maze Solver Robot repository! This project features a robot designed to autonomously navigate and solve mazes using an Arduino microcontroller. The robot employs sensors to detect the path and algorithmic logic to find its way to the maze's exit. This repository provides all the necessary code, hardware schematics, and detailed documentation to help you build and customize your maze-solving robot.

Features:
   1. Autonomous Navigation: The robot uses sensors to detect walls and paths, allowing it to navigate through mazes without human intervention.
   2. Arduino-based: Powered by an Arduino microcontroller, ensuring easy programming and hardware interfacing.
   3. Sensor Integration: Utilizes infrared (IR) or ultrasonic sensors for obstacle detection and pathfinding.
   4. Algorithm Implementation: Implements maze-solving algorithm: Line-Following algorithm.
   5. Customizable and Expandable: Modular code and hardware design allow for easy customization and expansion.

Hardware Requirements:
   1. Microcontroller: Arduino Uno or compatible board.
   2. Sensors: IR sensors or ultrasonic sensors for obstacle detection.
   3. Motor Driver: L298N or similar motor driver module.
   4. Chassis: Robot chassis with DC motors and wheels.
   5. Power Supply: Battery pack suitable for the motors and microcontroller.
   6. Miscellaneous: Jumper wires, breadboard, and other basic electronic components.

Software Requirements:
Arduino IDE: For programming the Arduino microcontroller.
Maze Mapping Software: (Optional) Software to visualize the maze and the robot's path.

# Getting Started
   1. Clone the Repository:
   2. Hardware Setup: Follow the provided schematics to connect the sensors, motor driver, and other components to the Arduino.
   3. Upload the Code: Open the Arduino IDE, load the provided .ino file, and upload it to your Arduino board.
   4. Build the Maze: Create a physical maze using walls or lines (depending on sensor type) for the robot to solve.
   5. Run the Robot: Place the robot at the maze's starting point and observe as it navigates towards the exit.

Algorithms:
The robot can be programmed to use various maze-solving algorithms. The provided code includes implementations for:
   1. Line/Wall-Following: A simple heuristic where the robot follows one wall (left or right) to find the exit.
   2. Depth-First Search (DFS): Explores as far as possible along each branch before backtracking.
   3. Breadth-First Search (BFS): Explores all nodes at the present depth level before moving on to nodes at the next depth level.

Customization:
You can easily customize the robot by modifying the Arduino code or adding additional sensors and actuators. Experiment with different maze-solving algorithms or sensor configurations to enhance your robot's performance.
