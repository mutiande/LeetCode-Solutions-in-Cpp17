class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(begin(wordList), end(wordList));
        if (!wordSet.count(endWord)) return 0;

        unordered_set<string> from { beginWord };
        unordered_set<string> to { endWord };
        int res = 1;
        while (!empty(from))
        {
            ++res;
            unordered_set<string> tmp;
            for (auto& x : from) wordSet.erase(x);
            for (auto& x : from)
            {
                for (int i = 0; i < size(x); ++i)
                {
                    string s = x;
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        s[i] = c;
                        if (wordSet.count(s))
                        {
                            if (to.count(s)) return res;
                            tmp.emplace(s);
                        }
                    }
                }
            }
            if (size(tmp) > size(to))
            {
                from = to;
                to = tmp;
            }
            else
            {
                from = tmp;
            }
        }
        return 0;
    }
};