#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Struct for book
struct add_book {
    int id;
    char name[20];
    char author[20];
    int quantity;
};


void cover_page();
void password_admin();
void password_user();
void admin_mode();
void add_books();
void view_books();
void search_books();
void delete_book();
void update_book();
void user_mode();
void select_mode();
void borrow_book();
void deposit_books();
void search_book();
void book_list();


FILE *file;
FILE *file2;

int main() {
    cover_page();
    select_mode();
    return 0;
}

void cover_page() {
    system("color f0");
    printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t*-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-*");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############              LIBRARY MANAGEMENT                   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t*-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-*");
    printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n");
    printf("\n");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t---------------------------------------------------------------------------");
    printf("\n\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    printf("\n\t\t\t$$$$$$$$$$$$                                                   $$$$$$$$$$$$");
    printf("\n\t\t\t$$$$$$$$$$$$               Welcome to Library                  $$$$$$$$$$$$");
    printf("\n\t\t\t$$$$$$$$$$$$                                                   $$$$$$$$$$$$");
    printf("\n\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t----------------------------------------------------------------------------\n\n");
    printf("\n");
    printf("\n\t\t\t Submitted by :                                         Submitted to:      ");
    printf("\n");
    printf("\n\t\t  1. Irfan Ahmad Alvi(212-15-4148)                               Fahim Faisal   ");
    printf("\n\t\t  2. Pranto Saha(212-15-4157)                                      Lecturer");
    printf("\n\t\t                                                              Department of CSE               ");
    printf("\n\t\t                                                        Daffodil International University ");
    printf("\n\t\t                                                                                         ");
    printf("\n\n");
}

void password_admin() {
    char pass1[20] = "1234";
    char pass2[20];

    printf("\n\t\tEnter password : ");
    fflush(stdin);
    gets(pass2);

    if(strcmp(pass1, pass2) == 0) {
        admin_mode();
    } else {
        printf("\n\t\t Wrong Password");
        printf("\n\t\t Try again....");
        password_admin();
    }
}

void password_user() {
    char pass1[20] = "123";
    char pass2[20];

    printf("\n\t\tEnter password : ");
    fflush(stdin);
    gets(pass2);

    if(strcmp(pass1, pass2) == 0) {
        user_mode();
    } else {
        printf("\n\t\t Wrong Password");
        printf("\n\t\t Try again....");
        password_user();
    }
}

void admin_mode() {
    system("cls");
    printf("\n\t\t1) Add Book\n");
    printf("\n\t\t2) View Books\n");
    printf("\n\t\t3) Search Book By ID\n");
    printf("\n\t\t4) Delete Book\n");
    printf("\n\t\t5) Update Book\n");
    printf("\n\t\t6) Exit\n");
    printf("\t\t\t\n\n");
        printf("\t\t**********************************************\n");
    printf("\t\tEnter your choice: ");
    int n;
    scanf("%d", &n);

    switch (n) {
        case 1:
            system("cls");
            add_books();
            break;
        case 2:
            view_books();
            break;
        case 3:
            search_books();
            break;
        case 4:
            delete_book();
            break;
        case 5:
            update_book();
            break;
        case 6:
            exit(0);
        default:
            printf("\n\t\tWrong choice. Try again.");
            admin_mode();
    }
}

void add_books() {
    printf("\n\n\t\t****************** Add Book ******************\n\n");
    int d, count = 0;
    struct add_book a;

    file = fopen("book.txt", "ab+");
    rewind(file);

    printf("\n\t\tBook ID: ");
    scanf("%d", &d);

    while (fread(&a, sizeof(a), 1, file) == 1) {
        if (d == a.id) {
            count = 1;
            break;
        }
    }

    if (count == 1) {
        printf("\n\t\tThe book ID already exists.");
    } else {
        printf("\n\t\tYou can add this book.");
        a.id = d;
        printf("\t\tBook Name: ");
        fflush(stdin);
        gets(a.name);
        printf("\t\tAuthor: ");
        fflush(stdin);
        gets(a.author);
        printf("\t\tQuantity: ");
        scanf("%d", &a.quantity);

        fseek(file, 0, SEEK_END);
        fwrite(&a, sizeof(a), 1, file);
        printf("\n\t\tBook added successfully.");
    }
    fclose(file);
    printf("\n\t\tPress any key...");
    fflush(stdin);
    getchar();
    admin_mode();
}

void view_books() {
    struct add_book a;
    int count = 0;

    system("cls");
    printf("\n\n\t\t********* View Book List *********\n\n");
    printf("\tID\tName\tAuthor\tQuantity\n\n");

    file = fopen("book.txt", "rb");
    if (file == NULL) {
        printf("\n\t\tNo books found.");
    } else {
        while (fread(&a, sizeof(a), 1, file) == 1) {
            printf("\t%d\t%s\t%s\t%d\n", a.id, a.name, a.author, a.quantity);
            count += a.quantity;
        }
        fclose(file);
        printf("\n\n\n\t\t Total Books: %d", count);
    }

    printf("\n\t\tPress any key...");
    fflush(stdin);
    getchar();
    admin_mode();
}

void search_books() {
    struct add_book a;
    int d, count = 0;
    system("cls");

    printf("\n\n\t\t ************ Search Book ************");
    printf("\n\t\t Searching.....\n\n");

    file = fopen("book.txt", "rb");
    if (file == NULL) {
        printf("\n\t\tNo books found.");
    } else {
        printf("\n\t\t Enter ID: ");
        scanf("%d", &d);

        while (fread(&a, sizeof(a), 1, file) == 1) {
            if (d == a.id) {
                printf("\n\n\t\t Book Found\n");
                printf("\t\t ID: %d\n", a.id);
                printf("\t\t Name: %s\n", a.name);
                printf("\t\t Author: %s\n", a.author);
                printf("\t\t Quantity: %d\n", a.quantity);
                count = 1;
                break;
            }
        }
        if (count == 0) {
            printf("\n\n\t\t Book Not Found");
        }
        fclose(file);
    }

    printf("\n\t\tPress any key...");
    fflush(stdin);
    getchar();
    admin_mode();
}

void delete_book() {
    struct add_book a;
    int d, count = 0;
    system("cls");

    printf("\n\n\t\t ************ Delete Book ************");
    printf("\n\t\t Deleting.....\n\n");

    file = fopen("book.txt", "rb");
    file2 = fopen("temp.txt", "wb");

    if (file == NULL) {
        printf("\n\t\tNo books found.");
    } else {
        printf("\n\t\t Enter ID: ");
        scanf("%d", &d);

        while (fread(&a, sizeof(a), 1, file) == 1) {
            if (d != a.id) {
                fwrite(&a, sizeof(a), 1, file2);
            } else {
                count = 1;
            }
        }

        fclose(file);
        fclose(file2);

        remove("book.txt");
        rename("temp.txt", "book.txt");

        if (count == 1) {
            printf("\n\t\tBook deleted successfully.");
        } else {
            printf("\n\t\tBook not found.");
        }
    }

    printf("\n\t\tPress any key...");
    fflush(stdin);
    getchar();
    admin_mode();
}

void update_book() {
    struct add_book a;
    int d, count = 0;
    system("cls");

    printf("\n\n\t\t ************ Update Book ************");
    printf("\n\t\t Updating.....\n\n");

    file = fopen("book.txt", "rb+");
    if (file == NULL) {
        printf("\n\t\tNo books found.");
    } else {
        printf("\n\t\t Enter ID of book to update: ");
        scanf("%d", &d);

        while (fread(&a, sizeof(a), 1, file) == 1) {
            if (d == a.id) {
                printf("\n\t\t Enter new details for the book:");
                printf("\n\t\t New Book Name: ");
                fflush(stdin);
                gets(a.name);
                printf("\t\t New Author: ");
                fflush(stdin);
                gets(a.author);
                printf("\t\t New Quantity: ");
                scanf("%d", &a.quantity);

                fseek(file, -sizeof(a), SEEK_CUR);
                fwrite(&a, sizeof(a), 1, file);
                count = 1;
                break;
            }
        }

        fclose(file);

        if (count == 1) {
            printf("\n\t\tBook details updated successfully.");
        } else {
            printf("\n\t\tBook not found.");
        }
    }

    printf("\n\t\tPress any key...");
    fflush(stdin);
    getchar();
    admin_mode();
}

void user_mode() {
    system("cls");
    printf("\n\t\t1) Search Book by ID\n");
    printf("\n\t\t2) Book list\n");
    printf("\n\t\t3) Borrow Book\n");
    printf("\n\t\t4) Deposit Book\n");
    printf("\n\t\t5) Exit\n");
    printf("\t\t\t\n\n\t\t**********************************************\n");
    printf("\n\t\tEnter your choice : ");
    int t;
    scanf("%d", &t);

    switch (t) {
        case 1:
            search_book();
            break;
        case 2:
            book_list();
            break;
        case 3:
            borrow_book();
            break;
        case 4:
            deposit_books();
            break;
        case 5:
            exit(0);
        default:
            printf("\n\t\tWrong choice");
            printf("\n\t\tTry again");
            user_mode();
    }
}

void borrow_book() {
    struct add_book a;
    system("cls");
    int d, count = 0;
    printf("\n\n\t\t ************* Borrow book *************\n\n");
    printf("\n\n\t\t Enter ID for Borrow Book : ");
    scanf("%d", &d);
    file = fopen("book.txt", "rb+");
    if (file == NULL) {
        printf("\n\t\tFailed to open file.");
    } else {
        rewind(file);
        while (fread(&a, sizeof(a), 1, file) == 1) {
            if (d == a.id) {
                count = 1;
                break;
            }
        }

        if (count == 0) {
            printf("\n\t\tBook is not available.");
        } else {
            printf("\n\t\tBook is available!");
            file2 = fopen("text.txt", "wb");
            rewind(file);
            while (fread(&a, sizeof(a), 1, file) == 1) {
                if (d != a.id) {
                    fseek(file2, ftell(file2)-sizeof(a), 0);
                    fwrite(&a, sizeof(a), 1, file2);
                }
            }
            fclose(file);
            fclose(file2);
            remove("book.txt");
            rename("text.txt", "book.txt");
            printf("The book is borrowed successfully.");
        }
    }
    printf("\n\t\tPress any key...");
    fflush(stdin);
    getchar();
    user_mode();
}

void deposit_books() {
    system("cls");
    printf("\n\n\t\t****************** Deposit Book ******************\n\n");
    int d, count = 0;
    printf("\n\t\tBook ID:");
    scanf("%d", &d);
    struct add_book a;
    file = fopen("book.txt", "ab+");
    if (file == NULL) {
        printf("\n\t\tFailed to open file.");
    } else {
        rewind(file);
        while (fread(&a, sizeof(a), 1, file) == 1) {
            if (d == a.id) {
                count = 1;
                break;
            }
        }

        if (count == 1) {
            printf("\n\t\tWrong Book ID");
        } else {
            printf("\n\t\tYou can add this book");
            printf("\n\t\tBook ID:");
            scanf("%d", &a.id);
            printf("\t\tBook Name : ");
            fflush(stdin);
            gets(a.name);
            printf("\t\tAuthor : ");
            fflush(stdin);
            gets(a.author);
            printf("\t\tQuantity : ");
            fflush(stdin);
            scanf("%d", &a.quantity);
            fseek(file, 0, SEEK_END);
            fwrite(&a, sizeof(a), 1, file);
            printf("\n\t\tBook is added successfully...");
        }
    }
    fclose(file);
    printf("\n\t\tPress any key...");
    fflush(stdin);
    getchar();
    user_mode();
}

void search_book() {
    struct add_book a;
    int d, count = 0;
    system("cls");

    printf("\n\n\t\t ************ Search Book ************");
    printf("\n\t\t Searching.....\n\n");

    file = fopen("book.txt", "rb");
    if (file == NULL) {
        printf("\n\t\tFailed to open file.");
    } else {
        printf("\n\t\t Enter Book ID: ");
        scanf("%d", &d);

        while (fread(&a, sizeof(a), 1, file) == 1) {
            if (d == a.id) {
                printf("\n\n\t\t Book is Found\n");
                printf("\t\t ID: %d", a.id);
                printf("\n\t\t Name: %s", a.name);
                printf("\n\t\t Author: %s", a.author);
                printf("\n\t\t Quantity: %d", a.quantity);
                count = 1;
                break;
            }
        }
        if (count == 0) {
            printf("\n\n\t\t Book is Not Found");
        }
        fclose(file);
    }
    printf("\n\n\t\t press any key....");
    fflush(stdin);
    getchar();
    user_mode();
}

void book_list() {
    struct add_book a;
    int count = 0;
    system("cls");

    printf("\n\n\t\t********* Book List *********\n\n");
    printf("\tID\tName\tAuthor\tQuantity\n\n");

    file = fopen("book.txt", "rb");
    if (file == NULL) {
        printf("\n\t\tNo books found.");
    } else {
        while (fread(&a, sizeof(a), 1, file) == 1) {
            printf("\t%d\t%s\t%s\t%d\n", a.id, a.name, a.author, a.quantity);
            count += a.quantity;
        }
        fclose(file);
    }
    printf("\n\n\n\t\t Total Book: %d", count);
    printf("\n\t\tPress any key...");
    fflush(stdin);
    getchar();
    user_mode();
}

void select_mode() {
    int a;
    printf("\n\t\t->> Press 1 for Admin Mode");
    printf("\n\t\t->> Press 2 for User Mode\n\t\t");
    scanf("%d", &a);
    if (a == 1) {
        password_admin();
    } else if (a == 2) {
        password_user();
    } else {
        printf("\n\t\tINVALID INPUT");
        printf("\n\t\tTry Again\n");
        select_mode();
    }
}

