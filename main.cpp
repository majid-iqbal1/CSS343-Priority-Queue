#include "COVIDPriorityQueue.h"
#include <iostream>
#include <fstream>

int main() {
    COVIDPriorityQueue queue;
    std::ifstream file("patients.txt");
    std::string name, precondition;
    int age;

    while (file >> name >> age >> precondition) {
        queue.push(Patient(name, age, precondition == "Yes"));
    }

    int availableVaccines;
    std::cout << "How many vaccines are available? ";
    std::cin >> availableVaccines;

    while (!queue.empty() && availableVaccines > 0) {
        Patient patient = queue.top();
        std::cout << patient.name << std::endl;
        queue.pop();
        --availableVaccines;
    }

    return 0;
}
