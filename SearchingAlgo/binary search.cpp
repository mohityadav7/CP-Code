#include<iostream>
using namespace std;
int main()
{
	int A[100],n,x,i,l,m,r,flag=0;
	
	cout<<"ENTER THE SIZE OF THE ARRAY :";
	cin>>n;
	
	cout<<"ELEMENTS OF THE ARRAY WILL BE : \n";
	for(i=0;i<n;i++)
	cin>>A[i];
	
	cout<<"ENTER THE ELEMENT YOU WANT TO SEARCH ";
	cin>>x;
	
	l=0;
	r=n-1;
	while(l<r)
	{
		m=(l+r)/2;
		
		if(A[m]==x)
		{
		flag=1;
		break;
		}
			
		else if(A[m]<x)
		l=m+1;
		
		else 
		r=m-1;
		
	}
	if(flag==1)
	cout<<"THE ELEMENT IS AT A POSITION : "<<m+1;
	else
	cout<<"NUMBER NOT FOUND";
	return 0;
	
}
