#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<iterator>
#include<algorithm>
using namespace std;

void Substring()
{
    char S[100], T[100];
    cout<<"Enter String 1 ";
    cin.getline(S,100);
    cout<<"Enter String 2 ";
    cin.getline(T,100);
    unordered_set<char> M;
    for(int i=0;S[i]!='\0';i++)
    {
        M.insert(S[i]);
    }
    for(int i=0;T[i]!='\0';i++)
    {
        if(M.find(T[i])==M.end())
        {
            cout<<"\nNot Subsets";
            return;
        }
    }
    cout<<"\nYes";
    return;
}

void Question3()
{

    char S[100], T[100];
    cout<<"Enter String 1 ";
    cin.getline(S,100);
    cout<<"Enter String 2 ";
    cin.getline(T,100);
    unordered_map<char, > M;
    for(int i=0;S[i]!=0;i++)
    {
    }
}

int main()
{
    Substring();
    return 0;
}
