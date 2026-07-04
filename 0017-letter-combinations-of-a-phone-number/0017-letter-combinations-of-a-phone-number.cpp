class Solution {
private:
    const vector<string> phoneMap = {
        "",     "",     "abc",  "def",  
        "ghi",  "jkl",  "mno",  "pqrs", 
        "tuv",  "wxyz"                  
    };

    void backtrack(const string& digits, int index, string& currentCombination, vector<string>& result) {
        
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }

        string letters = phoneMap[digits[index] - '0'];
        
        for (char letter : letters) {
            currentCombination.push_back(letter);       
            backtrack(digits, index + 1, currentCombination, result);
            currentCombination.pop_back();              
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        string currentCombination = "";
        backtrack(digits, 0, currentCombination, result);
        return result;
    }
};