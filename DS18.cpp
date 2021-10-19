/*Given a graph G, Write a Program to find the number of paths of length n between the source and destination entered by the user*/
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

void multiply(int a[][MaxC],int n,int a1,int b1)
{
	int **b,**c;
	b=new int*[n];
	c=new int*[n];
	for(int i=0;i<n;i++)
	{
		c[i]=new int[n];
		b[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			b[i][j]=a[i][j];
	}
	if(n!=1)
	{
		cout<<"Resultant Adjacent Matrix "<<"A^"<<n<<"\n"<<endl;
		for(int l=2;l<=n;l++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					c[i][j]=0;
					for(int k=0;k<n;k++)
					{
						c[i][j]+=a[i][k]*b[k][j];
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{	
					b[i][j]=c[i][j];
				}
			}
		}
		for(int i = 0; i < n; i++)
			cout<<"\t"<<(char)(65+i);
		cout<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<(char)(65+i)<<"\t";
			for(int j=0;j<n;j++)
				cout<<c[i][j]<<"\t";
			cout<<endl;
		}
			cout<<"\n The number of path between "<<(char)(a1+97)<<" and "<<(char)(b1+97)<<" of length "<<n<<" is "<<c[a1][b1]<<endl;	
	}
}

int main()
{
	int n;
	int v,e;
	char a1,b1;
	int c1,d1;
	int mat[50][50]={0};
	cout<<"Enter the number of vertexes: ";
	cin>>v;
	cout<<"Enter the number of edges: ";
	cin>>e;
	input(mat,e);
	PrintMat(mat,v);
	cout<<"\n Enter the length of path"<<endl;
	cin>>n;
	cout<<"Enter the start point and the end point"<<endl;
	cin>>a1>>b1;
	c1=(int)(a1)-97;
	d1=(int)(b1)-97;
	multiply(mat,n,c1,d1);
	return 1;
}
