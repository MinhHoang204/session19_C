#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void deleteStudent(int id, Student students[], int *currentLength) {
    int found = 0; 

    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--; 
            break;
        }
    }

    if (!found) {
        printf("Sinh vien co id %d khong ton tai trong mang.\n", id);
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
    printf("\nXoa sinh vien co id = 3:\n");
    deleteStudent(3, students, &currentLength);
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    printStudents(students, currentLength);

    return 0;
}

