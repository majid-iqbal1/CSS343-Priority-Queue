/**
 * The driver class processes patients from a file
 * for a given number of vaccines.
 *
 * @author Majid Iqbal
 * @date April 07, 2024
 */

#include "covid_priority_queue.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// The main class takes one argument by the user
// on how many vaccines are available.
int main(int argc, char *argv[]) {
  if (argc != 2) {
    cerr << "usuage: " << argv[0] << "number of vaccines " << endl;
    return 1;
  }

  int availableVaccines = stoi(argv[1]);

  CovidPriorityQueue queue;
  ifstream file("patients.txt");
  string line;

  // reads and process each line in the file to populate the queue.
  while (getline(file, line)) {
    istringstream iss(line);
    string name;
    string preCondition;
    int age;

    // Parse each line
    getline(iss, name, ',');
    iss >> age >> ws;
    getline(iss, preCondition);

    queue.push(Patient(name, age, preCondition == "Yes"));
  }

  // Dequeue and display patients based on priority until vaccines run out or
  // queue is empty.
  while (!queue.empty() && availableVaccines > 0) {
    Patient patient = queue.top();
    cout << patient.name << " ";
    queue.pop();
    --availableVaccines;
  }
  cout << endl;
  return 0;
}