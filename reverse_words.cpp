/***************************************************************************
 * 
 * Copyright (c) 2014 whuqin. All Rights Reserved
 *
 * Given an input string, reverse the string word by word.
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * 
 **************************************************************************/
#include <iostream>
using namespace std;

void reverse_word(char* str, int begin, int end)
{
    int index = begin;
    int mid = begin + (end - begin)/2;
    char tmp;
    while (index <= mid)
    {
        tmp = str[index];
        str[index] = str[end - (index - begin)];
        str[end - (index - begin)] = tmp;
        ++index;
    }
}

void delete_space(char* str)
{
    char* p = str;
    char* q = str;
    char* last = NULL;
    while (*p == ' ')
    {
        ++p; 
    }
    while (*p != 0)
    {
        if (last != NULL && *last == ' ' && *p == ' ')
        {
            ++p;
            continue;
        }
        last = q;
        *q = *p;
        ++q;
        ++p;
    }
    --q;
    if (*q != ' ')
    {
        ++q;
    }
    *q = 0; 
}

void reverse_words(char* str)
{
    delete_space(str);
    int begin = 0;
    int end = 0;
    char* p = str;
    reverse_word(str, 0, strlen(str)-1);
    while(*p != 0)
    {
        while(*p != ' ' && *p != 0)
        {
            ++p;
            ++end;
        }
        reverse_word(str, begin, end - 1);
        if (*p == 0)
        {
            break;
        }
        begin = end + 1;
        ++p;
        ++end;
    }
}

int main()
{
    char str[1024] = "a";
    reverse_words(str);
    cout << str << endl;
    return 0;
}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
