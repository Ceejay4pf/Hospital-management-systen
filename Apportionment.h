#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
using namespace std;

class Appointment {
private:
    int appointmentID;
    string doctorName;
    string patientName;
    string date;

public:
    Appointment(int appointmentID, const string& doctorName, const string& patientName, const string& date)
        : appointmentID(appointmentID), doctorName(doctorName), patientName(patientName), date(date) {}

    void display() const {
        cout << "Appointment ID: " << appointmentID
             << ", Doctor: " << doctorName
             << ", Patient: " << patientName
             << ", Date: " << date << endl;
    }
};

#endif
