class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (empty(M) || empty(M[0])) return 0;
        vector<int> p(size(M));
        iota(begin(p), end(p), 0);
        for (int i = 0; i < size(M); ++i)
        {
            for (int j = 0; j < size(M[0]); ++j)
            {
                if (M[i][j] == 1)
                {
                    join(p, i, j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < size(p); ++i)
        {
            if (p[i] == i) ++res;
        }
        return res;
    }
    
    int find(vector<int>& p, int i)
    {
        while (p[i] != i) i = p[i];
        return i;
    }

    void join(vector<int>& p, int a, int b)
    {
        p[find(p, b)] = p[find(p, a)];
    }
};