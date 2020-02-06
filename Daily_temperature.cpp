class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result;
        int len = T.size();
        int ret[len];
        int next[101];
        int i,j,k;
        unordered_map<int,vector<int>>days;
        for(i=0;i<len;i++)
        {
            ret[i] = INT_MAX;
        }
        for(i =0;i<101;i++)
        {
            next[i] = INT_MAX;
        }

        for(i = 0; i < len; i++)
        {
            warmer_index = INT_MAX
            for(j = T[i]+1; j<=100; j++)
            {
                if(next[j] < warmer_index)
                warmer_index = next[j];
                
            }
            if(warmer_index<INT_MAX)
                ret[i] = warmer_index -i;

            next[T[i]] = i
        }
        for(i=0;i<len;i++)
        {
            if(ret[i]==INT_MAX)
                ret[i] =0;
            result.push_back(ret[i]);
        }
        return result;
        
        
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
        vector<int> T = stringToIntegerVector(line);
        
        vector<int> ret = Solution().dailyTemperatures(T);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}