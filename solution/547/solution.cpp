#include <stdio.h>

#include <vector>

class DisjointSet{
public:
	DisjointSet(int n){
		for(int i=0;i<n;i++){
			_id.push_back(i);
			_size.push_back(1);
		}
		_count = n;
	}
	int find(int p){
		while(p!=_id[p]){
			_id[p] = _id[_id[p]];
			p = _id[p];
		}
		return p;
	}
	void union_(int p, int q){
		int i = find(p);
		int j = find(q);
		if(i==j)return;
		if(_size[i]>=_size[j]){
			_id[j] = _id[i];
			_size[i] += _size[j];
		}else{
			_id[i] = _id[j];
			_size[j] += _size[i];
		}
		_count--;
	}
	int count(){
		return _count;
	}
private:
	int _count;
	std::vector<int> _id;
	std::vector<char> _size;
};

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int> >& M) {
    	DisjointSet ds(M.size());
    	for(int i=0;i<M.size();i++){
    		for(int j=i;j<M.size();j++){
    			if(M[i][j]){
    				ds.union_(i, j);
    			}
    		}
    	}
    	return ds.count();
    }
};
