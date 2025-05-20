#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int bookID;
    bool available;

public:
    // Parameterized Constructor
    Book(string t, string a, int id) : title(t), author(a), bookID(id), available(true) {}

    // Function to display book details
    void displayBookDetails() const {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Book ID: " << bookID << endl;
        cout << "Status: " << (available ? "Available" : "Not Available") << endl;
    }

    // Function to borrow the book
    void borrowBook() {
        if (available) {
            available = false;
            cout << "Borrowing the book..." << endl;
            cout << "Book borrowed successfully." << endl;
        } else {
            cout << "Book not available." << endl;
        }
    }

    // Function to return the book
    void returnBook() {
        available = true;
        cout << "Returning the book..." << endl;
        cout << "Book returned successfully." << endl;
    }

    // Destructor
    ~Book() {
        cout << "Book \"" << title << "\" is removed from the system." << endl;
    }
};

int main() {
    // Creating a book object
    Book book1("Let Us C", "F. Scott Fitzgerald", 101);

    // Displaying book details
    book1.displayBookDetails();

    // Borrowing the book
    book1.borrowBook();

    // Attempting to borrow the book again
    book1.borrowBook();

    // Returning the book
    book1.returnBook();

    // Destroying the book object
    return 0;
}
