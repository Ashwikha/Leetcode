class Solution {
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

public:
    void recursive(int n, int op, int cl, string temp, vector<string>& ans) {
        if (temp.length() == (2 * n)) {
            ans.push_back(temp);
        }
        if (op < n)
            recursive(n, op + 1, cl, temp + '(', ans);

        if (cl < op)

            recursive(n, op, cl + 1, temp + ')', ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        int op = 0;
        int cl = 0;
        recursive(n, op, cl, temp, ans);
        return ans;
    }
};