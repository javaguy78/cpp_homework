#include <iostream>
#include "SimpleLinkedList/SimpleLinkedList.h"

using namespace std;

//SimpleLinkedList<std::string> sll("test");

void testTemplate() {
    SimpleLinkedList<int> intList;
    intList.add(2);
    intList.add(235);
    intList.add(193);

    std::cout << intList << std::endl;

}

//void testNewObject() {
//    sll.add("two");
//    sll.add("three");
//    sll.addLast("djs");
//    sll.addLast("Something new");
//
//    cout << "Original List:" << endl;
//    cout << sll << endl;
//    cout << "Original Size: " << sll.getSize() << endl;
//}

// void testCopiedByCopyConstructor() {
//    SimpleLinkedList copied(sll);
//    copied.add(2999);
//    cout << "Copied via Copy Constructor" << endl;
//    cout << copied << endl;
//    cout << "Copied Size: " << copied.getSize() << endl;
//}

//void testCopiedByAssignmentOperator() {
//    SimpleLinkedList assignment;
//    assignment = sll;
//    assignment.add(5000);
//    cout << "Copied via Assignment Operator:" << endl;
//    cout << assignment << endl;
//    cout << "Assignment Size: " << assignment.getSize() << endl;
//}

//void testAssignmentOfEmptyObjectToNewObject() {
//    SimpleLinkedList empty = SimpleLinkedList();
//    SimpleLinkedList emptyCopy1 = SimpleLinkedList(empty);
//    SimpleLinkedList emptyCopy3 = empty;
//    SimpleLinkedList emptyCopy17 = SimpleLinkedList(empty);
//    empty.addLast(3);
//    cout << empty << endl;
//    cout << emptyCopy1 << endl;
//    cout << emptyCopy3 << endl;
//    emptyCopy17 = emptyCopy3;
//    empty = empty; //self assignment test
//    cout << empty << endl;
//}

//void scratch() {
//    Element<long> longElement(3.12L);
//    Element<float> floatElement(3.14F);
//    Element<std::string> strElement("Awesome String");
//    Element<SimpleLinkedList> sslElement(sll);
// I get it!
//    return;
//}

/////////////////////////////////////////////////////////////////////////
/// PROGRAM ENTRY POINT                                   ///////////////
/////////////////////////////////////////////////////////////////////////

int main() {

    testTemplate();
//    testNewObject();
//    testCopiedByCopyConstructor();
//    testCopiedByAssignmentOperator();
//    testAssignmentOfEmptyObjectToNewObject();

//    scratch();

    return 0;
}
