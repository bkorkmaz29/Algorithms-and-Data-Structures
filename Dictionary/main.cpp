#include <iostream>
#include "Dictionary.h"


using namespace std;

int main()
{
    Dictionary<int, string> dictionary;
     cout<<"*****Part 1 - testing with empty dictionary*****"<<endl<<endl;
     cout<<"----------Test 1.1 - searching a key in a empty dictionary----------"<<endl;

    if(!dictionary.hasKey(2))
        cout<<"Success"<<endl;
    else
        cout<<"Failure"<<endl;

    cout<<"----------Test 1.2 - removing a node from a empty dictionary----------"<<endl;
    dictionary.remove(2);
    cout<<"Success"<<endl;

    cout<<"----------Test 1.3 - searching the info of a node with given key in a empty dictionary----------"<<endl;
    if(!dictionary.find(4))
        cout<<"Success"<<endl;
    else
        cout<<"Failure"<<endl;


    cout<<"----------Test 1.4 -printing a empty dictionary in order, post order and 2d----------"<<endl;
    dictionary.printInorder();
    dictionary.printPostorder();
    dictionary.print2D();

    cout<<"*****Part 2 - testing inserting and balancing*****"<<endl<<endl;

    cout<<"----------Test 2.1 - inserting 1 element (44)----------"<<endl;
    dictionary.insert(44, "forty four");
    dictionary.print2D();


    cout<<"----------Test 2.2 - inserting a 2nd element (11)----------"<<endl;
    dictionary.insert(11, "eleven");
    dictionary.print2D();


    cout<<"----------Test 2.3 - inserting a  3rd element (3)----------"<<endl;
    dictionary.insert(3, "three");
    dictionary.print2D();

    cout<<"----------Test 2.4 - inserting a 4th element (17)----------"<<endl;
    dictionary.insert(17, "seventeen");
    dictionary.print2D();

    cout<<"----------Test 2.5 - inserting a 5th element (1)----------"<<endl;
    dictionary.insert(1, "one");
    dictionary.print2D();

    cout<<"----------Test 2.6 - inserting a 6th element (33)----------"<<endl;
    dictionary.insert(33, "thirty three");
    dictionary.print2D();


    cout<<"----------Test 2.7 - inserting a 7th element (10)----------"<<endl;
    dictionary.insert(10, "ten");
    dictionary.print2D();

    cout<<"----------Test 2.8 - inserting a element with existing key (10)----------"<<endl;
    dictionary.insert(10, "ten");
    dictionary.print2D();

    cout<<"----------Test 2.9 - printing inorder and postorder----------"<<endl;

    cout<<endl<<"In order: ";
    dictionary.printInorder();
    cout<<"Post order: ";
    dictionary.printPostorder();



    cout<<"*****Part 3 - remove function*****"<<endl<<endl;
    cout<<"----------Test 3.1 - removing root (11)----------  "<<endl;
    dictionary.remove(11);
    if(!dictionary.hasKey(11))
        cout<<"Success"<<endl;
    else
        cout<<"Failure"<<endl;

    dictionary.print2D();


    cout<<"----------Test 3.2 - removing an element (10)---------- "<<endl;
   dictionary.remove(3);
    if(!dictionary.hasKey(3))
        cout<<"Success"<<endl;
    else
        cout<<"Failure"<<endl;

    dictionary.print2D();

    cout<<endl<<"----------Test 3.3 - removing every element except one element (1,2,10,33,)---------- "<<endl;
    dictionary.remove(1);
    dictionary.print2D();
    cout<<"-------------------- "<<endl;
    dictionary.remove(33);
    dictionary.print2D();
    cout<<"-------------------- "<<endl;
    dictionary.remove(17);
    dictionary.print2D();
    cout<<"-------------------- "<<endl;
    dictionary.remove(44);
    dictionary.print2D();
    if(!dictionary.hasKey(1) && !dictionary.hasKey(33) && !dictionary.hasKey(17) && !dictionary.hasKey(44))
        cout<<"Success"<<endl;
    else
        cout<<"Failure"<<endl;




    cout<<endl<<"----------Test 3.4 - removing the only element left---------- "<<endl;
    dictionary.remove(10);
     if(!dictionary.hasKey(10))
        cout<<"Success"<<endl;
    else
        cout<<"Failure"<<endl;


    dictionary.printInorder();

    cout<<"*****Part 4 - testing the find function*****"<<endl<<endl;
    cout<<endl<<"******Creating a dictionary for the test********  "<<endl;

    dictionary.insert(3, "three");
    dictionary.insert(88, "eighty eight");
    dictionary.insert(45, "forty five");
    dictionary.insert(64, "sixty four");
    dictionary.insert(35, "thirty five");
    dictionary.insert(2, "two");
    dictionary.print2D();

    cout<<endl<<"----------Test 4.1 - find info of 3---------- "<<endl;
    cout<<*dictionary.find(3)<<endl;

    cout<<endl<<"----------Test 4.2 - find info of 45---------- "<<endl;
    cout<<*dictionary.find(45)<<endl;

    cout<<endl<<"----------Test 4.3 - find info of 35---------- "<<endl;
    cout<<*dictionary.find(35)<<endl;


    cout<<endl<<"----------Test 4.4 - find info of 88---------- "<<endl;
    cout<<*dictionary.find(88)<<endl;

    cout<<endl<<"----------Test 4.5 - try to find info of 3 after it is removed---------- "<<endl;
    dictionary.remove(3);

    if(!dictionary.find(3))
        cout<<"Success"<<endl;
    else
        cout<<"Failure"<<endl;


    cout<<endl<<"----------Test 4.6 - try to find info of 36 which does not exist---------- "<<endl;
    if(!dictionary.find(36))
        cout<<"Success"<<endl;
    else
        cout<<"Failure"<<endl;



    return 0;
}
