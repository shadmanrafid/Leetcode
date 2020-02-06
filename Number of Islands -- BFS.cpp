class Solution {


public:
    int numIslands(vector<vector<char>>& grid) {

        int height = grid.size();
        if(height == 0) return 0;
        int breadth = grid[0].size();
        pair<int,int> top;
        queue<pair<int,int>>q;
        int islands = 0;
        for(int i = 0; i < height; i++)
            for(int j = 0; j < breadth; j++)
            {
                if(grid[i][j] == '1'){
                    islands++;
                    grid[i][j] = '0';

                    q.push({i,j});

                    while(!q.empty())
                    {
                        top = q.front();
                        int row = top.first;
                        int col = top.second;
                        q.pop();
                        if(row-1 >=0 && grid[row-1][col] == '1')
                        {
                            q.push({row-1,col});
                            grid[row-1][col] = '0';
                        }

                        if(col-1 >= 0 && grid[row][col-1] == '1')                                                     {
                            q.push({row,col - 1});
                            grid[row][col-1] = '0';
                        }


                        if(col+1 <breadth && grid[row][col +1] == '1')                                                  {
                            q.push({row,col + 1});

                            grid[row][col +1] = '0';
                        }
                        if(row+1 <height && grid[row +1][col] == '1')                                                 {
                            q.push({row+1,col});

                            grid[row+1][col] = '0';
                        }





                    }

                }
            }
        return islands;
    }
};