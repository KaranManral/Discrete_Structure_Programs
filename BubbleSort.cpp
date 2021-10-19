//WAP to implement Bubble Sort

#include <iostream>

using namespace std;

void bubbleSort(int a[],int n) //Function for bubble sort
{
	int temp;
	for(int i=0;i<n-1;i++) //Outer loop
	{
		int c=0;
		for(int j=0;j<n-i-1;j++) //Inner loop
		{
			c++;
			cout<<"\nChecking if "<<a[j+1]<<
					" is less than "<<a[j]<<endl;
			if(a[j+1]<a[j])
			{
				cout<<"\nResult=True,"<<a[j+1]<<" is less than "
						<<a[j]<<". Now swaping "<<a[j+1]
						<<" and "<<a[j]<<endl;
				
				temp=a[j];   //Swapping elements
				a[j]=a[j+1];	//Swapping elements
				a[j+1]=temp;	//Swapping elements
			}
			else
				cout<<"\nResult=False,"<<a[j+1]<<
					" is not less than "<<a[j]<<endl;
		}
		cout<<"\nNumber of Comparisons during pass "<<i+1<<
				"="<<c<<"\n"<<endl;
		cout<<"\nIntermediate Result:";
		for(int i=0;i<n;i++)  //Printing sorted array
			cout<<a[i]<<" ";
		cout<<endl;	
	}
}

int main()
{
	int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<n;i++) //Taking input in array
		cin>>a[i];
	bubbleSort(a,n);
	cout<<"\n\nSorted Array:-";
	for(int i=0;i<n;i++)  //Printing sorted array
		cout<<a[i]<<" ";	
	return 1;
}//main
