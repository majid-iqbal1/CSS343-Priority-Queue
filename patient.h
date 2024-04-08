/**
 * The header file defines a Patient structure with initialization.
 *
 * @author Majid Iqbal
 * @date April 07, 2024
 */

#ifndef PATIENT_H
#define PATIENT_H

#include <string>

struct Patient {
    std::string name;
    int age;
    bool hasPreCondition;

    Patient(std::string name, int age, bool preCondition);
};

#endif // PATIENT_H