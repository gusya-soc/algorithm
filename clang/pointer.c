#include<stdlib.h>
#include<stdio.h>

int main()
{
    // int a = 1,b=2;
    // int *p_a,*p_b;
    // p_a = &a;//将a变量的地址传递给指针p_a
    // // p_b = b;
    // // *p_b = 3;
    // printf("%d",*p_a);//p_a是a的地址，*p_a是a的值
    // *p_a = 3;//等价于 a = 3;
    // printf("%d",*p_a);
    // printf("%d",a);
    // p_a = 5;//非法操作，但能过编译
    // printf("%d",p_a);

    char c[10];
    c[0] = 'a';
    c[1] = 'b';
    c[2] = 'c';
    c[3] = '\0';
    char d;
    char *cp;
    cp = &d;
    // cp = c;
    // printf("%s\n",cp);
    // cp++;
    // printf("%s\n",cp);
    // printf("%s\n",(char *)cp);

    *cp = c[1];
    printf("%s\n",(char *)cp);
    return 0;
}