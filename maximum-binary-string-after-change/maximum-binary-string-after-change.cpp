class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size(), id, z = 0;
    
        for(int i = n - 1 ; i >= 0; i--){
          if(binary[i] == '0'){
              id = i;
              z++;
          }
        }
        
        if(z <= 1)
            return binary;
        
        string mod_binary(n,'1');
        mod_binary[id + z - 1] = '0';
        return mod_binary;
    }
};