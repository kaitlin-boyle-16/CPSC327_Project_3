#include "../includes_usr/fileIO.h"
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
		return a > b;
}
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename)
{
	books.clear();
	string line;
	ifstream myfile(filename);
	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}
	if (books.size() == 0) {
		return NO_BOOKS_IN_LIBRARY;
	}
	else {
		while (!myfile.eof()) {
			getline(myfile, line, '\n');
			books.push_back(line);
		}
		myfile.close();
	}

	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	string line;
		ifstream myfile (filename);
		if (!myfile.is_open()) {
			return COULD_NOT_OPEN_FILE;
		}
		if (books.size() == 0) {
			return NO_BOOKS_IN_LIBRARY;
		}
		else {
			while (!myfile.eof()) {
				getline(myfile, line, '\n');
				books.push_back(line);
			}
			sort(books.begin(), books.end(), compare); //serializes books here
			myfile.close();
		}
	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	patrons.clear();
		string line;
		ifstream myfile (filename);
		if (!myfile.is_open()) {
			return COULD_NOT_OPEN_FILE;
		}
		if (patrons.size() == 0) {
			return NO_PATRONS_IN_LIBRARY;
		}
		else {
			while (!myfile.eof()) {
				getline(myfile, line, '\n');
				patrons.push_back(line);
			}
			myfile.close();
		}
	return SUCCESS;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	string line;
			ifstream myfile (filename);
			if (!myfile.is_open()) {
				return COULD_NOT_OPEN_FILE;
			}
			if (patrons.size() == 0) {
				return NO_PATRONS_IN_LIBRARY;
			}
			else {
				sort(patrons.begin(), patrons.end(), compare); //serializes patrons here
				myfile.close();
			}
	return SUCCESS;
}
