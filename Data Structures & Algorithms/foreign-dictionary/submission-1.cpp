class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<bool>> v(26, vector<bool>(26, 0));
        int n = words.size();
        if(n == 1) return words[0];
        vector<bool> ischar(26, 0);
        int cnt = 0;

        for(int i = 0; i < n - 1; i++){
            string& w1 = words[i];
            string& w2 = words[i+1];
            int ind1 = 0, ind2 = 0;
            int n1 = w1.size(), n2 = w2.size();
            while(ind1 < n1 && ind2 < n2 && w1[ind1] == w2[ind2]){
                ischar[w1[ind1] - 'a'] = 1;
                ind1++;
                ind2++;
            }
            if(ind1 == n1) continue;
            if(ind2 == n2) return "";
            v[w1[ind1] - 'a'][w2[ind2] - 'a'] = 1;
            ischar[w1[ind1] - 'a'] = 1;
            ischar[w2[ind2] - 'a'] = 1;
            while(ind1 < n1){
                ischar[w1[ind1] - 'a'] = 1;
                ind1++;
            }
            while(ind2 < n2){
                ischar[w2[ind2] - 'a'] = 1;
                ind2++;
            }
        }

        vector<int> indeg(26, 0);
        
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(v[i][j] == 1) indeg[j]++;
            }
        }

        string ans;
        queue<int> q;
        vector<bool> vis(26, 0);

        for(int i = 0; i < 26; i++){
            if(ischar[i] && indeg[i] == 0){
                ans.push_back(i + 'a');
                vis[i] = 1;
                q.push(i);
            }
            if(ischar[i]) cnt++;
        }

        while(!q.empty()){
            int ind = q.front();
            q.pop();
            for(int i = 0; i < 26; i++){
                if(v[ind][i] == 1){
                    if(vis[i]) return "";
                    indeg[i]--;
                    if(indeg[i] == 0){
                        vis[i] = 1;
                        ans.push_back(i + 'a');
                        q.push(i);
                    }
                }
            }
        }

        if(ans.size() < cnt) return "";
        return ans;
    }
};
