#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char name[30];
    char author[30];
    int id;
    int total_copies;
    int issued_copies;
    struct book *next;
};

struct student {
    int enrollment; 
    char name[30];
    long long phone_number;
    char email[30];
    char book[30];
    char author[30];
    int id;
    struct student *next;
};

struct book *book_head = NULL;
struct student *student_head = NULL;

void add_book(const char * name, const char * author, int id, int total_copies) {
    struct book * new_book = (struct book * )malloc(sizeof(struct book));
    if (new_book == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(new_book->name, name);
    strcpy(new_book->author, author);
    new_book->id = id;
    new_book->total_copies = total_copies;
    new_book->issued_copies = 0;
    new_book->next = book_head;
    book_head = new_book;
}

void initialize_books() {
    add_book("A Tale Of Two Cities", "Charles Dickens", 105, 3);
    add_book("Pride And Prejudice", "Jane Austen", 104, 2);
    add_book("The Alchemist", "Paulo Coelho", 103, 5);
    add_book("To Kill A Mockingbird", "Harper Lee", 102, 4);
    add_book("The Kite Runner", "Khaled Hosseini", 101, 3);
}

void display_books() {
    struct book *ptr = book_head;
    while (ptr != NULL) {
        printf("\nName: %s\nAuthor: %s\nID: %d\nTotal Copies: %d\nIssued Copies: %d\n",
        ptr->name, ptr->author, ptr->id, ptr->total_copies, ptr->issued_copies);
        ptr = ptr->next;
    }
}

void issue_book() {
    struct student *new_student = NULL;
    int issue_choice, flag = 0;
    struct book *ptr = book_head;
    printf("\n===============AVAILABLE BOOKS================\n");
    display_books();
    printf("\n==============================================\n");
    printf("\nEnter the ID of the book you want to issue: ");
    scanf("%d", &issue_choice);
    while (ptr != NULL) {
        if (ptr->id == issue_choice) {
            if (ptr->total_copies == 0) {
                printf("\n!!SORRY!!, all copies of this book are currently issued.\n");
                flag = 2;
                break;
            } else {
                new_student = (struct student *)malloc(sizeof(struct student));
                if (new_student == NULL) {
                    printf("Memory allocation failed\n");
                    return;
                }
                printf("\nENTER STUDENT DETAILS:\n ");
                printf("\nEnter your Enrollment number: ");
                scanf("%d", &new_student->enrollment);
                printf("Enter your Name: ");
                scanf("%s", new_student->name);
                printf("Enter your Phone Number: ");
                scanf("%lld", &new_student->phone_number);
                printf("Enter your Email: ");
                scanf("%s", new_student->email);
                strcpy(new_student->book, ptr->name);
                strcpy(new_student->author, ptr->author);
                new_student->id = ptr->id;
                new_student->next = student_head;
                student_head = new_student;
                printf("\nIssue of Book ID %d done successfully!\n", new_student->id);
                flag = 1;
                ptr->issued_copies++;
                ptr->total_copies--;
                break;
            }
        }
        ptr = ptr->next;
    }
    if (flag == 0) printf("\n********** BOOK NOT AVAILABLE **********\n\n");
}

void return_book() {
    struct student * ptr = student_head, *prev = NULL;
    struct book *ptr2 = book_head;
    int return_choice, student, flag = 0;
    printf("Enter the Enrollment number of the student: ");
    scanf("%d", &student);
    printf("\nEnter the ID of the book you want to return: ");
    scanf("%d", &return_choice);
    while (ptr != NULL) {
        if (ptr->enrollment == student && ptr->id == return_choice) {
            while (ptr2 != NULL) {
                if (ptr2->id == return_choice) {
                    ptr2->total_copies++;
                    ptr2->issued_copies--;
                    break;
                }
                ptr2 = ptr2->next;
            }
            printf("\nEnrollment Number: %d", ptr->enrollment);
            printf("\nStudent Name: %s", ptr->name);
            printf("\nStudent Email: %s", ptr->email);
            printf("\nName of Book Issued: %s", ptr->book);
            printf("\nAuthor of Book Issued: %s", ptr->author);
            flag = 1;
            if (prev == NULL) {
                student_head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
            printf("\n\n\nRETURN OF THE BOOK ID %d DONE SUCCESSFULLY!!\n", return_choice);
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    if (flag == 0) printf("\n********** BOOK OR STUDENT ID IS INVALID **********\n\n");
}

void display_details() {
    struct student *ptr = student_head;
    printf("\n**************** DETAILS OF STUDENTS *****************\n");
    while (ptr != NULL) {
        printf("\nEnrollment Number: %d", ptr->enrollment);
        printf("\nStudent Name: %s", ptr->name);
        printf("\nStudent Email: %s", ptr->email);
        printf("\nName of Book Issued: %s", ptr->book);
        printf("\nAuthor of Book Issued: %s", ptr->author);
        printf("\nBook ID: %d\n", ptr->id);
        ptr = ptr->next;
        printf("\n");
    }
    printf("\n*******************************************************\n\n");
}

int main() {
    int choice;
    char ch = 'y';
    initialize_books();

    while (ch == 'y') {
        printf("\n***************** WELCOME TO STUDENT LIBRARY ****************\n\n");
        printf("========================= MAIN MENU =========================\n\n");
        printf("***************** 1. ISSUE OF BOOKS *************************\n");
        printf("***************** 2. RETURN OF BOOKS ************************\n");
        printf("***************** 3. DISPLAY STUDENT DETAILS ****************\n");
        printf("***************** 4. EXIT ***********************************\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                issue_book();
                break;
            case 2:
                return_book();
                break;
            case 3:
                display_details();
                break;
            case 4:
                printf("\n***** THANK YOU FOR USING OUR SERVICES *****\n\n");
                ch = 'n';
                break;
            default:
                printf("\n******** INVALID CHOICE ********\n********** TRY AGAIN!! *********\n\n");
                break;
        }
    }
    return 0;
}
