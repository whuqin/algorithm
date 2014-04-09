/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences.
For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is ["cats and dog", "cat sand dog"].
*/
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <iterator>
using namespace std;

map<string, vector<string> > key_dict;
vector<string> wordBreak(string s, set<string> &dict) {
    vector<string> str_vec;
    if (s.empty())
    {
        return str_vec;
    } 
    //search record
    map<string, vector<string> >::iterator it = key_dict.find(s);
    if (it != key_dict.end())
    {
        return it->second;
    }
    
    for (unsigned int i = 1; i <= s.size(); ++i)
    {
        string tmp = s.substr(0, i);
        if (dict.find(tmp) == dict.end())
        {
            continue;
        }

        if (i == s.size())
        {
            str_vec.push_back(tmp);
            break;
        }
        vector<string> tmp_vec = wordBreak(s.substr(i), dict);
        if (!tmp_vec.empty())
        {
            vector<string>::iterator it = tmp_vec.begin();
            for (; it != tmp_vec.end(); ++it)
            {
                str_vec.push_back(tmp + " " + *it);
            }
        }
    }
    key_dict.insert(make_pair(s, str_vec));
    return str_vec;
}
int main()
{
    string str_arr[10] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    set<string> dict;
    dict.insert("a");
    dict.insert("aa");
    dict.insert("aaa");
    dict.insert("aaaa");
    dict.insert("b");
    vector<string> result = wordBreak("aaab", dict);
    copy(result.begin(), result.end(), ostream_iterator<string>(cout, ";"));
}
