/**
 * The class implements a priority queue for COVID vaccination
 * to prioritize patients based on their precondition status and age,
 *
 * @author Majid Iqbal
 * @date April 07, 2024
 */

#include "covid_priority_queue.h"

// Comparator for prioritizing patients in the queue
// patients with preconditions are prioritized and if equal,
// the older patient is prioritized.
bool PatientPriority::operator()(const Patient &first,
                                 const Patient &second) const {
  if (first.hasPreCondition == second.hasPreCondition) {
    return first.age < second.age;
  }
  return !first.hasPreCondition;
}

// pushes the patient in the queue with the restriction of
// patient aged under 5.
void CovidPriorityQueue::push(const Patient &patient) {
  const int minAgeLimit = 5;
  if (patient.age >= minAgeLimit) {
    queue.push(patient);
  }
}

// empty the queue
bool CovidPriorityQueue::empty() const { return queue.empty(); }

// pops out the highest priority patient from the queue
void CovidPriorityQueue::pop() {
  if (!empty()) {
    queue.pop();
  }
}

// Returns the highest priority patient without removing them
Patient CovidPriorityQueue::top() const {
  if (!empty()) {
    return queue.top();
  }
  throw std::runtime_error("Oops! The queue is empty.");
}