// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
//
//
// click to show corner cases.
//
// Corner Cases:
//
//
//
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".
//
//


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> paths;
        stringstream ss(path);
        string item;
        while(getline(ss,item,'/')){
            if(item=="."||item=="") 
                continue;
            else {
                if(item==".."&&!paths.empty()) {
                    paths.pop();
                }                
                if(item!="..")
                    paths.push(item);
            }
        }
        string res;
        if(paths.empty())
            return "/";
        //for(int i=0;i<paths.size();i++){
        while(!paths.empty()){  
            res="/"+paths.top()+res;
            paths.pop();
        }
        return res;
    }
};
