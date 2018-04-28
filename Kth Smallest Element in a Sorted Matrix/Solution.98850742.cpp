struct Node {
    int x;
    int i;
    int j;
    Node(int x, int i, int j) : x(x), i(i), j(j) {}
};

bool operator<(const Node& a, const Node& b) {
    return a.x > b.x;
}

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<Node> q;
        for (int i = 0; i < n; ++i) {
            q.push(Node(matrix[0][i], 0, i));
        }
        for (int i = 0; i < k - 1; ++i) {
            Node cur = q.top();
            q.pop();
            if (cur.i < n - 1) {
                q.push(Node(matrix[cur.i + 1][cur.j], cur.i + 1, cur.j));
            }
        }
        return q.top().x;
    }
};