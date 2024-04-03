#ifndef COVID_PRIORITY_QUEUE_H_
#define COVID_PRIORITY_QUEUE_H_

#include "patient.h"
#include <queue>
#include <stdexcept>
#include <vector>

struct PatientPriority {
    bool operator()(const Patient& first, const Patient& second) const;
};

class CovidPriorityQueue {
private:
    std::priority_queue<Patient, std::vector<Patient>, PatientPriority> queue;

public:
    void push(const Patient& patient);
    bool empty() const;
    void pop();
    Patient top() const;
};

#endif // COVID_PRIORITY_QUEUE_H_