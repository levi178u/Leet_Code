class Solution {
public:
typedef pair<int ,int> p;
    int minGroups(vector<vector<int>>& a) {
       // intervals[i] = [lefti, righti] 
       int n= a.size();
        vector<int > v1,v2;
        

        for(int i=0 ;i<n ;i++){
            int si= a[i][0];
            int ei= a[i][1];

            v1.push_back(si);
            v2.push_back(ei);
            
        }
        sort(v1.begin() ,v1.end());
        sort(v2.begin() ,v2.end());

        int c=0,maxi =0;
        int i=0,j=0;
        while(i<n and j<n){
            if(v1[i] <= v2[j]){
                i++;
                c++;
            }else{
                c--;
                j++;
            }
            maxi= max(maxi, c);


        }


        
            return maxi;
    }
};