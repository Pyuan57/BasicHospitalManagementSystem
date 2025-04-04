#include<iostream> // Including the necessary header for input and output stream
#include<fstream>  // Including the header for file input and output operations
#include<iomanip>  // Including the header for manipulating input and output stream formatting

using namespace std;

class Patient { // Class to represent a Patient and manage patient records
public:
    int age;
    string name;
    string ic ;
    string diseases;
    string contactnumber;
    string room_numb;
    string type_of_blood;
    char gender;
    float price;
    float deposit;
    float return_money;

    void add_patient_record();// Function to add a new patient record to the file
    void search_patient_record(); // Function to search for a patient record by name
    void view_patient_record();// Function to view all patient records stored in the file
    void delete_patient_record(); // Function to delete a patient record by name
};

class HospitalSystem { // Class to manage the hospital system and interact with Patient class
public:
    int optionformenu;
    Patient patient;

    void system_options() { // Function to display the main menu and take user input
        cout << "=======================================\n";
        cout << "|        Welcome to TC Hospital       |\n";
        cout << "=======================================\n";
        cout << "| 1  |  Add patient new record        |\n";
        cout << "| 2  |  Search patient record         |\n";
        cout << "| 3  |  List record of patients       |\n";
        cout << "| 4  |  Delete patient records        |\n";
        cout << "| 5  |  Exit System                   |\n";
        cout << "=======================================\n";
        cout << "Please enter your options : ";
        cin >> optionformenu; // Take user input for the selected option
    }

    void program_run() { // Function to run the hospital management program
        do { // Loop until the user chooses to exit the system
            system_options(); // Display the main menu and take user input
            switch (optionformenu) { // Switch case to perform the selected option
                case 1:
                    patient.add_patient_record();
                    break;
                case 2:
                    patient.search_patient_record();
                    break;
                case 3:
                    patient.view_patient_record();
                    break;
                case 4:
                    patient.delete_patient_record();
                    break;
                case 5:
                    cout << "\nThank you for using our TC HOSPITAL system! Goodbye!" << endl;
                    break;
                default:
                    cout << "\nInvalid choice. Please try again." << endl;
            }
        } while (optionformenu != 5);
    }
};

void Patient::add_patient_record() {// Function to add a new patient record to the file

    system("cls||clear"); // Clear the screen
    Patient patient; // Create a new Patient instance
    cout << "=========================================\n";
    cout << "||             Patient Record          ||\n";
    cout << "=========================================\n";
    cout << "   1. Name              : " ;
    getline(cin >> ws,patient.name); // Take user input for patient details
    cout << "   2. Age               : " ;
    cin >> patient.age;
    cout << "   3. IC                : " ;
    cin >> patient.ic;
    cout << "   4. Gender (M/F)      : " ;
    cin >> patient.gender;
    cin.ignore();
    cout << "   5. Disease           : " ;
    getline(cin >> ws,patient.diseases);
    cout << "   6. Type of blood     : " ;
    cin >> patient.type_of_blood;
    cout << "   7. Contact Number    : " ;
    cin >> patient.contactnumber;
    cout << "   8. Room number       : " ;
    cin >> patient.room_numb;
    cout << "   9. Charges per room  : " ;
    cin >> patient.price;
    cout << "   10. Amount deposited : " ;
    cin >> patient.deposit;
    cout << "   11. Amount to return : " ;
    cin >> patient.return_money;

    ofstream file("patient.txt", ios::app); // Open the file in append mode
    if (!file) {  // Check if the file is opened successfully
        cout << "Fail to open file." << endl;
        return;
    }

file << left << setw(25) << patient.name  // Write patient details to the file in a formatted manner
     << setw(5) << patient.age
     << setw(15) << patient.ic
     << setw(10) << patient.gender
     << setw(15) << patient.type_of_blood
     << setw(25) << patient.diseases
     << setw(15) << patient.room_numb
     << setw(10) << patient.price
     << setw(10) << patient.deposit
     << setw(12) << patient.return_money
     << endl;
    cout << "\nPatient record added successfully!" << endl;

    char clearChoice; // Ask user if they want to clear the screen
        cout << "Do you want to clear the screen? (Y/N): ";
        cin >> clearChoice;

    if (clearChoice == 'Y' || clearChoice == 'y') { // Clear the screen based on user's choice
        system("cls||clear");
    }

    file.close(); // Close the file
}

void Patient::search_patient_record() { // Function to search for a patient record by name

    system("cls||clear"); // Clear the screen
    Patient patient; // Create a new Patient instance
    string line; // Temporary variable to store each line read from the file

    ifstream file; // Open the file for reading
    file.open("patient.txt");

    cout << "Enter patient name: "; // Prompt user to enter the patient name for search
    cin >> patient.name;
    getline(cin >> ws,name); // Handle whitespace characters
    cout << endl ;

    if (file.is_open())// Check if the file is opened successfully
    {
        while (!file.eof()) // Loop through the file to find the patient by name
        {
            getline(file,line);
            if ((line.find(patient.name, 0)) != string::npos)
            {
                cout << left << setw(25) << "Name" // Display header for patient details
                     << setw(5) << "Age"
                     << setw(15) << "IC"
                     << setw(10) << "Gender"
                     << setw(15) << "Type of blood"
                     << setw(25) << "Diseases"
                     << setw(15) << "Room number"
                     << setw(10) << "Price"
                     << setw(10) << "Deposit"
                     << setw(12) << "Return money"
                     << endl;
                cout << line << endl; // Display the patient details
                break;
            }
        }

        if((line.find(patient.name, 0)) == string::npos){ // Display a message if the patient is not found
             cout << "\nPatient's name is not in the record list ! " << endl << endl;
        }

        char clearChoice; // Ask user if they want to clear the screen
            cout << "\nDo you want to clear the screen? (Y/N): ";
            cin >> clearChoice;

        if (clearChoice == 'Y' || clearChoice == 'y') { // Clear the screen based on user's choice
        system("cls||clear");
    }
        file.close(); // Close the file
    }
}

void Patient::view_patient_record(){ // Function to view all patient records stored in the file

    system("cls||clear"); // Clear the screen
    string n; // Temporary variable to store each line read from the file
    ifstream file("patient.txt"); // Open the file for reading

    if (!file.is_open()) { // Check if the file is opened successfully
        cout << "Failed to list records." << endl;
        return;
    }

    if (file.peek() == ifstream::traits_type::eof()) { // Check if the file is empty
        cout << "No records found!" << endl;

    char clearChoice; // Ask user if they want to clear the screen
        cout << "\nDo you want to clear the screen? (Y/N): ";
        cin >> clearChoice;

    if (clearChoice == 'Y' || clearChoice == 'y') { // Clear the screen based on user's choice
        system("cls||clear");
    }
        file.close(); // Close the file
        return;
    }

     cout << left << setw(25) << "Name" // Display header for patient details
                     << setw(5) << "Age"
                     << setw(15) << "IC"
                     << setw(10) << "Gender"
                     << setw(15) << "Type of blood"
                     << setw(25) << "Diseases"
                     << setw(15) << "Room number"
                     << setw(10) << "Price"
                     << setw(10) << "Deposit"
                     << setw(12) << "Return money"
                     << endl;

    while (getline(file, n)) { // Loop through the file and display each patient record
        cout << n << endl;
    }

    char clearChoice; // Ask user if they want to clear the screen
        cout << "\nDo you want to clear the screen? (Y/N): ";
        cin >> clearChoice;

    if (clearChoice == 'Y' || clearChoice == 'y') { // Clear the screen based on user's choice
        system("cls||clear");
    }
    file.close(); // Close the file
}

void Patient::delete_patient_record() { // Function to delete a patient record by name

    system("cls||clear"); // Clear the screen
    Patient patient; // Create a new Patient instance

    cout << "Please enter the patient name you want to delete : "; // Prompt user to enter the patient name for deletion
    getline(cin >> ws,patient.name);

    ifstream inFile("patient.txt"); // Open the input file for reading
    ofstream outFile("temp.txt"); // Open a temporary file for writing

    if (!inFile) { // Check if the input file is opened successfully
        cout << "Error to open the file !" << endl;
        return;
    }

    string line; // Temporary variable to store each line read from the file
    bool found = false; // Flag to check if the patient is found for deletion
    while (getline(inFile, line)) { // Loop through the file and copy records to the temporary file
        if (line.find(patient.name) == string::npos) {
            outFile << line << endl;
        } else {
            found = true;
        }
    }

    if (!found) {  // Display a message based on whether the patient is found and deleted
        cout << "Patient name : " << patient.name << " not found." << endl;
    } else {
        cout << "Patient name : " << patient.name << " has been deleted." << endl;
    }

    char clearChoice; // Ask user if they want to clear the screen
        cout << "\nDo you want to clear the screen? (Y/N): ";
        cin >> clearChoice;

    if (clearChoice == 'Y' || clearChoice == 'y') { // Clear the screen based on user's choice
        system("cls||clear");
    }
    inFile.close(); // Close the input file
    outFile.close(); // Close the output file
    remove("patient.txt"); // Remove the original file
    rename("temp.txt", "patient.txt"); // Rename the temporary file
}

int main() { // Main function where the program starts execution
    // Create an instance of HospitalSystem and run the program
    HospitalSystem hospitalSystem;
    hospitalSystem.program_run();

    return 0;
}
