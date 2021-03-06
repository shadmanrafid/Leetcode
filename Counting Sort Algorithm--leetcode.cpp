#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        vector<int>cnt(3,0);
        vector<int>output(len,NULL);
        int i;
        for(i = 0; i < len; i++)
        {
            cnt[nums[i]]++;
        }
        for(i = 0; i < len; i++)
        {
            if(i == 0)
                continue;
            else cnt[i] += cnt[i-1];
        }
        for(i=0; i < len; i++)
        {
            output[cnt[nums[i]]-1] = nums[i];
            cnt[nums[i]]--;

        }
        for(i = 0; i<len; i++)
        {
            nums[i] = output[i];
            printf("%d ",nums[i]);
        }


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
        vector<int> nums = stringToIntegerVector(line);

        Solution().sortColors(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}
