class Solution {
public:
    vector<int> ans;
    vector<int> dp;
    vector<int> temp;
    bool find(int i,int &n,int &len) {
        if(i == len) {
            if(ans < temp) {
                ans = temp;
                return true;
            }
            return false;
        }
        if(temp[i] != -1) {
            //cout<<" done"<<endl;
            return find(i+1,n,len);
        }
        for(int j = n; j>=1; j--) {
            
            if(dp[j] == -1 && i+j < len && j != 1 && temp[i+j] == -1) {
                temp[i] = j;
                temp[i+j] = j;
                dp[j] = 1; 
                if(find(i+1,n,len)) return true;
                temp[i] = -1;
                temp[i+j] = -1;
                dp[j] = -1;
            }
            else if(j == 1 && dp[j] == -1) {
                temp[i] = j;
                dp[j] = 1;
                if(find(i+1,n,len)) return true;
                temp[i] = -1;
                dp[j] = -1;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int len = (n-1)*2+1;
        //cout<<len<<endl;
        ans.resize(len,0);
        temp.resize(len,-1);
        dp.resize(21,-1);
        find(0,n,len);
        return ans;
    }
};