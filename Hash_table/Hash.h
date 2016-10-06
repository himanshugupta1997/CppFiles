#ifndef MY_UNORDERED_MAP
#define MY_UNORDERED_MAP
#include<vector>
#include<string>
#include<stack>
#include<list>
#include<queue>
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
int Hash(char ch)
{
    return (ch*29);
}

int Hash(int key) {
    return key;
}
int Hash(const string & key) {
    int hash_value = 0;
    for (int i = 0; i < key.size(); i++) {
        hash_value  = hash_value * 29 + key[i];
    }
    return hash_value;
}
template <typename T1, typename T2>
class My_Map
{
    vector < list< pair < T1, T2> > > Table;
    int Count;
    void Rehash()
    {
      //  cout<<"\nRehash";
        vector < list <pair < T1, T2> > > temp;
        temp=Table;
        int i,j;
        Table.clear();
        Table.resize(temp.size()*2);
        for(i=0;i<temp.size();i++)
        {
            typename list <pair <T1 , T2 > > :: iterator it=temp[i].begin();
            while(it!=temp[i].end())
            {
                InsertorUpdate((*(it)).first,(*it).second);
                   it++;
            }

        }

    }
public:
    My_Map()
    {
        cout<<"\nHello";
        Table.resize(10);
        Count=0;
    }
    void InsertorUpdate(T1 Key, T2 Value)
    {
       //cout<<"\nInsert "<<Key;
        int index=Hash(Key);
        index=(index)%Table.size();
        typename list< pair <T1 , T2> > :: iterator it=Table[index].begin();
        if(!contains(Key))
        {

            pair<T1 , T2> P(Key,Value);
            Table[index].push_back(P);
        //    cout<<"\nCount Increased ";
            Count++;
        }
        else
        {
            pair<T1 , T2> P(Key,Value);
            while(it!=Table[index].end())
            {
                if((*(it)).first==Key)
                {
                    Table[index].erase(it);
                    Table[index].push_back(P);
                }
                it++;
            }

        }
        if(Count>Table.size())
        {
         //  cout<<"\nHello1";
            Count=0;
            Rehash();
        }
    }
    bool contains(T1 Key)
    {
        int index=Hash(Key)%Table.size();
        typename list<pair< T1, T2 > > :: iterator it=Table[index].begin();
        while(it!=Table[index].end())
        {
            if((*it).first==Key)
            {
                return true;
            }
            it++;
        }
        return false;

    }
    void RemoveKey(T1 Key)
    {
        int index=Hash(Key)%Table.size();
        typename list<pair< T1, T2 > > :: iterator it=Table[index].begin();
        while(it!=Table[index].end())
        {
            if((*it).first==Key)
            {
                Table[index].erase(it);
                return;
            }
            it++;
        }
        return;
    }



};




#endif // MY_UNORDERED_MAP
