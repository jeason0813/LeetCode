#include "code.h"

using namespace std;

namespace Roman_to_Integer
{
    int roman_to_digit(char c)
    {
        switch (c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }

    int roman_to_int(const string& s)
    {
        if (s.size() == 0)
        {
            return 0;
        }
        else if (s.size() == 1)
        {
            return roman_to_digit(s[0]);
        }

        if (roman_to_digit(s[0]) < roman_to_digit(s[1]))
        {
            return roman_to_digit(s[1]) - roman_to_digit(s[0]) + roman_to_int(s.substr(2, s.size() - 2));
        }
        else
        {
            return roman_to_digit(s[0]) + roman_to_int(s.substr(1, s.size() - 1));
        }
    }

    int Solution::romanToInt(string s)
    {
        return roman_to_int(s);
    }
}
