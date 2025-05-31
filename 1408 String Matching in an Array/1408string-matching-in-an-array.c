#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSubstring(const char *a, const char *b) {
    return strstr(b, a) != NULL;
}

char **stringMatching(char **words, int wordsSize, int *returnSize) {
    char **result = (char **)malloc(wordsSize * sizeof(char *));
    int count = 0;

    for (int i = 0; i < wordsSize; ++i) {
        for (int j = 0; j < wordsSize; ++j) {
            if (i != j && isSubstring(words[i], words[j])) {
                result[count++] = words[i];
                break;
            }
        }
    }

    *returnSize = count;
    return result;
}
