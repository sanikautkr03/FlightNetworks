# Flight Management System

## Overview

This Flight Management System is a C-based application designed to handle various functionalities related to flights, including managing flight information, booking flights, and user authentication. The system uses a graph data structure to represent flight connections and employs Dijkstra's algorithm for finding the shortest path between locations based on cost.

## Features

- **Flight Information Management**: Add, view, and manage flight details such as flight paths, seats, and costs.
- **Graph Representation**: Use of a graph to represent flight connections between locations.
- **Shortest Path Calculation**: Implementation of Dijkstra's algorithm to find the shortest path based on cost.
- **User and Manager Authentication**: Registration and login functionalities for users and managers.
- **Flight Booking and Cancellation**: Users can book and cancel flights, and their booking details are saved in user-specific files.
- **Dynamic Flight Path Management**: Add new flights and locations dynamically.

## File Structure

- `main.c`: Contains the main function and integrates various functionalities.
- `flight_management.c`: Implementation of all the functions declared in the header file.
- `README.md`: This file, providing an overview and usage instructions.

