#include<iostream>
using namespace std;

int MaxProfit(int arr[10],int size)
{
   int i=0,Profit=0;
    while(i<size)
    {
        int BuySum=0,count=0,max=-1,idx=0;
        for(int j=i;j<size;j++)
        {
            if(max<=arr[j])
            {
                idx=j;
                max=arr[j];
            }
            else
            {
                continue;
            }
        } //give us max 
        
        if(idx!=i)
        {
            for(int k=i;k<max;k++)
            {
                count++;
                BuySum+=arr[k];
            }
            Profit+=((arr[max]*count)-BuySum);
            i=idx+1;
        }
        else
        {
            i++; //if maximum stock is at first then , hold the element
        }
    }
    if(Profit==0)
    {
        cout<<"No Profit generated ! ";
    }
    else
    {
        cout<<"Maximum Profit Generated is : "<<Profit;
    }
    
    return 0;
}

int main()
{
    int n,arr[10];
    cout<<"Enter no. of Stocks : ";
    cin>>n;
    cout<<"Enter Stocks Prices : ";
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"] : ";
        cin>>arr[i];
        cout<<"\n";
    }
    
    MaxProfit(arr,n);
    
    return 0;
}
