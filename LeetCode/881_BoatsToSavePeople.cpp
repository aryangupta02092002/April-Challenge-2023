class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int sz = people.size();
        int low = 0, high = sz-1;
        int count = 0;
        sort(people.begin(), people.end());
        
        while(low <= high){
            count++;
            if(people[low] + people[high] <= limit){
                low++;
            }
            high--;
        }
        return count;
    }
};
