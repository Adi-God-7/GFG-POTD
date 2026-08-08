class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        if(edges.size() < n-1)return -1;
        vector<vector<int>>adj(n);
        for(int i = 0 ;i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>Don(n , -1);
        
        auto dfs = [&](auto && self , int ind , int curr)->void{
            for(auto i: adj[ind]){
                if(Don[i] == -1){
                    Don[i] = curr;
                    self(self , i , curr);
                }
            }
            return;
        };
        
        int count = 0;
        for(int i =0 ; i<n ; i++){
            if(Don[i]!=-1)continue;
            count++;
            Don[i] = i;
            dfs(dfs ,i ,i);
        }
        return count -1;
    }
};