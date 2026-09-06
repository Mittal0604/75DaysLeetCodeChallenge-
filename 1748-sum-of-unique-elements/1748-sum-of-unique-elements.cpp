class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int x : nums) {
            count[x]++;
        }
        int sum = 0;
        for (auto pair : count) {
            if (pair.second == 1) {
                sum += pair.first;
            }
        }
        return sum;
    }
};