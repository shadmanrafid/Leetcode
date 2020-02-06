class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        if(s.size() == 1) return false;
        stack<char>stk;
        for(int i =0;i<s.size();i++)
        {
            if(s[i] == ')' )
            {
                if(!stk.empty() && stk.top() == '(') stk.pop();
                else stk.push(s[i]);
            }
            else if(s[i] == '}' )
            {
                if(!stk.empty() && stk.top() == '{') stk.pop();
                else stk.push(s[i]);
            }
            else if(s[i] == ']' )
            {
                if(!stk.empty() && stk.top() == '[') stk.pop();
                else stk.push(s[i]);
            }
            else stk.push(s[i]);
            
        }
        if(stk.empty()) return true;
        else return false;
        
    }
};