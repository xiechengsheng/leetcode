// Given an array of strings, group anagrams together.
//
//
// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return:
//
// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note: All inputs will be in lower-case.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sol_map;
        for(string str:strs) {
            string s=str;
            sort(s.begin(),s.end());
            sol_map[s].push_back(str);
        }
        
        vector<vector<string>> results;
        for(auto it:sol_map) {
            vector<string> res(it.second.begin(),it.second.end());
            results.push_back(res);
        }
        return results;
    }
};
