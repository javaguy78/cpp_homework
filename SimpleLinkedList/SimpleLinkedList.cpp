#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

SimpleLinkedList::SimpleLinkedList() :
	first{ nullptr },
	last{ nullptr },
	size{ 0u } { }

SimpleLinkedList::SimpleLinkedList(int i) : SimpleLinkedList() {
	last = first = new Element(i);
	++size;
}

SimpleLinkedList::SimpleLinkedList(const SimpleLinkedList & in) : SimpleLinkedList() {
	if (in.first != nullptr) {
		first = new Element(in.first->i);
		Element * tmpLocal = first;
		Element * tmpCopy = in.first;
		while (tmpCopy->next != nullptr) {
			tmpCopy = tmpCopy->next;
			tmpLocal->next = new Element(tmpCopy->i);
			tmpLocal = tmpLocal->next;
			last = tmpLocal;
			++size;
		}
	}
}

SimpleLinkedList::SimpleLinkedList(SimpleLinkedList && in) {
	first = in.first;
	last = in.last;
	size = in.size;

	in.first = nullptr;
	in.last = nullptr;
	in.size = 0;
}

SimpleLinkedList::~SimpleLinkedList() {
	Element * tmp = first;
	while (tmp != 0) {
		first = first->next;
		delete tmp;
		tmp = first;
	}
}

void SimpleLinkedList::add(int i) {
	addLast(i);
}

void SimpleLinkedList::addLast(int i) {
	if (!first) {
		last = first = new Element(i);
	} else {
		last->next = new Element(i);
		last = last->next;
		++size;
	}
}

unsigned int SimpleLinkedList::getSize() const {
	return size;
}

Element * SimpleLinkedList::getFirst() const {
	return this->first;
}

void SimpleLinkedList::printAll() const {
	cout << *this << endl;
}

SimpleLinkedList & SimpleLinkedList::operator=(const SimpleLinkedList & in) {
	if (this != &in) {
		SimpleLinkedList(in).swap(*this);
	}
	return *this;
}

SimpleLinkedList & SimpleLinkedList::operator=(SimpleLinkedList && in) {
	using std::move;
	first = move(in.first);
	last = move(in.last);
	size = move(in.size);
	return *this;
}

std::ostream & operator<<(std::ostream& out, const SimpleLinkedList & sll) {
	Element * tmp = sll.getFirst();
	out << "{";
	while (tmp != nullptr) {
		out << tmp->i;
		if (tmp->next != nullptr) {
			out << ",";
		}
		tmp = tmp->next;
	};
	out << "}";
	return out;
}

void SimpleLinkedList::swap(SimpleLinkedList & in) {
	using  std::swap;
	swap(this->first, in.first);
	swap(this->last, in.last);
	swap(this->size, in.size);
}

Element::Element(int i) {
	this->i = i;
	this->next = nullptr;
}