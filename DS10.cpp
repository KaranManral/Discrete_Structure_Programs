/*
  WAP to print all permutaions of a set:
  i)Without Repetition
  ii)With Repetition
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

class Set
{
	private:	int size;  //int to store size of array.
				char* arr;  //array to store elements of set
	public:		Set()  //Default Constructor
				{
					size=0;
					arr='\0';
				}
				Set(int n) //Parameterised Constructor
				{
					size=n;
					arr=new char[size];
				}
				void enter()  //Function to input elements of the set
				{
					cout<<"Enter the elements of the SET"<<endl;
					for(int i=0;i<size;i++)
						cin>>arr[i];
				} 
				Set unique()  //Function to remove duplicate elements from the set.
				{
					if(size==0||size==1)
						return *this;
					Set A(size);
					int k;
					for(int i=0;i<size;i++)
					{
						k=0;
						for(int j=0;j<size;j++)
						{
							if(arr[i]==arr[j])
								k++;
							if(k>1)
								arr[i]='\0';
						}
					}
					k=0;
					for(int i=0;i<size;i++)
						if(arr[i]!='\0')
							A.arr[k++]=arr[i]; //Making set without repeated elements
					A.size=k;		
					return A;
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
				void Swap(int a,int b) //Function to swap elements of array
				{
					char temp=arr[a];
      				arr[a]=arr[b];
    				arr[b]=temp;
				}	
				void permuWithoutRepeat(int i)
				{
    				if (i==size-1) //Base case
    				{
    					for(int k=0;k<strlen(arr);k++)
        					cout<<arr[k]<<",";
        				cout<<"\b "<<endl;	
        				return;
    				}
    				for (int j=i;j<size;j++)
    				{
        				Swap(i,j);         //Swaping the elements to create permuations
        				permuWithoutRepeat(i+1);
        				Swap(i,j); //Swapping back to reach original string
    				}
				}
				void permuWithRepeat(string s)
				{
					if(s.length()==size) //Base Case
					{
						for(int j=0;j<s.length();j++)
							cout<<s.at(j)<<",";
						cout<<"\b "<<endl;	
						return; //returning to get out of last recursion
					}
					for(int i=0;i<size;i++)		
						permuWithRepeat(s+arr[i]); //Calling function with recursion to create permutations with repetition
				}
};
int main()
{
	int s,ch,i=1;
	do{
		cout<<"Enter the size of array"<<endl;
		cin>>s;
		Set A(s),B(s);
		A.enter();
		B=A.unique();
		B.show();
		cout<<"Enter choice \n1 for Without Repetition \n2 for With Repetition \n3 to Exit"<<endl;
	A:	cin>>ch;
		switch(ch)
		{
			case 1:
				{
					cout<<"Permutation without Repetition"<<endl;
					B.permuWithoutRepeat(0);
					break;
				}
			case 2:
				{
					cout<<"Permutation with Repetition"<<endl;
					B.permuWithRepeat("");
					break;
				}
			case 3:
				{
					cout<<"Program will exit now"<<endl;
					exit(0);
				}	
			default:
				{
					cout<<"Wrong choice entered,Re Enter the choice"<<endl;
					goto A;
				}		
		}
		cout<<"Do you want to run program again, Enter 1 for yes 0 for no"<<endl;
		cin>>i;
	}while(i==1);

	return 1;
}
