class Codec {

public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        /*
        Using my self-defined two digit 'hex' string, where
        'a'-'o' <==> 0 - 15.
        ',' is the seperator of the string
        */
        string ret("");
        for (string &s : strs) {
            for (char &c : s) {
                ret.append(1, c/16+'a');
                ret.append(1, c%16+'a');
            }
            ret.append(1, ',');
        }
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ret;
        int tmp = 0;
        bool done = false;
        string x("");
        for (char &c : s) {
            if (c == ',') { 
                ret.push_back(x); 
                x = "";
            }
            else {
                tmp = tmp*16 + c - 'a';
                if (done) {
                    x.append(1, (char)tmp);
                    tmp = 0;
                    done = false;
                }
                else done = true;
            }
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
