#include<iostream>
#include<queue>
#include<limits>
using namespace std;
int a[10000][10000];
int minDistance(int dist[], int sptSet[], int n)
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < n; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
void closest(int k, int n){
	int pi[n] = {0};
	int visited[n] = {0};
	queue <int> q;
	q.push(k);
	visited[k] = 1;
	while(q.size()){
		int u = q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(a[u][i]>=0 && a[u][i]<INT_MAX){
				if(visited[i]==0){
					q.push(i);
					pi[i] = u+1;
					visited[i] = 1;
				}
			}
		}
	}
	int arr[n] = {0};
	int included[n] = {0};
	for(int i=0;i<n;i++){
		arr[i] = INT_MAX;
	}
	arr[k] = 0;
	for(int i=0;i<n-1;i++){
		int u = minDistance(arr, included, n);
		included[i] = 1;
		for (int v = 0; v < n; v++)
         if (!included[v] && a[u][v] && arr[u] != INT_MAX 
                                       && arr[u]+a[u][v] < arr[v])
            arr[v] = arr[u] + a[u][v];
	}
	for(int i=0;i<n;i++){
		if(pi[i]==0 && i!=k){
			cout<<"-1 ";
		}
		else{
			if(i!=k){
			cout<<arr[i]<<" ";
		}
		}
	}
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
	int x, y, z;
	for(int i=0;i<m;i++){
		cin>>x>>y>>z;
		a[x-1][y-1] = z;
		a[y-1][x-1] = z;
	}
	int k;
	cin>>k;
	closest(k-1, n);	
	}
	return 0;
	
}
