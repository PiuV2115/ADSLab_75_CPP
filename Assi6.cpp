#include<iostream>
#include<vector>
using namespace std;

int find(int s[10],int e[10],int n,int k)
{
	vector<int> visit;
	int person=0;
	int min=9999,result;
	for(i=0;i<n;i++)
	{
		visit.push_back(0);
	}
	while(person<k)
	{
		int count=0,idx=0,endtime=0;
		for(int i=0;i<n;i++)
		{
			if(endtime<s[i]&&visit[i]!=1)
			{
				if(min>s[i])
				{
					idx=i;
					if(i==n-1)
					{
						visit[idx]=1
						result++;
						endtime=e[idx];
					}
				}
				else
				{
					min=s[j];
				}
			}
		}
		
		
	
	
	}

}


int main
{
	int s[10],e[10],n,k,result;
	cout<<"Enter no. of Shops : ";
	cin>>n;
	
	cout<<"Enter no. of Peoples :";
	cin>>k;
	
	cout<<"Enter Starting Times of shops : ";
	for(int i=0;i<N;i++)
		cin>>s[i];
		
	cout<<"Enter Ending Times of shops : ";
	for(int i=0;i<N;i++)
		cin>>e[i];
	
	result=find(s,e,n,k);
	
	return 0;
	
}
