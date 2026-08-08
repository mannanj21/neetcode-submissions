class Solution {
public:
    const int sep = 511;

    string num2ninebitstr(int num){
        string ans = "";
        for(int i = 8; i >= 0; i--){
            if(num & (1<<i)){
                ans.push_back('1');
            } else{
                ans.push_back('0');
            }
        }
        return ans;
    }

    int ninebitstr2num(string str){
        int num = 0;
        int ind = 0;
        for(int i = 8; i >= 0; i--){
            if(str[i] == '1'){
                num |= (1<<ind);
            }
            ind++;
        }
        return num;
    }

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto& str : strs){
            for(auto& ch : str){
                string a = num2ninebitstr((int)ch);
                ans.append(a);
            }
            ans.append(num2ninebitstr(sep));
        }
        return ans;
    }

    vector<string> decode(string s) {
        int n = s.size();
        if(n%9 != 0) return {};
        int i = 0;
        vector<string> ans;
        string a = "";
        while(i < n){
            string str = s.substr(i, 9);
            int num = ninebitstr2num(str);
            if(num != sep){
                a.push_back((char)num);
            } else{
                ans.push_back(a);
                a = "";
            }
            i += 9;
        }
        return ans;
    }
};
