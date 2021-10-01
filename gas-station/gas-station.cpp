class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,tank=0;
        int start=0;
        for(int i=0; i<gas.size();++i){
            total+=gas[i]-cost[i];
            tank+=gas[i]-cost[i];
            if(tank<0){
                start=i+1; //even if we skip the previous stations from where we started earlier it would not have helped .. we reached till here because the gas was sufficient till here and it became < 0 for the next station so we have to start from i + 1
                tank=0;
            }
            
        }
        if(total<0)return -1;
        return start;
    }
};