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
	Element * getFirst();
	void add(int);
	void addLast(int);
	void printAll();
	unsigned int getSize();
	SimpleLinkedList & operator=(const SimpleLinkedList &);
	SimpleLinkedList & operator=(SimpleLinkedList &&);
	void swap(SimpleLinkedList &);

private:
	Element * first;
	Element * last;
	unsigned int size;
};

#endif