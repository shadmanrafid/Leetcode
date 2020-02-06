class Solution {
public:
    // THE RIGHT SOLUTION IS TRAVERSE FROM GATE TO ROOMS!
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;
        int m = rooms.size();
        int n = rooms[0].size();
        int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        const int INF = 2147483647;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 0)
                    q.push(make_pair(i, j));
        while (!q.empty()) {
            int step = rooms[q.front().first][q.front().second];
            step++;
            for (int k = 0; k < 4; k++) {
                int i = q.front().first + d[k][0];
                int j = q.front().second + d[k][1];
                if (-1 < i && i < m && -1 < j && j < n && rooms[i][j] == INF) {
                    rooms[i][j] = rooms[i][j] > step ? step : rooms[i][j];
                    q.push(make_pair(i, j));
                }
            }
            q.pop();
        }
    }
};