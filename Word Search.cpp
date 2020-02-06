class Solution {
    bool word_forming(vector<vector<char>>& board,int i,int j,string word,int pos){
        if(i< 0 || i >=board.size() || j < 0 || j>=board[i].size()) return false;
        if( board[i][j] == '!' || board[i][j] != word[pos]) return false;
        
        char tmp = board[i][j];
        board[i][j] = '!';
        if(pos == word.size()-1) return true;
        
        if(word_forming(board,i-1,j,word,pos+1) || word_forming(board,i+1,j,word,pos+1) || word_forming(board,i,j-1,word,pos+1) || word_forming(board,i,j+1,word,pos+1)) return true;
        
            
        board[i][j] = tmp;
        
        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || word.size() == 0) return 0;
        bool ret;
        for(int i = 0;i<board.size(); i++)
            for(int j = 0; j< board[i].size(); j++)
            {
                ret = word_forming(board,i,j,word,0);
                if(ret) return true;
            }
        return false;
        
    }
};