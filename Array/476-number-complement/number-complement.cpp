class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
        {
            return 0;
        }
        vector<int>binary;

        int i = 0;
        while(num>0)
        {
            binary.push_back(num%2);
            num = num/2;
            i++;
        }

        for(int i = 0; i< binary.size(); i++)
        {
            if(binary[i] == 0)
            {
                binary[i] = 1;
            }
            else
            {
                binary[i] = 0;
            }
        }
       
        int val = 0;
        for(int i = 0; i<binary.size(); i++)
        {
            int temp = binary[i]*pow(2, i);
            val += temp;
        }

        return val;
    }
};