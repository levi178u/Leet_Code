class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        
        int sum=0, i=0,j=0, ans=0;

        int n=a.size();

        for(int i=0;i<n ;i++){

            sum = a[i];

            if(sum ==k){
                ans++;
            }

            for(int j=i+1 ; j<n;  j++){

                sum += a[j];
                if(sum ==k){
                    ans++;
                }
            }
        }

        return ans;
    }
};