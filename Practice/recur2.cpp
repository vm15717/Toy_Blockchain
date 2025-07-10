#include <iostream>
void fun2(int);

int main()
{
    int x = 3;
    fun2(x);
}

void fun2(int n)
{
    if (n > 0)
    {
        fun2(n-1);
        printf("%d\n", n);
    }
}

