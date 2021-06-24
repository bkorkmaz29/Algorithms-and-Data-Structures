#include <iostream>
#include <vector>

using namespace std;

vector<int> swap(vector<int>, int, int);
vector<int> insertionSort(vector<int>);

vector<int> swap(int i, int j, vector<int> array)
{
    if (i <= 1)
        return array;

    int temp = array[j];
    array[j] = array[i];
    array[i] = temp;

    if (array[i] < array[i-1])
        swap(array[i-1], array[i], array);
    else
        return array;
}

vector<int> insertionSort(vector<int> array)
{
    for (int i; i < array.size() - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            swap(i, i + 1, array);
        }
    }
}