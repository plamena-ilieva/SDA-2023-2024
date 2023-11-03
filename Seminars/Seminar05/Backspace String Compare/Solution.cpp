class Solution {
    public :

    stack<char> processString(string s) {
        stack<char> result; 

            for (char c : s) {
                if (c != '#') {
                    result.push(c); 
                } else if (!result.empty()) {
                    result.pop(); 
                }
            }
            return result;
        
    } 

    bool backspaceCompare(string s, string t) {
        
        stack<char> processedS = processString(s); // Process the first input string
        stack<char> processedT = processString(t); // Process the second input string

        while (!processedS.empty() && !processedT.empty()) {
            if (processedS.top() != processedT.top()) {
                return false;
            }
            processedS.pop();
            processedT.pop();
        }
        return processedS.empty() && processedT.empty(); // Compare the processed strings for equality
    }
};
