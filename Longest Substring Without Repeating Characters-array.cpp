int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len < 2)
        {
            return len;
        }
        int last_idx[128];
        
        int first = 0;
        int i;
        int max_len = 1;
        int cur_len = 0;


        for(i = 0; i< 128 ; i++)
        {
            last_idx[i] = -1;
        }
        for(i = 0; i<len; i++)
        {
            if(last_idx[s[i]] < 0)
            {
                cur_len++;
                last_idx[s[i]] = i;
            }
            else
            {
                if(cur_len > max_len)
                    max_len = cur_len;
                if(first > last_idx[s[i]])
                    cur_len = i - first +1;
                else
                {
                    cur_len = i - last_idx[s[i]];
                    first = last_idx[s[i]] +1;
                }
                last_idx[s[i]] = i;
            }
        }
        if(cur_len > max_len)
            max_len= cur_len;
       
        return max_len;
    }
};