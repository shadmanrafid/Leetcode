class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size();
        vector<int>::iterator it;
        
        vector <int> res;

        for(int i = 0; i < len; ++i)
        {
            //finding where nums1[i] is, in nums2
            it = find (nums2.begin(), nums2.end(), nums1[i]);
            bool flag = false;
            while(it != nums2.end())
            {
                if (*it > nums1[i])
                {
                    res.push_back(*it);
                    flag = true;
                    break;                   
                }         
                ++it;
            }//while
            
            if (flag==false)
                res.push_back(-1);          
        }        
       return res;
        
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