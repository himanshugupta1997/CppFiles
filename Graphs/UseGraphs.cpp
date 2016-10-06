#include"Graph.h"
#include<iostream>
#include<cstring>
#include"Directed_Graph.h"
using namespace std;

int main()
{
    char ch[100][100];
    cout<<"Enter the number of Strings ";
    int N;
    cin>>N;
    char b;
    cin.get(b);
    cout<<"Start Entering The Strings in lexographical order "<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"String "<<i+1<<"  ";
        cin.getline(ch[i],100);
    }
    DGraph G(9);
    char L[100][100];
    int i,j,k;
    int temp;
    int A[100]={0};
    for(j=0;j<100;j++)
    {
        temp=1;
        for(i=0,k=0;i<N;i++)
        {
            if(j>=strlen(ch[i]))
            {
                continue;
            }
            L[j][k]=ch[i][j];
            k++;
            A[j]++;
            temp=0;
        }
        if(temp)
        {
            break;
        }
    }
    cout<<endl;
    for(i=0;i<100;i++)
    {
        if(A[i]==0)
        {
            break;
        }
        for(j=0;j<A[i];j++)
        {
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(i=0;i<100;i++)
    {
        if(A[i]==0)
        {
            break;
        }
        for(j=0;j<A[i]-1;j++)
        {
            if(L[i][j]==L[i][j+1])
                continue;
            G.AddEdge(L[i][j+1]-'0',L[i][j]-'0');
        }
    }
    cout<<endl;
    G.PrintDGraph();
    G.Help();
    return 0;
}
