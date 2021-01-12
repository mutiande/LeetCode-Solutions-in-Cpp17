class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.emplace(begin(nums), 1);
        nums.emplace_back(1);
        int sz = size(nums);
        vector<vector<int>> dp(sz, vector<int>(sz));
        for (int n = 2; n < sz; ++n)
        {
            for (int i = 0; i + n < sz; ++i)
            {
                for (int j = i + 1; j < i + n; ++j)
                {
                    dp[i][i + n] = max(dp[i][i + n], dp[i][j] + dp[j][i + n] + nums[i] * nums[j] * nums[i + n]);
                }
            }
        }
        return dp[0][sz - 1];
    }
};