
#include <string>
#include <iostream>
#include "Sequence.h"
#include "Produce.h"


using namespace std;

int main()
{

    //Testing with 2 sequences with equal number of elements
{


    Sequence<int, std::string> sequence1;
    sequence1.PushBack(1, "1");
    sequence1.PushBack(2, "2");
    sequence1.PushBack(3, "3");
    sequence1.PushBack(4, "4");
    sequence1.PushBack(5, "5");
    sequence1.PushBack(6, "6");
    sequence1.PushBack(7, "7");
    sequence1.PushBack(8, "8");
    sequence1.PushBack(9, "9");
    sequence1.PushBack(10, "10");

    sequence1.PrintAll();
    std::cout << endl;

    Sequence<int, std::string> sequence2;
    sequence2.PushBack(1, "a");
    sequence2.PushBack(2, "b");
    sequence2.PushBack(3, "c");
    sequence2.PushBack(4, "d");
    sequence2.PushBack(5, "e");
    sequence2.PushBack(6, "f");
    sequence2.PushBack(7, "g");
    sequence2.PushBack(8, "h");
    sequence2.PushBack(9, "i");
    sequence2.PushBack(10, "j");

    sequence2.PrintAll();
    std::cout << endl;

    // testing for invalid parameters - commented out for further testing

    /*
    std::cout <<"------------------------------------Test----------------------------------------"<< endl;
    std::cout <<"Invalid length "<< endl<<endl;
    std::cout <<"seq1 = 10, seq2 = 10, start1 = 0, len1 = 12,start2 = 0, len2 = 19, limit = 10, expected chunks = 0 "<< endl<<endl;
    Sequence<int, std::string> produced5 = Produce(sequence1, 0, 12, sequence2, 0, 19,10);
    produced5.PrintAll();

    std::cout <<"------------------------------------Test----------------------------------------"<< endl;
    std::cout <<"Invalid starting point "<< endl<<endl;
    std::cout <<"seq1 = 10, seq2 = 10, start1 = 11, len1 = 1,start2 = 0, len2 = 8, limit = 10, expected chunks = 0 "<< endl<<endl;
    Sequence<int, std::string> produced6 = Produce(sequence1, 11, 1, sequence2, 0, 8,10);
    produced6.PrintAll();

    std::cout <<"------------------------------------Test----------------------------------------"<< endl;
    std::cout <<"Invalid limit "<< endl<<endl;
    std::cout <<"seq1 = 10, seq2 = 10, start1 = 4, len1 = 3,start2 = 1, len2 = 3, limit = 0, expected chunks = 0 "<< endl<<endl;
    Sequence<int, std::string> produced7 = Produce(sequence1, 2, 3, sequence2, 1, 2,0);
    produced7.PrintAll();
*/

    std::cout <<"------------------------------------Test 1----------------------------------------"<< endl;
    std::cout <<"Testing if function stops when first sequence finished"<< endl<<endl;
    std::cout <<"seq1 = 10, seq2 = 10, start1 = 5, len1 = 3,start2 = 0, len2 = 1, limit = 6, expected chunks = 1"<< endl<<endl;
    Sequence<int, std::string> produced1 = Produce(sequence1, 5, 3, sequence2, 0, 1,6);
    produced1.PrintAll();

    std::cout <<"------------------------------------Test 2----------------------------------------"<< endl;
    std::cout <<"Testing if function stops when second sequence finished"<< endl<<endl;
    std::cout <<"seq1 = 10, seq2 = 10, start1 = 2, len1 = 2,start2 = 1, len2 = 4, limit = 4, expected chunks = 2"<< endl<<endl;
    Sequence<int, std::string> produced2 = Produce(sequence1, 2, 2, sequence2, 1, 4,4);
    produced2.PrintAll();

    std::cout <<"------------------------------------Test 3----------------------------------------"<< endl;
    std::cout <<"Testing if function stops after reaching the limit "<< endl<<endl;
    std::cout <<"seq1 = 10, seq2 = 10, start1 = 1, len1 = 1,start2 = 0, len2 = 2, limit = 4, expected chunks = 4 "<< endl<<endl;
    Sequence<int, std::string> produced3 = Produce(sequence1, 1, 1, sequence2, 0, 2,4);
    produced3.PrintAll();

    std::cout <<"------------------------------------Test 4----------------------------------------"<< endl;
    std::cout <<"Testing if function works when number of expected chunks are same as limit"<< endl<<endl;
    std::cout <<"seq1 = 10, seq2 = 10, start1 = 3, len1 = 2,start2 = 2, len2 = 3, limit = 2, expected chunks = 2 "<< endl<<endl;
    Sequence<int, std::string> produced4 = Produce(sequence1, 3, 2, sequence2, 2, 3, 2);
    produced4.PrintAll();


    std::cout <<"------------------------------------Test 5----------------------------------------"<<endl;
    std::cout <<"Random Scenario"<< endl<<endl;
    std::cout <<"seq1 = 10, seq2 = 10, start1 = 0, len1 = 1,start2 = 0, len2 = 1, limit = 30, expected chunks = 10"<< endl<<endl;
    Sequence<int, std::string> produced5 = Produce(sequence1, 0, 1, sequence2, 0, 1, 30)  ;
    produced5.PrintAll();

}



{
    std::cout<<endl<<"---------------------------------Second Phase---------------------------"<<endl;
    std::cout<<"Testing with 2 Sequences with uneven number of elements"<<endl;

    Sequence<int, std::string> sequence1;
    sequence1.PushBack(1, "1");
    sequence1.PushBack(2, "2");
    sequence1.PushBack(3, "3");
    sequence1.PushBack(4, "4");
    sequence1.PushBack(5, "5");


    sequence1.PrintAll();
    std::cout << endl;

    Sequence<int, std::string> sequence2;
    sequence2.PushBack(1, "a");
    sequence2.PushBack(2, "b");
    sequence2.PushBack(3, "c");
    sequence2.PushBack(4, "d");
    sequence2.PushBack(5, "e");
    sequence2.PushBack(6, "f");
    sequence2.PushBack(7, "g");
    sequence2.PushBack(8, "h");


    sequence2.PrintAll();
    std::cout << endl;

    std::cout <<"------------------------------------Test 1----------------------------------------"<< endl;
    std::cout <<"Testing if function stops when first sequence finished"<< endl<<endl;
    std::cout <<"seq1 = 5, seq2 = 8, start1 = 0, len1 = 2,start2 = 4, len2 = 1, limit = 6, expected chunks = 2"<< endl<<endl;
    Sequence<int, std::string> produced1 = Produce(sequence1, 0, 2, sequence2, 4, 1,6);
    produced1.PrintAll();

    std::cout <<"------------------------------------Test 2----------------------------------------"<< endl;
    std::cout <<"Testing if function stops when second sequence finished"<< endl<<endl;
    std::cout <<"seq1 = 5, seq2 = 8, start1 = 0, len1 = 1,start2 = 3, len2 = 2, limit = 4, expected chunks = 3"<< endl<<endl;
    Sequence<int, std::string> produced2 = Produce(sequence1, 0, 1, sequence2, 1, 2,4);
    produced2.PrintAll();

    std::cout <<"------------------------------------Test 3----------------------------------------"<< endl;
    std::cout <<"Testing if function stops after reaching the limit "<< endl<<endl;
    std::cout <<"seq1 = 5, seq2 = 8, start1 = 0, len1 = 1,start2 = 1, len2 = 1, limit = 3, expected chunks = 3 "<< endl<<endl;
    Sequence<int, std::string> produced3 = Produce(sequence1, 0, 1, sequence2, 1, 1,3);
    produced3.PrintAll();

    std::cout <<"------------------------------------Test 4----------------------------------------"<< endl;
    std::cout <<"Testing if function works when number of expected chunks are same as limit"<< endl<<endl;
    std::cout <<"seq1 = 5, seq2 = 8, start1 = 0, len1 = 2,start2 = 2, len2 = 3, limit = 2, expected chunks = 2 "<< endl<<endl;
    Sequence<int, std::string> produced4 = Produce(sequence1, 0, 1, sequence2, 0, 3, 2);
    produced4.PrintAll();


    std::cout <<"------------------------------------Test 5----------------------------------------"<<endl;
    std::cout <<"Random Scenario"<< endl<<endl;
    std::cout <<"seq1 = 5, seq2 = 8, start1 = 0, len1 = 1,start2 = 0, len2 = 1, limit = 30, expected chunks = 5"<< endl<<endl;
    Sequence<int, std::string> produced5 = Produce(sequence1, 0, 1, sequence2, 0, 1, 30)  ;
    produced5.PrintAll();



}


    return 0;
}
