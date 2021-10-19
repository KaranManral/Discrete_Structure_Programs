/*Write a Program to accept a directed graph G and compute the in-degree and out-degree of each vertex*/

#include<iostream>
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
 		mat[c][d]+=1;
	}
}

int main()
{
	int v,e;
	int ar[50][50]={0};
	cout<<"Enter the number of vertices: ";
	cin>>v;
	cout<<"Enter the number of edges: ";
	cin>>e;
	input(ar,e);
	int in[v]={0};
	int out[v]={0};
	for(int i=0;i<v;i++) //Calculating in degree and out degree
	{
		for(int j=0;j<v;j++)
		{
			if(ar[i][j]>=1)
			{
				if(j!=i)
				{
					in[j]+=ar[i][j];
					out[i]+=ar[i][j];
				}
				else
				{
					in[i]+=1;
					out[j]+=1;
				}
			}
		}
	}
	PrintMat(ar,v);
	for(int i=0;i<v;i++) //printing result
	{
		cout<<"Indegree of vertex "<<(char)(i+97)<<" is "<<in[i]<<endl;
		cout<<"Outdegree of vertex "<<(char)(i+97)<<" is "<<out[i]<<endl;
		cout<<"\n"<<endl;
	}
	return 1;
}
