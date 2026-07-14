class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char ch : s)
            freq[ch]++;

        // Store in vector
        vector<pair<char, int>> vec(freq.begin(), freq.end());

        // Sort by frequency (descending)
        sort(vec.begin(), vec.end(),
             [](pair<char, int>& a, pair<char, int>& b) {
                 return a.second > b.second;
             });

        string ans = "";

        // Build answer
        for (auto &p : vec) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};