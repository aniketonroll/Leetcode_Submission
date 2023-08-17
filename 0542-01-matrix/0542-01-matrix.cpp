class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int maxY = mat.size() - 1, maxX = mat[0].size() - 1, qLen, dist = 1;
        queue<pair<int, int>> q;
		// finding our initial frontier and marking all `1` as unvisited
        for (int y = 0; y <= maxY; y++) {
            for (int x = 0; x <= maxX; x++) {
                // flipping 1s
                if (mat[y][x]) mat[y][x] = -1;
                // or adding valid 0s to our first frontier
                else if (y && mat[y - 1][x] || x && mat[y][x - 1] ||
                        y != maxY && mat[y + 1][x] || x != maxX && mat[y][x + 1]) q.push({x, y});
            }
        }
		// BFS time!
        qLen = q.size();
        while (qLen) {
            while (qLen--) {
                // extracting the coordinates of each point in our current frontier
                auto [x, y] = q.front();
                q.pop();
                // looking for unexplored cells and marking them as explored at dist
                // north
                if (y && mat[y - 1][x] == -1) {
                    mat[y - 1][x] = dist;
                    q.push({x, y - 1});
                }
                // west
                if (x && mat[y][x - 1] == -1) {
                    mat[y][x - 1] = dist;
                    q.push({x - 1, y});
                }
                // south
                if (y != maxY && mat[y + 1][x] == -1) {
                    mat[y + 1][x] = dist;
                    q.push({x, y + 1});
                }
                // east
                if (x != maxX && mat[y][x + 1] == -1) {
                    mat[y][x + 1] = dist;
                    q.push({x + 1, y});
                }
            }
            // preparing for the next loop
            dist++;
            qLen = q.size();
        }
        return mat;
    }
};