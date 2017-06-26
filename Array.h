
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class Array {
	friend ostream &operator<<( ostream &,  Array &);
	friend istream &operator >> ( istream &, Array &);
	friend bool operator==( Array&,  Array&);
	friend bool operator!=(Array&, Array&);	
private:
	int size;
	int *ptr;
public:
	Array( Array&);
	Array(int);
	Array();
	int getSize();
	Array &operator=(Array&);
	Array &operator+(Array &);
	int &operator[](size_t n);
};

#endif //ARRAY_H
