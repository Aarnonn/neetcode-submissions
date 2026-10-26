class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> freq;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    freq[board[i][j]]++;
                }
            }
            if (freq.empty()) {
                continue;
            }
            else {
                for (const auto& p : freq) {
                    if (p.second != 1) return false;
                }
            }
            freq.clear();
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    freq[board[j][i]]++;
                }
            }
            if (freq.empty()) {
                continue;
            }
            else {
                for (const auto& p : freq) {
                    if (p.second != 1) return false;
                }
            }
            freq.clear();
        }
        
        for (int sq = 0; sq < 9; sq++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int r = (sq / 3) * 3 + i;
                    int c = (sq % 3) * 3 + j;
                    if (board[r][c] != '.') {
                        freq[board[r][c]]++;
                    }
                }
            }
            if (freq.empty()) {
                continue;
            }
            else {
                for (const auto& p : freq) {
                    if (p.second != 1) return false;
                }
            }
            freq.clear();
        }
        
        return true;

    }
};
