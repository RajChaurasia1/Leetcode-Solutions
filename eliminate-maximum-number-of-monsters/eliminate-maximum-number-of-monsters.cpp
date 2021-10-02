class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<pair<int,int>>arr(dist.size());
        int t = 1;
        for(int i = 0 ; i < dist.size() ; i++){
            arr[i].first = dist[i];
            arr[i].second = speed[i];

        }
        sort(begin(arr),end(arr),[&](pair<int,int>&a, pair<int,int>&b){
           return ((a.first + a.second - 1)/a.second) < ((b.first + b.second - 1)/b.second); 
        });
        for(int i = 1 ; i < arr.size() ; i++){
            cout << arr[i].first << " " << arr[i].second << endl;
           arr[i].first-=(arr[i].second*t);
            if(arr[i].first <= 0)
                return t;
            t++;
        }
        return t;
    }
};