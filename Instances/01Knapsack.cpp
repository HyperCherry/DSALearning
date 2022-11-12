#include<iostream>

using namespace std;

void dynamicPack(int capacity, int itemCounts, int weights[], int values[]) {
    int dp[itemCounts + 1][capacity + 1];
    //init Table
    for (int i = 0; i < itemCounts + 1; i++) dp[i][0] = 0;
    for (int j = 0; j < capacity + 1; j++) dp[0][j] = 0;
    //Show me the table
    for (int i = 1; i < itemCounts + 1; i++) {
        for (int j = 1; j < capacity + 1; j++) {
            if (weights[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    for (int i = 0; i < itemCounts + 1; i++) {
        for (int j = 0; j < capacity + 1; j++) {
            std::cout << "[" << dp[i][j] << "]" << std::ends;
        }
        std::cout << std::endl;
    }
    std::cout << "所装入物品的最大总价值为:" << dp[itemCounts][capacity] << std::endl;
    //Start roll back
    for (int i = itemCounts; i > 0; i--) {
        if (dp[i][capacity] != dp[i - 1][capacity]) {
            std::cout << i << "号物品被装入背包,其价值为:"<<values[i-1] << std::endl;
            capacity -= weights[i - 1];
        }
    }
}

int main() {
    int capacity = 8;
    int itemCounts = 4;
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    dynamicPack(capacity, itemCounts, weights, values);
}