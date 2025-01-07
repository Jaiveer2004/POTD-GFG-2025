/*
Question: Pair with given sum in a sorted array
Link: https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1

Problem Statement: 
You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
Note: Pairs should have elements of distinct indexes.

# BRUTE FORCE APPROACH:
Use two loops to find the sum and then compare it with target, if matches increase the counter.
Time Complexity: O(N^2)
Auxiliary Space Complexity: O(1)

Now, let's optimize our code to make the time complexity O(N)

# OPTIMIZED APPROACH:
We will use the two-pointer technique to solve this problem.

Logic:
1. Initialize two pointers, start at the beginning of the array and end at the end of the array.
2. Calculate the sum of the elements at the start and end pointers.
3. If the sum is equal to the target, count the number of occurrences of the elements at the start and end pointers.
4. If the sum is less than the target, move the start pointer to the right to increase the sum.
5. If the sum is greater than the target, move the end pointer to the left to decrease the sum.
6. If the elements at the start and end pointers are the same, calculate the number of pairs using the combination formula.
7. Repeat the process until the start pointer is less than the end pointer.

Let's understand it using a testcase:
arr[] = [-1, 1, 5, 5, 7] and x = 6

start = 0, end = 4, count = 0

# Iteration 1:

  0  1  2  3  4
[-1, 1, 5, 5, 7]
sum = arr[start] + arr[end] = arr[0] + arr[4] = -1 + 7 = 6 [sum == x]
- It passes the condition (sum == x), so count the number of occurrences of arr[start] and arr[end]
left = arr[start] = -1, right = arr[end] = 7
c1 = 1, c2 = 1
while(start <= end && arr[start] == left) -> c1 = 1, start = 1 [start = 1]
while(start <= end && arr[end] == right) -> c2 = 1, end = 3 [end = 3]
if(left == right) -> count += (c1 * (c1 - 1)) / 2 -> False
else count += c1 * c2 -> count = 1 [count = 1]

# Iteration 2:

  1  2  3  4  5
[-1, 1, 5, 5, 7]

sum = arr[start] + arr[end] = arr[1] + arr[3] = 1 + 5 = 6 [sum == x]
- It passes the condition (sum == x), so count the number of occurrences of arr[start] and arr[end]
left = arr[start] = 1, right = arr[end] = 5
while(start <= end && arr[start] == left) -> c1 = 1, start = 2 [start = 2]
while(start <= end && arr[end] == right) -> c2 = 2, end = 2 [end = 2]
if(left == right) -> count += (c1 * (c1 - 1)) / 2 -> False
else count += c1 * c2 -> count = 1 + 2 = 3 [count = 3]

# Condition breaks as start is now equal to end

So, in the end count = 3


Let's understand it using a testcase:
arr[] = [1, 1, 1, 1, 1, 1] and x = 2

start = 0, end = 5
count = 0

# Iteration 1
arr[start] = 1, arr[end] = 1
sum = arr[start] + arr[end] = 1 + 1 = 2 [sum == x]
- Count the number of occurrences of arr[start] and arr[end]
- c1 = 6, c2 = 6
- Since left == right, count += (c1 * (c1 - 1)) / 2 -> count = 15
- Move start to the right and end to the left -> start = 6, end = 4

# Iteration 2
start = 6, end = 4
- Loop ends as start is not less than end

So, in the end count = 15

Return count = 15;

*/


#include<bits/stdc++.h>
using namespace std;

int countPairsBruteForce(vector<int> &arr, int x) {
    int count = 0;
    int size = arr.size();

    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] + arr[j] == x) {
                count++;
            }
        }
    }

    return count;
}

int optimized(vector<int> &arr, int x) {
    int count = 0;
    int size = arr.size();

    int start = 0, end = size - 1;

    while(start < end) {
        int sum = arr[start] + arr[end];

        if(sum < x) {
            start++;
        }

        else if (sum > x) {
            end--;
        }

        else {
            int left = arr[start];
            int right = arr[end];

            int c1 = 0, c2 = 0;

            while(start <= end && arr[start] == left) {
                c1++;
                start++;
            }

            while(start <= end && arr[end] == right) {
                c2++;
                end--;
            }

            if(left == right) {
                count += (c1 * (c1 - 1)) / 2;
            } else {
                count += c1 * c2;
            }
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

    int k;
    cin >> k;

    cout << countPairsBruteForce(arr, k) << endl;
    cout << optimized(arr, k) << endl;

     
     return 0;
}