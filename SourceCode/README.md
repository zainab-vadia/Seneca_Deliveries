Welcome to our SFT221 Project - Seneca Deliveries (a local delivery company management system).

Overview:

Seneca Deliveries is a program designed to efficiently manage package shipments across three different routes in the city. It optimizes truck selection based on available space, distance to destination, and ensures timely deliveries.

Project Description:

The system operates within a 25x25 square grid, representing the city map. Trucks follow distinct paths—blue, yellow, and green—initially starting on a common path and later branching out to cover different neighborhood sections. Packages are designated by weight, box size, and destination building within the black rectangles on the map.

Features:

Efficient truck selection for package deliveries.
Capacity check for trucks (1500 kg cargo and 48 m³ box size).
Algorithm to find the shortest route to destinations.
Handling invalid inputs and ensuring valid shipments

How it Works
1- Truck Allocation: Trucks follow designated routes; each truck is assigned packages based on proximity and available space.
2- Package Assignment: Packages are allocated to the nearest truck with available capacity and the shortest diversion distance.
3- Path Finding Algorithm: Utilizes A* algorithm to calculate the shortest path avoiding buildings.
4- Package Handling: Invalid inputs are flagged, and the system ensures adherence to weight and size limitations.

Usage
Input shipment details: weight, box size, destination (format: weight size destination).
The system determines the appropriate truck and diversion path (if required).
Packages are shipped or stored until trucks return empty.

Getting Started
To run the program:

1- Clone the repository:
git clone [https://github.com/username/seneca-deliveries.git](https://github.senecacollege.ca/prparmar1/Fall23-SFT221-ZCC-4.git)
2- Compile and execute the main program.
