#include "covid_priority_queue.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "usuage: " << argv[0] << "number of vaccines " << std::endl;
    return 1;
  }
  int availableVaccines = std::stoi(argv[1]);

  CovidPriorityQueue queue;
  std::ifstream file("patients.txt");
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string name;
    std::string preCondition;
    int age;

    std::getline(iss, name, ',');
    iss >> age >> std::ws;
    std::getline(iss, preCondition);

    queue.push(Patient(name, age, preCondition == "Yes"));
  }

  while (!queue.empty() && availableVaccines > 0) {
    Patient patient = queue.top();
    std::cout << patient.name << " ";
    queue.pop();
    --availableVaccines;
  }
  std::cout << std::endl;
  return 0;
}