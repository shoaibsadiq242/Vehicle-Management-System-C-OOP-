# Vehicle Management System (OOP - C++)

A console-based Vehicle Management System developed using Object-Oriented Programming (OOP) concepts in C++. This application allows users to manage vehicle records including adding, editing, searching, viewing, and updating vehicle status.

---

## 📌 Project Overview

This system manages vehicle information dynamically using classes and dynamic memory allocation. Each vehicle has a unique ID along with details such as name, type, price, and current status (Available, Rented, or Sold).

The program ensures ID uniqueness before adding new vehicles and automatically expands storage capacity when needed.

---

## 🚀 Features

* Add new vehicles with unique ID validation
* View all vehicle records
* Search vehicle by ID
* Edit vehicle details
* Change vehicle status (Available / Rented / Sold)
* Dynamic memory resizing when capacity is exceeded
* Interactive menu-driven console interface

---

## 🏗️ OOP Concepts Used

* Class and Objects
* Encapsulation (private data members with public member functions)
* Constructors
* Member functions
* Dynamic memory allocation using `new` and `delete`

---

## 🛠️ How to Run

```bash
# Compile the program
g++ main.cpp -o vehicle

# Run the program
./vehicle        # Linux / Mac
vehicle.exe      # Windows
```

---

## 📋 How It Works

1. The program starts with an initial storage capacity for vehicles.
2. Users select operations from the menu.
3. When adding a vehicle:

   * The system checks whether the ID already exists.
   * If storage is full, capacity is automatically doubled.
4. Vehicles can be searched, edited, or have their status updated using their unique ID.
5. The system continues running until the user chooses to exit.

---

## 📂 Project Structure

* `main.cpp` – Contains the Vehicle class and complete application logic.

---

## 🎯 Learning Outcome

This project demonstrates practical implementation of Object-Oriented Programming principles and dynamic memory handling in C++ through a real-world vehicle management scenario.

---

## 📄 License

This project is created for educational purposes and personal practice.

---

## 👨‍💻 Author

Malik Shoaib.
