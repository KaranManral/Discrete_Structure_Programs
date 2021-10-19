//WAP to find all possible combinations 

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void display(int* s,int n,int C) //Display Function
{
	for(int i=0;i<n;i++) //Printing in format
		cout<<s[i]<<"+";	
	cout<<"\b="<<C<<endl;	
}
int combos(int b[],int k,int N,int C,int S)
{
	if(k==0) //Base case
	{
		b[k]=C;
		display(b,N,S);  //Calling Display Function
		return 0;
	}
	for(int i=0;i<=C;i++)  //Making all permutations of required numbers to get sum
	{
		b[k]=i;
		combos(b,k-1,N,C-i,S); //Calling Function itself for recursion
	}
}

int main()
{
	int n,C;
	do{  //Checking if C is less than 10 or not
		cout<<"Enter value of n and C respectively"<<endl;
		cin>>n;
		cin>>C;
		if(C<0||C>10)
			cout<<"Invalid Output,Re-enter"<<endl;
		}while(C<0||C>10);
	if(C==0)
	{
		for(int i=0;i<n;i++)
			cout<<"0+";
		cout<<"\b=0"<<endl;
		exit(0);	
	}	
	int b[n];
	combos(b,n-1,n,C,C);
	return 1;
}
