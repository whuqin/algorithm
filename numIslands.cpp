/**
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by 
 * connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 *
 * 11110
 * 11010
 * 11000
 * 00000
 * Answer: 1
 *
 * Example 2:
 *
 * 11000
 * 11000
 * 00100
 * 00011
 * Answer: 3
 */
void traverse(vector<vector<char> > &grid, int row, int col) {
    if (row >= grid.size() || row < 0 || col < 0 || col >= grid[0].size()) {
        return;
    }
    if (grid[row][col] == '0' || grid[row][col] == '*') {
        return;
    }
    grid[row][col] = '*';
    traverse(grid, row, col + 1);
    traverse(grid, row, col - 1);
    traverse(grid, row + 1, col);
    traverse(grid, row - 1, col);
}

int numIslands(vector<vector<char>> &grid) {
    int count = 0;
    for (int row = 0; row < grid.size(); ++row) {
        for (int col = 0; col < grid[0].size(); ++col) {
            if (grid[row][col] == '1') {
                ++count;
                traverse(grid, row, col);
            }
        }
    }
    return count;
}
