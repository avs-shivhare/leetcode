class ExamTracker {
public:
    vector<vector<long long>> ans;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        if(ans.empty()) ans.push_back({time,score});
        else {
            ans.push_back({time,1ll*score+ans.back().back()});
        }
    }
    
    int upper(long long end) {
        int l = 0, r = ans.size()-1;
        int t = -1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(ans[mid][0] <= end) {
                t = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return t;
    }

    int lower(long long end) {
        int l = 0,r = ans.size()-1;
        int t = -1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(ans[mid][0] < end) {
                t = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return t;
    }

    long long totalScore(int s, int e) {
        int r = upper(e);
        int l = lower(s);
        if(r == -1) return 0;
        long long sum = ans[r][1];
        if(l != -1) sum -= ans[l][1];
        return sum;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */