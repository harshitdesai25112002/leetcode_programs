void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    char temp;

    do
    {
        temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
    while(left<right);
}