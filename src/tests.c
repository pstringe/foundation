#include <assert.h>
#include <stdio.h>
#include <unistd.h>

int f_isdigit(char c) {
    int is_num;
    
    is_num = (c >= 48 && c <= 57);
    return (is_num);
}

int f_isalpha(char c) {
    int is_lower;
    int is_upper;

    is_lower = (c >= 97 && c <= 122);
    is_upper = (c >= 65 && c <= 90);
    return ((is_lower || is_upper) ? 1 : 0);
}

int f_isalnum(char c) {
    int    is_num;
    int    is_alpha;

    is_num = f_isdigit(c);
    is_alpha = f_isalpha(c);
    return ((is_num || is_alpha) ? 1 : 0);
}

int f_isascii(int c) {
    int is_ascii = (c >= 0 && c <= 127);
    return (is_ascii ? 1 : 0);
}

int f_isprint(int c) {
    int isprintable = (c >= 41);
    return (isprintable ? 1 : 0);
}

int f_strlen(char *str){
    int i;
    i = 0; 
    while (*(str + i)) i++;
    return (i);
}

void f_putchar_fd(char c, int f) {
    write(f, &c, 1);
}

void f_putchar(char c) {
    f_putchar_fd(c, 1);
}

/*
**    To extract the last digit from n, we can mod by 10
**    To modify n such that the last digit is removed, we can divide by 10
*/

char f_dtoc(int n) {
    if (n > 9 || n < 0) {
        return (0);
    }
    return ((n + 48));
}

int f_strcmp(const char *s1, const char *s2) {
    int     i;
    int     n;
    int     m;

    n = f_strlen((char *)s1);
    m = f_strlen((char *)s2);
    i = 0;
    while (i < n && i < m) {
        if (!(s1[i] == s2[i])) return (-1);
        i++;
    }
    return (0);
}

int f_strncmp(const char *s1, const char *s2, size_t l) {
    int     i;
    int     n;
    int     m;

    n = f_strlen((char *)s1);
    m = f_strlen((char *)s2);
    i = 0;
    while (i < n && i < m && i < (int)l) {
        if (!(s1[i] == s2[i])) return (-1);
        i++;
    }
    return (0);
}

char *f_strcat(char* s1, const char* s2 ) {
    int     n;
    int     m;
    int     i;

    n = f_strlen(s1);
    m = f_strlen((char *)s2);
    
    i = n;
    while (i < n + m) {
        s1[i] = s2[i - n];
        i++;
    }
    return (s1);
}

void f_putnbr_fd(long long n, int fd)
{
	long long tmp;

	tmp = n;
	if (tmp < 0) {
		tmp = -tmp;
		f_putchar_fd('-', fd);
	}
	if (tmp >= 10) {
		f_putnbr_fd(tmp / 10, fd);
		f_putnbr_fd(tmp % 10, fd);
	}
	else {
		f_putchar_fd(tmp + '0', fd);
	}
}

void f_putnbr(long long n) {
    f_putnbr_fd(n , 1);
}

int f_putstr(char *s) {
    int i;
    i = 0;
    while (*(s + i))
        f_putchar(*(s + i++));
    return (i);
}

int f_putendl(char *s) {
    int bytes_written = 0;
    bytes_written = f_putstr(s);
    f_putchar('\n');
    return (bytes_written + 1);
}

int f_iswhitespace(char c){
    char*   whitespace_chars;
    int     i;

    whitespace_chars = " \t\r\n\f";
    i = 0;
    while (whitespace_chars[i]) {
        if (c == whitespace_chars[i++]) {
            return (1);
        }
    }
    
    return (0);
}

/*
** test suites
*/

int test_dtoc() {
    assert(f_dtoc(0) == '0');
    assert(f_dtoc(1) == '1');
    assert(f_dtoc(10) == '\0');
    //printf("dtoc tests passed successfully!\n");
    return (0);
}

int test_isalnum(void) {
    assert(f_isalnum('a') == 1);
    assert(f_isalnum('Z') == 1);
    assert(f_isalnum('5') == 1);
    assert(f_isalnum(' ') == 0);
    printf("isalnum tests passed successfully!\n");
    return (0);
}

int test_isalpha(void) {
    assert(f_isalpha('a') == 1);
    assert(f_isalpha('b') == 1);
    assert(f_isalpha('5') == 0);
    assert(f_isalpha('z') == 1);
    printf("isalpha tests passed successfully!\n");
    return (0);
}

int test_isdigit(void) {
    assert(f_isdigit('a') == 0);
    assert(f_isdigit('b') == 0);
    assert(f_isdigit('5') == 1);
    assert(f_isdigit('z') == 0);
    printf("isdigit tests passed successfully!\n");
    return (0);
}

int test_isascii(void) {
    assert(f_isascii('a') == 1);
    assert(f_isascii('b') == 1);
    assert(f_isascii('5') == 1);
    assert(f_isascii('z') == 1);
    printf("is_ascii tests passed successfully!\n");
    return (0);
}

int test_is_whitespace(void) {
    assert(f_isascii('a') == 0);
    assert(f_isascii('1') == 0);
    assert(f_isascii(' ') == 1);
    assert(f_isascii('\n') == 1);
    assert(f_isascii('\t') == 1);
    assert(f_isascii('\r') == 1);
    assert(f_isascii('\v') == 1);
    assert(f_isascii('\f') == 1);
    printf("is_ascii tests passed successfully!\n");
    return (0);
}

int test_isprint(void) {
    assert(f_isprint('a') == 1);
    assert(f_isprint('b') == 1);
    assert(f_isprint('5') == 1);
    assert(f_isprint(' ') == 0);
    assert(f_isprint('\t') == 0);
    assert(f_isprint('\n') == 0);
    printf("is_ascii tests passed successfully!\n");
    return (0);
}

int test_iswhitespace(void) {
    assert(f_iswhitespace('a') == 0);
    assert(f_iswhitespace('b') == 0);
    assert(f_iswhitespace('5') == 0);
    assert(f_iswhitespace(' ') == 1);
    assert(f_iswhitespace('\t') == 1);
    assert(f_iswhitespace('\n') == 1);
    assert(f_iswhitespace('\0') == 0);

    printf("is_whitespace tests passed successfully!\n");
    return (0);
}

int test_strlen(void) {
    assert(f_strlen("") == 0);
    assert(f_strlen("abc") == 3);
    assert(f_strlen("abcabc") == 6);
    assert(f_strlen("abcabcabc") == 9);
    assert(f_strlen("abcabcabcabc") == 12);
    printf("strlen tests passed successfully!\n");
    return (0);
}

int test_putchar(void) {
    f_putchar('t');
    f_putchar('e');
    f_putchar('s');
    f_putchar('t');
    f_putchar('\n');
    printf("putchar tests passed successfully!\n");
    return (0);
}

int test_putstr(char *s) {
    int bytes;
    bytes = f_putstr(s);
    assert(f_strlen(s) == bytes);
    printf("putstr tests passed successfully!\n");
    return (bytes);
}

int test_putendl(char *s) {
    int bytes;
    bytes = f_putendl(s);
    assert(f_strlen(s) + 1 == bytes);
    printf("putendl tests passed successfully!\n");
    return (bytes);
}

void test_strcat () {
    char s1[8] = {
        'a',
        'b',
        'c',
        '\0',
        '\0',
        '\0',
        '\0',
        '\0'
    };
    const char *s2;
    s2 = "123";
    assert(f_strcmp(f_strcat(s1, s2), "abc123") == 0);
    f_putstr("strcat tests past sucessfully\n");
}

void test_strcmp() {
    char    *s1;
    char    *s2;
    
    s1 = "abc";
    s2 = "123";
    assert(f_strcmp(s1, s1) == 0);
    assert(f_strcmp(s1, s2) == -1);
    f_putstr("strcmp tests past sucessfully\n");
}

void test_strncmp() {
    char    *s1;
    char    *s2;
    
    s1 = "abc";
    s2 = "123";
    assert(f_strncmp(s1, s1, 3) == 0);
    assert(f_strncmp(s1, s1, 2) == 0);
    assert(f_strncmp(s1, s2, 3) == -1);
    f_putstr("strncmp tests past sucessfully\n");
}

void test_putnbr() {
    f_putnbr(0);
    f_putchar('\n');
    f_putnbr(1);
    f_putchar('\n');
    f_putnbr(10);
    f_putchar('\n');
    f_putnbr(11);
    f_putchar('\n');
    f_putnbr(111);
}

int main(void) {
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_strlen();
    test_putchar();
    test_putstr("test putstr");
    test_putendl("test putendl");
    test_dtoc();
    test_putnbr();
    test_iswhitespace();
    test_strcat();
    test_strcmp();
    test_strncmp();
    return 0;
}