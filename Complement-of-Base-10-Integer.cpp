class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        int ans = 0;
        int i = 0;
        
        while(N != 0) {
            int t = N%2;
            if(t == 1) t= 0;
            else t = 1;
            ans += (t*pow(2, i));
            i++;
            N /= 2;
        }
        
        return ans;
    }
};
