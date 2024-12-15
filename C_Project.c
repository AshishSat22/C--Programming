#include <stdio.h>
#include <string.h>

// Constants
#define MAX_BOOKS 100
#define MAX_STAFF 50

// Structures for Books and Staff
typedef struct {
    char book_name[50];
    char genre[20];
    int quantity;
    char author[50];
    char publication[50];
    int price;
} Book;

typedef struct {
    char name[50];
    char gender[10];
    int age;
    char phone[15];
    char address[100];
} Staff;

// Arrays for storing data
Book books[MAX_BOOKS];
Staff staff[MAX_STAFF];
int book_count = 0;
int staff_count = 0;

// Functions for Staff
void add_staff() {
    if (staff_count >= MAX_STAFF) {
        printf("Staff list is full.\n");
        return;
    }

    printf("Enter Full Name: ");
    scanf(" %[^\n]s", staff[staff_count].name);
    printf("Enter Gender (M/F/O): ");
    scanf("%s", staff[staff_count].gender);
    printf("Enter Age: ");
    scanf("%d", &staff[staff_count].age);
    printf("Enter Phone Number: ");
    scanf("%s", staff[staff_count].phone);
    printf("Enter Address: ");
    scanf(" %[^\n]s", staff[staff_count].address);

    staff_count++;
    printf("Staff added successfully.\n");
}

void remove_staff() {
    char name[50];
    printf("Enter Staff Name to Remove: ");
    scanf(" %[^\n]s", name);

    int i, found = 0;
    for (i = 0; i < staff_count; i++) {
        if (strcmp(staff[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < staff_count - 1; j++) {
            staff[j] = staff[j + 1];
        }
        staff_count--;
        printf("Staff removed successfully.\n");
    } else {
        printf("Staff not found.\n");
    }
}

void view_staff() {
    printf("Staff Details:\n");
    for (int i = 0; i < staff_count; i++) {
        printf("Name: %s\nGender: %s\nAge: %d\nPhone: %s\nAddress: %s\n",
               staff[i].name, staff[i].gender, staff[i].age, staff[i].phone, staff[i].address);
        printf("--------------------------\n");
    }
}

// Functions for Books
void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Book list is full.\n");
        return;
    }

    printf("Enter Book Name: ");
    scanf(" %[^\n]s", books[book_count].book_name);
    printf("Enter Genre: ");
    scanf("%s", books[book_count].genre);
    printf("Enter Quantity: ");
    scanf("%d", &books[book_count].quantity);
    printf("Enter Author Name: ");
    scanf(" %[^\n]s", books[book_count].author);
    printf("Enter Publication House: ");
    scanf(" %[^\n]s", books[book_count].publication);
    printf("Enter Price: ");
    scanf("%d", &books[book_count].price);

    book_count++;
    printf("Book added successfully.\n");
}

void view_books() {
    printf("Available Books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("Book Name: %s\nGenre: %s\nQuantity: %d\nAuthor: %s\nPublication: %s\nPrice: %d\n",
               books[i].book_name, books[i].genre, books[i].quantity, books[i].author, books[i].publication, books[i].price);
        printf("--------------------------\n");
    }
}

// Main Menu Functions
void staff_menu() {
    int choice;
    do {
        printf("\n--- Staff Menu ---\n");
        printf("1. Add Staff\n2. Remove Staff\n3. View Staff\n4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_staff(); break;
            case 2: remove_staff(); break;
            case 3: view_staff(); break;
            case 4: return;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (1);
}

void book_menu() {
    int choice;
    do {
        printf("\n--- Book Menu ---\n");
        printf("1. Add Book\n2. View Books\n3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_book(); break;
            case 2: view_books(); break;
            case 3: return;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (1);
}

int main() {
    int choice;
    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Staff Menu\n2. Book Menu\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: staff_menu(); break;
            case 2: book_menu(); break;
            case 3: printf("Exiting program. Goodbye!\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (1);
}
