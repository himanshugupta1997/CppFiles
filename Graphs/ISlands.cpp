#include<iostream>
#include<vector>
using namespace std;

void DFSutil(int row, int col, const vector<vector<int > > &V , vector<vector <bool> > & visited)
{
    //cout<<"\nHello";
    visited[row][col]=true;
    int delta[2][8]={{-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1}};
    int R=V.size();
    int C=V[0].size();
    for(int i=0;i<8;i++)
    {
        int newr=row+delta[0][i];
        int newcol = col+delta[1][i];
        if(newr<R &&newcol<C&&newr>=0&&newcol>=0&&V[newr][newcol]&&visited[newr][newcol]==false)
        {
            DFSutil(newr,newcol,V,visited);
        }

    }

}

int numberofIslands(const vector<vector<int> > & V)
{
    //cout<<"\nHello";
    vector <vector <bool> > visited;
    visited.resize(V.size());
    for(int i=0;i<V.size();i++)
    {
        visited[i].resize(V[i].size());
        for(int j=0; j<V[i].size();j++)
        {
            visited[i][j]=false;
        }

    }
    int countofislands=0;
    for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            if(V[i][j]&&visited[i][j]==false)
            {
      //          cout<<"\nHello";
                DFSutil(i,j,V,visited);
                countofislands++;
            }
        }
    }
}

int main()
{
    vector<vector <int > > V = {{1, 1, 0, 0, 0},{0, 1, 0, 0, 1},{1, 0, 0, 1, 1},{0, 0, 0, 0, 0},{1, 0, 1, 0, 1}};
    cout<<numberofIslands(V);

    return 0;
}
