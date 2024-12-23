#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <vector>
#include "person.h"
#include "doctor.h"
#include "patient.h"

void saveToFile(const vector<Person*>& people) {
    ofstream outFile("hospital_data.txt");
    if (!outFile) {
        throw runtime_error("Error opening file for writing.");
    }

    for (const auto& person : people) {
        if (dynamic_cast<Doctor*>(person)) {
            outFile << "Doctor," << person->getName() << "," << person->getId() << endl;
        } else if (dynamic_cast<Patient*>(person)) {
            outFile << "Patient," << person->getName() << "," << person->getId() << endl;
        }
    }
    outFile.close();
}

void loadFromFile(vector<Person*>& people) {
    ifstream inFile("hospital_data.txt");
    if (!inFile) {
        throw runtime_error("Error opening file for reading.");
    }

    string type, name;
    int id;
    while (inFile >> type >> name >> id) {
        if (type == "Doctor") {
            people.push_back(new Doctor(name, id, "General"));
        } else if (type == "Patient") {
            people.push_back(new Patient(name, id, "Unknown"));
        }
    }
    inFile.close();
}

#endif
