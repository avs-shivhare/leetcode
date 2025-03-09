class Sg {
    public:
    int n = 0;
    vector<int> seg;
    vector<int> nums;
    Sg(int size,vector<int> &temp) {
        nums = temp;
        n = size;
        seg.resize((4*n)+1,-1);
        build(0,n-1,0);
    }
    void build(int l,int r,int ind) {
        if(l == r) {
            seg[ind] = l;
            return;
        }
        //cout<<l<<" "<<r<<" "<<ind<<endl;
        int mid = (l+r)>>1;
        build(l,mid,2*ind+1);
        build(mid+1,r,2*ind+2);
        if(nums[seg[2*ind+1]] > nums[seg[2*ind+2]]) {
            seg[ind] = seg[2*ind+1];
        }
        else seg[ind] = seg[2*ind+2];
        return;
    }
    int find(int l,int r,int ind,int el) {
        if(l>r) return -1;
        if(l == r) {
            if(nums[l] >= el) {
                nums[l] = 0;
                return l;
            }
            return -1;
        }
        int mid = (l+r)>>1;
        if(nums[seg[ind]] < el) return -1;
        int temp = find(l,mid,2*ind+1,el);
        if(temp == -1) {
            temp = find(mid+1,r,2*ind+2,el);
        }
        if(nums[seg[2*ind+1]] > nums[seg[2*ind+2]]) {
            seg[ind] = seg[2*ind+1];
        }
        else seg[ind] = seg[2*ind+2];
        return temp;
    }
};
class Solution {
public:

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        Sg s(n,baskets);
        int cnt = 0;
        for(auto i: fruits) {
            int ans = s.find(0,n-1,0,i);
            if(ans == -1) cnt++;
            //cout<<ans<<" "<<i<<endl;
        }
        return cnt;
    }
};