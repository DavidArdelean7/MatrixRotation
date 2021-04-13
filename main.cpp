#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("in.txt");

//function for reading the matrix
void read(int n, int a[100][100])
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        fin>>a[i][j];
}
//function for displaying the matrix
void show(int n, int a[100][100])
{
    for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
}
//function for rotating 4 elements at once, each arriving in their expected position for the final matrix result
void rot(int a[100][100], int i, int j, int n)
{
    int x=n-1;
    int aux=a[j][x-i]; //saving the next element
    a[j][x-i]=a[i][j]; //replacing the next element with the current one
    a[i][j]=a[x-j][i]; //replacing the current element with the previous one

    //changing the current element by changing the indices (jumping to the element opposed to the current one in the "circle" of permutations)
    int k=x-i;
    int z=x-j;
    a[z][x-k]=a[k][z]; //replacing the next element with the current one
    a[k][z]=aux;       //replacing the current element with the previous one
}

void MR (int i, int j, int n, int a[100][100], int N)
{
    int x=j; //saving the j index for the function parameter
    if (N>=2) //condition to stop the loop
    {

        while(j<N-1) //iterating on rows till the last but one
        {
            rot(a, i, j, n); //using the rotation function
            j++;
        }
        MR(i+1, x+1, n, a, N-1); // going one layer deeper into the matrix to apply the permutations
    }

}


int main()
{
    int n, a[100][100];
    fin>>n;
    read(n,a);
    show(n,a);
    MR(0,0,n,a, n);
    show(n,a);



    return 0;
}
