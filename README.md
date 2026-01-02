# Seneca Deliveries

A C-based delivery routing system that assigns shipments to the most suitable truck using capacity constraints and shortest-path routing on a fixed 25x25 grid map.

Built for SFT221 – Software Testing (Winter 2024).

---

## Overview

Seneca Deliveries simulates how a local delivery company decides which truck should deliver each shipment.

For every shipment, the system:
- Validates shipment input (weight, box size, destination)
- Determines which truck route comes closest to the destination
- Computes the shortest valid path while avoiding buildings
- Selects the least full truck when distances are equal
- Defers delivery if no truck can accept the shipment

The project focuses on clean modular design, predictable performance, and testability.

---

## Map Model

- Delivery area is a fixed 25x25 grid
- Coordinates use row number and column letter (example: 8Y)
- Buildings are impassable cells
- Open cells allow free movement
- Trucks follow predefined routes and may divert when required
- All trucks start from the depot at location 1A

---

## Routing Logic

- Euclidean distance is used to determine which truck route comes closest to a destination
- The closest point on each route is selected
- A shortest valid path is calculated from that point to the destination
- Buildings cannot be crossed
- Greedy A*-inspired approach with no backtracking
- Trucks with no valid path are excluded
- If distances are equal, the least full truck is selected

If no truck can accept the shipment, the system outputs:

Ships tomorrow

---

## Performance

- Fixed grid size and truck count
- Predictable, bounded runtime per shipment
- No external libraries required

---

## Project Structure

Seneca-Deliveries/
├── Documents/
├── SourceCode/
│ ├── project-starter/
│ │ ├── project-starter/
│ │ │ ├── main.c
│ │ │ ├── shipment.c
│ │ │ ├── shipment.h
│ │ │ ├── truck.c
│ │ │ ├── truck.h
│ │ │ ├── mapping.c
│ │ │ ├── mapping.h
│ │ │ ├── integration.c
│ │ │ ├── integration.h
│ │ │ └── project-starter.vcxproj
│ │ └── Testing/
├── README.md
└── hooksfile

yaml
Copy code

---

## Build and Run

### Visual Studio (Windows)

Open the solution file:

SourceCode/project-starter/project-starter.sln

Build:
Ctrl + Shift + B

Run:
Ctrl + F5

---

### GCC (Linux, macOS, MinGW)

cd SourceCode/project-starter/project-starter
gcc -o deliveries main.c shipment.c truck.c mapping.c integration.c
./deliveries

yaml
Copy code

---

## Testing

- Unit, integration, and acceptance tests are located in the Testing directory
- Tests validate routing logic, capacity handling, and full system integration
- Supports automated test execution using Git hooks












