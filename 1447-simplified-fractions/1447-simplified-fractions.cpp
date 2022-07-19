class Solution {
public:
    
    int get_gcd(int a, int b){
        return a * b / lcm(a, b);
    }
    
    void solve(int a, int b, set<string>& s){
        while(get_gcd(a,b) != 1){
            a /= get_gcd(a, b);
            b /= get_gcd(a, b);
        }
        string str = to_string(a) + "/" + to_string(b);
        s.insert(str);
    }
    
    vector<string> simplifiedFractions(int n) {
        set<string>s;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(i != j) solve(i,j,s);
            }
        }
        vector<string>arr;
        for(auto it: s) arr.push_back(it);
        return arr;
    }
};