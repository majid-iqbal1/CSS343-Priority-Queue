/**
 * The header file defines a Patient structure with initialization.
 *
 * @author Majid Iqbal
 * @date April 07, 2024
 */

#ifndef PATIENT_H_
#define PATIENT_H_

#include <string>

using namespace std;

struct Patient {
    string name;
    int age;
    bool hasPreCondition;

    Patient(string name, int age, bool preCondition);
};

#endif // PATIENT_H_