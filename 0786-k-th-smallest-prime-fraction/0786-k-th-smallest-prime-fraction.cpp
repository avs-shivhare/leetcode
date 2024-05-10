class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>> q;
        int n = arr.size();
        for(int i =0;i<n; i++) {
            for(int j =0; j<n; j++) {
                if(q.size() == k) {
                    if(q.top().first > (double)arr[i]/(double)arr[j]) {
                        q.pop();
                        q.push({(double)arr[i]/(double)arr[j],{arr[i],arr[j]}});
                    }
                }
                else {
                    q.push({(double)arr[i]/(double)arr[j],{arr[i],arr[j]}});
                }
            }
        }
        return {q.top().second.first,q.top().second.second};
    }
};