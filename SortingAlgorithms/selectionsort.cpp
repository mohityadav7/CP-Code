#include<iostream>
using namespace std;
int main()
{
	int A[100],n,x,i,min,j,s;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>A[i];
	
for(i=0;i<n;i++)
{
	min=i;
	for(j=i+1;j<n;j++)
	{
		if(A[min]>A[j])
		min=j;
	}
	if(min!=i)
	{
		s=A[i];
		A[i]=A[min];
		A[min]=s;
	}
}
cout<<"SORTED ARRAY :";
for(i=0;i<n;i++)
cout<<A[i] ;
return 0;
}
