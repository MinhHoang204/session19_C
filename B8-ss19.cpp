#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void sortStudentsByName(Student students[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printStudents(Student students[], int length) {
    for (int i = 0; i < length; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    Student students[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Tran Thi B", 21, "0987654321"},
        {3, "Le Van C", 19, "0112233445"},
        {4, "Pham Thi D", 22, "0998877665"},
        {5, "Do Van E", 23, "0334455667"}
    };

    int currentLength = 5; 
    printf("Danh sach sinh vien ban dau:\n");
    printStudents(students, currentLength);
    printf("\nSap xep sinh vien theo ten:\n");
    sortStudentsByName(students, currentLength);
    printf("\nDanh sach sinh vien sau khi sap xep:\n");
    printStudents(students, currentLength);

    return 0;
}
