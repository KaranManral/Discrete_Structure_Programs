/*Write a Program to represent Graphs using the Adjacency Matrices and check if it is a complete graph*/

#include<iostream>
#include<iomanip>
#define MaxC 50 
using namespace std;
 

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
 
void addEdge(int mat[][MaxC],int i,int j) //Creating Adjacency Matrix
{
	if(i!=j)
	{
		mat[i-1][j-1]+=1;
		mat[j-1][i-1]+=1;
	}
	else
	{
		mat[i-1][j-1]+=1;
	}
}

void input(int mat[][MaxC],int e)// Take input of the adjacency of each pair of vertexes.
{
	int a,b;
	for(int i=0;i<e;i++)
	{
		cout<<"Enter the vertices between which edge "<<i+1<<" is present"<<endl;
		cin>>a>>b;
 		addEdge(mat,a,b);
	}
}

bool checkGraph(int mat[][MaxC],int v)//Checking for completeness of graph
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i!=j)
				if(mat[i][j]!=1)
					return false;
		}
	}
	return true;
}

bool checkMultiGraph(int mat[][MaxC],int v) //Checking for multigraph
{
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			if(mat[i][j]>1)
				return true;
	return false;			
}

int main()
{
	int v,e;
	int mat[50][50]={0};
	cout<<"Enter the number of vertexes: ";
	cin>>v;
	cout<<"Enter the number of edges: ";
	cin>>e;
	input(mat,e);
	PrintMat(mat, v);
	if(checkGraph(mat,v)==true)
		cout<<"\n It is a complete graph"<<endl;
	else if(checkMultiGraph(mat,v)==true)	
		cout<<"\n It is a Multigraph"<<endl;
	else
		cout<<"\n It is not a complete graph"<<endl;
		
}
