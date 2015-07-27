class TrieNode {
public:
    // Initialize your data structure here.
    char *d, *e;
    TrieNode *left, *right;
    TrieNode(char *start = nullptr, char* end = nullptr, TrieNode* l = nullptr, TrieNode* r = nullptr): d(start), e(end), left(l), right(r) {
    }
};

class Trie {
    pair<TrieNode*, char*> find(const char* &str) {
        TrieNode *p = root;
        while (true) {
            if (p->d == p->e && *str == 0) {
                return make_pair(p, p->d);
            }
            if (p->d != p->e && *p->d == *str) {
                char *q = p->d;
                do {
                    q++;
                    str++;
                } while (q != p->e && *str != 0 && *q == *str);
                if (q != p->e) return make_pair(p, q);
                if (p->left == nullptr) return make_pair(p, p->e);
                p = p->left;
            } else {
                if (p->right == nullptr) return make_pair(p, p->d);
                p = p->right;
            }
        }
    }
    void del(TrieNode *p) {
        if (p == nullptr) return;
        if (p->right != nullptr && p->right->d != p->right->e) {
            delete[] p->right->d;
        }
        del(p->left);
        del(p->right);
        delete p;
    }
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        del(root);
    }

    // Inserts a word into the trie.
    void insert(string word) {
        const char *str = word.c_str();
        auto ret = find(str);
        if (*str != 0) {
            int len = strlen(str);
            char *p = new char[len + 1];
            strcpy(p, str);
            if (ret.second == ret.first->d) {
                ret.first->right = new TrieNode(p, p + len, nullptr, ret.first->right);
            } else {
                TrieNode *q = ret.first->left;
                ret.first->left= new TrieNode(p, p + len);
                ret.first->left = new TrieNode(ret.second, ret.first->e, q, ret.first->left);
                ret.first->e = ret.second;
            }
        } else if (ret.first->d != ret.first->e) {
            ret.first->left = new TrieNode(ret.second, ret.first->e, ret.first->left);
            ret.first->left->right = new TrieNode(ret.first->d, ret.first->d);
            ret.first->e = ret.second;
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        const char *str = word.c_str();
        auto ret = find(str);
        return *str == 0 && ret.first->e == ret.second;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        const char *str = prefix.c_str();
        auto ret = find(str);
        return *str == 0;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
