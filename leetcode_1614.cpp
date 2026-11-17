class Solution {
public:
    int maxDepth(string s) {
        int answer=0;
        int count=0;

        for(char c : s)
        {
            if(c=='(')count++;
            else
            if(c==')')count--;
            answer=max(answer,count);

        }
        return answer;
    }
};