class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int l =0,r = skill.size()-1;
        int temp = -1;
        sort(skill.begin(),skill.end());
        long long ans = 0;
        while(l<r) {
            if(temp == -1) {
                temp = skill[l]+skill[r];
            }
            else if(temp != skill[l]+skill[r]) return -1;
            ans += (skill[l]*skill[r]);
            l++;
            r--;
        }
        return ans;
    }
};