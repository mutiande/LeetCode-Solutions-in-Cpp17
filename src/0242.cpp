class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26);
        for (auto& x : s) ++v[x - 'a'];
        for (auto& x : t) --v[x - 'a'];
        return !any_of(begin(v), end(v), [](int x) { return x != 0; });
    }
};