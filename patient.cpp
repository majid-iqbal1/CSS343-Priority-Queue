#include "patient.h"

Patient::Patient(std::string name, int age, bool preCondition)
    : name(std::move(name)), age(age), hasPrecondition(preCondition) {}