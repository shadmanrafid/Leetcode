class Solution {
private:
    
    
    void backtrack(int count,int limit,string &path,string &pali,vector<bool>&visited,string &outlier,vector<string>&result){
        if(count == limit){
            string str = path;
            string rev = path;
            reverse(rev.begin(),rev.end());
            str += outlier;
            str += rev;
            result.push_back(str);
            return;
        }
        int i ;
        for(i = 0;i<limit;i++){
            if(i>0 && visited[i-1] != true && pali[i] == pali[i-1]||visited[i] == true) continue;
            visited[i] = true;
            count++;
            path.push_back(pali[i]);
            backtrack(count,limit,path,pali,visited,outlier,result);
            visited[i] = false;
            count--;
            path.pop_back();
        }
    }
        
        
        
public:
    vector<string> generatePalindromes(string s) {
        vector<string>result;
        int len = s.size();
        if(len <2) {
            result.push_back(s);
            return result;
        }
        int i,j;
        unordered_map<int,int>hash_map;
        for(i = 0;i<128;i++){
            hash_map[i] = 0;
        }
        for(i = 0;i<len;i++){
            hash_map[s[i]]++;
            
        }
        int odd = 0, even = 0;
        char ch ;
        for(auto it = hash_map.begin(); it != hash_map.end();it++ ){
            if(hash_map[it->first] != 0 && hash_map[it->first]%2 == 1){
                odd++;
                ch = it->first;
            }
        }
        
        if(odd>1) return result;
        string outlier = "";
        for(i = 0;i<hash_map[ch];i++) outlier += ch;
        string pali = "";
        for(i = 0;i<128;i++){
            if(hash_map[i] !=0 && i != (int)ch){
                for(j=0;j<hash_map[i]/2;j++) pali += (char)i;
            }
        }
        
        vector<bool>visited(pali.size(),false);
        int count = 0;
        int limit = pali.size();
        string path = "";
        sort(pali.begin(),pali.end());
        backtrack(count,limit,path,pali,visited,outlier,result);
        
        return result;
        
    }
};