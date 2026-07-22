class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(int start, int k, int remaining) {

        // Valid combination
        if (remaining == 0 && path.size() == k) {
            ans.push_back(path);
            return;
        }

        // Invalid case
        if (remaining < 0 || path.size() > k)
            return;

        for (int i = start; i <= 9; i++) {

            path.push_back(i);

            solve(i + 1, k, remaining - i);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        solve(1, k, n);

        return ans;
    }
};