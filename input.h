#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <map>

typedef std::map<size_t, Book> Books;
extern Books books;

template<class T>
void read(std::map<size_t, T>& inBook, std::istream& istr)
{
	std::string line;
	getline(istr, line);
	while (line != "end")
	{
		std::istringstream istr1(line);
		size_t id;

		istr >> id;
		T Book_(id, istr1);
		inBook[id] = Book_ ;	
	}	    
};

template<typename Key>
void print(Key &idx, std::ostream& ostr)
{
};

template<>
void print<std::map<size_t, Book>*>(std::map<size_t, Book>* & _books, std::ostream& ostr)
{
};

template<typename Key>
void borrow(Key &idx, std::string& _borrower)
{
};

template<typename Key>
void borrow(Key &idx)
{	
};

#endif
