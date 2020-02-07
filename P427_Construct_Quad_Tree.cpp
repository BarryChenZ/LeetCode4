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
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return construct (grid, 0, 0, grid.size ());
    }
    Node* construct (vector<vector<int>> &grid, int r, int c, int size) {
        if (size == 0)
            return NULL;

        if (size == 1)
            return new Node (grid[r][c], true, NULL, NULL, NULL, NULL);

        // scan for impurities. even just one impurity in the entire space 
        // decays representation from 1 node to 4 child nodes.
        bool impure = false;
        int lastval = grid[r][c];
        for (int i = r; i < r + size && impure == false; i++)
            for (int j = c; j < c + size && impure == false; lastval = grid [i][j], j++)
                impure = lastval != grid [i][j];

        if (!impure)
            return new Node (grid[r][c], true, NULL, NULL, NULL, NULL);

        return new Node (false, false, 
                         construct (grid, r, c, size/2),
                         construct (grid, r, c + size/2, size/2),
                         construct (grid, r + size/2, c, size/2),
                         construct (grid, r + size/2, c + size/2, size/2));
    }
};
