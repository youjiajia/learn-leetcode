#include <stdio.h>

#include <string>
#include <vector>

#define TRIE_MAX_CHAR_NUM 26

struct TrieNode{
	TrieNode *child[TRIE_MAX_CHAR_NUM];
	bool is_end;
	TrieNode():is_end(false){
		for(int i=0;i<TRIE_MAX_CHAR_NUM;i++){
			child[i] = 0;
		}
	}
};

class TrieTree{
private:
	TrieNode* new_node(){
		TrieNode *node = new TrieNode();
		_node_vec.push_back(node);
		return node;
	}
	std::vector<TrieNode *> _node_vec;
	TrieNode _root;
public:
	TrieTree(){

    }
	~TrieTree(){
		for(int i=0;i<_node_vec.size();i++){
			delete _node_vec[i];
		}
	}
    TrieNode *root(){
    	return &_root;
    }
	void insert(const char* word){
		TrieNode *ptr = &_root;
		while(*word){
			int pos = *word - 'a';
			if(!ptr->child[pos]){
				ptr->child[pos] = new_node();
			}
			ptr = ptr->child[pos];
			word++;
		}
		ptr->is_end = true;
	}
	bool search_trie(TrieNode* node, const char* word){
		if(*word == '\0'){
			if(node->is_end)
				return true;
			return false;
		}
		if(*word == '.'){
			for(int i=0;i<TRIE_MAX_CHAR_NUM;i++){
				if(node->child[i]&&search_trie(node->child[i], word+1))
					return true;
			}
		}else{
			int pos = *word - 'a';
			if(node->child[pos]&&search_trie(node->child[pos], word+1))
				return true;
		}
		return false;
	}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    /** Adds a word into the data structure. */
    void addWord(std::string word) {
    	_trie_tree.insert(word.c_str());
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(std::string word) {
        return _trie_tree.search_trie(_trie_tree.root(), word.c_str());
    }
private:
	TrieTree _trie_tree;
};
