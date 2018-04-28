class Solution {
public:
    bool dfs(int v, vector<int>& u, vector<vector<int> > &g) {
        u[v] = 1;
        bool cur = 1;
        for (const int& to : g[v]) {
            if (u[to] == 1) {
                return 0;
            }
            if (!u[to]) {
                cur = dfs(to, u, g);
            }
        }
        u[v] = 2;
        return cur;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = prerequisites.size();
        if (numCourses < 2 || n < 2) {
            return 1;
        }
        vector<vector<int> > g(numCourses,vector<int>());
        for (int i = 0; i < n; ++i) {
            g[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> u(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (!u[i] && !dfs(i, u, g)) {
                return 0;
            }
        }
        return 1;
    }
};