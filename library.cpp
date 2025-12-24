#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;

class Book {
public:
	void setTitle(string t) {
		if (t.length() != 0) {
			title = t;
		}
		else {
			title = "A Book";
		}
	}
	void setYear(int y) {
		if (y >= 0) {
			yearPublished = y;
		}
		else {
			yearPublished = -1;
		}
	}

	string getTitle() {
		return title;
	}
	int getYear() {
		return yearPublished;
	}

	Book() {
		title = "book";
		yearPublished = 2025;
	}
	Book(string t, int y) {
		title = t;
		yearPublished = y;
	}

private:
	string title;
	int yearPublished;
};

class Library {
public:
	void addBook(string title, int yr) {
		if (numBook >= MAX_BOOKS) {
			cout << "out of space!";
		}
		else {
			collection[numBook] = new Book(title, yr);
			numBook++;
		}
	}
	void deleteBook(int n) {
		if (n >= 0 && n < numBook) {
			delete collection[n];
			numBook--;
			for (int i = n; i < numBook; i++) {
				collection[n] = collection[n + 1];
			}
		}
		else {
			cout << "invalid book number" << endl;
		}
	}

	void printCollection() {
		for (int i = 0; i < numBook; i++) {
			cout << collection[i]->getTitle() << ", " << collection[i]->getYear() << endl;
		}
	}

	string getBookTitle(int n){
		if (n >= 0 && n < numBook) {
			return collection[n]->getTitle();
		}
		return "book number does not exist";
	}
	int getBookYear(int n) {
		if (n >= 0 && n < numBook) {
			return collection[n]->getYear();
		}
		return -1;
	}

	Library() {
		name = "Stories";
		for (int i = 0; i < MAX_BOOKS; i++) {
			collection[i] = nullptr;
		}
		numBook = 0;
	}
	Library(string nm) {
		name = nm;
		for (int i = 0; i < MAX_BOOKS; i++) {
			collection[i] = nullptr;
		}
		numBook = 0;
	}

	~Library() {
		for (int n = 0; n < numBook; n++) {
			delete collection[n];
		}
	}
private:
	string name;
	Book* collection[MAX_BOOKS];
	int numBook;
};

int main() {
	Library l;
	l.addBook("how to make coffee", 2000);
	l.printCollection();

	Library l2("Small Book Library");
	l2.addBook("sam i am", 2002);
	l2.addBook("i am sam", 2003);
	l2.addBook("am i sam?", 2004);
	l2.printCollection();

	l2.deleteBook(1);
	l2.printCollection();
}