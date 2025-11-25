# 📦 Seneca Deliveries — Software Testing Project  
A structured C-based project for managing shipments, trucks, and integration logic.  
Built as part of **SFT221 – Winter 2024 (Group 2)**.

---

## 📁 Project Structure

```
Seneca-Deliveries/
│
├── Documents/                
├── SourceCode/
│   ├── project-starter/
│   │   ├── project-starter/
│   │   │   ├── main.c
│   │   │   ├── shipment.c / shipment.h
│   │   │   ├── truck.c / truck.h
│   │   │   ├── mapping.c / mapping.h
│   │   │   ├── integration.c / integration.h
│   │   │   └── project-starter.vcxproj*
│   │   └── Testing/
│   └── README.md
│
├── README.md
└── hooksfile
```

---

## 🚚 Project Overview

The **Seneca Deliveries System** models core logistics operations using modular C programming:

### ✔ Shipments  
- Stores shipment details (ID, weight, destination, status)

### ✔ Trucks  
- Tracks truck capacity, current load, and assigned shipments

### ✔ Mapping  
- Matches shipments to valid trucks  
- Ensures weight/capacity rules are respected

### ✔ Integration  
- Connects all modules together  
- Provides full-system operations and verification logic

This project focuses on **modular design**, **header organization**, and **software testing principles**.

---

## 🛠 Build & Run Instructions

### 🔹 Visual Studio (Windows)
1. Open:
   ```
   SourceCode/project-starter/project-starter.sln
   ```
2. Build → **Ctrl + Shift + B**  
3. Run → **Ctrl + F5**

---

### 🔹 GCC (Linux / Mac / Windows MinGW)

Navigate into the project directory:

```
cd SourceCode/project-starter/project-starter
```

Compile:

```
gcc -o deliveries main.c shipment.c truck.c mapping.c integration.c
```

Run:

```
./deliveries
```

---

## 🧪 Testing

The `Testing/` directory contains:

- Manual & automated tests  
- Input sets  
- Validation files  

Example command:

```
gcc -o tests TestFile.c shipment.c truck.c mapping.c integration.c
./tests
```

---

## ✨ Features Implemented

- Full modular C project  
- Separation of logic using `.c` + `.h`  
- Defensive programming & validation  
- Integration logic for end-to-end workflow  
- Ready-to-run Visual Studio solution  
- Expandable testing folder  

---

## 📌 Requirements

- ANSI C / C11  
- No external libraries unless provided  
- Must meet SFT221 course standards  
- Must pass unit + integration tests  

---


## 📄 License

For academic use only.  
