class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long n=mass;
        for(int i=0;i<asteroids.size();i++){
            if(n<asteroids[i]){
                return false;
            }
            else{
                n=n+asteroids[i];
            }
        }
        return true;
    }
};