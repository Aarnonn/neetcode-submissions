class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (const auto& s : strs) {
            encoded += s;
            encoded += static_cast<char>(257);
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> output;
        string str = "";
        for (char c : s) {
            if (c != static_cast<char>(257)) {
                str += c;
            }
            else { // delimiter found, should reset str
                output.push_back(str);
                str = "";
            }
        }
        return output;
    }
};
