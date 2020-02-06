class Solution {
private:
    unordered_map<char,string>hash_map;
    vector<string> result;
    
    void backtrack(string possibility,int last,int len,string digits){
        if(last == len-1){
            result.push_back(possibility);
            return;
        }
        
        string str = hash_map[digits[last+1]];
        char ch;
        for(int i = 0;i<str.size();i++){
            possibility += str[i];
            backtrack(possibility,last+1,len,digits);
            possibility.erase(last+1,1);
            }
        
    }
    
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.length(); 
        if(len == 0)  return result;
        hash_map['2'] = "abc";
        hash_map['3'] = "def";
        hash_map['4'] = "ghi";
        hash_map['5'] = "jkl";
        hash_map['6'] = "mno";
        hash_map['7'] = "pqrs";
        hash_map['8'] = "tuv";
        hash_map['9'] = "wxyz";
        
        string str = hash_map[digits[0]];
        char ch;
        string possibility = "";
        for(int i = 0;i<str.size();i++){
            possibility += str[i];
            backtrack(possibility,0,len,digits);
            possibility.erase(0,1);
            
        }
        return result;
        
    }
};