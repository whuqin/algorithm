/***************************************************************************
 * 
 * Copyright (c) 2014. All Rights Reserved
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 **************************************************************************/
#include <vector>
#include <queue>
using namespace std;

struct node {
    int x;
    int y;
    node(int i_x, int i_y):x(i_x), y(i_y){}
};
bool** visited;
int direction[4][4] = {{0,1},{0,-1},{1,0},{-1,0}};

//find the item who is 'o' and adjacent to the boundary 'o'
void bfs(vector<vector<char> >& board, int x, int y) {
    queue<node> node_q;
    node tmp(x, y);
    node_q.push(tmp);
    while (!node_q.empty()) {
        node tmp = node_q.front();
        node_q.pop();
        board[tmp.x][tmp.y] = '*';
        visited[tmp.x][tmp.y] = true;
        for (int i = 0; i < 4; ++i) {
            int tmp_x = tmp.x + direction[i][0];
            int tmp_y = tmp.y + direction[i][1];
            if (tmp_x >= 0 && tmp_x < board.size() && tmp_y >= 0 && tmp_y < board[0].size() 
                    && !visited[x][y] && board[tmp_x][tmp_y] == 'O') {
                node_q.push(node(tmp_x, tmp_y));
            }
        }
    }
}

void solve(vector<vector<char> > &board) {
    if (board.size() == 0 || board[0].size() == 0) {
        return;
    } else if (board.size() <= 2 || board[0].size() <= 2) {
        return;
    }
    int rows = board.size();
    int cols = board[0].size();
    visited = new bool*[rows];
    for (int i = 0; i < rows; ++i) {
        visited[i] = new bool[cols];
        for (int j = 0; j < cols; ++j) {
            visited[i][j] = false;
        }
    }
    //bfs the boundary 'o'
    for (int i = 0; i < board.size(); ++i) {
        if (board[i][0] == 'O' && !visited[i][0]) {
            bfs(board, i, 0);
        }
        if (board[i][cols - 1] == 'O' && !visited[i][cols - 1]) {
            bfs(board, i, cols - 1);
        }
    }
    for (int i = 0; i < board[0].size(); ++i) {
        if (board[0][i] == 'O' && !visited[0][i]) {
            bfs(board, 0, i);
        }
        if (board[rows-1][i] == 'O' && !visited[rows-1][i]) {
            bfs(board, rows-1, i);
        }
    }
    //transfer * to o
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == '*') {
                board[i][j] = 'O';
            } else {
                board[i][j] = 'X';
            }
        }
    }
}
int main() {
    vector<vector<char> > vec;
    solve(vec);
}
/* vim: set ts=4 sw=4 sts=4 tw=100 */
