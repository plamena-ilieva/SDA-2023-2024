char findTheDifference(string s, string t) {
        vector<int> v(26, 0);
        for(auto& c:s) 
          v[c-'a'] += 1;

        for(auto& c:t) {
          if(--v[c-'a'] < 0) 
            return c;
        }
        return '\0';
    }
