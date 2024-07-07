//TC : O(m+n)
//SC: O(1)


class Solution {
public:
    int strStr(string haystack, string needle) {
         int m = haystack.length();
        int n = needle.length();

        if (n > m) return -1;

        long long hash = 0;
        long long k = 26;
        long long mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            char c = needle[i];
            hash = (hash * k + (c - 'a' + 1)) % mod;
        }

        long long hash2 = 0;
        long long knMinus1 = 1;
        for (int i = 0; i < n - 1; i++) {
            knMinus1 = (knMinus1 * k) % mod;
        }

        for (int i = 0; i < m; i++) {
            if (i >= n) {
                // Remove the leading character of the previous window
                char leadingChar = haystack[i - n];
                hash2 = (hash2 - (leadingChar - 'a' + 1) * knMinus1 % mod + mod) % mod;
            }

            char b = haystack[i];
            hash2 = (hash2 * k + (b - 'a' + 1)) % mod;

            if (i >= n - 1 && hash == hash2) {
                return i - n + 1;
            }
        }
        return -1;
    }
};