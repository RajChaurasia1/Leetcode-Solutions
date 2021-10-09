class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        double ans = 1e9;
        vector<vector<int>>worker;
        for(int i = 0 ; i < quality.size() ; i++){
           worker.push_back({quality[i],wage[i]});
        }
        
        sort(begin(worker), end(worker), [](vector<int>&a, vector<int>&b){
           return (double)a[1]/a[0] < (double)b[1]/b[0]; 
        });
        
        
        priority_queue<int>pq;
        double q = 0;
        for(int i = 0 ; i < worker.size() ; i++){
            q += worker[i][0];
            pq.push(worker[i][0]);
            
            if(pq.size() > k){
                q -= pq.top();
                pq.pop();
            }
            if(pq.size() == k)
                ans = min(ans,q*((double)worker[i][1]/worker[i][0]));
                
        }
        
        
        return ans;
    }
};