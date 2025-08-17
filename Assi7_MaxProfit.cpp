/*
PROBLEM STATMENT : 
You are given an array representing the stock prices for a certain number of days.
Your task is to determine the maximum profit you can earn by buying stocks on multiple days before a chosen "selling day" (which must be the day with the maximum price in the remaining range).
You can buy 1 stock per day at the given day's price.
On the "selling day" (which is the maximum price day in the remaining days), you can sell all the stocks bought so far.
Repeat this until you traverse all days.
If no profit can be generated, print "No Profit generated !".
*/

#include<iostream>
using namespace std;

// Function to calculate maximum profit
int MaxProfit(int arr[10], int size)
{
    int i = 0, Profit = 0;

    // Loop through all stock days
    while (i < size)
    {
        int BuySum = 0, count = 0, maxPrice = -1, maxIdx = 0;

        // Step 1: Find the maximum price (selling day) in the remaining array
        for (int j = i; j < size; j++)
        {
            if (maxPrice <= arr[j])   // keep updating max
            {
                maxIdx = j;           // store index of maximum price
                maxPrice = arr[j];
            }
        }

        // Step 2: If maximum is not at the first position,
        // we can buy stocks before that and sell on max day
        if (maxIdx != i)
        {
            for (int k = i; k < maxIdx; k++)
            {
                count++;              // count how many stocks we bought
                BuySum += arr[k];     // sum of buying prices
            }

            // Selling all bought stocks at max price
            int result = (arr[maxIdx] * count) - BuySum;
            Profit += result;

            // Move to the next day after selling
            i = maxIdx + 1;
        }
        else
        {
            // If maximum stock is at the current day, skip it
            i++;
        }
    }

    // Step 3: Print result
    if (Profit == 0)
    {
        cout << "No Profit generated !";
    }
    else
    {
        cout << "Maximum Profit Generated is : " << Profit;
    }

    return 0;
}

// Main Function
int main()
{
    int n, arr[10];

    cout << "Enter no. of Stocks : ";
    cin >> n;

    cout << "Enter Stock Prices : \n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "] : ";
        cin >> arr[i];
        cout << "\n";
    }

    MaxProfit(arr, n);

    return 0;
}

/*
SAMPLE OUTPUT :

Enter no. of Stocks : 5
Enter Stocks Prices :
1] : 3

2] : 4

3] : 5

4] : 1

5] : 2

Maximum Profit Generated is : 4
*/
