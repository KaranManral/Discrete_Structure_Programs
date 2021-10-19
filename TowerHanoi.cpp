//WAP for Tower Of Hanoi using Recursion

#include <iostream>

using namespace std;
 
int sum=0;
 
void tOH(int n, char A,char C, char B)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << A <<" to rod " << C<<endl; 
        sum++;
        return;
    }
    tOH(n-1, A, B, C); //Calling function 
    cout << "Move disk " << n << " from rod " << A<<" to rod " << C << endl;
    sum++;
    tOH(n-1, B, C, A); //Calling function
}
 

int main()
{
    int n;
    cout<<"Enter the number of Disks"<<endl;
    cin>>n;
    tOH(n, '1', '3', '2'); 
    cout<<"\n Total number of moves taken:"<<sum<<endl;
    return 0;
}
