class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long> last;
        int n = skill.size();
        int m = mana.size();
        for(int i = 0; i<m; i++) {
            vector<long long> temp;
            vector<long long> temp2;
            for(int j = 0; j<n; j++) {
                if(i == 0) {
                    temp.push_back(1ll*skill[j]*mana[i]);
                    temp2.push_back(temp.back()+(temp2.size()?temp2.back():0));
                }
                else {
                    temp.push_back(1ll*skill[j]*mana[i]);
                    long long t = temp.back()+(temp2.size()?temp2.back():last[j]);
                    if(j+1<n) t = max(t,last[j+1]);
                    temp2.push_back(t);
                }
            }
            // cout<<"before done"<<endl;
            // for(auto j: temp) cout<<j<<" ";
            // cout<<endl;
            // for(auto j: temp2) cout<<j<<" ";
            // cout<<endl;
            if(i == 0) {
                last = temp2;
            }
            else {
                for(int j = n-1; j>= 0; j--) {
                    if(j == n-1) temp2[j] = max(temp2[j],last[j]+temp[j]);
                    else {
                        temp2[j] = max(temp2[j+1]-temp[j+1],last[j+1]);
                    }
                }
                last = temp2;
            }
            // cout<<"after done"<<endl;
            // for(auto j: temp2) cout<<j<<" ";
            // cout<<endl;
        }
        return last.back();
    }
};