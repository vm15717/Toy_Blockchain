#include <iostream>
void fun1(int);

int main()
{
    int x = 3;
    fun1(x);
}

void fun1(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        fun1(n - 1);
    }
}