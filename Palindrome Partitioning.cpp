class Solution {
private:
    vector<vector<string>>result;
    vector<vector<bool>>dp;
    
    
    void backtracking(int idx,string s,vector<string>path){
        if(idx == s.length()-1){
            result.push_back(path);
            return;
        }
        for(int i = idx+1;i<s.length();i++){
            if(dp[idx+1][i] == true){
                path.push_back(s.substr(idx+1,i-idx));
                backtracking(i,s,path);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        
        int len = s.length();
        dp.resize(len,vector<bool>(len,false));
        if(len == 0) return result;
        if(len == 1){
            vector<string>temp = {s};
            result.push_back(temp);
            return result;
        } 
        
        int i,j;
        for(i=0;i<len;i++){
            dp[i][i] = true;
        }
        for(i=1;i<len;i++)
            for(j=0;j<i;j++){
                if(i==j+1 && s[i] == s[j]){
                    dp[j][i] = true;
                }
                else if(dp[j+1][i-1] == 1 && s[j] == s[i]){
                    dp[j][i] = true;
                }
                
            }
        
            
        vector<string>path;
        backtracking(-1,s,path);
        return result;
        
    }
};

