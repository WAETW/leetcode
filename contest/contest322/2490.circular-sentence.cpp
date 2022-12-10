class Solution {
   public:
    bool isCircularSentence(string sentence) {
        istringstream in(sentence);
        vector<string> v;
        string t;
        while (in >> t) {
            v.push_back(t);
        }
        int n = v.size();
        if (n == 1) {
            if (*prev(v[0].end()) != *v[0].begin()) {
                return false;
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (*prev(v[i].end()) != *v[i + 1].begin()) {
                return false;
            }
            if (i == n - 2) {
                if (*prev(v[i + 1].end()) != *v[0].begin()) {
                    return false;
                }
            }
        }
        return true;
    }
};