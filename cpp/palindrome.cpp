/***************************************************************************
 * 
 * Copyright (c) 2014 whuqin. All Rights Reserved
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return
 *
 *   [
 *       ["aa","b"],
 *       ["a","a","b"]
 *   ]
 * 
 **************************************************************************/
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

bool isPalindrome(const string& str) {
    int i = 0; 
    int j = str.size() - 1;
    for (; i <= j; ++i, --j) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

void partition(const string& str, vector<string>& one, 
        vector<vector<string> >& all) {
    if (str.size() == 0) {
        all.push_back(one);
        return;
    }

    for (int i = 1; i <= str.size(); ++i) {
        string tmp = str.substr(0, i);
        if (isPalindrome(tmp)) {
            one.push_back(tmp);
            string back_str = str.substr(i);
            partition(back_str, one, all);
            one.pop_back();
        }
    }
}

vector<vector<string> > partition(string s) {
    vector<vector<string> > all;
    vector<string> one;
    partition(s, one, all);
    return all;
}

int main() {
    string str("aabccbaa");
    vector<vector<string> > vec = partition(str);
    for (int i = 0; i < vec.size(); ++i) {
        ostringstream os;
        copy(vec[i].begin(), vec[i].end(), ostream_iterator<string>(os, ","));
        cout << os.str() << endl;
    }
    return 0;
}















