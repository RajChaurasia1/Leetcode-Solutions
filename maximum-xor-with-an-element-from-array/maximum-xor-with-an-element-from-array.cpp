class Solution {
public:
    
    struct Node{
      
        Node* left;
        Node* right;
        
    };
    
    void insert(Node* root, int num){
        Node*temp = root;
        
        int bitid = 31;
        while(bitid >= 0){
            int bit = (num & (1 << bitid));
            if(!bit){
                if(temp->left == NULL)
                    temp->left = new Node();
                temp = temp->left;
            }
            else{
                if(temp->right == NULL)
                    temp->right = new Node();
                temp = temp->right;
            }
            
            
            bitid--;
        }
        return ;
    }
    
    int search(Node* root, int num){
        if(root->left == NULL && root->right == NULL)
            return -1;
        Node* temp = root;
        int bitid = 31, ans = 0;
        while(bitid >= 0){
            int bit = (num & (1 << bitid));
            
            if(!bit){
                if(temp->right!=NULL){
                    temp = temp->right;
                    ans|=(1 << bitid);
                    
                }
                else
                    temp = temp->left;
            }
            else{
                if(temp->left!=NULL){
                    temp = temp->left;
                    ans|=(1 << bitid);
                }
                else{
                    temp = temp->right;
                }
            }
            
            
            bitid--;
        }
       
        return ans;
        
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Node*root = new Node();
        
        int n = size(nums), m = size(queries);
        vector<int>ans(m);
        sort(begin(nums),end(nums));
        vector<vector<int>>query(m,vector<int>(3));
        for(int i = 0 ; i < m ; i++){
            query[i][0] = queries[i][0];
            query[i][1] = queries[i][1];
            query[i][2] = i;
        }
        
        sort(begin(query),end(query),[](vector<int>&a, vector<int>&b){
            if(a[1] == b[1])
                return a[2] < b[2];
            return a[1] < b[1];
                
        });
        
        int j = 0;
        
        for(int i = 0 ; i < m ; i++){
           // cout << query[i][1] << endl;
            while(j < n && nums[j] <= query[i][1]){
                insert(root,nums[j]);
                ++j;
            }
          
            ans[query[i][2]] = search(root,query[i][0]);
        }
        return ans;
    }
};