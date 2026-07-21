class Solution {
public:
    vector<string> ans;

    void solve(string &curr, int open, int close, int n) {

        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            solve(curr, open + 1, close, n);
            curr.pop_back();      // Backtrack
        }

        if (close < open) {
            curr.push_back(')');
            solve(curr, open, close + 1, n);
            curr.pop_back();      // Backtrack
        }
    }

    vector<string> generateParenthesis(int n) {

        string curr = "";
        solve(curr, 0, 0, n);

        return ans;
    }
};