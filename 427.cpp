/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

//先建立所有节点再合并的版本，比较慢
class Solution {
    Node *construct(int row, int col, int len, vector<vector<int>> &grid) {
        if (len == 1) return new Node(grid[row][col], true, 0, 0, 0, 0);
        Node *curr = new Node(true, false, 
                              construct(row, col, len>>1, grid), 
                              construct(row, col + (len >> 1), len >> 1, grid), 
                              construct(row + (len >> 1), col, len >> 1, grid), 
                              construct(row + (len >> 1), col + (len >> 1), len >> 1, grid));
        merge(curr);
        return curr;
    }
    void merge(Node *pnode) {
        if (!pnode->topLeft->isLeaf || 
            !pnode->topRight->isLeaf || 
            !pnode->bottomLeft->isLeaf || 
            !pnode->bottomRight->isLeaf) return;
        if (pnode->topLeft->val == pnode->topRight->val &&
           pnode->topRight->val == pnode->bottomLeft->val &&
           pnode->bottomLeft->val == pnode->bottomRight->val) {
            pnode->val = pnode->topLeft->val;
            pnode->isLeaf = true;
            delete pnode->topLeft;
            pnode->topLeft = NULL;
            delete pnode->topRight;
            pnode->topRight = NULL;
            delete pnode->bottomLeft;
            pnode->bottomLeft = NULL;
            delete pnode->bottomRight;
            pnode->bottomRight = NULL;
        }
    }
    
public:
    Node* construct(vector<vector<int>>& grid) {
        return construct(0, 0, grid.size(), grid);
    }
};

//先比较是否相同再深入建立的版本，较快
class Solution {
public:
    
    Node* quadTree(vector<vector<int>>& grid, int x, int y, int offset){
        if (offset <= 0){
            return nullptr;
        }
        //Check if the content of the area is consistent
        for (int i = x; i < x+offset; ++i){
            for (int j = y; j < y+offset; ++j){
                if (grid[i][j] != grid[x][y]){
                    return new Node(false, false,//!isLeaf
                    quadTree(grid, x, y, offset/2),
                    quadTree(grid, x, y+offset/2, offset/2),
                    quadTree(grid, x+offset/2, y, offset/2),
                    quadTree(grid, x+offset/2, y+offset/2, offset/2));
                }
            }
        }//isLeaf
        return new Node(grid[x][y], true, nullptr, nullptr, nullptr, nullptr);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return quadTree(grid, 0,0, grid.size());
    }
};