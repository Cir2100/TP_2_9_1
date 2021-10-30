#pragma once
#include <string>

template <class T>
class MyArray
{
private:
	int size;
	T* data;
	
public:
	MyArray() : size(0), data(nullptr) { /*printBuilder("MyArray");*/ }
	MyArray(const MyArray<T>& myArray);
	~MyArray() { clear(); /*printDeconstuctor("MyArray");*/ }

	void add(const T& obj);
	void add(MyArray<T>& _array);
	void del(int index);
	void clear();
	void sort();
	const int getSize() { return size; }
	T& operator[](int);
	MyArray<T>& operator=(const MyArray<T>& myArray);
};

template <class T>
MyArray<T>::MyArray(const MyArray<T>& myArray) {
	data = new T[myArray.size];
	size = myArray.size;
	for (int i = 0; i < myArray.size; i++)
		data[i] = myArray.data[i];

	/*printCopyBuilder("MyArray");*/
}

template <class T>
T& MyArray<T>::operator[](int index)
{
	std::string err = "Index " + std::to_string(index) + " does not exist";
	if (index < 0 || index >= size)
		throw err;
	return data[index];
}

template <class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& myArray)
{
	if (this == &myArray)
		return *this;
	delete[] data;
	data = new T[myArray.size];
	size = myArray.size;
	for (int i = 0; i < myArray.size; i++)
		data[i] = myArray.data[i];
	return *this;
}

template <class T>
void MyArray<T>::add(const T& obj)
{
	T* tmp = data;
	size++;
	data = new T[size];
	for (int i = 0; i < size - 1; i++)
		data[i] = tmp[i];
	data[size - 1] = obj;
}

template <class T>
void MyArray<T>::add(MyArray<T>& _array) {
	T* tmp = data;
	data = new T[size + _array.getSize()];
	for (int i = 0; i < size; i++)
		data[i] = tmp[i];
	for (int i = 0; i < _array.getSize(); i++)
		data[size + i] = _array.data[i];
	size += _array.getSize();
}

template <class T>
void MyArray<T>::del(int index)
{
	std::string err = "Index " + std::to_string(index) + " does not exist";
	if (index < 0 || index >= size)
		throw err;
	if (size > 1) {
		T* tmp = new T[size - 1];
		int k = 0;
		for (int i = 0; i < size; i++)
			if (i != index)
				tmp[k++] = data[i];
		size--;
		data = tmp;
	}
	else {
		size--;
		data = new T[0];
	}
}

template <class T>
void MyArray<T>::sort() {
	for (int i = 1; i < size; i++)
		for (int j = 0; j < size - i; j++)
			if (data[j] > data[j + 1])
				std::swap(data[j], data[j + 1]);
}

template <class T>
void MyArray<T>::clear() {
	delete[] data;
	data = nullptr;
	size = 0;
}