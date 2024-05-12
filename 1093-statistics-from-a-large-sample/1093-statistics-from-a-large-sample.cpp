class Solution {
public:
    double find(vector<int> &count,int cnt) {
        bool f = false, sec = false;
        if(cnt & 1) {
            f = true;
            cnt = cnt/2+1;
            double m1 = 0,m2 =0;
            for(int i =0; i<count.size(); i++) {
                if(count[i] == 0) continue;
                cout<<i<<endl;
                for(int j = 1; j<= count[i]; j++) {
                    cnt--;
                    if(cnt <= 0) {
                        //cout<<i<<endl;
                        if(f) return i;
                        if(!sec) {
                            m1 = i;
                            sec = true;
                        }
                        else {
                            m2 = i;
                            return (m1+m2)/2;
                        }
                    }
                }
            }
        }
        cnt = cnt/2;
        double m1 = 0,m2 =0;
        for(int i =0; i<count.size(); i++) {
            if(count[i] == 0) continue;
            cout<<i<<endl;
            for(int j = 1; j<= count[i]; j++) {
                cnt--;
                if(cnt <= 0) {
                    //cout<<i<<endl;
                    if(f) return i;
                    if(!sec) {
                        m1 = i;
                        sec = true;
                    }
                    else {
                        m2 = i;
                        return (m1+m2)/2;
                    }
                }
            }
        }
        //cout<<m1<<" "<<m2<<endl;
        return (m1+m2)/(double)2;
    }
    vector<double> sampleStats(vector<int>& count) {
        double mini = INT_MAX;
        double maxi = 0;
        double sum = 0.0;
        int cntMax = 0;
        double mode = 0.0;
        int cnt = 0;
        int n= count.size();
        for(int i =0; i<n; i++) {
            if(count[i]== 0) continue;
            maxi = max(maxi,(double)i);
            mini = min(mini,(double)i);
            sum += (((double)i)*count[i]);
            if(cntMax < count[i]) {
                mode = i;
                cntMax = count[i];
            }
            cnt += count[i];
        }
        cout<<cnt<<endl;
        double mean = sum/cnt;
        double meadian = find(count,cnt);
        return {mini,maxi,mean,meadian,mode};
    }
};