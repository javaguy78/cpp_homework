#pragma once
#ifndef SIMPLE_LINKED_LIST_H
#define SIMPLE_LINKED_LIST_H

template<typename T>
struct Element {
	Element * next;
	T data;
	Element(T t) : next{ nullptr } {
		data = t;
	}
};

class SimpleLinkedList {
public:
	SimpleLinkedList();
	SimpleLinkedList(int);
	SimpleLinkedList(const SimpleLinkedList &);
	SimpleLinkedList(SimpleLinkedList &&);
	~SimpleLinkedList();
	Element<int> const * getFirst() const;
	void add(int);
	void addLast(int);
	void printAll() const;
	unsigned int getSize() const;
	SimpleLinkedList & operator=(const SimpleLinkedList &);
	SimpleLinkedList & operator=(SimpleLinkedList &&);
	void swap(SimpleLinkedList &);

private:
	Element<int> * first;
	Element<int> * last;
	unsigned int size;
	void unwind();
};

std::ostream & operator<<(std::ostream&, const SimpleLinkedList&);

#endif