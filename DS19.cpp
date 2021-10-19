/*Given an adjacency matrix of a graph, write a program to check whether a given set of vertices {v1,v2,v3.....,vk} forms 
an Euler path / Euler Circuit (for circuit assume vk=v1)*/

#include<iostream>
#define MaxC 50

using namespace std;

bool func(int arr[][50],int x)                     // For checking Euler Circuit
{
	int sum=0;
	for(int i=0; i<x; i++)
	{
		for(int j=0; j<x; j++)
		{
			sum+=arr[i][j];
		}
		if(sum%2==0)
			continue;
		else
			return false;
	}
	return true;
}
		
bool func1(int arr[][50],int x)            // For checking Euler Path
		{
			int c;
			for(int i=0; i<x; i++)
			{
				int sum=0;
				for(int j=0; j<x; j++)
				{
					sum+=arr[i][j];
				}
				if(sum%2!=0)
	                c++;
			}
			if(c==2)
			return true;
			else 
			return false;
		}
void PrintMat(int mat[][MaxC], int n)// A function to print the adjacency matrix.
{
	int i, j;
	for(i = 0; i < n; i++)
		cout<<"\t"<<(char)(65+i);
	cout<<endl;
	for(i = 0; i < n; i++)
	{
		cout<<(char)(65+i)<<"\t";
		for(j =0; j < n; j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void input(int mat[][MaxC],int e)// Take input of the adjacency of each pair of vertexes.
{
	char a,b;
	int c,d;
	for(int i=0;i<e;i++)
	{
		cout<<"Enter the vertices between which edge "<<i+1<<" is present"<<endl;
		cin>>a>>b;
		c=(int)(a)-97;
		d=(int)(b)-97;
		if(c!=d)
		{
			mat[c][d]+=1;
			mat[d][c]+=1;
		}
		else
		{
			mat[c][d]+=1;
		}
	}
}

int main()
{
	int v,e,z;
	int ar[50][50]={0};
	cout<<"Enter the number of vertices: ";
	cin>>v;
	cout<<"Enter the number of edges: ";
	cin>>e;
	input(ar,e);
	PrintMat(ar,v);
	cout<<"\n\n    1.) To check adjacency matrix of given graph forms a EULER Circuit"
    	    <<"\n\n    2.) To check adjacency matrix of given graph forms a EULER Path";
	cout<<"\n\nEnter your choice: ";
    cin>>z;
    if(z==1)
    {
    	if(func(ar,v))                     
			cout<<"\n Yes, it is a EULER CIRCUIT..... ";
		else
			cout<<"\n No, it is not a EULER CIRCUIT...... ";
    }
    else if(z==2)
    {
	   	if(func1(ar,v))                     
			cout<<"\n Yes, it is a EULER PATH..... ";
		else
			cout<<"\n No, it is not a EULER PATH...... ";
	   }
    else
    {
  	    cout<<"\n Wrong choice entered by User,Program will exit now";
  	    exit(0);
	}
	return 1;
}

