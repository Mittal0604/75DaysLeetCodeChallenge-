class Solution {
    public:
    static bool compare(string a, string b) {
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        // Convert int → string
        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        // Sort using custom comparator
        sort(arr.begin(), arr.end(), compare);

        // Edge case: if largest element is "0"
        if (arr[0] == "0") return "0";

        // Build result string
        string result = "";
        for (string s : arr) {
            result += s;
        }

        return result;
    }
};