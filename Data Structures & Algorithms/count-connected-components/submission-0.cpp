class Solution {
public:
    void fn(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = 1;

        for(auto& neigh : adj[node]){
            if(!vis[neigh]) fn(neigh, adj, vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& p : edges){
            adj[p[1]].push_back(p[0]);
            adj[p[0]].push_back(p[1]);
        }

        vector<bool> vis(n, 0);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                fn(i, adj, vis);
                cnt++;
            }
        }

        return cnt;
    }
};
