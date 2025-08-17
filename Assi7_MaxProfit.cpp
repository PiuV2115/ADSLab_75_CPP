#include<iostream>
using namespace std;

int MaxProfit(int arr[10],int size)
{
   int i=0,Profit=0;
    while(i<size)
    {
        int BuySum=0,count=0,max=-1,maxidx=0;
        for(int j=i;j<size;j++)
        {
            if(max<=arr[j])
            {
                maxidx=j;
                max=arr[j];
            }
            else
            {
                continue;
            }
        } //give us max 
        
        if(maxidx!=i)
        {
            for(int k=i;k<maxidx;k++)
            {
                count++;
                BuySum+=arr[k];
            }
            int result=(arr[maxidx]*count)-BuySum;
            Profit+=result;
            i=maxidx+1;
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
    cout<<"Enter Stocks Prices : \n";
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"] : ";
        cin>>arr[i];
        cout<<"\n";
    }
    
    MaxProfit(arr,n);
    
    return 0;
}
