class Solution {
public:
   int findTheLongestSubstring(const string& s) {
       static const int characterMap[26] = {1,0,0,0,2,0,0,0,4,0,0,0,0,0,8,0,0,0,0,0,16,0,0,0,0,0};
       int mp[32];
       memset(mp, -1, sizeof(mp));
       
       int prefixXOR = 0;
       int longestSubstring = 0;
       mp[0] = 0;

       for (int i = 0; i < s.length(); ++i) {
           prefixXOR ^= characterMap[s[i] - 'a'];
           if (mp[prefixXOR] == -1) {
               mp[prefixXOR] = i + 1;
           } else {
               longestSubstring = std::max(longestSubstring, i - mp[prefixXOR] + 1);
           }
       }

       return longestSubstring;
   }
};


static const auto kds = []() {
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);
   return 0;
}();