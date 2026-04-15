#include <stdio.h>

int main() {
    long long a, b, x, y;
    scanf("%lld %lld %lld %lld", &a, &b, &x, &y);

    long long u = x, o = y;

    while (o) {
        long long t = u % o;
        u = o;
        o = t;
    }

    long long g = u;

    x /= g;
    y /= g;

    long long a1 = a / x;
    long long a2 = b / y;

    if (a1 < a2)
        printf("%lld\n", a1);
    else
        printf("%lld\n", a2);

    return 0;
}
