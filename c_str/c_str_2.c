#include <stdio.h>
#include <string.h>
#include <strings.h>

int main(int argc, char *argv[])
{
    char *str = "abc";
    printf("str= %s \n", str);
    printf("length= %d \n", strlen(str));

    /**
     * https://stackoverflow.com/questions/18410234/how-does-one-represent-the-empty-char#:~:text=You%20can%20use%20c%5Bi,character%20with%20an%20escaped%20zero.&text=Yes%2C%20and%20there%20is%20no,having%200%20as%20numeric%20code.
     * https://theasciicode.com.ar/
     * 
     * null char is an asic character with deciaml code = 0
     * (char) 0 = null char = '\0'; 
     * */
    printf("ind char %d \n", str[3] == '\0');
    return 0;
}