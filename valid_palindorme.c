#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isPalindrome(char* s) {
    bool answer = true;
    int left;
    int right;   

    char* testchar = s;
    /*Uppercase to Lowercase Conversion and whitespace removing.*/
    
    int writeptr = 0;   //It points in the string s where to write the lowercase to avoid if there is any space.
    int readptr = 0;    //It Points in the string s from where to read the character of uppercase.

    while(testchar[readptr] != '\0')
    {
        if(isalnum((unsigned char)testchar[readptr]))
        {
            testchar[writeptr] = tolower((unsigned char) testchar[readptr]);
            writeptr++;
        }
        readptr++;
    }
    testchar[writeptr] = '\0';

    /*To check whether a string is palindrome or not. Using two pointer technique.*/
    
    int strlength = strlen(testchar);
    int until = strlength/2;
    int i = 0;

    left = 0;
    right = strlength-1;

    while(i <= until)
    {
        if(left>=right)
        {
            answer = true;
            i++;
        }
        else if(testchar[left] == testchar[right])
        {
            left++;
            right--;
            i++;
        }
        else
        {
            answer = false;
            break;
        }
    }
    return answer;
}