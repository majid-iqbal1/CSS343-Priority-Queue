#include "COVIDPriorityQueue.h"

bool PatientPriority::operator()(const Patient& a, const Patient& b) const {
    if (a.hasPrecondition == b.hasPrecondition) {
        return a.age < b.age; // Older patients get higher priority
    }
    return !a.hasPrecondition; // Patients with preconditions get highest priority
}

void COVIDPriorityQueue::push(const Patient& patient) {
    if (patient.age >= 5) {
        queue.push(patient);
    }
}

bool COVIDPriorityQueue::empty() const {
    return queue.empty();
}

void COVIDPriorityQueue::pop() {
    if (!empty()) {
        queue.pop();
    }
}

Patient COVIDPriorityQueue::top() const {
    if (!empty()) {
        return queue.top();
    }
    throw std::runtime_error("Attempted to access the top of an empty priority queue");
}
