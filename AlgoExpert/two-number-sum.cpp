#include <iostream>
#include <vector>
#include <unordered_map>

int numbers[] = {2, 5, -3, 6, 11, 4, -6, 7, 9};

int target = 3;
std::vector<int> solution(int *);
/*  This works but too slow ---> O(n^2)

int *ptr1, *ptr2 = nums;
int solution(int, int);
int solution(int i, int j){
   while (i) {
        while(j){
            if((((i + j) == target) && ( i != j))) {
                return std::vector<int> {i, j};
            }
            else
              j++;
        }
        i++;
    }
    std::cout<<"No existing solution"<<std::endl;
    return 0;
}
*/

// Better approach ---> O(n)

std::vector<int> solution(int *x)
{
    std::vector<int> v(x, x + sizeof x / sizeof x[0]);
    std::unordered_map<int, int> imap;

    for (int i = 0;; ++i)
    {
        auto it = imap.find(target - x[i]);

        if (it != imap.end())
        {
            return std::vector<int>{i, it->second};
        }
        imap[x[i]] = i;
    }
}
