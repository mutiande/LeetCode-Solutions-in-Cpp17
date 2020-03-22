class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(begin(people), end(people), [](vector<int>& x, vector<int>& y) {
            return x[0] == y[0] ? x[1] < y[1] : x[0] > y[0];
        });
        vector<vector<int>> res;
        for (auto& x : people)
        {
            res.emplace(begin(res) + x[1], x);
        }
        return res;
    }
};