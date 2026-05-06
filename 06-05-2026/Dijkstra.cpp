#include <climits>
#include <vector>
#include <iostream>
using namespace std;

typedef pair<int,int> pir;

void sort_push(vector<pir>& distpq, pir new_p ) {
	int weigth = new_p.second;
	for(int i = 0 ; i < distpq.size() ; i++) {
		if(distpq[i].second > weigth) {
			distpq.insert(distpq.begin() + i , new_p) ;
			return;
		}
	}
	distpq.push_back(new_p);
}



void dijkstra(int start, vector<vector<pir>>& adj, int n , vector<string>& nodeNames ) {
	vector<int> dist(n,INT_MAX);
	dist[start] = 0 ;
	vector<pir> pq ;
	pq.push_back({start,0});
	while(!pq.empty()) {
		int u = pq[0].first;
		int v = pq[0].second;
		pq.erase(pq.begin());
        cout << "u = " << u <<"\n" << "v = " << v << endl ; 
		if(v < dist[u]) continue;

		for (auto& edge : adj[u]) {
			int v = edge.first;
			int weight = edge.second;
			if (dist[u] + weight < dist[v]) {
				dist[v] = dist[u] + weight;
				sort_push(pq,{v , dist[v]});
			}
		}
	}
		cout  <<"from edge " << nodeNames[start] << ":\n";
		for (int i = 0; i < n; i++) {
			cout << "to edge " << nodeNames[i] << " : " << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
		}
	}

	int main() {
		vector<string> nodeNames = { "A", "B", "C", "D" };
		int n = nodeNames.size();
		vector<vector<pir>> adj(n);
		adj[0].push_back({1,5});
		adj[1].push_back({2,3});
		adj[1].push_back({3,8});
		adj[2].push_back({3,10});
        
        dijkstra(0, adj , n , nodeNames);
		return 0;
	}