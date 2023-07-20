#include "foundation.h"

/*
** test suites
*/

char    *f_strstr(const char *big, const char *little) {
    int n;
    int m;
    int i;
    int j;

    n = f_strlen((char *)big);
    m = f_strlen((char *)little);

    i = 0;
    while (*(big + i) != '\0') {
        j = 0;
        while (big[i + j] == little[j]) {
            j++;
        }
        if (j == m) {
            return ((char *)(big + i));
        }
        i++;
    }
    return ((char *)(big + (i - m)));
}

void    test_strstr() {
    char *s1 = "thebiggestlittlestring";
    char *s2 = "little";

    assert(f_strcmp(f_strstr(s1, s2), "littlestring") == 0);
    f_putstr("strstr passes");
}

int main (void) {
    test_strstr();
    return (0);
}
