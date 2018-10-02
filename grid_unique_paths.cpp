#include<iostream>

using namespace std;

int r(int x, int y, int a, int b){
	if(x==a-1 && y==b-1)
		return 0;
	
	if(x==a-1)
		return 1;
	if(y==b-1)
		return 1;
	
	return(r(x+1,y,a,b) + r(x,y+1,a,b));
		
}

int r2(int x, int y, int a, int b, int memo[][100]){

	if(x==a-1 && y==b-1)
		return 0;
	
	if(x==a-1)
		return 1;
	if(y==b-1)
		return 1;
		
	if(memo[x][y]!=0)
		return memo[x][y];
	
	memo[x][y]=(r2(x+1,y,a,b,memo) + r2(x,y+1,a,b,memo));
	
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cout<<memo[i][j]<<"    ";
		}
		cout<<endl;
	}
	return memo[x][y];
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		
		int memo[100][100]={};
		
		for(int i=0;i<a;i++)
			memo[i][b-1]=1;
		for(int i=0;i<b;i++)
			memo[a-1][i]=1;
		
		cout<<r2(0,0,a,b,memo)<<endl;
	
	
		cout<<"          "<<r(0,0,a,b)<<endl;

		
	}
}

