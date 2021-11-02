class Solution {
public:
    string validIPAddress(string IP) {
        int ip4 = -1;
        
        for(int i = 0 ; i < IP.size() ; i++){
          if(IP[i] == '.'){
              ip4 = 1;
              break;
          }
            else if(IP[i] == ':'){
                ip4 = 0;
                break;
            }
                
        }
      
        if(ip4 == -1)
            return "Neither";
        
        
        if(ip4){
            int dot = 0;
            for(int i = 0 ; i < IP.size() ; i++){
                if(IP[i] == '.')
                    return "Neither";
              
                int j = i, z = 0, zero = 0;
                string num;
                while(j < IP.size() && IP[j] != '.'){
                    if(IP[j] >= 58 || IP[j] < 48)
                        return "Neither";
                    num += IP[j];
                    ++j;
                }
                if(IP[j] == '.')
                    dot++;
                
                if(num.size() > 3 || stoi(num) > 255 || num == "" || dot > 3)
                    return "Neither";
                if(num[0] == '0')
                    z = 1;
                
                for(int k = 0 ; k < num.size(); k++){
                    if(num[k] == '0')
                        zero++;
                    else if(num[k] >= 58 || num[k] < 48)
                        return "Neither";
                }
                
                if(z &&  (num.size() > 1))
                    return "Neither";
                
                i = j;
                if(i == IP.size() - 1 && IP[i] == '.')
                    return "Neither";
            }
           
            if(dot == 3)
            return "IPv4";
        }
        else{
            int colon = 0;
            for(int i = 0 ; i < IP.size() ; i++){
                if(IP[i] == ':')
                    return "Neither";
                int j = i, z = 0, zero = 0;
                string num;
                while(j < IP.size() && IP[j] != ':'){
                    num += IP[j];
                    ++j;
                }
               if(IP[j] == ':')
                   colon++;
               if(num == "" || colon > 7 || num.size() > 4)
                return "Neither";
                
                for(int k = 0 ; k < num.size(); k++){
                  
                    if((num[k] >= 48 && num[k] <= 57)||(num[k] >= 97 && num[k] <= 102)||(num[k] >= 65 && num[k] <= 70)){
                        continue;
                    }
                    else{
                        return "Neither";}
                      
                }
                i = j;
                if(i == IP.size() - 1 && IP[i] == ':')
                    return "Neither";
            }
            if(colon == 7)
            return "IPv6";
        }
        
        return "Neither";
    }
};