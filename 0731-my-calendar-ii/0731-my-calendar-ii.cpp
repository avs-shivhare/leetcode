class MyCalendarTwo {
public:
    vector<pair<int,int>> d,s;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto &i: d) {
            if(max(i.first,start)< min(i.second,end)) return false;
        }
        for(auto &i: s) {
            if(max(i.first,start)< min(i.second,end)) {
                d.push_back({max(i.first,start),min(i.second,end)});
            }
        }
        s.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */