class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nge;
        vector<int> result;
        stak<int>st;
        int len2 = nums2.size();
        int len1= nums1.size();
        // int ret[len1];
        
        int i,top;
        // for(i =0;i<len1;i++)
        // {
        //     ret[i] = -1;
        // }
        st.push(nums2[0]);
        for( i= 1; i<len2 ;i++)
        {
            
            while(!st.empty()&&st.top()<nums2[i])
            {
                top = st.top();
                st.pop();
                nge[top] = nums2[i];
                //st.push(num2[i]);
            }
            st.push(nums2[i]);
            

        }
        while(!st.empty())
        {
            top = st.top();
            st.pop();
            nge[top] = -1;
        }
        for(i=0;i<len1;i++)
        {
            result.push_back(nge[nums1[i]]);
        }
        return result;
        // for(i=0;i<len1;i++)
        // {
        //     result.push_back(ret[i])
        // }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        vector<int> ret = Solution().nextGreaterElement(nums1, nums2);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}