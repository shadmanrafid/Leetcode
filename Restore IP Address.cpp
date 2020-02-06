class Solution {
private:
    vector<string>result;
    
   bool valid_ip(string s)
    {
        int len = s.size();
        int cur = -1;
        int last = -1;
        int it;
        int num = 0;
        int last_idx = -1;
        int segment; 
        bool set_break = false;
        for(int i = 1;i<len-1;i++)
        {
            if(s[i] == '.'){
                num++;
                last = cur;
                cur = i;
                if(num == 1){
                    cur = i;
                    if(cur != 1 && (s[0] == '0'  || stoi(s.substr(0,cur))>255) )
                    {
                        return false;
                    }
                    if(cur >3) return false;
                    continue;
                }
                if(cur-last < 2 || cur-last > 4){
                    return false;
                }
                
                if(cur - last > 2 &&(stoi(s.substr(last+1,cur-last-1)) > 255 || s[last + 1] == '0'))
                {
                    return false;
                }
                if(num == 3){
                    if(len - cur > 4){
                        return false;
                    }
                    if(len-cur > 2 && (stoi(s.substr(cur+1,len-cur-1)) > 255 || s[cur + 1] == '0'))
                    {
                        return false;
                    }
                }
            }
        }
                
      return true;  
    }
   
   
    
   void dfs(string s,int pos,int num){
        //cout<<s<<" "<<num<<endl;
        if(num == 0 ){
            if(valid_ip(s)){
                result.push_back(s);
            }
            return;
        }
       
        
        int len = s.size();
        
        if(num > 0){
            for(int i = pos +2; i<len ;i++){
                
                s.insert(i,".");
                
                dfs(s,i,num-1);
                s.erase(s.begin() + i);
                //return;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        
        int len = s.size();
        if(len<4 || len>12) return result;
        
        for(int i=1;i<4;i++)
        {
            s.insert(i,".");
            dfs(s,i,2);
            s.erase(s.begin() + i);
            
        }
        return result;
    }
};