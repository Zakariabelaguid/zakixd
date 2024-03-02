#include <stdio.h>

#define NUM_COURSES 7
#define PASS_MARK 10

// Function to input marks for each module
void inputMarks(float marks[NUM_COURSES][4]) {
    for (int i = 0; i < NUM_COURSES; i++) {
        printf("Enter marks for Module %d (TD TP Quiz Exam): ", i + 1);
        scanf("%f %f %f %f", &marks[i][0], &marks[i][1], &marks[i][2], &marks[i][3]);
    }
}

// Function to calculate the total marks for each module
void calculateTotalMarks(float marks[NUM_COURSES][4], float totalMarks[NUM_COURSES]) {
    for (int i = 0; i < NUM_COURSES; i++) {
        totalMarks[i] = marks[i][0] + marks[i][1] + marks[i][2] + marks[i][3];
    }
}

// Function to calculate the semester average
float calculateSemesterAverage(float totalMarks[NUM_COURSES]) {
    float total = 0;
    for (int i = 0; i < NUM_COURSES; i++) {
        total += totalMarks[i];
    }
    return total / NUM_COURSES;
}

// Function to check if the student needs remediation
int needsRemediation(float semesterAverage) {
    return semesterAverage < PASS_MARK;
}

// Function to display results
void displayResults(float totalMarks[NUM_COURSES], float semesterAverage, int remediation) {
    printf("\nModule\t\tTotal Marks\n");
    for (int i = 0; i < NUM_COURSES; i++) {
        printf("Module %d:\t%.2f\n", i + 1, totalMarks[i]);
    }

    printf("\nSemester Average: %.2f\n", semesterAverage);

    if (remediation) {
        printf("\nRemediation is required.\n");
    } else {
        printf("\nCongratulations! You have passed the semester.\n");
    }
}

int main() {
    float marks[NUM_COURSES][4];
    float totalMarks[NUM_COURSES];
    float semesterAverage;
    int remediation;

    // Input marks for each module
    inputMarks(marks);

    // Calculate total marks for each module
    calculateTotalMarks(marks, totalMarks);

    // Calculate semester average
    semesterAverage = calculateSemesterAverage(totalMarks);

    // Check if remediation is required
    remediation = needsRemediation(semesterAverage);

    // Display results
    displayResults(totalMarks, semesterAverage, remediation);

    return 0;
}
