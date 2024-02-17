#include <stdio.h>
#include <string.h>
#define FILE_NAME "C:\\Users\\user\\Documents\\CODE BLOCKS\\PFsemProject\\library_database.txt"
struct Book
{
    int serialNumber;
    char isbn[20];
    char title[100];
    char edition[50];
    char author[100];
    int isReserved;
};
void addBook();
void deleteBook();
void searchBookByISBN();
void searchBookByTitle();
void searchBookByAuthor();
void modifyBook();
void displayAllBooks();
void issueBook();
void saveToFile(struct Book *book);
void main()
{
    int choice;
    do
    {
        printf("------------------------------------------------\n");
        printf("<<========Library Management System========>>\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Modify/Update Book\n");
        printf("5. Display All Books\n");
        printf("6. Issue Book\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n------------------------------------------------\n");
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            deleteBook();
            break;
        case 3:
            printf("\nSearch Book By:\n");
            printf("a) ISBN\n");
            printf("b) Book Title\n");
            printf("c) Author Name\n");
            char searchChoice;
            scanf(" %c", &searchChoice);
            switch (searchChoice)
            {
            case 'a':
                searchBookByISBN();
                break;
            case 'b':
                searchBookByTitle();
                break;
            case 'c':
                searchBookByAuthor();
                break;
            default:
                printf("Invalid choice for search.\n");
            }
            break;
        case 4:
            modifyBook();
            break;
        case 5:
            displayAllBooks();
            break;
        case 6:
            issueBook();
            break;
        case 7:
            saveToFile(NULL);
            printf("Exiting the Library Management System.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 7);
}

void addBook()
{
    struct Book newBook;
    printf("Enter Book Serial Number: ");
    scanf("%d", &newBook.serialNumber);
    printf("Enter ISBN: ");
    scanf("%s", newBook.isbn);
    printf("Enter Book Title: ");
    scanf(" %[^\n]s", newBook.title);
    printf("Enter Edition: ");
    scanf(" %[^\n]s", newBook.edition);
    printf("Enter Author: ");
    scanf(" %[^\n]s", newBook.author);
    newBook.isReserved = 0;
    saveToFile(&newBook);
    printf("Book added successfully.\n");
}
void deleteBook()
{
    char searchISBN[20];
    printf("Enter the ISBN of the book to be deleted: ");
    scanf("%s", searchISBN);
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        printf("Error opening temporary file.\n");
        fclose(file);
        return;
    }
    struct Book currentBook;
    while (fscanf(file, "%d %s %s %s %s %d",&currentBook.serialNumber,currentBook.isbn,currentBook.title,currentBook.edition,currentBook.author,&currentBook.isReserved)!=EOF)
    {
        if (strcmp(currentBook.isbn, searchISBN) != 0)
        {
            fprintf(tempFile, "%d %s %s %s %s %d\n",currentBook.serialNumber,currentBook.isbn,currentBook.title,currentBook.edition,currentBook.author,currentBook.isReserved);
        }
    }
    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    printf("Book deleted successfully.\n");
}
void searchBookByISBN()
{
    char searchISBN[20];
    printf("Enter the ISBN of the book: ");
    scanf("%s", searchISBN);
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }
    struct Book currentBook;
    int found = 0;
    while (fscanf(file, "%d %s %s %s %s %d",&currentBook.serialNumber, currentBook.isbn,currentBook.title,currentBook.edition,currentBook.author,&currentBook.isReserved) != EOF)
    {
        if (strcmp(currentBook.isbn, searchISBN) == 0)
        {
            printf("\nBook found:\n");
            printf("Serial Number: %d\n", currentBook.serialNumber);
            printf("ISBN: %s\n", currentBook.isbn);
            printf("Title: %s\n", currentBook.title);
            printf("Edition: %s\n", currentBook.edition);
            printf("Author: %s\n", currentBook.author);
            printf("Reserved: %s\n", currentBook.isReserved ? "Yes" : "No");
            found = 1;
            break;
        }
    }
    fclose(file);
    if (!found)
    {
        printf("Book not found.\n");
    }
}

void searchBookByTitle()
{
    char searchTitle[100];
    printf("Enter the title of the book: ");
    scanf(" %s", searchTitle);
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }
    struct Book currentBook;
    int found = 0;
    while (fscanf(file, "%d %s %s %s %s %d",&currentBook.serialNumber,currentBook.isbn,currentBook.title,currentBook.edition,currentBook.author,&currentBook.isReserved)!=EOF)
    {
        if (strcmp(currentBook.title, searchTitle) == 0)
        {
            printf("\nBook found:\n");
            printf("Serial Number: %d\n", currentBook.serialNumber);
            printf("ISBN: %s\n", currentBook.isbn);
            printf("Title: %s\n", currentBook.title);
            printf("Edition: %s\n", currentBook.edition);
            printf("Author: %s\n", currentBook.author);
            printf("Reserved: %s\n", currentBook.isReserved ? "Yes" : "No");
            found = 1;
            break;
        }
    }
    fclose(file);
    if (!found)
    {
        printf("Book not found.\n");
    }
}
void searchBookByAuthor()
{
    char searchAuthor[100];
    printf("Enter the author of the book: ");
    scanf(" %s", searchAuthor);
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }
    struct Book currentBook;
    int found = 0;
    while (fscanf(file, "%d %s %s %s %s %d",&currentBook.serialNumber,currentBook.isbn,currentBook.title,currentBook.edition,currentBook.author,&currentBook.isReserved) != EOF)
    {
        if (strcmp(currentBook.author, searchAuthor) == 0)
        {
            printf("\nBook found:\n");
            printf("Serial Number: %d\n", currentBook.serialNumber);
            printf("ISBN: %s\n", currentBook.isbn);
            printf("Title: %s\n", currentBook.title);
            printf("Edition: %s\n", currentBook.edition);
            printf("Author: %s\n", currentBook.author);
            printf("Reserved: %s\n", currentBook.isReserved ? "Yes" : "No");
            found = 1;
            break;
        }
    }
    fclose(file);
    if (!found)
    {
        printf("Book not found.\n");
    }
}
void modifyBook()
{
    char searchISBN[20];
    printf("Enter the ISBN of the book to be modified: ");
    scanf("%s", searchISBN);
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        printf("Error opening temporary file.\n");
        fclose(file);
        return;
    }
    struct Book currentBook;
    int found = 0;
    while (fscanf(file, "%d %s %s %s %s %d",&currentBook.serialNumber,currentBook.isbn,currentBook.title,currentBook.edition,currentBook.author,&currentBook.isReserved) != EOF)
    {
        if (strcmp(currentBook.isbn, searchISBN) == 0)
        {
            printf("\nEnter new details for the book:\n");
            printf("Enter Book Serial Number: ");
            scanf("%d", &currentBook.serialNumber);
            printf("Enter ISBN: ");
            scanf("%s", currentBook.isbn);
            printf("Enter Book Title: ");
            scanf(" %[^\n]s", currentBook.title);
            printf("Enter Edition: ");
            scanf(" %[^\n]s", currentBook.edition);
            printf("Enter Author: ");
            scanf(" %[^\n]s", currentBook.author);
            found = 1;
        }
        fprintf(tempFile, "%d %s %s %s %s %d\n",currentBook.serialNumber,currentBook.isbn,currentBook.title,currentBook.edition,currentBook.author,currentBook.isReserved);
    }
    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    if (found)
    {
        printf("Book modified successfully.\n");
    }
    else
    {
        printf("Book not found.\n");
    }
}
void displayAllBooks()
{
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }
    struct Book currentBook;

    printf("\nAll Books in the Library:\n");
    printf("-------------------------------------------------\n");
    printf("%-15s %-20s %-30s %-15s %-20s %-10s\n", "Serial Number", "ISBN", "Title", "Edition", "Author", "Reserved");
    printf("-------------------------------------------------\n");

    while (fscanf(file, "%d %s %s %s %s %d",&currentBook.serialNumber,currentBook.isbn,currentBook.title,currentBook.edition,currentBook.author,&currentBook.isReserved) != EOF)
    {
        printf("%-15d %-20s %-30s %-15s %-20s %-10s\n",currentBook.serialNumber,currentBook.isbn,currentBook.title,currentBook.edition,currentBook.author,currentBook.isReserved ? "Yes" : "No");
    }

    printf("-------------------------------------------------\n");
    fclose(file);
}
void issueBook()
{
    char searchISBN[20];
    printf("Enter the ISBN of the book to be issued: ");
    scanf("%s", searchISBN);
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        printf("Error opening temporary file.\n");
        fclose(file);
        return;
    }
    struct Book currentBook;
    int found = 0;
    while (fscanf(file, "%d %s %s %s %s %d",&currentBook.serialNumber,currentBook.isbn,currentBook.title,currentBook.edition,currentBook.author,&currentBook.isReserved) != EOF)
    {
        if (strcmp(currentBook.isbn, searchISBN) == 0)
        {
            if (currentBook.isReserved == 0)
            {
                currentBook.isReserved = 1;
                printf("Book issued successfully.\n");
            }
            else
            {
                printf("Book is already reserved.\n");
            }
            found = 1;
        }
        fprintf(tempFile, "%d %s %s %s %s %d\n",currentBook.serialNumber,currentBook.isbn,currentBook.title,currentBook.edition,currentBook.author,currentBook.isReserved);
    }
    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    if (!found)
    {
        printf("Book not found.\n");
    }
}
void saveToFile(struct Book *book)
{
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }
    if (book != NULL)
    {
        fprintf(file, "%d %s %s %s %s %d\n",book->serialNumber,book->isbn,book->title,book->edition,book->author,book->isReserved);
    }
    fclose(file);
}
