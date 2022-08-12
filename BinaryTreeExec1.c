#include<stdio.h>
/**
 * 由n个节点可以组成多少个二叉树
 * @param n
 * @return number
 */

int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) res*=i;
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", factorial(2*n)/ (factorial(n+1)* factorial(n)));
}
