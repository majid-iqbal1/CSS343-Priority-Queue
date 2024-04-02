# COVID Priority Queue

## Overview
This C++ program simulates a priority queue for COVID vaccination scheduling. It prioritizes older patients and those with pre-existing conditions.

## Functionality
- Patients are queued based on age and health condition.
- The queue is managed using the Standard Template Library's `priority_queue`.

## Running the Program
Execute the program from the command line. It will read patient data from `patients.txt` and ask for the number of available vaccines to determine who should be vaccinated first.

## Input File
The program reads from `patients.txt`, which should contain records in the format:

Name, Age, Precondition Illnesses
John Doe, 30, Yes
Jane Doe, 25, No


Patients under 5 years old are not included in the queue.

## Usage
Start the program and input the number of available vaccines when prompted. The program will then display the names of the patients who will receive the vaccine based on priority.