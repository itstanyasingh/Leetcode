class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int index, vector<int>& candidates, int target) {

        // Base Case
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (index == candidates.size())
            return;

        // Take current element
        if (candidates[index] <= target) {
            curr.push_back(candidates[index]);
            solve(index, candidates, target - candidates[index]); // same index
            curr.pop_back(); // Backtrack
        }

        // Skip current element
        solve(index + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        solve(0, candidates, target);
        return ans;
    }
};