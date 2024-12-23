class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int k) {

        int sum = 0, i = 0, j = 0;
        int c = 0;

        int n = a.size();
        int ans=0, rem=0;

        unordered_map<int ,int > mp;

        mp[0]=1;

        while(j<n){

            sum += a[j];
             rem= sum -k;

            if(mp.count(rem)){
                
                ans += mp[rem];
            }

            mp[sum]++;
            j++;
        }

        return ans;
    }
};