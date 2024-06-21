class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grm, int k) {
        int n = grm.size();
        vector<int> prefix(n,0), suffix(n,0);
        int start = 0,end = 0;
        for(int i =0; i<n; i++) {
            prefix[i] = start;
            suffix[n-i-1] = end;
            if(grm[i] == 0) {
                start+= cust[i];
            }
            if(grm[n-i-1] == 0) {
                end+= cust[n-i-1];
            }
        }
        int i = 0,j =0;
        int maxi = 0;
        int sum = 0;
        while(i<n && i-j+1 < k) {
            sum += cust[i];
            i++;
        }
        maxi = max(maxi,(j<n?prefix[j]:0)+sum+(i<n?suffix[i]:0));
        while(i<n) {
            sum += cust[i];
            maxi = max(maxi,prefix[j]+sum+suffix[i]);
            sum -= cust[j];
            i++;
            j++;
        }
        return maxi;
    }
};