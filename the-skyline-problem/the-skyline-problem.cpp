class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
       vector<vector<int>>ans;
       vector<vector<int>>build;
        int n = buildings.size();
        for(int i = 0 ; i < n ; i++){
            build.push_back({buildings[i][0],-1*buildings[i][2]});
            build.push_back({buildings[i][1],buildings[i][2]});
        
        }
        
        sort(begin(build),end(build),[](vector<int>&a, vector<int>&b){
           if(a[0] == b[0])
               return a[1] < b[1];
            return a[0] < b[0];
        });
        
        
        multiset<int,greater<int>>pq;
        pq.insert(0);
        
        int curr_max = 0;
        
        for(auto xy : build){
            
            int x = xy[0];
            int h = xy[1];
           // cout << x << " " << h << endl;
            if(h < 0)
                pq.insert(-1*h);
            else
                pq.erase(pq.find(h));
            
            if(*pq.begin() != curr_max){
               // cout<<"chg"<<endl;
                vector<int>temp;
                temp.push_back(x);
                temp.push_back(*pq.begin());
                ans.push_back(temp);
                curr_max = *pq.begin();
            }
            
            
        }
        
        return ans;
    }
};