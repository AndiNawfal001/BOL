#include <stdio.h>

int main() {
    int i = 1;

loop:
    if (i > 5)
        goto end;

    printf("%d\n", i);
    i++;
    goto loop;

end:
    return 0;
}