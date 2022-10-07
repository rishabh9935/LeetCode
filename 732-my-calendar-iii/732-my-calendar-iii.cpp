class MyCalendarThree {
public:
    vector<pair<int, int>>all;
    int n;
    
    MyCalendarThree() {
        n = 0;
    }
    
    int book(int start, int end) {
        // inserting the start point in the sorted array
        pair<int, int>val = {start, 0}; // 0 indicates arrival
        auto pos = lower_bound(all.begin(), all.end(), val);
        all.insert(pos, val);
        
        // inserting the second point in the sorted array
        val = {end-1, 1}; // 1 indicates departure
        pos = lower_bound(all.begin(), all.end(), val);
        all.insert(pos, val);
        
        n += 2; // since added two points
        
        int maxi = 0;
        
        // finding the maximum intersection of partitions
        int res = 0;
        for(int i=0; i<n; i++){
            auto t = all[i];
            if(t.second == 0)
                res++;
            else
                res--;
            
            maxi = max(maxi, res);
        }
        
        return maxi;
    }
};