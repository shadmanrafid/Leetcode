class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if(len == 0 || len == 1)
            return 0;
        stack<int>stk;
        int longest = 0, current = 0, n = 0,last = -1;
        int first;
        stk.push(-1);
        for( ;n<len;n++)
        {
            if(s[n] == '(') stk.push(n);
            else if(s[n]==')')
            {
                
                stk.pop();
                if(stk.empty()) stk.push(n);
                else
                {
                    first = stk.top();
                    current = n - first;
                    longest = (current > longest)? current:longest;
                } 
                
            }
        }
        return longest;
        
    }


};