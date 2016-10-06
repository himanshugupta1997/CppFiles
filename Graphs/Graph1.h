#ifndef Graph_H
#define Graph_H
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph
{
     vector <list <int> > adjlist;
 public:
    Graph()
    {

    }
    int V() const
    {
        return adjlist.size();
    }
    void addEdge(int source, int destination)
    {
        int max = source>destination?source:destination;
        if(max+1>V())
        {
            adjlist.resize(max+1);
        }
        list<int> ::iterator it=adjlist[source].begin();
        while(it!=adjlist[source].end())
        {
            if(*it!=destination)
            {
                throw;
            }
            it++;
        }
        adjlist[source].push_back(destination);
        adjlist[destination].push_back(source);

    }
    void DFS()
    {
        vector <bool> visited(V(),false);
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==true)
            {
                continue;
            }
            DFSUtil(i,visited);
        }
    }
    void DFSUtil(int source, vector<bool> & visited)
    {
        visited[source]=true;
        cout<<source<<" ";
        list<int> ::iterator it=adjlist[source].begin();
        while(it!=adjlist[source].end())
        {
            if(visited[*it]==false)
            {
                DFSUtil(*it,visited);
            }
            it++;
        }
    }
    void shortestpath(int source, int destination)
    {
        vector <int> Count(V(),0);
        int j=0;
        queue<int> Q;
        Q.push(source);
        Count[Q.front()]=0;
        vector<int> Parent(V(),0)
        Parent[0]=source;
        while(!Q.empty())
        {
            if(Q.front()==destination)
            {
                break;
            }
            list<int> ::iterator it=adjlist[Q.front()].begin();
            while(it!=adjlist[Q.front()].end())
            {
                if(Count[*it]!=0)
                {
                    Q.push(*it);
                    Count[*it]=Q.front()+1;
                }

                it++;
            }
            Q.pop();
        }
        cout<<"\nMinimum number of steps required is "<<

    }
};




#endif
