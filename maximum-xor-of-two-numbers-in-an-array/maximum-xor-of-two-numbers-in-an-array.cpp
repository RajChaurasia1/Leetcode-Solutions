class Solution {
    
  public: 
       struct Node{
            Node *left,*right;
        };
      
         void insert(Node*root,int val){
            int bitid = 31;
            Node *curr = root;
            while(bitid >= 0){
                int mask = 1 << bitid;
                int bit = (mask & val) > 0 ? 1 : 0;
                
                if(bit == 0){
                    if(curr->left == NULL){
                        curr->left = new Node();
                    }
                    curr = curr->left;
                    }
                else{
                     if(curr->right == NULL){
                        curr->right = new Node();
                    }
                    curr = curr->right;
                }
                
                bitid--;
            }
        }
        
        int find(Node*root,int num){
            int bitid = 31, ans = 0;
            Node *curr = root;
                while(bitid >= 0){
                int mask = 1 << bitid;
                int bit = (mask & num) > 0 ? 1 : 0;
              //  cout << bit << endl;
                if(bit == 0){
                    if(curr->right != NULL){
                        curr = curr->right;
                          ans|=mask;
                    }
                    else{
                       
                        curr = curr->left;
                       
                    }
                    }
                else{
                     if(curr->left != NULL){
                         curr = curr->left;
                          ans|=mask;
                    }
                    else{
                       
                        curr = curr->right;
                        
                    }
                   
                }
                
                bitid--;
            }
         //   cout << ans << endl;
            return ans;
        }
        

    int findMaximumXOR(vector<int>& nums) {
        
        Node *t = new Node();
        
       for(int i = 0 ; i < nums.size() ;i++){
           insert(t,nums[i]);
       }
        int ans = 0;
      
         for(int i = 0 ; i < nums.size() ;i++){
           //int req = INT_MAX^nums[i];
           //  cout << req << endl;
           int found = find(t,nums[i]);
       //      cout << found << " ";
           ans = max(ans,found);
       }
        return ans;
    }
};