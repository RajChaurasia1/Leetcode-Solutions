class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int>dq;
        
        for(int i = 0 ; i < students.size() ; i++){
            dq.push_back(students[i]);
        }
        
        int ate = 0;
        for(int i = 0 ; i < sandwiches.size() ; i++){
            
            int cnt = 0;
            if(sandwiches[i] != dq.front()){
                int size = dq.size();
            while(sandwiches[i] != dq.front()){
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
                
                if(cnt == dq.size())
                    break;
            }
                
                if(cnt == size){
                return dq.size();
            }
            }
            if(sandwiches[i] == dq.front()){
                dq.pop_front();
                ate++;
            }
            
            
            
        }
        return sandwiches.size() - ate;
    }
};