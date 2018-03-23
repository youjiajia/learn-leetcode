#include <stdio.h>
#include <vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int allnum = 0;
        int part_length = 1;
        int high_point = 0;
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int state = BEGIN;
        ratings.push_back(ratings[ratings.size()-1]);
        for(int i=0;i<ratings.size()-1;i++){
            int poor = ratings[i+1] - ratings[i];
            switch(state){
                case BEGIN:
                    if(poor>0){
                        state = UP;
                    }else if(poor<0){
                        state = DOWN;
                    }else allnum+=1;
                    break;
                case UP:
                    part_length++;
                    if(poor<0){
                        state = DOWN;
                        high_point = part_length;
                    }else if(poor == 0){
                        generate(high_point, part_length, allnum);
                        state = BEGIN;
                    }
                    break;
                case DOWN:
                    part_length++;
                    if(poor>0){
                        generate(high_point, part_length, allnum);
                        allnum--;
                        state = UP;
                    }else if(poor == 0){
                        generate(high_point, part_length, allnum);
                        state = BEGIN;
                    }
                    break;

            }
        }
        return allnum;
    }
    void generate(int &high_point, int& part_length, int &allnum){\
        int n1 = high_point - 1;
        int n2 = part_length - high_point;
        int sign;
        if(high_point==0)sign=0;
        else if(n1 > n2)sign=n2*(n1+1);
        else sign=n1*(n2+1);
        allnum += (1+part_length)*part_length/2 - sign;
        printf("%d\n", allnum);
        part_length = 1;
        high_point = 0;
    }
};

int main(){
    int a[]={1,2};
    std::vector<int> v;
    for(int i=0;i<2;i++)v.push_back(a[i]);
    Solution s;
    int result = s.candy(v);
    printf("%d\n", result);
}


