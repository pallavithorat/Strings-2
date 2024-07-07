class Solution { //TC : O(N) , SC:O(N)
public:
    bool allZero(vector<int>& counter) {
        for (int &i : counter) {
            if (i != 0)
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string txt, string pat) {
        int n = txt.size();
        vector<int> counter(26, 0);

        for (int i = 0; i < pat.length(); i++) {
            char ch = pat[i];
            counter[ch - 'a']++;
        }

        int i = 0, j = 0;
        vector<int> result;
        int k = pat.length();

        while (j < n) {
            // Decrement the count of the current character in the counter
            counter[txt[j] - 'a']--;

            // Check if the window size matches the size of the pattern
            if (j - i + 1 == k) {
                if (allZero(counter)) {
                    result.push_back(i);
                }
                // Slide the window to the right: increment the count of the character at position i
                counter[txt[i] - 'a']++;
                i++;
            }
            j++;
        }

        return result;
    }
};