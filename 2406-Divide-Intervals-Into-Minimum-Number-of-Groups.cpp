class Solution {
public:
typedef pair<int ,int> p;
    int minGroups(vector<vector<int>>& a) {
       // intervals[i] = [lefti, righti] 
       int n= a.size();
        vector<p> vp;
        

        for(int i=0 ;i<n ;i++){
            int si= a[i][0];
            int ei= a[i][1];

            vp.push_back({si,1});
            vp.push_back({ei+1,-1});
        }
        sort(vp.begin() ,vp.end());

        int c=0,maxi =0;

        for(auto &i : vp){
            int x = i.second;

            c +=x;

            maxi=max(maxi, c);

        }
            return maxi;
    }
};