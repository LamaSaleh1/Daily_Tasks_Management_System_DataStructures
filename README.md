# Daily Tasks Management System 📋

## 📌 Project Overview
This project, developed for the **Data Structures (CS214)** course, provides an efficient solution for organizing and managing daily activities. It features a text-based interface that allows users to create, categorize, and track tasks using dynamic memory management.

## 🛠 Data Structures Implementation
The core of this system is built on a **Singly Linked List**, which was chosen to ensure optimal performance in a task-management context:
* **Dynamic Allocation:** Tasks are stored as nodes in a linked list, allowing the system to handle a varying number of tasks without memory waste or fixed-size limitations.
* **Efficient Operations:** Optimized for $O(1)$ insertion (at the head) and flexible deletion of tasks by name.
* **Node Structure:** Each task node contains data for the task name, date, and status (New, In Progress, Completed), along with a pointer to the next task.

## ✨ Key Features
* **Add New Tasks:** Dynamic creation of task nodes.
* **Status Management:** Ability to update task progress in real-time.
* **Smart Filtering:** Option to display all tasks or filter tasks specifically for "Today" based on the system date.
* **Task Deletion:** Safe removal of nodes and proper deallocation of memory to prevent memory leaks.

## 💻 Tech Stack
* **Language:** C++
* **Concepts:** Singly Linked Lists, Dynamic Memory Management, Pointers, and OOP.
* **Development Environment:** VS Code / C++ Compiler.

## 📂 Repository Structure
* **[📁 Source Code](./src)**: The complete source code implementing the `ToDoList` class and linked list logic.
* **[📁 Report.pdf](./Daily_Tasks_Management_System_Report.pdf)**: Detailed technical report covering the design, implementation, and conclusion.

---
*Prepared by Lama Alghofaily (Team Leader) as part of the CS214 course requirements.*
