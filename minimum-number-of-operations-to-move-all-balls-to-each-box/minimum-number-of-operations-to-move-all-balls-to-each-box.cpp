class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int>ans,balls;
        int moves = 0;
        for(int i = 0 ; i < boxes.size() ; i++){
            if(boxes[i] == '1')
                balls.push_back(i);
           
        }
        
        for(int x = 0 ; x < boxes.size() ; x++){
            int moves = 0;
            for(auto b : balls){
                moves+=abs(b - x);
            }
            ans.push_back(moves);
        }
        
        return ans;
        
    }
};