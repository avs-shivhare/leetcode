class Solution {
public:
    double m = 0;
    bool compare(int t1,int t2) {
        int f = abs(t1-m);
        int s = abs(t2-m);
        if(f > s) return true;
        else if(f == s && t1 > t2) return true;
        return false;
    }
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        int n = arr.size();
        m = temp[(n-1)>>1];
        sort(arr.begin(),arr.end(),[this](int t1,int t2) {
            int f = abs(t1-m);
            int s = abs(t2-m);
            if(f > s) return true;
            else if(f == s && t1 > t2) return true;
            return false;
        });
        cout<<m<<endl;
        vector<int> ans;
        for(int i: arr) cout<<i<<" ";
        cout<<endl;
        for(int i =0; i<n && i<k; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};