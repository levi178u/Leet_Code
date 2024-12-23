class Solution {
public:
#define ll long long
    long long countSubarrays(vector<int>& a, int k) {

        ll maxi = *max_element(a.begin(), a.end());
        int n = a.size();

        ll i = 0, j = 0, c = 0, ans = 0;

        while (j < n) {

            if (a[j] == maxi) {
                c++;
            }
            while (c >= k) {

                if (a[i] == maxi) {
                    c--;
                }
                i++;
            }
            ans += i;

            j++;
        }
        return ans;
    }
};