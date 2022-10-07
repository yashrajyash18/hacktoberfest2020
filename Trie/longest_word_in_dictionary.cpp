// Explanation:-

// The idea is simple. First, we construct a trie for the dictionary. Then we traverse the whole trie to get the longest word.
// We could choose DFS or BFS to achieve the trie traversal. Here, I leverage the property of BFS that it would get a layer of a tree from top to down at one time. Therefore, every time we get a new candidate word, we could replace the old one. Also, I scan the children of a trie node from last to first because we want the word with the smallest lexicographical order.

// Code:-
struct Node {
    Node *link[26];
    bool end = false;

    bool iscontains(char ch) {
        return link[ch-'a']!=nullptr;
    }

    void put(char ch, Node *node) {
        link[ch-'a'] = node;
    }

    Node* get(char ch) {
        return link[ch-'a'];
    }

    void setend() {
        end = true;
    }
    bool getend() {
        return end;
    }

};
class Trie {
  private : Node *root;
  public:
    Trie() {
        root = new Node();
    }
    void insert(string str) {
        Node* node = root;
        for(int i=0;i<str.size();i++) {
            if(!node->iscontains(str[i])) {
                node->put(str[i],new Node());

            }
            node = node->get(str[i]);
        }

        node->setend();
    }
    bool ispre(string str) {
        Node* node = root;
        for(int i=0;i<str.size();i++) {
            if(node->iscontains(str[i])) {
                node = node->get(str[i]);

                if(!node->getend())return false;
            }
        }

        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(int i=0;i<words.size();i++) {
            trie.insert(words[i]);
        }
        string ans ="";
        for(int i=0;i<words.size();i++) {
            if(trie.ispre(words[i])) {
                if(ans.size()<words[i].size()) ans = words[i];
                else if (ans.size()==words[i].size()) {
                    if(words[i]<ans) ans = words[i];
                }
            }
        }

        return ans;

    }
};
