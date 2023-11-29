class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> st;
        double pw=pow(4,10);
        int n=s.length();
        int li[n];
        for(int i=0;i<n;i++){
            if(s[i]=='A'){
                li[i]=0;
            }
            else if(s[i]=='T'){
                li[i]=1;
            }
            else if(s[i]=='G'){
                li[i]=2;
            }
            else{
                li[i]=3;
            }
        }
        long long int hash_val=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n-9;i++){
            if(i==0){
                for(int i=0;i<10;i++){
                    hash_val= 4*hash_val + li[i]; //converting to decimal number
                }
                mp[hash_val]++;
            }
            else{
                hash_val = hash_val * 4 - li[i - 1] * pw + li[i + 9]; // Finding new hash value
                mp[hash_val]++;
                if(mp[hash_val]==2){
                    st.push_back(s.substr(i,10));
                }
            }
        }
        return st;
    }
};