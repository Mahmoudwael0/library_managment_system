#include <iostream>
#include <string>
using namespace std;

// Node structure for Linked List
struct Book {
    int bookID;
    string title;
    string author;
    Book* next;
};

// Function to create a new book node
Book* createBook(int id, string title, string author) {
    Book* newBook = new Book();
    newBook->bookID = id;
    newBook->title = title;
    newBook->author = author;
    newBook->next = NULL;
    return newBook;
}

// Function to search book by ID
void searchByID(Book* head, int id) {
    Book* temp = head;
    while (temp != NULL) {
        if (temp->bookID == id) {
            cout << "Book Found!\n";
            cout << "ID: " << temp->bookID << endl;
            cout << "Title: " << temp->title << endl;
            cout << "Author: " << temp->author << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Book with ID " << id << " not found.\n";
}

// Function to search book by Title
void searchByTitle(Book* head, string title) {
    Book* temp = head;
    while (temp != NULL) {
        if (temp->title == title) {
            cout << "Book Found!\n";
            cout << "ID: " << temp->bookID << endl;
            cout << "Title: " << temp->title << endl;
            cout << "Author: " << temp->author << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Book titled \"" << title << "\" not found.\n";
}

// Main function (for testing)
int main() {
    // Creating sample book list
    Book* head = createBook(101, "C++ Basics", "Bjarne");
    head->next = createBook(102, "Data Structures", "Mark");
    head->next->next = createBook(103, "Algorithms", "Thomas");

    // Searching
    searchByID(head, 102);
    cout << endl;
    searchByTitle(head, "Algorithms");

    return 0;
}
