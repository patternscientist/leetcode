class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (!mp.contains(key))
            return "";
        auto& vec = mp[key];
        int n = (int)vec.size();
        int l = 0;
        int r = n-1;
        int idx = -1;
        while (l <= r){
            int mid = l + (r-l) / 2;
            if (vec[mid].first <= timestamp){
                idx = mid;
                l   = mid+1;
            } else 
                r   = mid-1;
        }
        return (idx == -1) ? "" : vec[idx].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */