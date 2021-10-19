//WAP to store a polynomial and display its sum

#include<iostream>
#include<cmath>
#define MAXSIZE 10

using namespace std;
 
void polyType(int num) //Function to Display polynomial type
{
    cout<<"Polynomial is of type"<<endl;
    for(int i=num;i>=0;i--)
    {
    	cout<<"x^"<<i<<"+";
	}
	cout<<"\b "<<endl;
}

void storePoly(int a[],int num) //Function to store the coefficients of polynomial in an array
{
	cout<<"Enter "<<(num+1)<<" coefficients"<<endl;
	for (int i = 0; i <= num; i++)
    {
        cin>>a[i];
    }
    int n=num;
    cout<<"Given Polynomial is:";
    for(int i=0;i<=num;i++)
    {
    	cout<<a[i]<<"x^"<<(n--)<<"+";
	}
	cout<<"\b "<<endl;
}

double sum(int a[],int num,double x) //Function to return sum
{
	double sum=0.0;
	double n=num;
	for(int i=0;i<=num;i++)
	{
		sum+=a[i]*pow(x,n--);	
	}
	return sum;
}

int main()
{
    int array[MAXSIZE];
    int i, num;
    double x, polySum;
    cout<<"Enter the order of the polynomial"<<endl;
    cin>>num;
 	polyType(num);
 	storePoly(array,num);
	cout<<"\n Enter the value of x "<<endl;
    cin>>x;
    polySum=sum(array,num,x);
    cout<<"Sum of the polynomial="<<polySum;
    
	return 1;
}//main
