/*Write a program to accept an input n from the user and graphically represent the values of T(n)
 where n varies from 0 to n for the recurrence relations.
  For e.g. T(n) = T(n-1) + n, T(0) = 1,
  T(n) = T(n-1) + n^2, T(0) =1, 
  T(n) = 2*T(n)/2 + n, T(1)=1.*/

#include <iostream>

using namespace std;

int rec1(int n) //To calculate recursive relation T(n-1)+n , T(0)=1
{
	if(n==0)
	return 1;
	else
	{
	 cout<<"\n"<<"T("<<n<<")=T("<<n-1<<")"<<"+"<<n<<endl;
	 return rec1(n-1)+n;
    }
}

int rec2(int n) //To calculate the recursive relation T(n-1)+n*2  , T(0)=1
{
	if(n==0)
	return 1;
	else{
	cout<<"\n"<<"T("<<n<<")=T("<<n-1<<")"<<"+"<<n*n<<endl;
	return rec2(n-1)+n*n;
    }
}

int rec3(int n) //To calculate the recursive relation 2*T(n/2)+n , T(1)=1
{
	if(n==1)
	return 1;
	else
	{
	  cout<<"\n"<<"T("<<n<<")=2*T("<<n/2<<")+"<<n<<" = "<<2*n<<endl;
	  return 2*rec3(n/2)+n;
    }
}
int main()
{
   char ch = 'y';
   while(ch == 'y' || ch== 'Y')
   {
   	int n,m;
   cout<<"Enter your Choice"<<endl;
   cout<<"1 To calculate the recurrence relation T(n-1)+n"<<endl;
   cout<<"2 To calculate the recurrence relation T(n-1)+n^2 "<<endl;
   cout<<"3 To calculate the recurrence relation 2*T(n/2)+n "<<endl;
   cin>>n;
   cout<<"\nEnter the value of n "<<endl;
   cin>>m;
   if(n==1)
   cout<<"\nBy Substitution, Output: "<<rec1(m)<<endl;
   else if(n==2)
   cout<<"\nBy Substitution,Output: "<<rec2(m)<<endl;
   else if(n==3) 
   cout<<"\nOutput: "<<rec3(m)<<endl;
   else
   cout<<"Wrong Choice Entered"<<endl;
   cout<<"\nEnter y to continue program"<<endl;
   cin>>ch;
  }
}
