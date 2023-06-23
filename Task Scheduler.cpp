class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        
        for(char ch: tasks) {
            freq[ch-'A']++;
        }
        sort(freq.begin(), freq.end());
        
        int chunks = freq[25]-1;
        int freeSpots = chunks*n;
        
        for(int i=24; i>=0; i--) {
            freeSpots-=min(chunks, freq[i]);
        }
        
        return freeSpots < 0 ? tasks.size() : freeSpots + tasks.size(); 
    }
};
