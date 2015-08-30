class Solution {
public:
    string numberToWords(int num) {
        int part1 = num / 1000000000;
        int part2 = (num / 1000000) % 1000;
        int part3 = (num / 1000) % 1000;
        int part4 = num % 1000;
        string ret = "", tmp;
        if (num == 0) ret = "Zero";
        else {
            tmp = threeDigitsToWords(part1);
            if (tmp != "") ret += tmp + " Billion";
            tmp = threeDigitsToWords(part2);
            if (tmp != "") ret += (ret != "" ? " " : "") + tmp + " Million";
            tmp = threeDigitsToWords(part3);
            if (tmp != "") ret += (ret != "" ? " " : "") + tmp + " Thousand";
            tmp = threeDigitsToWords(part4);
            if (tmp != "") ret += (ret != "" ? " " : "") + tmp;
        }
        return ret;
    }
    
    string threeDigitsToWords(int num) {
        string ret = "";
        int digit=0, digitSeq = 1, nextDigit = 0;
        while (digitSeq <= 3) {
            if (digitSeq == 1) {
                digit = num/100;
            }
            else if (digitSeq == 2) {
                digit = (num/10) % 10;
                nextDigit = num % 10;
            }
            else {
                digit = num % 10;
            }
            if (ret != "" && digit != 0) ret += " ";
            switch (digit) {
                case 1: { 
                    if (digitSeq != 2) ret += "One"; 
                    else {
                        digitSeq ++;
                        switch (nextDigit) {
                            case 0 : { ret += "Ten"; break; }
                            case 1 : { ret += "Eleven"; break; }
                            case 2 : { ret += "Twelve"; break; }
                            case 3 : { ret += "Thirteen"; break; }
                            case 4 : { ret += "Fourteen"; break; }
                            case 5 : { ret += "Fifteen"; break; }
                            case 6 : { ret += "Sixteen"; break; }
                            case 7 : { ret += "Seventeen"; break; }
                            case 8 : { ret += "Eighteen"; break; }
                            case 9 : { ret += "Nineteen"; break; }
                            default : { break; }
                        }
                    }
                    break; }
                case 2: { ret += (digitSeq == 2 ? "Twenty" : "Two"); break; }
                case 3: { ret += (digitSeq == 2 ? "Thirty" : "Three"); break; }
                case 4: { ret += (digitSeq == 2 ? "Forty" : "Four"); break; }
                case 5: { ret += (digitSeq == 2 ? "Fifty" : "Five"); break; }
                case 6: { ret += (digitSeq == 2 ? "Sixty" : "Six"); break; }
                case 7: { ret += (digitSeq == 2 ? "Seventy" : "Seven"); break; }
                case 8: { ret += (digitSeq == 2 ? "Eighty" : "Eight"); break; }
                case 9: { ret += (digitSeq == 2 ? "Ninety" : "Nine"); break; }
                default: { break; }
            }
            if (digitSeq == 1 && digit != 0) ret += " Hundred";
            digitSeq ++;
        }
        return ret;
    }
};
