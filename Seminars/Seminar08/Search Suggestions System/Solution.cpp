struct Node{
    Node* links[26];
    bool flag = false;
    vector<string> words;
    bool containsKey(char ch){
        return links[ch -'a'] != nullptr;
    }
    void put(char ch, Node* node){
        links[ch -'a'] = node;
    }
    Node* get(char ch){
        return links[ch -'a'];
    }
    void setEnd(){
        flag = true;
    }
};
class Solution {
public:
    void insert(Node* trie,string word,stack<Node*>&st){
        st.push(trie);
        for(int i=0;i<word.length();i++){
            if(!trie->containsKey(word[i])){
                trie->put(word[i],new Node());
            }
            trie = trie->get(word[i]);
            st.push(trie);
        }
        trie->setEnd();
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans(searchWord.length());
        sort(products.begin(),products.end());
        Node* trie = new Node();
        for(auto word:products){
            stack<Node*> st;
            insert(trie,word,st);
            while(!st.empty()) {
                Node* temp = st.top();
                st.pop();
                if(temp->words.size() < 3) temp->words.push_back(word);
            }
        }
        for(int i=0;i<searchWord.length();i++){
            if(!trie->containsKey(searchWord[i])){
                return ans;
            }
            trie = trie->get(searchWord[i]);
            ans[i]=trie->words;
        }
        return ans;
    }
};