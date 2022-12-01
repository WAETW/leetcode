/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
   public:
    TimeMap() {
    }
    unordered_map<string, vector<pair<int, string>>> mp;
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        if (!mp.count(key))
            return "";
        int l = 0;
        int r = mp[key].size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (mp[key][m].first == timestamp)
                return mp[key][m].second;
            if (mp[key][m].first < timestamp) {
                l = m + 1;
            } else if (mp[key][m].first > timestamp) {
                r = m - 1;
            }
        }
        return r < 0 ? "" : mp[key][r].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
