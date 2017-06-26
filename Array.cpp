// Array.cpp : Defines the entry point for the console application.
//

#include "Array.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;
Array::Array( Array &arr)
{
	size = arr.getSize();
	ptr = new int[size];
	for (int i = 0; i < size; ++i)
		ptr[i] = arr.ptr[i];
}
Array::Array(int s) {
	size = s;
	ptr = new int[size];
	for (int i = 0; i < size; ++i)
		ptr[i] = 0;
}
Array::Array() {
	size = 10;
	ptr = new int[10];
	for (int i = 0; i < size; ++i)
		ptr[i] = 0;
}
int Array::getSize(void) {
	return size;
}

Array & Array::operator=(Array &arr)
{
	(*this).size = arr.getSize();
	for (int i = 0; i < (*this).size; ++i)
		(*this).ptr[i] = arr.ptr[i];
	return *this;

}

Array & Array::operator+(Array &rhs)
{
	int arraySize = (*this).getSize();
	int *arr = new int[arraySize];
	for (size_t i = 0; i < arraySize; ++i) {
		arr[i] = (*this).ptr[i];
	}
	delete ptr;
	this->size = arraySize + rhs.getSize();
	(*this).ptr = new int[size];
	for (size_t i = 0; i < arraySize;++i) {
		(*this).ptr[i] = arr[i];
	}
	int k = 0;
	for (size_t i = arraySize; i < this->size; ++i) {
		(*this).ptr[i] = rhs.ptr[k];
		++k;
	}
	delete arr;
	return *this;
}

int & Array::operator[](size_t n)
{
	if (n < this->getSize())
		return this->ptr[n];
	else
		throw out_of_range("Array subscript out of range.");
}

ostream & operator<<(ostream &output, Array &array)
{
	for (int i = 0; i < array.getSize(); ++i)
		output << array.ptr[i] << " ";
	return output;
}

istream &operator>>( istream &input, Array &array)
{
	int elem;
	int size = array.getSize();
	for (int i = 0; i < size; ++i) {
		input >> array.ptr[i];
	}
	return input;
}

bool operator==( Array &arr1,  Array &arr2)
{
	if (arr1.getSize() == arr2.getSize()) {
		for (int i = 0; i < arr1.getSize(); ++i)
			if (arr1.ptr[i] != arr2.ptr[i])
				return false;
		return true;
	}
	else
		return false;
}

bool operator!=(Array &arr1, Array &arr2)
{
	if (arr1.getSize() != arr2.getSize())
		return true;
	else
		for (int i = 0; i < arr1.getSize(); ++i) {
			if (arr1.ptr[i] != arr2.ptr[i])
				return true;
			return false;
		}
}