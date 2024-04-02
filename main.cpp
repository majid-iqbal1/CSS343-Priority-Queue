#include "COVIDPriorityQueue.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    COVIDPriorityQueue queue;
    std::ifstream file("patients.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, precondition;
        int age;

        std::string temp;
        while (iss >> temp) {
            if (name.empty()) {
                name = temp;
            } else {
                std::istringstream validator(temp);
                if (validator >> age) {
                    break;
                } else {
                    name += " " + temp;
                }
            }
        }
        iss >> precondition;
        queue.push(Patient(name, age, precondition == "Yes"));
    }

    int availableVaccines;
    std::cout << "How many vaccines are available? ";
    std::cin >> availableVaccines;

    while (!queue.empty() && availableVaccines > 0) {
        Patient patient = queue.top();
        std::cout << patient.name << " ";
        queue.pop();
        --availableVaccines;
    }
    std::cout << std::endl;
    return 0;
}