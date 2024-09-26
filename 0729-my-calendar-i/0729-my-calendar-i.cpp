class MyCalendar {
public:
    vector<int> arr;
    unordered_map<int,int> mpp;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto x = lower_bound(arr.begin(),arr.end(),start);
        if(x == arr.end() || end <= mpp[*x] || start > *x ) {
            arr.insert(x,end-1);
            mpp[end-1] = start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */