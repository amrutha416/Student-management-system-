
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char rollNumber[20];
    int age;
    float marks;
    int year;
    int semester;
};

struct Student students[100];
int count = 0;

void addStudent() {
    if (count >= 100) {
        printf("Maximum student limit reached.\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^
]", students[count].name);
    printf("Enter roll number: ");
    scanf(" %[^
]", students[count].rollNumber);
    printf("Enter age: ");
    scanf("%d", &students[count].age);
    printf("Enter marks: ");
    scanf("%f", &students[count].marks);
    printf("Enter year (1-4): ");
    scanf("%d", &students[count].year);
    printf("Enter semester (1 or 2): ");
    scanf("%d", &students[count].semester);
    count++;
    printf("Student added successfully.\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n+------+----------------------+------------------+-----+--------+------+-----------+\n");
    printf("| S.No | Name                 | Roll Number       | Age | Marks  | Year | Semester  |\n");
    printf("+------+----------------------+------------------+-----+--------+------+-----------+\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-4d | %-20s | %-16s | %-3d | %-6.2f | %-4d | %-9d |\n",
            i + 1,
            students[i].name,
            students[i].rollNumber,
            students[i].age,
            students[i].marks,
            students[i].year,
            students[i].semester
        );
    }
    printf("+------+----------------------+------------------+-----+--------+------+-----------+\n");
}

void searchStudent() {
    char roll[20];
    printf("Enter roll number to search: ");
    scanf(" %[^
]", roll);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].rollNumber, roll) == 0) {
            printf("\nStudent Found:\n");
            printf("Name       : %s\n", students[i].name);
            printf("Roll Number: %s\n", students[i].rollNumber);
            printf("Age        : %d\n", students[i].age);
            printf("Marks      : %.2f\n", students[i].marks);
            printf("Year       : %d\n", students[i].year);
            printf("Semester   : %d\n", students[i].semester);
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent() {
    char roll[20];
    printf("Enter roll number to delete: ");
    scanf(" %[^
]", roll);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].rollNumber, roll) == 0) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void updateStudent() {
    char roll[20];
    printf("Enter roll number to update: ");
    scanf(" %[^
]", roll);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].rollNumber, roll) == 0) {
            printf("Enter new name: ");
            scanf(" %[^
]", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Enter new year (1-4): ");
            scanf("%d", &students[i].year);
            printf("Enter new semester (1 or 2): ");
            scanf("%d", &students[i].semester);
            printf("Student updated successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: 
                printf("Exiting... Thank you!\n");
                exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
