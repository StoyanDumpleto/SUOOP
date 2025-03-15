#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <map>
#include <string>
#include <sstream>


typedef std::map<size_t, Book> Books;
extern Books books;

template<class T>
void read(std::map<size_t, T>& inBook, std::istream& is)
{
	while (true)
	{
		std::string id;
		getline(is, id);
		if (id == "end")
			break;
		std::istringstream istr(id);
		size_t idx;
		istr >> idx;
		std::string author;
		std::string title;
		getline(is, author);
		getline(is, title);
		std::istringstream temp(author + "\n" + title);
		inBook[idx] = Book(idx, temp);
		auto itr = inBook.find(idx);
		itr->second.setBorrowed("available");
	}
}

template<typename TBook>
void print( TBook & book, std::ostream& ostr)
{
	std::string status = book.getBorrower();
	ostr << "book "  << book.getId() << " \"" << book.getTitle() << "\"" << " by \"" 
	     << book.getAuthor() << "\" " << "is \"" << status << "\"" << endl;
};

template<typename Т>
void print(std::map<size_t, Book>* _books, std::ostream& ostr)
{
	ostr << "-----" << endl;
	ostr << "total books: " << _books->size() << endl;
	for (auto itr = _books->begin(); itr != _books->end(); ++itr)
	{
		ostr << "book " << itr->first << " \"" << itr->second.getTitle() << "\"" << " by \""
			<< itr->second.getAuthor() << "\" " << "is \"" << itr->second.getBorrower() << "\"" << endl;
	}
}; 

template<typename TBook>
void borrow(TBook& book, std::string& _borrower)
{
	std::string status = "borrowed by " + _borrower;
	book.setBorrowed(status);
	cout << "book " << book.getId() << " \"" << book.getTitle() << "\"" << " by" << " \""
		 << book.getAuthor() << "\" " << "is \"" << status << "\"" << endl;
};

template<typename TBook>
void borrow(TBook& book)
{
	std::string status = "available";
	book.setBorrowed(status);
	cout << "book " << book.getId() << " \"" << book.getTitle() << "\"" << " by \""
		 << book.getAuthor() << "\" " << "is \"" << status << "\"" << endl;
};

#endif


