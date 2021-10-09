//BFS
#include<iostream>
#include "queue.cpp"
using namespace std;


void bfs(int v,int adj_mat[20][20]){
	bool visited[v];
	
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	
	Queue q;
	q.enQueue(0);
	visited[0]=true;
	
	int vis;
	while(!q.isEmpty()){
		vis=q.peek();
		
		cout<<(char)(vis+'A')<<" ";
		int it=q.deQueue();
		
		for(int i=0;i<v;i++){
			if(adj_mat[vis][i]==1 && (!visited[i])){
				q.enQueue(i);
				visited[i]=true;
			}
		}
	}
	cout<<endl;
}

int main(){
	
	freopen("input11.txt","r",stdin);
	
	int v;	
	cin>>v;
	int adj_mat[20][20];
	
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cin>>adj_mat[i][j];
		}
	}
	
	system("clear");
	cout<<"The Adjacency Matrix is"<<endl;
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<adj_mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	bool visited[20];
	
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	
	cout<<"The BFS Traversal"<<endl;
	bfs(v,adj_mat);
	
	cout<<endl; 
	return 0;
}
/*
6
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 1 0
0 1 0 0 1 1 
0 1 1 1 0 1 
0 0 0 1 1 0
*/
