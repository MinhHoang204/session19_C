#include <stdio.h>
#include <string.h>
#define MAX_MENU 100

typedef struct {
    int id;
    char name[50];
    float price;
} Dish;

void printMenu(Dish menu[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. id: %d, name: %s, price: %.2f\n", i + 1, menu[i].id, menu[i].name, menu[i].price);
    }
}

void addDish(Dish menu[], int *count, int position, Dish newDish) {
    if (*count >= MAX_MENU || position < 0 || position > *count) {
        printf("Vi tri khong hop le hoac menu da day.\n");
        return;
    }

    for (int i = *count; i > position; i--) {
        menu[i] = menu[i - 1];
    }
    menu[position] = newDish;
    (*count)++;
}

void editDish(Dish menu[], int count, int position, Dish updatedDish) {
    if (position < 0 || position >= count) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    menu[position] = updatedDish;
}

void deleteDish(Dish menu[], int *count, int position) {
    if (position < 0 || position >= *count) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = position; i < *count - 1; i++) {
        menu[i] = menu[i + 1];
    }
    (*count)--;
}

void sortDescByPrice(Dish menu[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (menu[i].price < menu[j].price) {
                Dish temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
}

void sortAscByPrice(Dish menu[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (menu[i].price > menu[j].price) {
                Dish temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
}

void linearSearchByName(Dish menu[], int count, char name[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(menu[i].name, name) == 0) {
            printf("Tim thay: id: %d, name: %s, price: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
            return;
        }
    }
    printf("Khong tim thay mon an.\n");
}

void binarySearchByName(Dish menu[], int count, char name[]) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(menu[mid].name, name);
        if (cmp == 0) {
            printf("Tim thay: id: %d, name: %s, price: %.2f\n", menu[mid].id, menu[mid].name, menu[mid].price);
            return;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Khong tim thay mon an.\n");
}

int main() {
    Dish menu[MAX_MENU] = {
        {1, "Pho", 30000},
        {2, "Bun Cha", 35000},
        {3, "Banh Mi", 20000},
        {4, "Com Tam", 40000},
        {5, "Bun Bo", 45000}
    };
    int count = 5;

    int choice;
    do {
        printf("\nMENU\n");
        printf("1. In ra menu\n");
        printf("2. Them mon an\n");
        printf("3. Sua mon an\n");
        printf("4. Xoa mon an\n");
        printf("5. Sap xep mon an\n");
        printf("6. Tim kiem mon an\n");
        printf("7. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printMenu(menu, count);
                break;
            case 2: {
                Dish newDish;
                int position;
                printf("Nhap id: ");
                scanf("%d", &newDish.id);
                printf("Nhap ten: ");
                scanf("%s", newDish.name);
                printf("Nhap gia: ");
                scanf("%f", &newDish.price);
                printf("Nhap vi tri: ");
                scanf("%d", &position);
                addDish(menu, &count, position - 1, newDish);
                break;
            }
            case 3: {
                Dish updatedDish;
                int position;
                printf("Nhap vi tri: ");
                scanf("%d", &position);
                printf("Nhap id: ");
                scanf("%d", &updatedDish.id);
                printf("Nhap ten: ");
                scanf("%s", updatedDish.name);
                printf("Nhap gia: ");
                scanf("%f", &updatedDish.price);
                editDish(menu, count, position - 1, updatedDish);
                break;
            }
            case 4: {
                int position;
                printf("Nhap vi tri: ");
                scanf("%d", &position);
                deleteDish(menu, &count, position - 1);
                break;
            }
            case 5: {
                int subChoice;
                printf("a. Giam dan theo price\n");
                printf("b. Tang dan theo price\n");
                printf("Lua chon: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    sortDescByPrice(menu, count);
                } else if (subChoice == 2) {
                    sortAscByPrice(menu, count);
                }
                break;
            }
            case 6: {
                int subChoice;
                char name[50];
                printf("Nhap ten mon an: ");
                scanf("%s", name);
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tìm ki?m nh? phân\n");
                printf("Lua chon: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    linearSearchByName(menu, count, name);
                } else if (subChoice == 2) {
                    sortAscByPrice(menu, count); 
                    binarySearchByName(menu, count, name);
                }
                break;
            }
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    return 0;
}

