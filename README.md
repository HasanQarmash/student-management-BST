# 🎓 Student Management System (BST-Based)

[![C](https://img.shields.io/badge/Language-C-blue.svg)](<https://en.wikipedia.org/wiki/C_(programming_language)>)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)
[![Build](https://img.shields.io/badge/Build-Passing-brightgreen.svg)](https://github.com)

> **A comprehensive Student Management System implemented in C using Binary Search Trees for efficient data organization and retrieval.**

## 🌟 Overview

This project is a robust student management system that leverages the power of **Binary Search Trees (BST)** to efficiently store, search, and manage student records. Built as part of a Computer Science course project, it demonstrates advanced data structure implementation and file I/O operations.

## ✨ Key Features

### 🔍 **Smart Search & Retrieval**

- **Lightning-fast student lookup** by ID using BST properties
- **City-based filtering** - Find all students from a specific city
- **Class-based grouping** - List students by their class ID

### 📝 **Complete CRUD Operations**

- ✅ **Create** - Add new student records
- 📖 **Read** - Load student data from files
- 🔄 **Update** - Modify existing student information
- 🗑️ **Delete** - Remove students by ID

### 📊 **Advanced Data Management**

- **Lexicographic sorting** - Students listed alphabetically by name
- **Dual BST implementation** - Sorted by ID and Name
- **File persistence** - Save/load data to/from external files
- **Memory-efficient** operations with dynamic allocation

### 🎯 **User Experience**

- **Interactive menu-driven interface**
- **Real-time data validation**
- **Comprehensive error handling**
- **Clear, formatted output display**

## 🏗️ System Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                    Student Management System                │
├─────────────────────────────────────────────────────────────┤
│  📁 Data Structures:                                       │
│    • Primary BST (sorted by Student ID)                   │
│    • Secondary BST (sorted by Student Name)               │
│    • Dynamic Arrays for bulk operations                   │
│                                                            │
│  🔧 Core Operations:                                       │
│    • Insert/Delete/Find (O(log n) complexity)            │
│    • In-order traversal for sorted output                │
│    • Tree-to-Array conversion for filtering              │
│                                                            │
│  💾 File I/O:                                             │
│    • studentsData.txt (input/output)                     │
│    • Persistent data storage                             │
└─────────────────────────────────────────────────────────────┘
```

## 📋 Student Data Model

Each student record contains:

| Field               | Type        | Description                     |
| ------------------- | ----------- | ------------------------------- |
| **Student ID**      | `int`       | Unique identifier (Primary Key) |
| **Name**            | `char[50]`  | Full student name               |
| **Home Address**    | `char[100]` | City/Location                   |
| **Class ID**        | `int`       | Current class identifier        |
| **Enrollment Date** | `char[20]`  | Date of enrollment              |

## 🚀 Getting Started

### Prerequisites

- **C Compiler** (GCC, MinGW, or Visual Studio)
- **Windows OS** (current implementation)
- **Code::Blocks IDE** (recommended)

### 📥 Installation

1. **Clone the repository**

   ```bash
   git clone https://github.com/HasanQarmash/student-management-BST.git
   cd student-management-BST
   ```

2. **Compile the project**

   ```bash
   gcc main.c -o student_management.exe
   ```

   _Or use the provided Code::Blocks project file (.cbp)_

3. **Prepare data file**

   - Create `studentsData.txt` in the project directory
   - Format: `StudentID Name HomeAddress ClassID EnrollmentDate`
   - Example:
     ```
     1001 John_Doe NewYork 101 2023-09-01
     1002 Jane_Smith Boston 102 2023-09-01
     ```

4. **Run the application**
   ```bash
   ./student_management.exe
   ```

## 🎮 Usage Guide

### Main Menu Options:

```
🏠 STUDENT MANAGEMENT SYSTEM
═══════════════════════════════════════
1️⃣  Load Students from File
2️⃣  Find/Update Student by ID
3️⃣  List All Students (Alphabetical)
4️⃣  Filter Students by City
5️⃣  Filter Students by Class
6️⃣  Delete Student by ID
7️⃣  Save Data to File
8️⃣  Exit Program
═══════════════════════════════════════
```

### 📖 Example Workflows:

#### **Adding New Students:**

1. Select option `1` to load existing data
2. Use option `2` with a new ID to add students
3. Save changes with option `7`

#### **Searching Students:**

- **By ID**: Use option `2` for direct lookup
- **By City**: Use option `4` for location-based search
- **By Class**: Use option `5` for class-based grouping

#### **Data Management:**

- **Update**: Use option `2` → Enter existing ID → Choose update
- **Delete**: Use option `6` → Enter student ID
- **Export**: Use option `7` to save current state

## 🔧 Technical Implementation

### **Binary Search Tree Features:**

- **Self-balancing** insertion/deletion
- **O(log n)** average time complexity for search operations
- **In-order traversal** for sorted output
- **Memory-efficient** recursive algorithms

### **File Format:**

```
StudentID StudentName HomeAddress ClassID EnrollmentDate
1001 Ahmad_Hassan Jerusalem 201 2023-09-15
1002 Fatima_Ali Ramallah 202 2023-09-16
```

### **Memory Management:**

- Dynamic memory allocation for tree nodes
- Proper cleanup and deallocation
- Memory leak prevention

## 📊 Performance Metrics

| Operation            | Time Complexity | Space Complexity       |
| -------------------- | --------------- | ---------------------- |
| Search by ID         | O(log n)        | O(1)                   |
| Insert Student       | O(log n)        | O(1)                   |
| Delete Student       | O(log n)        | O(1)                   |
| List All Students    | O(n)            | O(n)                   |
| Filter by City/Class | O(n)            | O(k) where k = matches |

## 🏆 Project Highlights

- 🎯 **Educational Value**: Demonstrates practical BST implementation
- 🔄 **Real-world Application**: Actual student management functionality
- 📈 **Scalable Design**: Efficient for large student databases
- 🛠️ **Clean Code**: Well-structured, commented C implementation
- 💾 **Data Persistence**: File-based storage system

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/AmazingFeature`)
3. **Commit** your changes (`git commit -m 'Add some AmazingFeature'`)
4. **Push** to the branch (`git push origin feature/AmazingFeature`)
5. **Open** a Pull Request

### 🎯 Potential Enhancements:

- [ ] GUI implementation using GTK+ or Qt
- [ ] Database integration (SQLite/MySQL)
- [ ] Advanced search filters
- [ ] Data export to CSV/Excel
- [ ] Student photo management
- [ ] Grade tracking system
- [ ] Attendance management

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📚 Project Requirements

The complete project requirements and specifications can be found in [Project_Requirements.pdf](Project_Requirements.pdf). This document contains:
- Detailed project specifications from Birzeit University
- Implementation requirements and constraints  
- Grading criteria and evaluation metrics
- Course context (COMP2121 - Spring 2023)

## 👨‍💻 Author

**Hasan Qarmash**

- 🎓 Student ID: 1210611
- 🏫 Birzeit University - Computer Science Department
- 📧 Contact: [qarmash.hasan@gmail.com]

## 🙏 Acknowledgments

- **Birzeit University** - Computer Science Department
- **Data Structures Course** - Spring 2023
- **BST Algorithm** - Based on classic computer science principles
- **Code::Blocks IDE** - Development environment

---

<div align="center">

**⭐ Star this repository if you found it helpful! ⭐**

[![GitHub stars](https://img.shields.io/github/stars/HasanQarmash/student-management-BST.svg?style=social&label=Star)](https://github.com/HasanQarmash/student-management-BST)
[![GitHub forks](https://img.shields.io/github/forks/HasanQarmash/student-management-BST.svg?style=social&label=Fork)](https://github.com/HasanQarmash/student-management-BST/fork)

</div>
