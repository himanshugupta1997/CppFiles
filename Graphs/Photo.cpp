#include<iostream>
#include<vector>
#include<algorithm>
#include"Graph.h"
using namespace std;

int maximumTeams(vector <vector <int> > & V)
{
    for(int i=0;i<V.size();i++)
    {
        sort(V[i].begin(),V[i],end());

    }
    Graph G
    for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V.size();j++)
        {
            if(i!=j&&canbeplaced(V[i]))
        }
    }
}
