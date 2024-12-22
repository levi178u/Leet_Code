class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> leftmostBuildingQueries(vector<int>& h,
                                        vector<vector<int>>& q) {

        int n = h.size();
        int nq = q.size();

        vector<vector<pi>> ref(n);

        vector<int> ans(nq, -1);

        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for (int i = 0; i < nq; i++) {

            int a = q[i][0];
            int b = q[i][1];

            if (a > b and h[a] > h[b]) {
                ans[i] = a;
            } else if (a < b and h[a] < h[b]) {
                ans[i] = b;
            } else if (a == b) {
                ans[i] = b;
            } else {

                int hmax = max(h[a], h[b]);
                int imax = max(a, b);

                ref[imax].push_back({hmax, i});
            }
        }

        for (int i = 0; i < n; i++) {

            while (!pq.empty() and pq.top().first < h[i]) {

                int idx = pq.top().second;
                ans[idx] = i;

                pq.pop();
            }
            for (auto& k : ref[i]) {

                pq.push({k.first, k.second});
            }
        }
        return ans;
    }
};