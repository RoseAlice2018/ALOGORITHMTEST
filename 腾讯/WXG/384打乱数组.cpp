#include<vector>
using namespace std;
class Solution {
public:
    Solution(vector<int>& nums) {
        store = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return store;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> after_shuffle(store.size());
        vector<int> exist(store.size(),0);
        for(int i=0;i<store.size();i++)
        {
            int k = rand()%store.size();
            while(exist[k])
                k = rand()%store.size();
            exist[k]=1;
            after_shuffle[k]=store[i];
        }
        return after_shuffle;
    }
    vector<int> store;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */