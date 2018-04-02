class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.length()<10)return result;
        int hash_map[1048576] = {0};
        char listchar[] = {'A', 'C', 'G', 'T'};
        int charmap[128] = {0};
        charmap['A'] = 0;
        charmap['C'] = 1;
        charmap['G'] = 2;
        charmap['T'] = 3;
        int num = 0;
        for(int i = 9;i>=0;i--){
            num = (num<<2) + charmap[s[i]];
        }
        hash_map[num] ++;
        for(int i=10;i<s.length();i++){
            num = num >> 2 | charmap[s[i]] << 18;
            hash_map[num] ++;
        }
        for(int i=0;i<1048576;i++){
            if(hash_map[i]>1){
                int data = i;
                string str;
                for(int j=0;j<10;j++){
                    str += listchar[data&3];
                    data=data>>2;
                }
                result.push_back(str);
            }
        }
        return result;
    }
};