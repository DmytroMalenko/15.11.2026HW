#include <iostream>
#include "Contacts.h"
using namespace std;

int main() {
    PhoneBook book;

    Abonent a1("Liam Carter", "021-103-49-27", "444-777-03-22", "+0983948013", "Worker");
    Abonent a2("Emma Hayes", "554-001-21-39", "-", "+04932308190", "Friend");

    book.addAbonent(a1);
    book.addAbonent(a2);

    cout << "<------ ALL ABONENTS ------>" << endl;
    book.showAll();

    cout << "\n--- SEARCH ---" << endl;
    book.findAbonent("Emma Hayes");

    cout << "\nSaving..." << endl;
    book.saveToFile("phonebook.txt");

    cout << "\nDeleting..." << endl;
    book.removeAbonent("Liam Carter");
    book.showAll();

    cout << "\nAdding from another file..." << endl;
    PhoneBook newBook;
    newBook.loadFromFile("phonebook.txt");
    newBook.showAll();

    return 0;
}