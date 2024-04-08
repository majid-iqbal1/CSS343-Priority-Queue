/**
 * Initializing the constructor with the patient info.
 *
 * @author Majid Iqbal
 * @date April 07, 2024
 */

#include "patient.h"

Patient::Patient(std::string name, int age, bool preCondition)
    : name(std::move(name)), age(age), hasPreCondition(preCondition) {}