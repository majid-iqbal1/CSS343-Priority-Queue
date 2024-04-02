#ifndef PATIENT_H
#define PATIENT_H

#include <string>

struct Patient {
    std::string name;
    int age;
    bool hasPrecondition;

    Patient(std::string name, int age, bool precondition) : name(std::move(name)), age(age),
            hasPrecondition(precondition) {}
};

#endif // PATIENT_H