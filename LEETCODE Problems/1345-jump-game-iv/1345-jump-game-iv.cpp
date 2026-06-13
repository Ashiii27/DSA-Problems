class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int N = arr.size();
        unordered_map<int, vector<int>> jumps;
        for (int i = 0; i < N; ++i) {
            jumps[arr[i]].emplace_back(i);
        }

        vector<bool> visited(N, false);
        deque<int> q{0};

        visited[0] = true;
        int ret = 0;
        for (; !q.empty(); ++ret) {
            const int SZ = q.size();
            for (int ii = 0; ii < SZ; ++ii) {
                const int index = q.front();
                q.pop_front();
                if (index == N - 1) {
                    return ret;
                }
                for (const int neigh : {index - 1, index + 1}) {
                    if (neigh >= 0 && neigh < N && !visited[neigh]) {
                        visited[neigh] = true;
                        q.emplace_back(neigh);
                    }
                }
                if (auto it = jumps.find(arr[index]); it != jumps.end() && !it->second.empty()) {
                    for (const int neigh : it->second) {
                        if (!visited[neigh]) {
                            visited[neigh] = true;
                            q.emplace_back(neigh);
                        }
                    }
                    it->second.clear();
                }
            }
        }
        return ret;
    }
};