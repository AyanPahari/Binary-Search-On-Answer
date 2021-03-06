class Solution {
public:
    int uniquePaths(int m, int n) {
        int x = m + n - 2;
        int y = m - 1;
        unsigned long long res = 1;
        for (int i = 1; i <= y; i++) res = res * (x - y + i) / i;
        return res;
    }
};