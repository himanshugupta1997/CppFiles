#include<iostream>
#include<queue>

using namespace std;

class graph{
	int v;
	int e;
	int **adj;
	
	public:
		graph(int a){
			this->v=a;
			this->e=0;
			
			adj=new int *[a];
			for(int i=0;i<a;i++){
				adj[i]=new int[a];
			}
			for(int i=0;i<this->v;i++){
				for(int j=0;j<this->v;j++){
					this->adj[i][j]=(i==j)?1:0;
					
				}
			}
		}
		void edge(int x, int y){
			this->adj[x][y]=1;
			this->adj[y][x]=1;
			this->e=e+2;
			cout<<"bidirectional edge added!"<<endl;
		}
		
		void print(){
			for(int i=0;i<this->v;i++){
				for(int j=0;j<this->v;j++){
					cout<<this->adj[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		
		void bfs(){
			bool * visited = new bool[this->v];
			for(int i=0;i<this->v;i++)
				visited[i]=false;
			
			queue<int> q;
			
			q.push(0);
			visited[0]=true;
			
			while(!q.empty()){
				
				int f = q.front();
				q.pop();
				
				cout<<f<<" ";
				
				for(int i=0;i<this->v;i++){
					if(this->adj[f][i] && f!=i && !visited[i]){
						q.push(i);
						visited[i]=true;
					}
				}
			}
			cout<<endl;
		}
		
		void dfsAux(int index , bool b[]){
			cout<<index<<" ";
			b[index]=true;
			for(int i=0;i<this->v;i++){
					if(this->adj[index][i] && index!=i && !b[i]){
						b[i]=true;
						dfsAux(i,b);
					}
				}
				cout<<endl;
		}
		
		void dfs(){
			bool * visited = new bool[this->v];
			for(int i=0;i<this->v;i++)
				visited[i]=false;
				
			dfsAux(0,visited);
		}
		
		void sp(int s, int d){
			int * dist = new int[this->v];
			int * p = new int [this->v];
			for(int i=0;i<this->v;i++){
				dist[i]=-1;
				p[i]=-1;
			}
			
			queue<int> q;
			dist[s]=0;
			q.push(s);
			
			while(!q.empty()){
				int f=q.front();
				q.pop();
				
				for(int i=0;i<this->v;i++){
					if(this->adj[f][i] && f!=i && dist[i]==-1){
						dist[i]=dist[f]+1;
						p[i]=f;
						q.push(i);
					}
				}
			}
			
			int e = d;
			while(e!=s){
				cout<<e<<" ";
				e=p[e];
			}
			cout<<e;
			cout<<endl;
		}
};

int main()
{
	int x,y;
	cin>>x>>y;
	
	graph g(x);
	
	int a,b;
	for(int i=0;i<y;i++){
		cin>>a>>b;
		g.edge(a,b);
	}
	
	g.print();
	
	g.bfs();
	
	g.dfs();
	
	int src, dst;
	cin>>src>>dst;
	
	g.sp(src,dst);
	
}

