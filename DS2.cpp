/* WAP to create a class SET and take two sets as input from user to perform following SET OPERATIONS:
a)Subset:Check whether one set is subset of other or not
b)Union and Intersection of two sets
c)Complement:Assume Universal Set as per the input from the user 
d)Set Difference and Symmetric Difference between two SETS
e)Cartesian Product of Sets
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#define max 100

using namespace std;

class Set
{
	private: int a[max],size;
	public : Set() //Default Constructor
				{
					size=0;
				}
			Set(int s)//Paramerterised Constructor
			{
				size=s;
			}	
			
			Set Union(const Set& A);
            Set Intersection(const Set& A);
            Set operator-(const Set& A);
            bool checkSubset(const Set& A);
            void displayCartesianProduct(const Set& A);
			void inputArray();
            void sortArray();
			void const print();
};

void Set::inputArray() //Function to take input in array
{
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<size;i++)
		cin>>a[i];
}

void const Set::print() //Function to print array
{
    if(size==0)
        cout<<"{Empty}"<<endl;
    else    
    {
        cout<<"{";
	    for(int i=0;i<size;i++)
	    	cout<<a[i]<<",";
	    cout<<"\b }"<<endl;	
    }
}

void Set::sortArray() //Function to sort array in ascending order
{
    if(size>1)
    {
        int min,temp;
        for(int i=0;i<size-1;i++)
        {
         min=i;
        for(int j=i+1;j<size;j++)
            if(a[j]<a[min])
                min=j;
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
        }
    }
    else 
        return;
}

Set Set::Union(const Set& A) //Function to union two sets 
{
    if(size==0&&A.size==0)
        return (*this);
    else
    {    
	    Set B(size+A.size+1);

		for(int i=0;i<A.size;i++) //Inserting Set 1 in Union Set
			B.a[i]=A.a[i];
		int d=A.size,k;
		for(int i=0;i<size;i++)
		{
			k=0;
			for(int j=0;j<A.size;j++)
			{
				if(A.a[j]==a[i])
				k++;
			}
			if(k==0)
				B.a[d++]=a[i]; //Inserting Elements of Set 2 if not repeated
			B.size=d;	
		}
	    return B;
    }
}

Set Set::Intersection(const Set& A) //Function for intersection
{
    if(size==0&&A.size==0)
        return (*this);
    else
    {    
        Set ob(size);
        int t=0,d,b=0;
	    for(int i=0;i<size;i++)
        {
            d=0;
            for(int j=0;j<A.size;j++)
            {
                if(a[i]==A.a[j])
                    d++;
            }    
            if(d!=0)
            {   
                for(int k=0;k<ob.size;k++)
                {
                    if(a[i]==ob.a[k])
                        b++;
                }
                if(b==0)    
                    ob.a[t++]=a[i]; //Putting elements in Intersection set
            }
            ob.size=t;    
        }
        Set B(ob.size);
        t=0;
        for(int i=0;i<ob.size;i++)
        {
            d=0;
            for(int j=i+1;j<ob.size;j++)
            {
                if(ob.a[i]==ob.a[j])
                    d++;
            }
            if(d==0)
                B.a[t++]=ob.a[i]; //Removing Repeated elements
            B.size=t;    
        }
	    return B;
    }
}

Set Set::operator-(const Set& A) //Function for Subtracting Sets 
{
    if(size==0&&A.size==0)
        return (*this);
    else
    {
        Set B(size);
        int t=0,d;
        for(int i=0;i<size;i++) 
        {
            d=0;
            for(int j=0;j<A.size;j++)
            {
                if(a[i]==A.a[j])
                    d++;
            }
            if(d==0)
                B.a[t++]=a[i];
            B.size=t;    
        }
        return B;
    }
}

void Set::displayCartesianProduct(const Set& A) //Function to Display Cartesian Product of two sets
{
	for(int i=0;i<size;i++)
		for(int j=0;j<A.size;j++)
			cout<<"{"<<a[i]<<","<<A.a[j]<<"},";
	cout<<endl;		
}
bool Set::checkSubset(const Set& A) //Function to check for subset
{
	int i=0,j=0;
	for(i=0;i<A.size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(A.a[i]==a[j])
				break;	
		}	
		if(j==size)
			return false;
	}
	return true;
}

int main()
{
	int s,s1,i,j=0,ch;
	Set B,A,U,I,AB,CA,CB,BA,SD;
    cout<<"Enter the size of Set 1"<<endl;
	cin>>s;
    if(s!=0)
    {
	    A=Set(s);
	    A.inputArray();
    }
    cout<<"Do you want to input second array? Enter 1 for yes or 0 for No"<<endl;
    cin>>i;
    if(i==1)
    {
    	cout<<"Enter the size of Set 2"<<endl;
	    cin>>s1;
        if(s1!=0)
	    {
            B=Set(s1);
	        B.inputArray();
        }
    }
    if(s==0)
        U=B.Union(A);
    else    
	    U=A.Union(B);	 //Taking Union
    CA=U-A; //Complementing A
    CB=U-B;  //Complementing B
    AB=A-B; //A-B
    BA=B-A; //B-A
    I=A.Intersection(B);  //Taking Intersection
    cout<<"\n\nPrinting Details\n\n"<<endl;
	cout<<"Set 1"<<endl;
    A.sortArray();
	A.print();	
	cout<<"Set 2"<<endl;
	B.sortArray();
	B.print();
	while(j!=1) //Loop to run program again if user wants to
	{    
	    cout<<"\n Enter the choice \n1) Check for subset \n2) Union \n3) Intersection \n4) Complement \n5) Calculate Set Difference \n6) Calculate Symmetric Difference \n7) Display Cartesian Product"<<endl;
	    cin>>ch;
	    switch(ch) //Switch block to perform actions according to user inputs
	    {
	    	case 1:
	    		{
	    			if(A.checkSubset(B)==true)
	    				cout<<"Set 2 is subset of Set 1"<<endl;
	    			else if(B.checkSubset(A)==true)
						cout<<"Set 1 is subset of Set 2"<<endl;
					else
						cout<<"Neither Set 1 is subset of Set 2 nor Set 2 is subset of Set 1"<<endl;		
	    			break;
				}
			case 2:
				{
					cout<<"Union"<<endl;
        			U.sortArray();
	    			U.print();
	    			break;
				}	
			case 3:
				{
					cout<<"Intersection"<<endl;
        			I.sortArray();
	    			I.print();
	    			break;
				}	
        	case 4:
        		{
        			cout<<"Complement of Set 1"<<endl;
        			CA.sortArray();
        			CA.print();
        			cout<<"Complement of Set 2"<<endl;
        			CB.sortArray();
        			CB.print();	
        			break;
				}		
        	case 5:
        		{
        			cout<<"A-B"<<endl;
      		  		AB.sortArray();
      		  		AB.print();
      		  		cout<<"B-A"<<endl;
      		  		BA.sortArray();
      			  	BA.print();
      			  	break;
				}
        	case 6:
        		{
        			SD=AB.Union(BA);
        			SD.sortArray();
        			cout<<"Symmetric Difference of sets=";
        			SD.print();
        			break;
				}
			case 7:
				{
					cout<<"Cartesian Product of Set 1 and Set 2 i.e. AXB=";
					A.displayCartesianProduct(B);
					break;
				}	
        	default:
        		{
        			cout<<"Wrong Choice Entered,Program will now exit"<<endl;
        			exit(0);
				}
		}
        cout<<"\n \n ENTER 1 TO EXIT PROGRAM OR 0 TO PERFORM ANOTHER OPERATION"<<endl;
       	cin>>j;
    }
	return 1;
}//main
