class Solution {
public:
     map<int,vector<int>>adj;
    void dfs(int u,vector<int>&disc,vector<int>&                        low,vector<int>&parent,vector<vector<int>>&bridge)
    {
        static int time=0;
        disc[u]=low[u]=time;
        time+=1;
        for(auto v:adj[u])
        {
            if(disc[v]==-1)
            {
                parent[v]=u;
                dfs(v,disc,low,parent,bridge);
                low[u]=min(low[u],low[v]);
                if(low[v]>disc[u])
                {
                    vector<int>z={u,v};
                    bridge.push_back(z);
                }
            }
            else if(v!=parent[u])
            {
                low[u]=min(low[u],disc[v]);
            }
            
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        vector<int>parent(n,-1);
        vector<vector<int>>bridge;
        for(int i=0;i<n;i++)
        {
            if(disc[i]==-1)
            dfs(i,disc,low,parent,bridge);
        }
        return bridge;
    }
};