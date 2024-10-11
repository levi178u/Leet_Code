class Solution {
public:
#define ll long long 

    int smallestChair(vector<vector<int>>& a, int tf) {
        // times[i] = [arrivali, leavingi]

        int n=a.size();

        vector<int> ch(n, -1);

        int tfr = a[tf][0];

        sort(a.begin(), a.end());


        for(int i=0; i<n; i++){
            
            for(int j=0;j<n; j++){
                int arr = a[i][0];
                int dep = a[i][1];
            

            if(ch[j] <= arr){
                ch[j]= dep;

                if(arr == tfr){
                return j;

            } break;
            } 

        }

        }
       

    return -1;
        
        
    }
};