#include "covid_priority_queue.h"

bool PatientPriority::operator()(const Patient &first,
                                 const Patient &second) const {
  if (first.hasPrecondition == second.hasPrecondition) {
    return first.age < second.age;
  }
  return !first.hasPrecondition;
}

void CovidPriorityQueue::push(const Patient &patient) {
  const int minAgeLimit = 5;
  if (patient.age >= minAgeLimit) {
    queue.push(patient);
  }
}

bool CovidPriorityQueue::empty() const { return queue.empty(); }

void CovidPriorityQueue::pop() {
  if (!empty()) {
    queue.pop();
  }
}

Patient CovidPriorityQueue::top() const {
  if (!empty()) {
    return queue.top();
  }
  throw std::runtime_error(
      "Attempted to access the top of an empty priority queue");
}