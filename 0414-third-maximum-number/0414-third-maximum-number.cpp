class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = -2147483649LL; 
        long long second = -2147483649LL;
        long long third = -2147483649LL;

        for (int num : nums) {
            // Skip duplicates
            if (num == first || num == second || num == third) {
                continue;
            }

            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        // If third maximum doesn't exist, return the maximum (first)
        return (third == -2147483649LL) ? (int)first : (int)third;
    }
};