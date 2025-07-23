#include <iostream>
using namespace std;

int indx = 0, count = 0, answer[20];

void merge(int nums[], int low, int high)
{

    for (int i = low; i < high + 1; i++)
    {
        if (nums[i] == 0)
        {
            int j = i;
            while (j < high)
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                j++;
            }
        }
    }
}

void divide(int nums[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (high + low) / 2;

    divide(nums, low, mid);
    divide(nums, mid + 1, high);
    merge(nums, low, high);
}

int main()
{
    int nums[20], choice = 1, ans;
    int i = 0, size;
    bool flag = false;
    cout << "Enter Array Size : ";
    cin >> size;

    while (i <= size)
    {
        cout << "Enter array[ " << i << " ] (Enter 2 to exit):: ";
        cin >> choice;
        cout << endl;
        nums[i] = choice;
        i++;
    }

    divide(nums, 0, size - 1);
    cout << "Rearranged Array :: [ ";
    for (int j = 0; j < size; j++)
    {
        cout << nums[j] << "  ,";
    }
    cout << " ]" << endl;

    return 0;
}
