#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>nums;
    int find_max(int n,int k)
    {
        int maxx =INT_MIN;
        for( int i = n-k+1;i<=n;i++)
        {
            maxx = max(maxx,this->nums[i]);
        }
        return maxx;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        this->nums = nums;
        int len = this->nums.size();
        vector<int>res;
        if(len*k == 0)
            return res;
        else if(k == 1)
            return nums;
        int i,j;
        int maxx = find_max(k-1,k);
        res.push_back(maxx);
        for(i = k; i < len;i++)
        {
            if(this->nums[i-k]<maxx)
            {
                maxx = max(maxx,this->nums[i]);
                
            }
            else if(nums[i-k] == maxx)
            {
                maxx = find_max(i,k);
            }
            res.push_back(maxx);
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

int stringToInteger(string input) {
    return stoi(input);
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
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().maxSlidingWindow(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}