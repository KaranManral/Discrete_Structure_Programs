/* WAP to create a class SET with data member size and an array and create functions to perform following operations

	a)Cardinality of SET
	b)is a member of set
	c)Power SET
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Set
{
	private:	int size;  //int to store size of array.
				int* arr;  //array to store elements of set
	public:		Set()  //Default Constructor
				{
					size=0;
					arr='\0';
				}
				Set(int n) //Parameterised Constructor
				{
					size=n;
					arr=new int[size];
				}
				void setSize()  //Function to ask size of set from user.
				{
					cout<<"Enter the size of the array"<<endl;
					cin>>size;
					arr=new int[size];
				}
				void enter()  //Function to input elements of the set
				{
					cout<<"Enter the elements of the SET"<<endl;
					for(int i=0;i<size;i++)
						cin>>arr[i];
				} 
  				void sort() //Function to sort array in ascending order
				{
 				    if(size>1)
  				  	{
       					int min,temp;
        				for(int i=0;i<size-1;i++)
        				{
         					min=i;
        					for(int j=i+1;j<size;j++)
            					if(arr[j]<arr[min])
                					min=j;
                			//Swaping elements		
        					temp=arr[min];
        					arr[min]=arr[i];
        					arr[i]=temp;
        				}
    				}
    				else 
        				return;
				}
				Set unique()  //Function to remove duplicate elements from the set.
				{
					if(size==0||size==1)
						return *this;
					sort();  //Calling sort function
					Set A(size);
					int j=0;
					for(int i=0;i<size-1;i++)
						if(arr[i]!=arr[i+1])
							A.arr[j++]=arr[i]; //Making set without repeated elements
					A.arr[j++]=arr[size-1];
					A.size=j;		
					return A;
				}
				bool isMember(int n)  //Function to check if an integer is a member of set or not
				{
					for(int i=0;i<size;i++)
						if(arr[i]==n)
							return true;
					return false;		
				}
				int cardinality() //Function to return cardinality of the set
				{
					if(size==0)
						return 0;
					else
						return size;	
				}
				void powerSet()  //Function to display the Power Set
				{
					int psize=pow(2,size);
					cout<<"{{},";
					for(int i=0;i<psize;i++)
					{
						if(i>0)
							cout<<"{";
						for(int j=0;j<size;j++)
						{
							if(i&(1<<j)) //Checking for combination of power set
								cout<<arr[j]<<",";
						}
						if(i>0)
							cout<<"\b},";
					}
					cout<<"\b}";
				}		
				void show()//Function to display set
				{
					if(size==0)
						cout<<"The set is:- {}"<<endl;
					else
					{
						cout<<"The set is:- {";
						for(int i=0;i<size;i++)
							cout<<arr[i]<<",";	
						cout<<"\b}"<<endl;	
					}
				}	
};	

int main()
{
	int ch,c=1;
	Set A,B;
	A.setSize();
	A.enter();
	B=A.unique();
	B.show();
	do{
		cout<<"Enter the choice \n 1 to know Cardinality \n 2 to check if given integer is member of set or not \n 3 to display Power SET of the given Set"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					cout<<"Cardinality of the set is "<<B.cardinality();
					break;
				}
			case 2:
				{
					int n;
					cout<<"Enter a integer to check if it is a member of set or not"<<endl;
					cin>>n;
					if(B.isMember(n))
						cout<<"Given integer is a member of the set."<<endl;
					else
						cout<<"Given integer is not a member of the set."<<endl;	
					break;
				}	
			case 3:
				{
					cout<<"Power SET of the given set :-";
					B.powerSet();
					break;
				}
			default:
				{
					cout<<"Wrong choice Entered,program will exit now"<<endl;
					exit(0);
				}		
		}
		cout<<"\n Do you want to run program again? Enter 1 for yes or 0 for No"<<endl;
		cin>>c;
		}while(c!=0);
	return 1;
}//main
