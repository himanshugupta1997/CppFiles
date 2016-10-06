#include"Hash.h"
#include<math.h>
using namespace std;

int main()
{
    My_Map<int , int> M;
    for(int i=0;i<100;i++)
    {
      // cout<<"\n  "<<i;
        M.InsertorUpdate(i+1,i);
    }
    for(int i=0;i<100;i++)
    {
        cout<<"\n"<<M.contains(i);
    }

    return 0;

}
