class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
vector<int> result;
        stack< pair<int,int> >st;
        pair<int,int> a;
        int first,second;
        int len = T.size();
        int ret[len];        
        int i;
        for(i =0;i<len;i++)
        {
            ret[i] = INT_MAX;
        }
        a = make_pair(0,T[0]);
        st.push(a);
        for(i=1;i<len;i++)
        {
            
            while(!st.empty()&&st.top().second<T[i])
            {
                auto b = st.top(); 
                ret[b.first] = i-b.first;
                st.pop();
                if(!st.empty())
                b = st.top();
            }
            
            st.push(make_pair(i,T[i]));

            }
            
        while(!st.empty())
        {
            auto b = st.top();
            ret[b.first] = 0;
            st.pop();
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