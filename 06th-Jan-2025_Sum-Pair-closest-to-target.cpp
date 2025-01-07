/*
Question: Sum Pair closest to target
Link: https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1

Problem Statement: 
Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.
Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

Logic:
Sort the array.
Check if closestSum is less than the actual sum
Return the answer in form of vector.

*/

#include<bits/stdc++.h>
using namespace std;

void answer(vector<int> &arr, int x) {

    sort(arr.begin(), arr.end());

    int start = 0, end = arr.size() - 1;

    int left, right;
    left = right = -1;

    int closestSum = INT_MAX;

    vector<int> ans;

    while(start < end) {
        int sum = arr[start] + arr[end];

        if(abs(sum - x) < abs(closestSum)) {
            closestSum = abs(sum - x);
            left = arr[start];
            right = arr[end];
        }

        if(sum < x) {
            start++;
        } else {
            end--;
        }
    }

    ans.push_back(left);
    ans.push_back(right);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

}
 
int main()
{
    int size;
    cin >> size;
    
    vector<int> arr(size);
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    answer(arr, k);
     
    return 0;
}