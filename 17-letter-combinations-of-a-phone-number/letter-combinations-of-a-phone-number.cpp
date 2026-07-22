class Solution {
public:

    vector<string> ans;
    string current;

    vector<string> mp = {
        "", "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void solve(int index, string &digits)
    {
        if(index == digits.size())
        {
            ans.push_back(current);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for(char ch : letters)
        {
            current.push_back(ch);

            solve(index + 1, digits);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        solve(0, digits);

        return ans;
    }
};