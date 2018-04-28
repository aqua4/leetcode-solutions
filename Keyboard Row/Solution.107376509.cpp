class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int row1[127] = {0};
        row1['Q'] = 1;
        row1['q'] = 1;
        row1['W'] = 1;
        row1['w'] = 1;
        row1['E'] = 1;
        row1['e'] = 1;
        row1['R'] = 1;
        row1['r'] = 1;
        row1['T'] = 1;
        row1['t'] = 1;
        row1['Y'] = 1;
        row1['y'] = 1;
        row1['U'] = 1;
        row1['u'] = 1;
        row1['I'] = 1;
        row1['i'] = 1;
        row1['O'] = 1;
        row1['o'] = 1;
        row1['P'] = 1;
        row1['p'] = 1;
        row1['A'] = 2;
        row1['a'] = 2;
        row1['S'] = 2;
        row1['s'] = 2;
        row1['D'] = 2;
        row1['d'] = 2;
        row1['F'] = 2;
        row1['f'] = 2;
        row1['G'] = 2;
        row1['g'] = 2;
        row1['H'] = 2;
        row1['h'] = 2;
        row1['J'] = 2;
        row1['j'] = 2;
        row1['K'] = 2;
        row1['k'] = 2;
        row1['L'] = 2;
        row1['l'] = 2;
        row1['Z'] = 3;
        row1['z'] = 3;
        row1['X'] = 3;
        row1['x'] = 3;
        row1['C'] = 3;
        row1['c'] = 3;
        row1['V'] = 3;
        row1['v'] = 3;
        row1['B'] = 3;
        row1['b'] = 3;
        row1['N'] = 3;
        row1['n'] = 3;
        row1['M'] = 3;
        row1['m'] = 3;
        vector<string> ans;
        for (const auto& word : words) {
            if (word.length() < 2) {
                ans.push_back(word);
                continue;
            }
            int row = row1[word[0]];
            bool bad = 0;
            for (int i = 1; i < word.length(); ++i) {
                if (row1[word[i]] != row) {
                    bad = 1;
                    break;
                }
            }
            if (!bad) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};