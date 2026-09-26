class Solution {
public:
    vector<string> ans;
    string letters[10] = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(int index, string& current, string& digits) {
        
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

       
        string possible = letters[digits[index] - '0'];

        for (char c : possible) {
            current.push_back(c);             
            backtrack(index + 1, current, digits); 
            current.pop_back();                
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string current = "";
        backtrack(0, current, digits);

        return ans;
    }
};