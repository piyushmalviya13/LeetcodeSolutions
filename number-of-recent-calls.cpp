class RecentCounter {
public:
    vector <int> req;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        req.push_back(t);
        int min = t - 3000;
        int c = 0;
        for(int i = req.size()-1;i>=0;i--) {
            if(req[i] >= min) c++;
            else break;
        }
        
        return c;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
