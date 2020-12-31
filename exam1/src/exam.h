#ifndef EXAM_H
#define EXAM_H

#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

class Exam
{
public:
void backtrack2(string s,int start,set<string>&res)
{
    if(start ==s.size()){
        res.insert(s);
        return ;
    }
    for(int i=start;i<s.size();i++)
    {
        std::swap(s[i],s[start]);
        backtrack2(s,start+1,res);
        std::swap(s[i],s[start]);
    }
}
    vector<string> output(string input) {
        std::set<std::string> res1;
        backtrack2(input,0,res1);
        vector<string> res(res1.begin(),res1.end());
        return res;
    }
};

#endif // EXAM_H
