class Solution {
public:
    bool isCapital(char ch){
        int val = ch;
        if(val >= 65 && val<= 90){
            return true;
        }
        return false;
    }

    bool allCaps(string word){
        if(word.length() == 0){
            return false;
        }
        for(char ch: word){
            if(!isCapital(ch)){
                cout<< "not caps = " << ch << endl; 
                return false;
            }
        }
        return true;
    }

    bool allNonCaps(string word){
        if(word.length() == 0){
            return false;
        }
        int start = 0;
        for(char ch: word){
            if(isCapital(ch) && start != 0){
                return false;
            }
            start++;
        }
        return true;
    }

    // bool firstCaps(string word){
    //     if(word.length() == 0){
    //         return false;
    //     }
    //     int start = 0;
    //     for(char ch: word){
    //         if(iscapital(ch) && start == 0){
    //             return true;
    //         }
    //         start++;
    //     }
    //     return true;
    // }
    bool detectCapitalUse(string word) {
        if(word.length() == 0){
            return false;
        }
        // bool allCaps
        // cout<< "word =" << word << "all caps = " << 
        if(allCaps(word) || allNonCaps(word)){
            return true;
        }
        return false;
    }
};