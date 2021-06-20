#include <iostream>

using namespace std;

int main()
{
    //creating a initial ring for tests
    Ring<int, int> ring1;


    std::cout<<endl<<endl<<"********************************Part 1**********************************"<<endl;

    std::cout <<endl<<"------------------------------------Test 1.1----------------------------------------"<< endl;
    std::cout <<"Testing RemoveAll function on a empty ring"<< endl<<endl;
    ring1.RemoveAll();
    ring1.Print();

    std::cout <<endl<<"------------------------------------Test 1.2----------------------------------------"<< endl;
    std::cout <<"Testing RemoveNode function on a empty ring - trying to remove 2"<< endl<<endl;
    ring1.RemoveNode(2,2);
    ring1.Print();


    std::cout <<endl<<"------------------------------------Test 1.3----------------------------------------"<< endl;
    std::cout <<"Testing PushFront function on a empty ring - 1 pushed front "<< endl<<endl;
    ring1.PushFront(1,1);
    ring1.Print();
    ring1.RemoveAll();

    std::cout <<endl<<"------------------------------------Test 1.4----------------------------------------"<< endl;
    std::cout <<"Testing PushBack function on a empty ring - 1 pushed back"<< endl<<endl;
    ring1.PushBack(1,1);
    ring1.Print();
    ring1.RemoveAll();


     std::cout <<endl<<"------------------------------------Test 1.5----------------------------------------"<< endl;
    std::cout <<"Testing PushAfter function on a empty ring - trying to push 1 after 5"<< endl<<endl;
    ring1.PushAfter(1,1,5,1);
    ring1.Print();
    ring1.RemoveAll();



    std::cout <<endl<<"------------------------------------Test 1.6----------------------------------------"<< endl;
    std::cout <<"Testing PushBack function on a single node ring - 2 pushed back  "<< endl<<endl;
    ring1.PushBack(1,1);
    ring1.PushBack(2,2);
    ring1.Print();
    ring1.RemoveAll();




    std::cout <<endl<<"------------------------------------Test 1.7----------------------------------------"<< endl;
    std::cout <<"Testing PushFront function on a single node ring - 2 pushed front"<< endl<<endl;
    ring1.PushBack(1,1);
    ring1.PushFront(2,2);
    ring1.Print();
    ring1.RemoveAll();

    std::cout <<endl<<"------------------------------------Test 1.8----------------------------------------"<< endl;
    std::cout <<"Testing PushAfter function on a single node ring - 2 pushed after 1"<< endl<<endl;
    ring1.PushBack(1,1);
    ring1.PushAfter(2,2,1,1);
    ring1.Print();
    ring1.RemoveAll();



    std::cout <<endl<<"------------------------------------Test 1.9----------------------------------------"<< endl;
    std::cout <<"Testing remove function for single node ring - 1 added then removed"<< endl<<endl;
    ring1.PushBack(1,1);
    ring1.RemoveNode(1,1);
    ring1.Print();


    std::cout <<endl<<"------------------------------------Test 1.10 ---------------------------------------"<< endl;
    std::cout <<"Testing remove function on a empty ring after removing nodes"<< endl<<endl;
    ring1.RemoveNode(1,1);
    ring1.Print();

    std::cout <<endl<<"------------------------------------Test 1.11 ---------------------------------------"<< endl;
    std::cout <<"Testing remove function for trying to remove a node after same node removed - removing 2 then trying to remove 2"<< endl<<endl;
    ring1.PushBack(1,1);
    ring1.PushBack(2,2);
    ring1.PushBack(3,3);
    ring1.RemoveNode(2,1);
    ring1.RemoveNode(2,1);
    ring1.Print();
    ring1.RemoveAll();





    std::cout<<endl<<endl<<"*****************************************Part 2*************************************************"<<endl;
    std::cout<<endl<<"Creating a 5 node ring for further tests"<<endl<<endl;
    for(int i = 1; i<6; i++){
        ring1.PushBack(i,i);
    }
    ring1.Print();



    std::cout <<endl<<"------------------------------------Test 2.1----------------------------------------"<< endl;
    std::cout <<"Testing remove function for head - removing 1"<< endl<<endl;
    ring1.RemoveNode(1,1);
    ring1.Print();
    ring1.PushFront(1,1);

    std::cout <<endl<<"------------------------------------Test 2.2----------------------------------------"<< endl;
    std::cout <<"Testing remove function for tail - removing 5"<< endl<<endl;
    ring1.RemoveNode(5,1);
    ring1.Print();
    ring1.PushBack(5,5);

    std::cout <<endl<<"------------------------------------Test 2.3----------------------------------------"<< endl;
    std::cout <<"Testing remove function for random node - removing 3"<< endl<<endl;
    ring1.RemoveNode(3,1);
    ring1.Print();
    ring1.PushAfter(3,3,2,1);


    std::cout <<endl<<"------------------------------------Test 2.4----------------------------------------"<< endl;
    std::cout <<"Testing PushAfter function - pushing 6 after 3 "<< endl<<endl;
    ring1.PushAfter(6,6,3,1);
    ring1.Print();
    ring1.RemoveNode(6,1);

    std::cout <<endl<<"------------------------------------Test 2.5----------------------------------------"<< endl;
    std::cout <<"Testing PushAfter function - pushing 6 after tail "<< endl<<endl;
    ring1.PushAfter(6,6,5,1);
    ring1.Print();
    ring1.RemoveNode(6,1);


    std::cout<<endl<<endl<<"**************************************** Part 3 *******************************************"<<endl;
    std::cout<<endl<<"Adding 10 nodes to the ring with same keys as before further tests"<<endl<<endl;
    for(int i = 1; i<6; i++){
        ring1.PushBack(i,i);
    }

     for(int i = 1; i<6; i++){
        ring1.PushBack(i,i);
    }
    ring1.Print();

    std::cout <<endl<<"------------------------------------Test 3.1----------------------------------------"<< endl;
    std::cout <<"Testing remove function for further occurrences - removing second 4"<< endl<<endl;
    ring1.RemoveNode(4,2);
    ring1.Print();

    std::cout <<endl<<"------------------------------------Test 3.2----------------------------------------"<< endl;
    std::cout <<"Testing remove function for occurrence changes - after 2nd 4 removed trying to remove third 4 (which is now 2nd)"<< endl<<endl;
    ring1.RemoveNode(4,3);
    ring1.Print();

    std::cout <<endl<<"------------------------------------Test 3.3----------------------------------------"<< endl;
    std::cout <<"Testing remove function for further occurrences - removing third 5 "<< endl<<endl;
    ring1.RemoveNode(5,3);
    ring1.Print();


    std::cout <<endl<<"------------------------------------Test 3.4----------------------------------------"<< endl;
    std::cout <<"Testing PushAfter function for 2nd occurrence - pushing 4 again after second 3 "<< endl<<endl;
    ring1.PushAfter(4,4,3,2);
    ring1.Print();



    std::cout <<endl<<"------------------------------------Test 3.5----------------------------------------"<< endl;
    std::cout <<"Testing PushAfter function for 3rd occurrence - pushing 5 again after third 4 "<< endl<<endl;
    ring1.PushAfter(5,5,4,3);
    ring1.Print();


    return 0;
}