class Solution {
public:
#define ll long long 
    long long maximumSubarraySum(vector<int>& a, int k) {
        
      ll ans=0, sum =0;
      int n= a.size();

     unordered_map< int ,int > mp;

     for(int i=0; i< k;i++){

        sum += a[i];
        mp[a[i]]++;
     }

     if(mp.size() == k){
            ans= sum;
        }

     for(int i=k ;i<n ;i++){

        mp[a[i-k]]--;

        if(mp[a[i-k]] == 0){
            mp.erase(a[i-k]);
        }


        mp[a[i]]++;

        sum += a[i]- a[i-k];

        if(mp.size() == k){

            ans= max(ans, sum);
        }
     }

    return ans;

    

    }
};