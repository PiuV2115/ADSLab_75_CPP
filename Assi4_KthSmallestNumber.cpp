/*
Problem Title  : Kth Smallest Number

Statement : Given two sorted arrays arr1 and arr2, your task is to merge them into a single sorted array and 
find the K-th smallest element from the merged array using binary search instead of linear traversal.

*/

#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &arr1, vector<int> &arr2, int key)
{
    vector<int> temp;
    int i = 0, j = 0;

    // Merge two sorted arrays
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
            temp.push_back(arr1[i++]);
        else
            temp.push_back(arr2[j++]);
    }

    while (i < arr1.size())
        temp.push_back(arr1[i++]);

    while (j < arr2.size())
        temp.push_back(arr2[j++]);

    // Use binary search to find kth smallest
    int left = 0, right = temp.size() - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mid == key - 1)
        {
            result = temp[mid];
            break;
        }
        else if (mid < key - 1)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (result != -1)
        cout << key << "th Smallest Element is : " << result << endl;
    else
        cout << "Invalid key" << endl;
}

int main()
{
    int key;
    vector<int> a1 = {4, 5, 6};
    vector<int> a2 = {1, 2, 3};

    cout << "Kth smallest to find : ";
    cin >> key;

    if (key <= 0 || key > a1.size() + a2.size())
    {
        cout << "Invalid Input" << endl;
        return 0;
    }

    Merge(a1, a2, key);

    return 0;
}

/*
Input :
arr1 = [4, 5, 6]
arr2 = [1, 2, 3]
K = 4

output:
4th Smallest Element is : 4

*/
