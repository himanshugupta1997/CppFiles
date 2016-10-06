#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<iterator>
#include<limits>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    vector <list <int > > adjlist;
public:
    Graph(int N)
    {
        adjlist.resize(N+1);
    }
    void AddEdge(int Source, int Destination)
    {
        int Great=Source>Destination?Source:Destination;
        if(Great>adjlist.size())
        {
            adjlist.resize(Great+1);
        }
        list <int> :: iterator it=adjlist[Source].begin();
        it=find(adjlist[Source].begin(),adjlist[Source].end(),Destination);
        if(it!=adjlist[Source].end())
        {
            return;
        }
        //cout<<endl<<"Hello"<<endl;
        adjlist[Source].push_back(Destination);
        adjlist[Destination].push_back(Source);
        return;
    }
    void PrintGraph()
    {
        cout<<endl;
        for(int i=0;i<adjlist.size();i++)
        {
            if(adjlist[i].size()==0)
            {
                cout<<i<<" is not connected to anyone "<<endl;
                continue;
            }
            cout<<i<<" is connected to  ";
            list<int> :: iterator it=adjlist[i].begin();
            while(it!=adjlist[i].end())
            {
                cout<<(*it)<<" ";
                it++;
            }
            cout<<endl;
        }
    }
    void RemoveEdge(int Source,int Destination)
    {
        int Great=Source>Destination?Source:Destination;
        if(Great>adjlist.size())
        {
            adjlist.resize(Great+1);
        }
        list <int> :: iterator it=adjlist[Source].begin();
        it=find(adjlist[Source].begin(),adjlist[Source].end(),Destination);
        if(it==adjlist[Source].end())
        {
            return;
        }
        adjlist[Source].erase(it);
        it=find(adjlist[Destination].begin(),adjlist[Destination].end(),Source);
        adjlist[Destination].erase(it);
        return;
    }
    int BFS(int Source, int Destination)
    {
       // cout<<endl;
        list<int> :: iterator it=adjlist[Source].begin();
        queue <pair <int , int > > Q;
        vector <int> V(adjlist.size(),0);
        pair <int , int > P;
        P.first=0;
        P.second=Source;
        Q.push(P);
        //cout<<"Source Pushed in "<<Source;
        V[Source]=1;
        int Count=0;
//        int K=-1;
        while(!Q.empty())
        {
          //  cout<<"\nLoop Called For "<<(Q.front()).second;
            it=adjlist[(Q.front()).second].begin();
            while(it!=adjlist[Q.front().second].end())
            {
                if(V[*it]!=0)
                {
                    it++;
                    continue;
                }
                if(*it==Destination)
                {
                    break;
                }
            //    cout<<"\nElement Pushed in Queue "<<*it;
                pair <int , int > P1(Q.front().first+1,*it);
                V[*it]=Q.front().first+1;
                Q.push(P1);
                it++;
            }
            if(*it==Destination)
            {
                    break;
            }
            Q.pop();
        }
        int m=-10000;
        for(int i=0;i<V.size();i++)
        {
            if(m<V[i]&&V[i]!=0)
            {
                m=V[i];
            }
        }
     //   cout<<endl<<endl;
        return m;

    }
    bool isConnected(int Source, int Destination)
    {
        int Great=Source>Destination?Source:Destination;
        if(Great>adjlist.size())
        {
            return false;
        }
        list <int> :: iterator it=adjlist[Source].begin();
        it=find(adjlist[Source].begin(),adjlist[Source].end(),Destination);
        if(it!=adjlist[Source].end())
        {
            return true;
        }
        return false;
    }
    bool IsCyclic()
    {
        vector <int> V(adjlist.size(),0);
        //queue<int> Q;
        //pair <int, int> P;
        for(int i=0;i<adjlist.size();i++)
        {
         // cout<<"\nLoop Called With Value of i as "<<i;
          //cout<<"\nStatement 1    Count Incremented of "<<i<<" Now Count "<<V[i]+1;
          V[i]++;
          if(V[i]==4)
          {
            //  cout<<"\nReturning True";
              return true;
          }
          list <int > :: iterator it=adjlist[i].begin();
          while(it!=adjlist[i].end())
          {
              //cout<<"\nStatement 2   Count Incremented of "<<*it<<"  Now Count "<<V[*it]+1;
              V[*it]++;
              if(V[*it]==4)
              {
          //        cout<<"\nReturning True";
                  return true;
              }
              it++;
          }

        }
        //cout<<endl<<endl;
        return false;

    }
    bool isbipartitr()
    {
        list<int> :: iterator it=adjlist[Source].begin();
        queue <pair <int , int > > Q;
        vector <int> V(adjlist.size(),0);
        pair <int , int > P;
        P.first=0;
        P.second=Source;
        Q.push(P);
        //cout<<"Source Pushed in "<<Source;
        V[Source]=1;
        int Count=0;
//        int K=-1;
        while(!Q.empty())
        {
          //  cout<<"\nLoop Called For "<<(Q.front()).second;
            it=adjlist[(Q.front()).second].begin();
            while(it!=adjlist[Q.front().second].end())
            {
                if(V[*it]!=0)
                {
                    it++;
                    continue;
                }
                if(*it==Destination)
                {
                    break;
                }
            //    cout<<"\nElement Pushed in Queue "<<*it;
                pair <int , int > P1(Q.front().first+1,*it);
                V[*it]=Q.front().first+1;
                Q.push(P1);
                it++;
            }
            if(*it==Destination)
            {
                    break;
            }
            Q.pop();
        }
        int m=-10000;
        for(int i=0;i<V.size();i++)
        {
            if(m<V[i]&&V[i]!=0)
            {
                m=V[i];
            }
        }
     //   cout<<endl<<endl;
        return m;

    }

    }




};
#endif // GRAPH_H
