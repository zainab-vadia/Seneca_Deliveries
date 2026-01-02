🚚 Seneca Deliveries

A C-based delivery routing system that assigns shipments to the best available truck using capacity constraints and shortest-path routing on a 25 × 25 grid map.


What This Project Does

Seneca Deliveries simulates how a local delivery company decides which truck should carry each shipment.

For every shipment, the system:

Validates input (weight, box size, destination)

Finds which truck can get closest to the destination

Computes the shortest valid path around buildings

Selects the least full truck when distances tie

Defers delivery when no truck can carry the shipment

The focus is on clean logic, predictable performance, and testability.

🗺 The Map Model

The city is represented as a 25 × 25 grid

Coordinates use row + column notation (e.g. 8Y)

Buildings are impassable cells

Open space allows free movement

Each truck follows a predefined route and may divert when needed

All trucks start from the depot at 1A

Trucks & Shipments

Trucks

3 delivery trucks (Blue, Green, Yellow)

Max weight: 1000 kg

Max volume: 36 m³

A truck becomes full when either limit is reached

Shipments

Weight (kg)

Box size (m³)

Destination on the grid

Routing & Decision Logic

Uses Euclidean distance to determine which route passes closest to a destination

Calculates the shortest valid path from that route to the destination

Buildings are treated as obstacles

Pathfinding uses a greedy A*-inspired approach

If two trucks are equally close, the least full truck is selected

If no truck can accept the shipment:

Ships tomorrow

Performance

Fixed grid size (25 × 25)

Fixed number of trucks (3)

No external libraries

Predictable, bounded runtime per shipment

Designed to be efficient, simple, and easy to reason about.

Tech Stack

Language: C (ANSI / C11)

Build: GCC, Visual Studio

Testing: Unit, integration, and acceptance tests

Design: Modular .c / .h architecture

Project Structure
Seneca-Deliveries/
├── Documents/
├── SourceCode/
│   ├── project-starter/
│   │   ├── project-starter/
│   │   │   ├── main.c
│   │   │   ├── shipment.c / shipment.h
│   │   │   ├── truck.c / truck.h
│   │   │   ├── mapping.c / mapping.h
│   │   │   ├── integration.c / integration.h
│   │   │   └── project-starter.vcxproj
│   │   └── Testing/
├── README.md
└── hooksfile

Build & Run
Visual Studio (Windows)

Open:

SourceCode/project-starter/project-starter.sln


Build: Ctrl + Shift + B
Run: Ctrl + F5

GCC
cd SourceCode/project-starter/project-starter
gcc -o deliveries main.c shipment.c truck.c mapping.c integration.c
./deliveries

Testing

Unit, integration, and acceptance tests included

Focused on routing accuracy, validation, and system integration

Supports automated testing via Git hooks
