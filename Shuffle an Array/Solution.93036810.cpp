class Solution {
private:
vector<int> arr;
vector<int> init;
public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        arr = nums;
        init = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr = init;
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(arr.begin(), arr.end());
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */