class Solution {
public:
    vector<int> minOperations(string boxes) {
        
         int n = boxes.size();
        vector<int> leftCost(n), leftCount(n);
        vector<int> rightCost(n), rightCount(n);
        vector<int> res;
        
        for(int i=1; i<n; i++){
            if(boxes[i-1] == '1')
                leftCount[i] = leftCount[i-1]+1;
            else 
                leftCount[i] = leftCount[i-1];
            leftCost[i] = leftCost[i-1]+leftCount[i];
        }
        
        for(int i=n-2; i>=0; i--){
            if(boxes[i+1] == '1')
                rightCount[i] = rightCount[i+1]+1;
            else 
                rightCount[i] = rightCount[i+1];
            rightCost[i] = rightCost[i+1]+rightCount[i];
        }
        
        for(int i=0; i<n; i++){
            res.push_back(leftCost[i]+rightCost[i]);
        }
        
        return res;
    }
};