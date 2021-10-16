class Solution {
public:
      vector<string>ans;
       void dfs(string node, map<string,priority_queue<string,vector<string>,greater<string>>>&graph){
        // process node's edges 
        if(graph.count(node))
        {
            // If node has any edge call DFS with the edge destination node
            // also remove the edge as we will not visit the edge again (Euler walk)
            while(!graph[node].empty())
            {
                string child = graph[node].top();
                graph[node].pop();
                dfs(child,graph);
            }  
        }
        
        // push node in to result when all its edges are processed
        ans.push_back(node);        
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        map<string,priority_queue<string,vector<string>,greater<string>>>graph;
              
       
        // populate graph adjacency list
        for(int i=0;i<tickets.size();i++)      
            graph[tickets[i][0]].push(tickets[i][1]);
        
        // run DFS starting from JFK
        dfs("JFK",graph);
        
        // reverse result vector to get itenary list order
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};