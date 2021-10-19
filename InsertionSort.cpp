//WAP to implement Insertion sort

#include <iostream>

using namespace std;

void inSort(int arr[], int n) //Function for insertion sort
{
    int temp, j;
    for (int i=1;i<n;i++) //Outer Loop
    {
    	int c=0;
        temp=arr[i]; //storing element at i'th position in temporary variable
        j=i-1;
        cout<<"\n Checking Condition if array element at position is more than array element at next postion"<<endl;
        while(j>=0&&arr[j]>temp) //Inner Loop also checking the condition if elment at j postion is greater than next position
        {
        	cout<<"\n Result=True,"<<arr[j]<<" is more than "<<temp<<". Now we do Swapping"<<endl;
        	c++;
            arr[j+1]=arr[j]; //Swapping element at j to next position
            j=j-1;  //decrement in j for loop to work
        }
        arr[j+1]=temp; //Filling j'th postion with value stored in temp variable
        if(c==0)
        	cout<<"\nResult=False"<<endl;
		cout<<"\n Number of Comparisons during pass "<<i<<"="<<c<<"\n"<<endl;
		cout<<"\n Intermediate Result:";
		for(int i=0;i<n;i++)  //Printing intermediate array
			cout<<arr[i]<<" ";
    }
}

int main()
{
	int n;
	cout<<"\n Enter the size of array"<<endl;
	cin>>n;
	int a[n];
	cout<<"\n Enter the elements of the array"<<endl;
	for(int i=0;i<n;i++) //Taking input in array
		cin>>a[i];
	inSort(a,n);
	cout<<"\n \n Sorted Array:-";
	for(int i=0;i<n;i++)  //Printing sorted array
		cout<<a[i]<<" ";	
	return 1;
}//main
