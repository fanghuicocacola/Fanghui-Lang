#include <stdio.h>

int main()
{
    int x;
    float y;
    float a = 0.4463;
    float b = 0.4663;
    float c = 0.5663;
   
    scanf_s("%d", &x);
    if (x <= 150) {
        y = x * a;
    }
    else if (x <= 400) {
        y = 150 * a + (x - 150) * b;
    }
    else if (x >= 401) {
        y = 150 * a + 250 * b + (x - 400) * c;
    }
    printf_s("%0.1f", y);
}

