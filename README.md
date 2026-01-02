Seneca Deliveries

A C-based delivery routing system that assigns shipments to the most suitable truck using capacity constraints and shortest-path routing on a 25x25 grid map.

Built as part of SFT221 – Software Testing (Winter 2024).

Overview

Seneca Deliveries simulates how a local delivery company decides which truck should deliver each shipment.

For every shipment, the system:

Validates shipment input (weight, size, destination)

Determines which truck route comes closest to the destination

Calculates the shortest valid path around buildings

Selects the least full truck when distances are equal

Defers shipment if no truck can accept it

Map Model

Delivery area is a fixed 25x25 grid

Coordinates use row number and column letter (example: 8Y)

Buildings are impassable

Open cells allow movement

Trucks follow predefined routes and may divert when required

All trucks start from the depot at 1A

Routing Logic

Euclidean distance is used to determine route proximity

Shortest valid path is computed while avoiding buildings

Greedy A*-inspired approach with no backtracking

Trucks with no valid path are excluded

Least-full truck is chosen when distances tie

Performance

Fixed grid size and truck count

Predictable, bounded runtime per shipment

No external libraries required

Project Structure
Seneca-Deliveries/
├── Documents/
├── SourceCode/
│   ├── project-starter/
│   │   ├── project-starter/
│   │   │   ├── main.c
│   │   │   ├── shipment.c
│   │   │   ├── shipment.h
│   │   │   ├── truck.c
│   │   │   ├── truck.h
│   │   │   ├── mapping.c
│   │   │   ├── mapping.h
│   │   │   ├── integration.c
│   │   │   ├── integration.h
│   │   │   └── project-starter.vcxproj
│   │   └── Testing/
├── README.md
└── hooksfile

Build and Run

Visual Studio (Windows)

Open:
SourceCode/project-starter/project-starter.sln

Build:
Ctrl + Shift + B

Run:
Ctrl + F5

GCC (Linux, macOS, MinGW)

cd SourceCode/project-starter/project-starter
gcc -o deliveries main.c shipment.c truck.c mapping.c integration.c
./deliveries

Testing

Unit, integration, and acceptance tests located in Testing/

Designed to validate routing, capacity handling, and integration logic

Supports automated test execution via Git hooks
