class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        int count = 0;
        if (n % 2 == 1) {
            result.push_back(0);
            count ++;
        }        
        for(int i=1; i<=n/2; i++) {
            result.push_back(i);
            result.push_back(-i);
            count+=2;
            if (count == n) break;
        }
        return result;
    }
};