class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int n : nums) {
            freq[n]++;
            if (freq[n] > nums.size() / 2) {
                return n;
            }
        }
        return -1;
    }
};