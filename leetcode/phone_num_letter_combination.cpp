class Solution {
public:
    unordered_map<char, string> digitToChar;
    vector<string> sol;

    void prepareMapping() {
      digitToChar.clear();
      digitToChar['2'] = "abc";
      digitToChar['3'] = "def";
      digitToChar['4'] = "ghi";
      digitToChar['5'] = "jkl";
      digitToChar['6'] = "mno";
      digitToChar['7'] = "pqrs";
      digitToChar['8'] = "tuv";
      digitToChar['9'] = "wxyz";
    }

    void getCombinations(string digits, int itr, string& curr) {
      if (itr >= digits.size()) {
        return;
      }
      if (itr == digits.size() - 1) {
        for (int i=0; i<digitToChar[digits[itr]].size(); i++) {
          sol.push_back(curr + digitToChar[digits[itr]][i]);
        }
        return;
      }

      for (int i=0; i<digitToChar[digits[itr]].size(); i++) {
        curr += digitToChar[digits[itr]][i];
        getCombinations(digits, itr+1, curr);
        curr.pop_back();
      }
    }

    vector<string> letterCombinations(string digits) {
        prepareMapping();
        string curr = "";
        sol.clear();
        getCombinations(digits, 0, curr);
        return sol;
    }
};
