/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    int i;
    int c = 0;
    vector<NestedInteger> list;
    stack<pair<NestedInteger, int> > s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        i = -1;
        list = nestedList;
    }

    int next() {
        /*if (s.empty()) {
            ++i;
            s.push(make_pair(list[i], 0));
            while (!s.top().first.isInteger() && s.top().first.getList().size()) {
                s.push(make_pair(s.top().first.getList()[0], 0));
            }
        }
        int val = s.top().first.getInteger();
        s.pop();
        while (!s.empty() && s.top().second >= s.top().first.getList().size() - 1) {
            s.pop();
        }
        if (!s.empty()) {
            ++s.top().second;
            s.push(make_pair(s.top().first.getList()[s.top().second], s.top().second));
            while (!s.top().first.isInteger() && s.top().first.getList().size()) {
                s.push(make_pair(s.top().first.getList()[0], 0));
            }
        }*/
        int val = s.top().first.getInteger();
        s.pop();
        //if (c< 10) {++c; cout << val << " ";}
        return val;
    }
    
    bool find_next(NestedInteger n) {
        if (n.isInteger()) {
            return 1;
        }
        for (int j = 0; j < n.getList().size(); ++j) {
            s.top().second = j;
            s.push(make_pair(n.getList()[j], 0));
            if (find_next(n.getList()[j])) {
                return 1;
            }
            s.pop();
        }
        return 0;
    }

    bool hasNext() {
        while (!s.empty() && s.top().second >= s.top().first.getList().size() - 1) {
            s.pop();
        }
        if (s.empty()) {
            if (i == (int)list.size() - 1) {
                return 0;
            }
            while(i < (int)list.size() - 1) {
                ++i;
                s.push(make_pair(list[i], 0));
                if (find_next(list[i])) {
                    return 1;
                }
                s.pop();
            }
        }
        /*auto out = s;
        while (!out.empty()) {
            cout << out.top().second << " ";
            out.pop();
        }
        cout << endl;*/
        while (!s.empty()) {
            int cur = s.top().second;
            vector<NestedInteger> l = s.top().first.getList();
            for (int j = cur + 1; j < l.size(); ++j) {
                s.top().second = j;
                s.push(make_pair(l[j], 0));
                if (find_next(l[j])) {
                    return 1;
                }
                s.pop();
            }
            s.pop();
        }
        return 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */