class Solution {
private:
    vector<vector<string>> result;
    unordered_map<string,vector<string>>hash;
public:
    void dfs(string beginWord,string endWord, vector<string>path){
        path.push_back(beginWord);
        if(beginWord == endWord){
            result.push_back(path);
            return;
        }
        for(auto word:hash[beginWord]){
            dfs(word,endWord,path);
        }
        
        
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size() == 0) return result;
        unordered_set<string>wordSet;
        for(auto word:wordList) wordSet.insert(word);
        queue<string>adj;
        adj.push(beginWord);

        string top;
        unordered_set<string>words;
        bool setbreak = false;
        int len = 0,word_length = beginWord.size();
        int i;
        string temp;
        char ch;
        while(!adj.empty()){
            words.clear();
            len = adj.size();
            for(i = 0; i<len;i++){
                top = adj.front();
                adj.pop();
                if(top == endWord) setbreak = true;
                words.insert(top);
                wordSet.erase(top);
            }
            if(setbreak) break;
            
            for(auto word:words){
                
                for(i = 0; i < word_length; i++){
                    temp = word;
                    for(ch = 'a'; ch<='z'; ch++){
                        temp[i] = ch;
                        if(temp != word && wordSet.find(temp) != wordSet.end()){
                            hash[word].push_back(temp);
                            adj.push(temp);
                            
                            
                        }
                    
                    }
                }
                
            }
        }

        vector<string>path;
        path.push_back(beginWord);
        for(auto word:hash[beginWord])
            dfs(word,endWord,path);
        return result;
        
        
    }
};


