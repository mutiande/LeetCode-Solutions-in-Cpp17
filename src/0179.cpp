class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (all_of(begin(nums), end(nums), [](int x) { return x == 0; }))
        {
            return "0";
        }
        vector<string> v;
        transform(begin(nums), end(nums), back_inserter(v), [](int x) { return to_string(x); });
        sort(begin(v), end(v), [](const string& x, const string& y) { return x + y > y + x; });
        return accumulate(begin(v), end(v), string{""});
    }
};