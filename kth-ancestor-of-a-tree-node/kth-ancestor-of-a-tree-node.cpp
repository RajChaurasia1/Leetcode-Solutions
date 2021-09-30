class TreeAncestor {
public:
   vector<vector<int>> dp;
    int height;
	
    TreeAncestor(int n, vector<int>& parent) {

        height = (int)ceil(log2(n)); 

        dp = vector<vector<int>>(n+1, vector<int>(height+1, -1));
 
        for(int i = 0; i < n; i++)
            dp[i][0] = parent[i];

        for(int h = 1; h <= height; h++)
            for(int i = 0; i < n; i++)
                if( dp[i][h-1] != -1)
                    dp[i][h] = dp[dp[i][h-1]][h-1];
    }
	
	// O(h) - h = height of tree
    int getKthAncestor(int node, int k) {
        for (int i = 0; i <= height; i++) 
        { 
            if (k & (1 << i)) 
            { 
                node = dp[node][i]; 
                if (node == -1) 
                    break; 
            } 
        }
        return node;
    }

 };

  


/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */