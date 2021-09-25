class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = days.size(), ans = 0, i;
       
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for( i = 0 ; i < n ; i++){
            if(apples[i] > 0)
            pq.push({days[i] + i + 1, apples[i]});
            
            while(!pq.empty() && pq.top().first <= i + 1)
                pq.pop();
            
            if(!pq.empty()){
                auto p = pq.top();
                pq.pop();
                p.second--;
                ans++;
                if(p.second > 0)
                    pq.push(p);
            }
        }
        
        
        while(!pq.empty()){
            while(!pq.empty() && pq.top().first <= i + 1)
                pq.pop();
            
            if(!pq.empty()){
                auto p = pq.top();
                pq.pop();
                p.second--;
                ans++;
                if(p.second > 0)
                    pq.push(p);
            }
            ++i;
        }
        return ans;
    }
};