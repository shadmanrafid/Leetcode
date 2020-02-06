class Solution {
private:
    unordered_map<char,int>hash;
    string mid = "";
public:
    vector<string> generatePalindromes(string s) {

        for(auto item : s)
            hash[item]++;

        vector<string> result;

        for (auto& it : hash) {
            if (it.second % 2 == 1){
                mid += it.first;
                it.second--;
            };
            if (mid.size() > 1) return {};
        }

        buildPalindromes(result,"",s.size(),hash);

        return result;
    }

private:

    void buildPalindromes(vector<string>&result,string item,int lens,unordered_map<char,int>&hash){

        if(item.size() * 2 + mid.size() == lens){
            result.push_back(item + mid + string(item.rbegin(),item.rend()));
            return;
        }
        for(auto&val : hash){
            if(val.second != 0){
                val.second -= 2;
                buildPalindromes(result,item + val.first, lens, hash);
                val.second += 2;
            }
        }
    }

};