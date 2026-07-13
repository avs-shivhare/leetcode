class Solution {
public:
    vector<int> ans;
    string temp ="";
    void find(int i,int &low,int &high,int prev) {
        if(!temp.empty()) {
            //cout<<temp<<endl;
            long long t = stoll(temp);
            if(t >= low && t <= high) ans.push_back(t);
            if(t > high) return;
        }
        if(prev < 9) {
            temp.push_back(prev+1+'0');
            find(i+1,low,high,prev+1);
            temp.pop_back();
        }
        return;
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i = 0; i<9; i++) {
            find(0,low,high,i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};