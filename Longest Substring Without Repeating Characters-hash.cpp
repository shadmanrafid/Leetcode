class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len < 2)
        {
            return len;
        }
        map<char,int>last_ind;
        
        int first = 0;
        int i;
        int max_len = 1;
        int cur_len = 0;


        for(i = 0; i< len ; i++)
        {
            if(last_ind.find(s[i]) !=last_ind.end())
                continue;
            else
            {
                last_ind[s[i]] = -1;
            }
        }
        for(i = 0; i<len; i++)
        {
            if(last_ind[s[i]] < 0)
            {
                cur_len++;
                last_ind[s[i]] = i;
            }
            else
            {
                if(cur_len > max_len)
                    max_len = cur_len;
                if(first > last_ind[s[i]])
                    cur_len = i - first +1;
                else
                {
                    cur_len = i - last_ind[s[i]];
                    first = last_ind[s[i]] +1;
                }
                last_ind[s[i]] = i;

            }
        }

        if(cur_len > max_len)
            max_len= cur_len;
       
        return max_len;
    }
};