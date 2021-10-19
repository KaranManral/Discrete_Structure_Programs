//Given a full m-ary tree with i internal vertices, Write a Program to find the number of leaf nodes.

#include <iostream>

using namespace std;
  
int leafNodes(int m,int i)//Function to calculate number of Leaf Nodes
{
	int L=i*(m-1)+1;//Formula to calculate no. of leaf nodes
	return L;
}

int main()
{
    int m,i;
 	cout<<"Enter the number of children each node have"<<endl;
 	cin>>m;
 	cout<<"Enter the number of internal nodes"<<endl;
 	cin>>i;
    cout << "Leaf nodes = "<<leafNodes(m,i)<<endl;
    return 1;
}
