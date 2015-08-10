#pragma once
#ifndef SIMPLE_LINKED_LIST_H
#define SIMPLE_LINKED_LIST_H

struct Element {
	Element * next;
	int i;
	Element(int);
};

class SimpleLinkedList {
public:
	SimpleLinkedList();
	SimpleLinkedList(int);
	SimpleLinkedList(const SimpleLinkedList &);
	SimpleLinkedList(SimpleLinkedList &&);
	~SimpleLinkedList();
	Element const * getFirst() const;
	void add(int);
	void addLast(int);
	void printAll() const;
	unsigned int getSize() const;
	SimpleLinkedList & operator=(const SimpleLinkedList &);
	SimpleLinkedList & operator=(SimpleLinkedList &&);
	void swap(SimpleLinkedList &);

private:
	Element * first;
	Element * last;
	unsigned int size;
	void unwind();
};

std::ostream & operator<<(std::ostream&, const SimpleLinkedList&);

#endif