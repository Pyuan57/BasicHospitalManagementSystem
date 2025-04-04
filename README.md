# Hospital Management System (C++)

## Overview
The **Hospital Management System** is a simple, efficient, and user-friendly software solution designed to manage patient records and associated details in a hospital setting. Built in C++, this system offers a text-based interface for adding, searching, viewing, and deleting patient records, as well as managing their financial details like deposits, room charges, and refunds.

## Key Features
- **Add New Patient Record**: Allows hospital staff to add new patient details including personal information, medical conditions, and financial information.
- **Search Patient Record**: Search for a patient’s record by their name.
- **View All Patient Records**: Display a list of all patients stored in the system.
- **Delete Patient Record**: Remove a patient’s record from the system by searching for their name.
- **Financial Management**: Tracks room charges, deposits, and return money for each patient.

## How It Works
The **Hospital Management System** uses a `Patient` class to store and manage patient details. The system is driven by a menu-driven interface that offers the following options:

1. **Add Patient Record**: Collects patient information (name, age, gender, disease, contact number, etc.) and stores it in a file.
2. **Search Patient Record**: Allows users to search for a specific patient's record by name and view the associated details.
3. **View All Patient Records**: Displays all patient records stored in the system.
4. **Delete Patient Record**: Removes a patient’s record from the system by searching their name.

The **HospitalSystem** class manages the overall functionality of the application, presenting a menu to the user and executing the selected action.

## System Requirements
- C++ compiler
- Text editor or IDE to run and edit the code (e.g., Visual Studio or Code::Blocks)

## Functionality Breakdown

### Patient Class
- **Attributes**: 
  - Name, age, IC number, diseases, contact number, room number, blood type, gender, price, deposit, return money.
- **Methods**: 
  - `add_patient_record()`: Adds a new patient’s details to the system.
  - `search_patient_record()`: Searches for and displays a patient's record based on their name.
  - `view_patient_record()`: Displays all patient records stored in the system.
  - `delete_patient_record()`: Deletes a patient’s record from the system.

### HospitalSystem Class
- **Methods**:
  - `system_options()`: Displays the main menu and prompts the user for input.
  - `program_run()`: Manages the program execution by calling relevant methods based on user input.

### Main Function
- Initializes the `HospitalSystem` object and runs the hospital management system.

## How to Use
1. **Run the Program**: Start the program by running the `main` function. The system will present a menu with options.
2. **Choose an Option**: Use the menu to:
   - Add a new patient record (Option 1)
   - Search for an existing patient (Option 2)
   - View all patient records (Option 3)
   - Delete a patient record (Option 4)
   - Exit the program (Option 5)
3. **Interact with Records**: Depending on your choice, you can enter or view patient details or manage existing records.

## File Storage
All patient records are stored in a text file named `patient.txt`. This file stores patient details in a structured format. Each patient's record is written in a specific column-width format for easy viewing.

## Sample Usage
```bash
=======================================
|        Welcome to TC Hospital       |
=======================================
| 1  |  Add patient new record        |
| 2  |  Search patient record         |
| 3  |  List record of patients       |
| 4  |  Delete patient records        |
| 5  |  Exit System                   |
=======================================
Please enter your options : 1


