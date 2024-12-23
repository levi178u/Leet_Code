class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {

        int n= a.size();

        int pro=1, i=0, j=0;
        int ans=0;

        while(j<n){

            pro *=a[j];

            while(i<=j and pro >= k ){

                 pro /=a[i];
                 i++;
            }

            ans += j-i+1;

            j++;
            
        }
   
       
       return ans;
        
    }
};