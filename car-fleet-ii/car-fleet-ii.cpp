class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        
        stack<int>s;
        vector<double>time(cars.size(),-1);
        
        
        for(int i = cars.size() - 1; i >= 0 ; i--){
            while(!s.empty() && cars[i][1] <= cars[s.top()][1])
                s.pop();
            
            while(!s.empty()){
                double t = (double)(cars[s.top()][0]-cars[i][0])/(cars[i][1]-cars[s.top()][1]);
                if(t <= time[s.top()] || time[s.top()] == -1){
                    time[i] = t;
                    break;
                }
                s.pop();
            }
            s.push(i);
            
        }
        
        return time;
        
    }
};