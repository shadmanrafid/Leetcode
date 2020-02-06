class Solution {
    void dfs(vector<vector<char>>& grid,int i,int j){
        int height = grid.size();
        int breadth = grid[0].size();
        grid[i][j] = '0';
        stack<pair<int,int>>stk;
        stk.push({i,j});
        
        while(!stk.empty())
        {
            pair<int,int> top = stk.top();
            stk.pop();
            if(grid[top.first][top.second] == '1') grid[top.first][top.second] = '0';
            if(top.first+1 <height && grid[top.first +1][top.second] == '1') stk.push({top.first+1,top.second});
            
            if(top.second+1 <breadth && grid[top.first][top.second +1] == '1') stk.push({top.first,top.second + 1});
            
            if(top.second-1 >= 0 && grid[top.first][top.second-1] == '1') stk.push({top.first,top.second - 1});
            
            if(top.first-1 >=0 && grid[top.first-1][top.second] == '1') stk.push({top.first-1,top.second});
            
        }
        
    }
        
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int height = grid.size();
        if(height == 0) return 0;
        int breadth = grid[0].size();
        
        int islands = 0;
        for(int i = 0; i < height; i++)
            for(int j = 0; j < breadth; j++)
            {
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid,i,j);
                    
                }
            }
        return islands;
    }
};