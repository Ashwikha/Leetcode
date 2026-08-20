class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>p(gain.size()+1,0);
     
        for(int i=0;i<gain.size();i++){
            p[i+1]=p[i]+gain[i];
        }
        int maxi=INT_MIN;
        for(int i=0;i<p.size();i++){
            maxi=max(maxi,p[i]);
        }
        return maxi;
    }
};