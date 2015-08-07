#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

int main() {
	SimpleLinkedList sll(1);
	sll.add(13);
	sll.add(1313);
	sll.addLast(1234);

	cout << "Original List:" << endl;
	sll.printAll();
	cout << "Original Size: " << sll.getSize() << endl;

	SimpleLinkedList copied = sll;
	copied.add(2999);
	cout << "Copied via Copy Constructor" << endl;
	copied.printAll();
	cout << "Copied Size: " << copied.getSize() << endl;

	SimpleLinkedList assignment;
	assignment = sll;
	assignment.add(5000);
	cout << "Copied via Assignment Operator:" << endl;
	assignment.printAll();
	cout << "Assignment Size: " << assignment.getSize() << endl;
	
	SimpleLinkedList empty = SimpleLinkedList();
	SimpleLinkedList emptyCopy1 = SimpleLinkedList(empty);
	SimpleLinkedList emptyCopy3 = empty;
	SimpleLinkedList emptyCopy17 = SimpleLinkedList(empty);
	empty.addLast(3);
	empty.printAll();
	emptyCopy1.printAll();
	emptyCopy3.printAll();
	emptyCopy17 = emptyCopy3;
	empty = empty; //self assignment test
	empty.printAll();

	return 0;

}