class Solution {
public:
#define ll long long
    long long countSubarrays(vector<int>& a, int k) {

        ll maxi = *max_element(a.begin(), a.end());
        int n = a.size();

        ll i = 0, j = 0, c = 0, ans = 0;

        unordered_map<int, int> mp;

        while (j < n) {

            mp[a[j]]++;

            while (mp[maxi] >= k) {

                mp[a[i]]--;

                if (mp[a[j]] == 0) {
                    mp.erase(a[j]);
                }

                i++;
            }

            ans +=i;
            j++;
        }
        return ans;
    }
};