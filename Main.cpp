#include "doctor.h"
#include "patient.h"
#include "appointment.h"
#include "filehandler.h"
#include <vector>

using namespace std;

void displayMenu() {
    cout << "Hospital Management System" << endl;
    cout << "1. Add Doctor" << endl;
    cout << "2. Add Patient" << endl;
    cout << "3. Add Appointment" << endl;
    cout << "4. Display All" << endl;
    cout << "5. Save to File" << endl;
    cout << "6. Load from File" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    vector<Person*> people;
    vector<Appointment> appointments;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        try {
            if (choice == 1) {
                string name, specialty;
                int id;
                cout << "Enter Doctor's Name: ";
                cin >> name;
                cout << "Enter Doctor's ID: ";
                cin >> id;
                cout << "Enter Doctor's Specialty: ";
                cin >> specialty;
                people.push_back(new Doctor(name, id, specialty));
            } else if (choice == 2) {
                string name, ailment;
                int id;
                cout << "Enter Patient's Name: ";
                cin >> name;
                cout << "Enter Patient's ID: ";
                cin >> id;
                cout << "Enter Patient's Ailment: ";
                cin >> ailment;
                people.push_back(new Patient(name, id, ailment));
            } else if (choice == 3) {
                int appointmentID;
                string doctorName, patientName, date;
                cout << "Enter Appointment ID: ";
                cin >> appointmentID;
                cout << "Enter Doctor's Name: ";
                cin >> doctorName;
                cout << "Enter Patient's Name: ";
                cin >> patientName;
                cout << "Enter Date (YYYY-MM-DD): ";
                cin >> date;
                appointments.emplace_back(appointmentID, doctorName, patientName, date);
            } else if (choice == 5) {
                saveToFile(people);
                cout << "Data saved successfully." << endl;
            } else if (choice == 6) {
                loadFromFile(people);
                cout << "Data loaded successfully." << endl;
            }
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }

    } while (choice != 7);

    for (auto person : people) {
        delete person;
    }

    return 0;
}
