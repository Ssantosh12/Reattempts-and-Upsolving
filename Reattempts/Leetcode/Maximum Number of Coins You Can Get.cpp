class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // no matter what three piles we choose we will have to give the largest pile to Alice
        // so the best way is to choose first two as current 2 the maximums and last 1 minimum (ex:1 2 4 7 8 9 => 8 and 4 will be ours optimally)
        
        int ind,times=piles.size()/3,coins=0;
        sort(piles.begin(),piles.end());
        ind=piles.size()-2;
        while(times--){
            coins+=piles[ind];
            ind-=2;
        }
        return coins;
    }
};
