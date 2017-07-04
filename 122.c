/*
Author: HULK
Date ： 2017-06-29 14:59:47
*/

/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    int i ;
    for (int i = 1; i < pricesSize; ++i)
    {
    	int tmp = prices[i] - prices[i-1];
    	max += tmp>0?tmp:0;
    }
    return max;
}