#include<iostream>
#include<queue>
using namespace std;
int a[10000][10000];
void shortest(int pi[], int k, int n){
	int a[n] = {0};
	for(int i=0;i<n;i++){
		if(i!=k){
			if(pi[i]==0){
				a[i] = -1;
			}
			else{
				int count = 0;
				int j = i;
				while(pi[j]!=0){
					count++;
					j = pi[j]-1;
				}
				a[i] = count;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(i==k){
			continue;
		}
		else{
			if(a[i]==-1){
				cout<<"-1"<<" ";
			}
			else{
				cout<<a[i]*6<<" ";
			}
		}
	}
}
void bfs(int k, int n){
	int visited[n] = {0};
	int pi[n] = {0};
	queue <int> q;
	q.push(k);
	visited[k] = 1;
	while(q.size()){
		int u = q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(a[u][i]==1){
				if(visited[i]==0){
					q.push(i);
					pi[i] = u+1;
					visited[i] = 1;
				}
			}
		}
	}
	shortest(pi, k, n);
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
	cin>>n;
	int m;
	cin>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				a[i][j] = 0;
			}
		}
	int x, y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		a[x-1][y-1] = 1;
		a[y-1][x-1] = 1;
	}
	
	int k;
	cin>>k;
	bfs(k-1, n);	
	}
	return 0;
	
}
