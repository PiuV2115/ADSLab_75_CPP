/*
PROBLEM STATEMENT

You are given n shops, each with a start time (when it opens) and an end time (when it closes).
There are k people available to visit these shops.

# A person can only visit a shop if the shop's start time is greater than or equal to the person's current time.
#Once a person visits a shop, their "current time" becomes the end time of that shop.
#Each shop can be visited only once by at most one person.
#The goal is to maximize the total number of shops visited by all k people.

You need to output the maximum number of shops visited.
*/


#include<iostream>
#include<vector>
using namespace std;

void findMax(int s[10],int e[10],int n,int k)
{
	int visit[10];
	int person=0,count=0;
	int result=0;
	for(int i=0;i<n;i++)
	{
		visit[i]=0;
	}
	
	while(person<k)	//outermost loop for k people
	{
	    int endtime=0;	//starting end time for each peson will be 0 
	    
	    do	//middle loop
	    {
	        count=0; //to terminate do-while loop
	        
	        int min=9999,idx=0;   //to find Minimum
	        
	        for(int i=0;i<n;i++)	//innermost loop
	    	{
	    	    	if(endtime<=s[i]&&visit[i]!=1)	//condition to check constraints
	    	    	{
	    	       	count++;
	    	       	
		    		if(min>s[i])	// to check minimum starting time
			   	{
					idx=i;
					min=s[i];
				}
				else
				{
			        	continue;
				}
	    	    	}  //end of outer if
		
		}	//end of innermost for loop
	
		if(count>0)	//condition to update
		{
			 visit[idx]=1;
		    	 result++;
	              	 endtime=e[idx];
		}
		else
		{
			 break; //else break do-while loop
		}
		
	   }while(1); //end of do-while
	    	
	   person++; //increamenting 
	   
	}//end of outermost while loop
			   
cout<<"Maximum no. of shops Visited by Peoples : "<<result<<"\n"; //returning maximum shops

}//end of find function




int main()
{
	int s[10],e[10],n,k,result=0;
	cout<<"Enter no. of Shops : ";
	cin>>n;
	
	cout<<"Enter no. of Peoples :";
	cin>>k;
	
	cout<<"Enter Starting Times of shops : \n";
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"] ";
		cin>>s[i];
		cout<<endl;
	}
		
		
	cout<<"Enter Ending Times of shops : \n";
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"] ";
		cin>>e[i];
		cout<<endl;
	}

/*
SAMPLE INPUT AND OUTPUT

Enter no. of Shops : 5
Enter no. of Peoples : 2
Enter Starting Times of shops :
1] 1
2] 3
3] 0
4] 5
5] 8

Enter Ending Times of shops :
1] 2
2] 4
3] 6
4] 7
5] 9

Maximum no. of shops Visited by Peoples : 4

*/
		
	findMax(s,e,n,k);
	
	return 0;
	
}
