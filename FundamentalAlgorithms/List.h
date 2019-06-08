#pragma once
#include <stdexcept>
#include <iterator>
#include <iostream>

template<class T>
class ListIterator : public std::iterator<std::input_iterator_tag, T>
{
private:
	T* current;

public:
	ListIterator(T* position)
	{
		current = position;
	}

	ListIterator& operator=(const ListIterator& iterator)
	{
		this->current = iterator.current;
		return *this;
	}

	bool operator!=(const ListIterator& iterator)
	{
		return this->current != iterator.current;
	}

	bool operator==(const ListIterator& iterator)
	{
		return this->current == iterator.current;
	}

	ListIterator& operator++()
	{
		current++;
		return *this;
	}

	ListIterator operator++(int)
	{
		ListIterator tmp = *this;
		current++;
		return tmp;
	}

	T& operator*()
	{
		return *current;
	}
};

template<class T>
class List
{
private:
	T* data;
	int capacity;
	int count;

public:
	typedef ListIterator<T> iterator;

	List(int initialCapacity) :capacity(initialCapacity), count(0)
	{
		data = new T[initialCapacity];
	}

	~List()
	{
		delete[] data;
	}

	iterator begin() const { return iterator(&(data[0])); }
	iterator end() const { return iterator(&(data[count])); }

	int Count() const { return count; }

	void Add(const T& item)
	{
		data[count] = item;
		count++;

		//if ()
	}
};