// https://leetcode.com/problems/frog-position-after-t-seconds/
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> adj[n+1];

        for(int i=0;i<edges.size();i++) { // This is for making adjacency list
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        vector<int> vis(n+1,0);// for visited
        vector<double> prob(n+1,0); // for calculating probabilities
        prob[1] = 1.0; // the first probability will always be 1
        q.push(1);
        int time=0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front();

                q.pop();
                int unvisited_nodes = 0;
                vis[node] = 1;
                for(int i:adj[node]) {
                    if(!vis[i])unvisited_nodes++;
                }

                for(int neighbours:adj[node]) {
                    if(!vis[neighbours]) {
                        prob[neighbours] = prob[node] /(double)unvisited_nodes;
                        q.push(neighbours);
                    }
                }

                if(unvisited_nodes>0) prob[node] = 0; // if we have unvisited nodes then the frog will nver come back to its parent position as it is given in the question so the probability of the parent position will become zero
            }
            time++;
            if(time==t)break;
        }

        return prob[target];
    }
};
