// Exercise 5 from Chapter 9 of the book
// Programming Principles and Practice Using C++

// Goal: Design and implement a Book class

// Book should have:

// Data Members:
// ISBN (International Standard Book Number)
// Title
// Author
// Copyright date
// Checked out or not?

// Member Functions:
// For returning those values
// For checking the book in and out
// ---------------------------------------------------------------------------
#include "../../std_lib_facilities.h"

// Define class Invalid for throwng exceptions
class Invalid {};


class Book{
public:
    // Constructor
    Book(string author, string title, string isbn, string date);

    // non-modifying member functions
    string author() const { return _author; }
    string title() const { return _title; }
    string isbn() const { return _isbn; }
    string copyr_date() const { return _copyright_date; }

private:
    string _author;
    string _title;
    string _isbn;
    string _copyright_date;
};

// helper functions

// function reads digits until finding something other than
// a digit

int check_digits(int i, const string& isbn)
{
    if(! isdigit(isbn[i])) error("expected an integer");

    ++i;

    while(i<isbn.length())
    {
        // not a digit, return the character position
        if(!isdigit(isbn[i])) return i;
        ++i;   
    }
    error("Format error: no '-' found");
    return i;
}

// check wether a given string has the following format:
// n-n-n-x
// where n is an integer and x is either a digit or a letter
bool isbn_valid(string isbn)
{
    try{
        int i,j = 0;
        // why 3...?
        while(j<3)
        {
            i = check_digits(i, isbn);
            if(isbn[i] != '-') error("ISBN format error, expected a '-' ");
            ++j;
        }

        // check that x is a digit or a letter
        // and is the last character of the string
        if(! (isalpha(isbn[i] && i == isbn.length()))) return false;
    }
    catch(exception& e){
        return false;
    }

    return true;
}

bool is_book(string author, string title, string isbn, string date)
{
    // function checks that book is valid
    if(author.length() < 1) return false;

    if(title.length() < 1) return false;

    if(date.length() < 1) return false;

    if(!isbn_valid(isbn)) return false;

    return true;
}

Book::Book(string author, string title, string isbn, string date)
    : _author{author}, _title{title}, _isbn{isbn}, _copyright_date{date}
{
    if(!is_book(author, title, isbn, date))
        throw Invalid{};
}

int main()
{
    return 1;
}
