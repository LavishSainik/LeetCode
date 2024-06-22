class Solution {
public:
    
    class DSU{
     public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n){
            parent.resize(n);
            rank.resize(n, 0);
            iota(parent.begin(), parent.end(), 0); // Initialize each element's parent to itself
        }

        int find(int a){
            if(parent[a] != a){
                parent[a] = find(parent[a]);
            }
            return parent[a];
        }

        void unionit(int a, int b){
            int para = find(a);
            int parb = find(b);

            if(para == parb) return;

            if(rank[para] > rank[parb]){
                parent[parb] = para;
            }
            else if(rank[para] < rank[parb]){
                parent[para] = parb;
            }
            else{
                parent[parb] = para;
                rank[para]++;
            }
        }
    };

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DSU sets(s.size());

        for(int i = 0; i < pairs.size(); i++){
            sets.unionit(pairs[i][0], pairs[i][1]);
        }

        unordered_map<int, vector<char>> chars;
        unordered_map<int, vector<int>> indexes;

        for(int i = 0; i < s.size(); i++){
            int parent = sets.find(i);
            chars[parent].push_back(s[i]);
            indexes[parent].push_back(i);
        }

        string ans(s.size(), ' ');
        for (const auto& group : chars) {
            auto chars = group.second;
            auto indices = indexes[group.first];
            
            sort(chars.begin(), chars.end());
            sort(indices.begin(), indices.end());

            for (int i = 0; i < chars.size(); ++i) {
                ans[indices[i]] = chars[i];
            }
        }

        return ans;
    }
};
