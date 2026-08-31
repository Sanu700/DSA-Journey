class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;   // minimum possible number of open '('
        int high = 0;  // maximum possible number of open '('

        for(char c : s) {

            if(c == '(') {
                low++;
                high++;
            }
            else if(c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // treat '*' as ')'
                high++;  // treat '*' as '('
            }

            // Even the maximum possible balance is negative
            if(high < 0)
                return false;

            // We can never have negative open brackets
            low = max(low, 0);
        }

        return low == 0;
    }
};