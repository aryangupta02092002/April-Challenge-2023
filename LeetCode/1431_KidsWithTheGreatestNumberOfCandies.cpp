class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int sz = candies.size();
        vector<bool> ans;
        int curr = candies[0];
        for(int i=0; i<sz; i++){  
            if(candies[i] > curr)
               curr = candies[i];   
        }

        for(int i=0; i<sz; i++){
            if((candies[i] + extraCandies) >= curr)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
