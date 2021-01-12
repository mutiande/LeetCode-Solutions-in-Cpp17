class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = lowerBound(nums, 0, size(nums), target);
        int b = upperBound(nums, 0, size(nums), target);
        return vector<int>{a, b};
    }

    int lowerBound(vector<int>& nums, int l, int r, int target)
    {
        while (l != r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] >= target)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        if (l < size(nums) && nums[l] == target) return l;
        return -1;
    }

    int upperBound(vector<int>& nums, int l, int r, int target)
    {
        while (l != r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] > target)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        if (l > 0 && nums[l - 1] == target) return l - 1;
        return -1;
    }
};