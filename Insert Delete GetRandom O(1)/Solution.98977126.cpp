class RandomizedSet {
private:
    unordered_map<int, int> hash;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (!hash[val]) {
            v.push_back(val);
            hash[val] = v.size();
            return 1;
        }
        return 0;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash[val]) {
            hash[v[v.size() - 1]] = hash[val];
            swap(v[hash[val] - 1], v[v.size() - 1]);
            v.pop_back();
            hash[val] = 0;
            return 1;
        }
        return 0;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */