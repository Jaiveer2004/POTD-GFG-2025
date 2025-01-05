/*
Question: Count Pairs whose sum is less than target
Link: https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-less-than-target/1

Problem Statement: 
Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.


Logic: 
Sort the array
Using two pointers, (start and end) calculate the sum of start and end,
If arr[start] + arr[end] < x : Add end - start to the count, count += end - start
Reason of count += end - start: If end has sum less than x, than all the elements before them would also have sum less than x. 
*/

#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int x) {
    
    sort(arr.begin(), arr.end());

    int count = 0;
    int start = 0, end = arr.size() - 1;

    while(start < end) {
        int sum = arr[start] + arr[end];
        if(sum < x) {
            count += end - start;
            start++;
        }
        else {
            end--;
        }
    }

    return count;
}

int main()
{

    int size;
    cin >> size;
    
    vector<int> arr(size);
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    cout << countPairs(arr, x);
     
    return 0;
}