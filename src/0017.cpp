class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (empty(digits)) return res;
        dfs(digits, res, 0, "");
        return res;
    }

    void dfs(string digits, vector<string>& res, int n, string s)
    {
        if (n == size(digits))
        {
            res.emplace_back(s);
            return;
        }
        for (auto& x : key[digits[n] - '2'])
        {
            s += x;
            dfs(digits, res, n + 1, s);
            s.pop_back();
        }
    }
private:
    vector<string> key = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};