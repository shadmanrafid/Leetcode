class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int height = rooms.size();
        if(height == 0) return;
        int breadth = rooms[0].size();
        queue<pair<int,int>>q;
        int row;
        int col;
        int dis;
        int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i= 0;i<height; i++)
            for(int j=0;i<breadth;j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
                while(!q.empty()){

                    dis = rooms[q.front().first][q.front().second];
                    for(int k = 0;k<4;k++){
                        row = q.front().first + d[k][0];
                        col = q.front().second + d[k][1];
                        if(row <0||row>height||col<0||col>breadth||rooms[row][col] == -1|| rooms[row][col] == 0)continue;
                        if(rooms[row][col] > dis)rooms[row][col] = dis+1;
                        
                    }
                    q.pop();
                        
                }

            }
};