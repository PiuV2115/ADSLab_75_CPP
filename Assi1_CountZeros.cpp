#include<iostream>
using namespace std;
int main()
{
    //declaring variables
    int arr[10],size=0,count=0,flag=0;

    //Reading size
    cout<<"Enter array size : ";
    cin>>size;

    //Reading Array
    cout<<"Enter array : ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    //checking Invalid conditions
    for(int i=0;i<size;i++)
    {
        count++;
    }
    //checking Invalids
    if(count==size||count==0)
    {
        cout<<"Invalids";
    }

    //Initialisation
    int low=0;
    int high=size-1;
    int mid=0;

    //starting of binary search
    while(low<=high)
    {
        mid=(low+high)/2;

        //checking for mid=1
        if(arr[mid]==1)
        {
            if(arr[mid+1]==1)
            {
                //traverse again
                low=mid+1;
            }
            else
            {
                cout<<size-mid-1;
                break;
            }
        }

        //either mid =0
        else
        {
            if(arr[mid+1]==0)
            {
                if(arr[mid-1]==0)
                {
                   //traverse again
                   high=mid-1;
                }
                else
                {
                    cout<<size-mid;
                    break;
                }
            }
            else
            {
                cout<<"Invalid";
                break;
            }
        }//end of outer else

    }//end of while

    return 0;
}//end of main
