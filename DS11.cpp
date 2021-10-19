//WAP to calculate nCr and nPr using recursion

#include <iostream>
#include <iomanip>

using namespace std;

int permu(int n,int r)
{
	if(r>n)  //Checking if r is greater than n
		return 0;
	else if(r<=0)	//Base Case
		return 1;
	else	
		return n*permu(n-1,r-1); 
}

int combi(int n,int r)
{
	if(r>n) 	//Checking if r is greater than n
		return 0;
	else if(n==0||r==0||n==r)		//Base Case
		return 1;	
	else
		return combi(n-1,r-1)+combi(n-1,r);
}

int main()
{
	int n,r;
	do
	{
		cout<<"Enter value n and r"<<endl;
		cin>>n>>r;
		if(n<r)
			cout<<"INVALID INPUT"<<endl;
	}while(n<r);
	int p=permu(n,r);
	int c=combi(n,r);
	cout<<"Total possible Permutations="<<p<<endl;
	cout<<"Total possible Combinations="<<c<<endl;
}//main
