/**
 * This header file declares a CovidPriorityQueue class,
 *  to priority queue for managing patient data.
 *
 * @author Majid Iqbal
 * @date April 07, 2024
 */

#ifndef COVID_PRIORITY_QUEUE_H_
#define COVID_PRIORITY_QUEUE_H_

#include "patient.h"
#include <queue>
#include <stdexcept>
#include <vector>

using namespace std;

// Comparator for prioritizing patients in the queue
struct PatientPriority {
    bool operator()(const Patient& first, const Patient& second) const;
};

// this class manages a priority queue for patients
class CovidPriorityQueue {
private:
    priority_queue<Patient, vector<Patient>, PatientPriority> queue;

public:
    void push(const Patient& patient);
    bool empty() const;
    void pop();
    Patient top() const;
};

#endif // COVID_PRIORITY_QUEUE_H_