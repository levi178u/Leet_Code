class Solution {
public:
#define ll long long 
    long long countGood(vector<int>& a, int k) {
        
       unordered_map<ll,ll > mp;

        ll ans=0;

        ll n=a.size();


        ll i=0, j=0;

        while(j<n){

            k -=mp[a[j]];
             mp[a[j]]++;

            while(k<=0){

               mp[a[i]]--;
               k += mp[a[i]];

               i++;
            }
            ans +=i;

            j++;
        }

        return ans;

    }
};