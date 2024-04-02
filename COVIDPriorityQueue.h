#ifndef COVIDPRIORITYQUEUE_H_
#define COVIDPRIORITYQUEUE_H_

#include "patient.h"
#include <queue>
#include <vector>

struct PatientPriority {
    bool operator()(const Patient& a, const Patient& b) const;
};

class COVIDPriorityQueue {
private:
    std::priority_queue<Patient, std::vector<Patient>, PatientPriority> queue;

public:
    void push(const Patient& patient);
    bool empty() const;
    void pop();
    Patient top() const;
};

#endif // COVIDPRIORITYQUEUE_H_