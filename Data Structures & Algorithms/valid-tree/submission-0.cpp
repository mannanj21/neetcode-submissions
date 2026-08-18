class Solution {
public:
    bool fn(int par, int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = 1;
        for(auto& neigh : adj[node]){
            if(neigh != par){
                if(vis[neigh]) return 0;
                fn(node, neigh, adj, vis);
            }
        }
        return 1;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto& p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(n, 0);

        bool ch = fn(-1, 0, adj, vis);
        if(!ch) return ch;

        for(int i = 0; i < n; i++){
            if(!vis[i]) return 0;
        }

        return 1;
    }
};
