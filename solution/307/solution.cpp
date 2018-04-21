#include <stdio.h>

#include <vector>

void build_segment_tree(std::vector<int> &value, std::vector<int> &nums, int pos, int left, int right){
	if(left==right){
		value[pos] = nums[left];
		return;
	}
	int mid = (left + right) / 2;
	build_segment_tree(value, nums, pos*2+1, left, mid);
	build_segment_tree(value, nums, pos*2+2, mid+1, right);
	value[pos] = value[pos*2+1] + value[pos*2+2];
}


int sum_segment_tree(std::vector<int> &value, int pos, int left, int right, int leftq, int rightq){
	if(rightq < left || leftq > right)return 0;
	if(rightq >= right && leftq <= left)return value[pos];
	int mid = (left + right) / 2;
	return sum_segment_tree(value, pos*2+1, left, mid, leftq, rightq) + sum_segment_tree(value, pos*2+2, mid+1, right, leftq, rightq);
}

void update_segment_tree(std::vector<int> &value, int pos, int left, int right, int index, int new_value){
	if(left == right && left == index){
		value[pos] = new_value;
		return;
	}
	int mid = (left + right) / 2;
	if(index <= mid){
		update_segment_tree(value, pos*2+1, left, mid, index, new_value);
	}else{
		update_segment_tree(value, pos*2+2, mid+1, right, index, new_value);
	}
	value[pos] = value[pos*2+1] + value[pos*2+2];
}

class NumArray {
public:
    NumArray(std::vector<int> nums) {
        if(nums.size()==0)return;
        int n = nums.size() * 3;
        for(int i=0;i<n;i++){
        	_value.push_back(0);
        }
        _right = nums.size() - 1;
        build_segment_tree(_value, nums, 0, 0, _right);
    }

    void update(int i, int val) {
    	update_segment_tree(_value, 0, 0, _right, i, val);
    }

    int sumRange(int i, int j) {
    	return sum_segment_tree(_value, 0, 0, _right, i, j);
    }
private:
	int _right;
	std::vector<int> _value;
};


int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	NumArray num_array(nums);
	printf("%d\n", num_array.sumRange(0, 2));
	num_array.update(1, 2);
	printf("%d\n", num_array.sumRange(0, 2));	
	return 0;
}