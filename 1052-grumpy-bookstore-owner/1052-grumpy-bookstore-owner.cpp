class Solution {
public:
    int maxSatisfied(vector<int>& customer, vector<int>& grumpy, int minutes) {
        int n = customer.size();

        int sum0 = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i] == 0) sum0 += customer[i];
            else grumpy[i] *= customer[i];
        }

        int k = minutes;
        //basically find maximum sum of subarray length k

        int i=0,j=0;
        int maxc = 0,temp=0;

        while(j<n){
            temp += grumpy[j];
            if(j-i+1 > k) {
                temp -= grumpy[i];
                i++;
            }
            if(j-i+1 == k){
                maxc = max(maxc,temp);
            }
            j++;
        }
        return sum0+maxc;
    }
};