#include "COVIDPriorityQueue.h"

bool PatientPriority::operator()(const Patient &first,
                                 const Patient &second) const {
  if (first.hasPrecondition == second.hasPrecondition) {
    return first.age < second.age;
  }
  return !first.hasPrecondition;
}

void COVIDPriorityQueue::push(const Patient &patient) {
  const int minAgeLimit = 5;
  if (patient.age >= minAgeLimit) {
    queue.push(patient);
  }
}

bool COVIDPriorityQueue::empty() const { return queue.empty(); }

void COVIDPriorityQueue::pop() {
  if (!empty()) {
    queue.pop();
  }
}

Patient COVIDPriorityQueue::top() const {
  if (!empty()) {
    return queue.top();
  }
  throw std::runtime_error(
      "Attempted to access the top of an empty priority queue");
}
