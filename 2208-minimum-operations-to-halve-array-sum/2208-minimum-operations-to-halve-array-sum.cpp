class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> q;
        double sum = 0.0;
        for(int i: nums) {
            sum += i;
            q.push((double)i);
        }
        int i =0;
        double sum2 = sum;
        sum /=2;
        //cout<<sum<<" "<<sum2<<endl;
        while(true) {
            if(sum2 <= sum) {
                break;
            }
            double t1 = q.top();
            q.pop();
            double ans = t1/2;
            //cout<<ans<<endl;
            q.push(ans);
            sum2 -= ans;
            //cout<<sum2<<endl;
            i++;
        }
        return i;
    }
};