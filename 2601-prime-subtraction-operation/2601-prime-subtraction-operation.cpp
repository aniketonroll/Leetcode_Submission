class Solution {
public:
    vector<int> sieve_of_eratosthenes(int n)
    {
        vector<int> v;
        bool is_prime[n + 1];
        memset(is_prime, true, sizeof(is_prime));
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    is_prime[i] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) {
                v.push_back(i);
            }
        }
        return v;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {   
            if(nums[i]==1 && i==0) continue; //if the element is 1 and it is at the 0th index then it is the minimum possible value for that place and it should not be changed                                                   
            else if(nums[i]==1 && i>0) return false; //if the element is 1 but it is not at the 0th index this means that there is a number greater than equal to 1 already in this array. Think!

            vector<int> prime = sieve_of_eratosthenes(nums[i]-1); //adding all the prime numbers lesser than the current element of array

            prime.insert(prime.begin(),0); //adding 0 at the beginning of the prime array so that if there is any number that should not be subtracted by any other number or if the current element is at the proper place then dont change it
            
            if(i==0) nums[i]-=prime[prime.size()-1]; //it is first element so reduce it as much as possible
            else
            {
                bool flag = false;
                for(int j=prime.size()-1;j>=0;j--)
                {
                    if((nums[i]-prime[j])>nums[i-1])
                    {
                        nums[i]-=prime[j];
                        flag = true;
                        break;
                    }
                }
                
                if(!flag) return false;
            }
        }
        
        return true;
    }
};