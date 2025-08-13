#include<iostream>
#include<vector>
using namespace std;

int find(int s[10],int e[10],int n,int k)
{
	int visit[10];
	int person=0,count=0;
	int result=0;
	for(int i=0;i<n;i++)
	{
		visit[i]=0;
	}
	while(person<k)
	{
	    int endtime=0;
	    do
	    {
	        count=0;
	        int min=9999,idx=0;
	       	for(int i=0;i<n;i++)
	    	{
	    	    if(endtime<=s[i]&&visit[i]!=1)
	    	    {
	    	        count++;
		    	if(min>s[i])
			    {
					idx=i;
					min=s[i];
				}
				else
				{
			        continue;
				}
	    	    }
			}
			if(count>0)
			{
			 visit[idx]=1;
		     result++;
	         endtime=e[idx];
			}
			else
			{
			    break;
			}
	    	}while(1);
	    	 person++;
	    }		   
	   	return result;
	}




int main()
{
	int s[10],e[10],n,k,result;
	cout<<"Enter no. of Shops : ";
	cin>>n;
	
	cout<<"Enter no. of Peoples :";
	cin>>k;
	
	cout<<"Enter Starting Times of shops : ";
	for(int i=0;i<n;i++)
		cin>>s[i];
		
	cout<<"Enter Ending Times of shops : ";
	for(int i=0;i<n;i++)
		cin>>e[i];
	
	result=find(s,e,n,k);
	
	return result;
	
}
