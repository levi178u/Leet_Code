
typedef vector<int> vi;
typedef long long ll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vector<bool>> vvb;

int c=1;

class Solution {
public:
void add(int i,int p,vvi &adj,vi &a,int k){
    for(int ch : adj[i]){
        if(ch == p) continue;
        add(ch,i,adj,a,k);
        if(a[ch] % k == 0) c++;
        a[i] += a[ch];
        a[i] %= k;
    }
}
int maxKDivisibleComponents(int n, vvi& edges, vi& a, int k) {
    c = 1;
    vvi adj(n);
    for(auto &e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    add(0,-1,adj,a,k);

    return c;
}
};