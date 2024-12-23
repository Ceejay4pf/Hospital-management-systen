#ifndef PATIENT_H
#define PATIENT_H

#include "person.h"

class Patient : public Person {
private:
    string ailment;

public:
    Patient(const string& name, int id, const string& ailment)
        : Person(name, id), ailment(ailment) {}

    void display() const override {
        cout << "Patient ID: " << id << ", Name: " << name << ", Ailment: " << ailment << endl;
    }
};

#endif
