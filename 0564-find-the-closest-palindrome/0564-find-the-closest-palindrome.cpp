class Solution {
public:
    long long find(long long num,bool even) {
        if(even) {
            string t = to_string(num);
            string x= t;
            reverse(x.begin(),x.end());
            t +=x;
            return stoll(t);
        }
        string t = to_string(num);
        string x = t.substr(0,t.size()-1);
        reverse(x.begin(),x.end());
        t += x;
        return stoll(t);
        
    }
    string nearestPalindromic(string n) {
        int si = n.size();
        int mid = si/2;
        bool even = true;
        if(si%2 == 1) {
            mid++;
            even= false;
        }
        long long first = stoll(n.substr(0,mid));
        vector<long long> temp;
        temp.push_back(find(first+1,even));
        temp.push_back(find(first-1,even));
        temp.push_back(find(first,even));
        temp.push_back((long long)pow(10,si)+1);
        temp.push_back((long long)pow(10,si-1)-1);
        long long result = INT_MAX;
        long long org = stoll(n);
        long long diff = INT_MAX;
        for(auto i: temp) {
            //cout<<i<<endl;
            if(i == org) continue;
            string x = to_string(i);
            string t = x;
            reverse(t.begin(),t.end());
            if(x == t) {
                if(abs(i-org) < diff) {
                    result = i;
                    diff = abs(i-org);
                }
                else if(abs(i-org) == diff) {
                    result = min(i,result);
                }
            }
        }
        return to_string(result);
    }
};