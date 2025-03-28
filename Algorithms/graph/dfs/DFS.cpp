#include <iostream>
#include <vector>
#include <stack>
using namespace std;



//Recursive way
void dfs(vector<vector<int> > graph, vector<bool> &visited, int source) {
	visited[source] = true;
	cout<<source<<endl;
	for(int next : graph[source]) {
		if(visited[next] == false) {
			dfs(graph, visited, next);
		}
	}
}

vector<int> dfs(vector<vector<int> > graph, int source, int n) {
	vector<bool> vis(n, false);
	vector<int> dfsTraversalOfGraph;
	vis[source] = true;
	stack<int> st;
	st.push(source);

	while(!st.empty()) {
		int curr = st.top();
		dfsTraversalOfGraph.push_back(curr);
		st.pop();
		for(int next : graph[curr]) {
			if(vis[next] == false) {
				vis[next] = true;
				st.push(next);
			}
		}
	}
	return dfsTraversalOfGraph;
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
	vector<int> ans = dfs(graph, 0, n);
	for(int i = 0 ; i < ans.size() ; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}