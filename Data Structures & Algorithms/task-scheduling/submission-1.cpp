class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26,0);

        for(auto ch:tasks){
            freq[ch-'A']++;
        }

        int maxFreq = 0;

        for(int i=0;i<26;i++){
            maxFreq = max(freq[i],maxFreq);
        }

        int maxCount = 0;

        for(int i=0;i<26;i++){
            if(freq[i]==maxFreq) maxCount++;
        }

        int min =  (maxFreq-1)*(n+1) + maxCount;

        return max((int)tasks.size(), min);



    }
};
