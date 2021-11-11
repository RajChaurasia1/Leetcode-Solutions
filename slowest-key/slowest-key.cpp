class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int max_id = 0, max_pressed = releaseTimes[0];
        for(int i = 1 ; i < releaseTimes.size() ; i++){
            if(releaseTimes[i] - releaseTimes[i - 1] > max_pressed){
                max_pressed = releaseTimes[i] - releaseTimes[i - 1];
                max_id = i;
            }
            else if(max_pressed == releaseTimes[i] - releaseTimes[i - 1]){
                if(keysPressed[max_id] < keysPressed[i]){
                    max_id = i;
                }
            }
        }
        
        return keysPressed[max_id];
    }
};