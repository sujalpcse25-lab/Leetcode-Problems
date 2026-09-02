class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx = 0, sy = 0;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0)
            return 0;

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        int startMask = (1 << cnt) - 1;

        q.push({sx, sy, energy, startMask});
        visited[sx][sy][energy][startMask] = true;

        int moves = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [x, y, curEnergy, mask] = q.front();
                q.pop();

                if (mask == 0)
                    return moves;

                if (curEnergy == 0)
                    continue;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    if (classroom[nx][ny] == 'X')
                        continue;

                    int newEnergy = curEnergy - 1;

                    if (classroom[nx][ny] == 'R')
                        newEnergy = energy;

                    int newMask = mask;

                    if (classroom[nx][ny] == 'L') {
                        newMask &= ~(1 << id[nx][ny]);
                    }

                    if (!visited[nx][ny][newEnergy][newMask]) {
                        visited[nx][ny][newEnergy][newMask] = true;

                        q.push({
                            nx,
                            ny,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};