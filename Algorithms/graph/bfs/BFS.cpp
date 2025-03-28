#include <iostream>
#include<vector>
#include<queue>
using namespace std;

// Iterative way.
vector<int> bfs(vector<vector<int> > graph, int source, int n) {
	vector<int> bfsTraversalOfGraph;
	vector<bool> visited(n, false);
	visited[source] = true;
	queue<int> q;
	q.push(source);
	while(!q.empty()) {
		int curr = q.front();
		bfsTraversalOfGraph.push_back(curr);
		q.pop();
		for(int next : graph[curr]) {
			if(visited[next] == false){
				q.push(next);
				visited[next] = true;
			}
		}
	}
	return bfsTraversalOfGraph;
}


int main() {
	int n; // Number of node in graph.
	cin>>n;
	vector<vector<int> > graph(n); // Adjecency list representation of graph.
	int m; // Number of edges.
	cin>>m;
	for(int i = 0 ; i< m ;i++) {
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> ans = bfs(graph, 0, n);
	for(int i = 0 ; i < n ; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;

}