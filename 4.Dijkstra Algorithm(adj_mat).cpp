// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Given adj list

//     0  1  2
    
// 0   0  1  6 

// 1   1  0  3

// 2   6  3  0

class Solution
{
	public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);            // Initialize distances with infinity
        dist[S] = 0;                             // Distance from source to itself is 0
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});                         // {distance, node}
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int currD = pq.top().first;
            pq.pop();
            
            if (currD > dist[u])               // Skip if this node has been processed with a shorter distance
                continue;
            
            for (auto p : adj[u]) {
                int v = p[0];
                int w = p[1];
                
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};
