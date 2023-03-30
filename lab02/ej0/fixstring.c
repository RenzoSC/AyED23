#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i =0;
    while (s[i] != '\0')
    {
        i++;
    }
    
}

bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int length = fstring_length(s1);
    if (length  != fstring_length(s2))
    {
        return false;
    }else{
        for (unsigned int i = 0; i < length; i++)
        {
            if (s1[i] != s2[i])
            {
                return false;
            }
            
        }
        
    }
    return true;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int length = fstring_length(s1);
    unsigned int i=0;
    while (i<length)
    {
        if (s1[i] < s2[i])
        {
            return true;
        }else if(s1[i]> s2[i]){
            return false;
        }
        i++;
    }
    return true;
}

