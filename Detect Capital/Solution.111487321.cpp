class Solution {
public:
    bool detectCapitalUse(string word) {
        bool first = 0;
        if (word.length() < 2) {
            return 1;
        }
        if (word[0] <= 'Z') {
            first = 1;
        }
        bool second = 0;
        if (word[1] <= 'Z') {
            if (!first) {
                return 0;
            }
            second = 1;
        }
        for (int i = 2; i < word.length(); ++i) {
            if ((word[i] <= 'Z' && !second) || (word[i] >='a' && second)) {
                return 0;
            }
        }
        return 1;
    }
};