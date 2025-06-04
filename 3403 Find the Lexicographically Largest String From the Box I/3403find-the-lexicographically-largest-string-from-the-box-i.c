#include <stdlib.h>
#include <string.h>

char* lastSubstring(char* s) {
    int i = 0, j = 1, k = 0;
    int n = strlen(s);

    while (j + k < n) {
        if (s[i + k] == s[j + k]) {
            k++;
        } else if (s[i + k] > s[j + k]) {
            j = j + k + 1;
            k = 0;
        } else {
            i = (i + k + 1 > j) ? i + k + 1 : j;
            j = i + 1;
            k = 0;
        }
    }

    return s + i;
}

char* answerString(char* word, int numFriends) {
    if (numFriends == 1)
        return strdup(word);

    char* maxSub = lastSubstring(word);
    int wordLen = strlen(word);
    int maxLen = strlen(maxSub);
    int size = wordLen - numFriends + 1;
    int len = size < maxLen ? size : maxLen;

    char* result = (char*)malloc(len + 1);
    strncpy(result, maxSub, len);
    result[len] = '\0';
    return result;
}

