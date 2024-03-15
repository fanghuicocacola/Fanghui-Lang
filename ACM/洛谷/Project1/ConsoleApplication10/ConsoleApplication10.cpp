#include <stdio.h>
#include<string.h>
int main()
{
    int n,x;
    char s[55];
    scanf_s("%d\n", &n);
    n = n % 26;
    gets_s(s);
    s[strlen(s)+1] = '\0';
    x = strlen(s);
    for (int i = 0; i < x; i++) {
        if (s[i] + n >= 128)
            s[i] += n - 26;
        else
            s[i] += n;
        while(s[i] > 122) {
            s[i] = s[i] % 122 + 'a' - 1;
        }
        
    }
    
    puts(s);
   
    return 0;
}


