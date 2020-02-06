class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string>hash_map;
        hash_map[1] = "I";
        hash_map[5] = "V";
        hash_map[10] = "X";
        hash_map[50] = "L";
        hash_map[100] = "C";
        hash_map[500] = "D";
        hash_map[1000] = "M";
        hash_map[4] = "IV";
        hash_map[9] = "IX";
        hash_map[40] = "XL";
        hash_map[90] = "XC";
        hash_map[400] = "CD";
        hash_map[900] = "CM";
        int digit;
        int power = -1;
        int val,i;
        int mul;
        string result = "";
        
        while(num > 0){
            digit = num%10;
            power++;
            num /= 10;
            mul = pow(10,power);
            val = mul * digit;
            if(hash_map.find(val) != hash_map.end()){
                result = hash_map[val] + result;
            }
            else{
                if(digit <= 3){
                    for(i=0;i<digit;i++) result = hash_map[mul]+result;
                }
                else{
                    string temp = hash_map[5*mul];
                    for(i=0;i<digit-5;i++) temp += hash_map[mul];
                    result = temp+result;
                }
            }
        }
        return result;
    }
};