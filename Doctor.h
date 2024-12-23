#ifndef DOCTOR_H
#define DOCTOR_H

#include "person.h"

class Doctor : public Person {
private:
    string specialty;

public:
    Doctor(const string& name, int id, const string& specialty)
        : Person(name, id), specialty(specialty) {}

    void display() const override {
        cout << "Doctor ID: " << id << ", Name: " << name << ", Specialty: " << specialty << endl;
    }
};

#endif
