#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;

public:
    Person(const string& name, int id) : name(name), id(id) {}
    virtual ~Person() {}
    virtual void display() const = 0;
    string getName() const { return name; }
    int getId() const { return id; }
};

#endif# Hospital-management-system-

