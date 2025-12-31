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
	void setAuthor(string a) {
		if (a.length() != 0) {
			author = a;
		}
		else {
			author = "Unknown";
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
	string getAuthor() { 
		return author; 
	}
	int getYear() {
		return yearPublished;
	}

	Book() {
		title = "A Book";
		author = "Unknown";
		yearPublished = 2025;
	}
	Book(string t, string a, int y) {
		setTitle(t);
		setAuthor(a);
		setYear(y);
	}

private:
	string title;
	string author;
	int yearPublished;
};

class Library {
public:
	void addBook(string title, string author, int yr) {
		if (numBook >= MAX_BOOKS) {
			cout << "out of space!";
		}
		else {
			collection[numBook] = new Book(title, author, yr);
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
			cout << collection[i]->getTitle() << " | By, " << collection[i]->getAuthor() << " | Published in " << collection[i]->getYear() << endl;
		}
	}
	void printLibraryInfo() {
		cout << "Library name: " << name << endl;
		cout << "Number of books: " << numBook << endl;
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
		name = "Town Library";
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
	//how to use library class

	Library l;
	l.addBook("How to Make Coffee", "Ariel B.", 2000);
	l.printLibraryInfo();
	l.printCollection();

	cout << "=====" << endl;

	Library l2("Small Book Library");
	l2.addBook("Sam I Am", "Sam I. Am", 2002);
	l2.addBook("I Am Sam", "Sam I. Am", 2003);
	l2.addBook("Am I Sam?", "Sam I. Am", 2004);
	l2.printLibraryInfo();
	l2.printCollection();

	cout << "=====" << endl;

	l2.deleteBook(1); //removes index 1 book of l2 library (removes I Am Sam book)
	l2.printLibraryInfo();
	l2.printCollection();
}
