/*
Question: Count all triplets with given sum in sorted array
Link: https://www.geeksforgeeks.org/problems/count-all-triplets-with-given-sum-in-sorted-array/1

Problem Statement: You are given a sorted array and a target variable "k". You have to count of 3 variables such that there sum is equal to the given target.

# BRUTE FORCE APPROACH
Take three loops and check if there sum is equal to target, increment to count if yes.
Time Complexity: O(N^3)
Auxillary Space Complexity : O(1)

Now, lets optimize our code a little to make the time complexity O(N^2)

# OPTIMIZED APPROACH:
We will use the two-pointer technique to solve this problem.

Logic:
1. Fix the first element as arr[i].
2. Use two pointers (start and end) to find pairs in the remaining array whose sum is equal to (x - arr[i]).
3. If the sum of the triplet is less than x, move the start pointer to the right to increase the sum.
4. If the sum of the triplet is greater than x, move the end pointer to the left to decrease the sum.
5. If the sum of the triplet is equal to x, count the number of occurrences of the elements at the start and end pointers, and update the count accordingly.

Let's understand it using a testcase:
arr[] = [-3, -1, -1, 0, 1, 2] and x = -2

i -> [0, arr.size() - 1] -> [0, 5]
count = 0

# i = 0
 0, 1, 2, 3, 4, 5
[-3, -1, -1, 0, 1, 2]

start = 1, end = 5
sum = arr[0] + arr[1] + arr[5] = -3 + (-1) + 2 = -2 [sum == x]
- Count the number of occurrences of arr[start] and arr[end]
- count++ -> count = 1
- Move start to the right and end to the left -> start = 2, end = 4

start = 2, end = 4
sum = arr[0] + arr[2] + arr[4] = -3 + (-1) + 1 = -3 [sum < x]
- Move start to the right -> start = 3

start = 3, end = 4
sum = arr[0] + arr[3] + arr[4] = -3 + 0 + 1 = -2 [sum == x]
- Count the number of occurrences of arr[start] and arr[end]
- count++ -> count = 2
- Move start to the right and end to the left -> start = 4, end = 3

# i = 1
 0, 1, 2, 3, 4, 5
[-3, -1, -1, 0, 1, 2]

start = 2, end = 5
sum = arr[1] + arr[2] + arr[5] = -1 + (-1) + 2 = 0 [sum > x]
- Move end to the left -> end = 4

start = 2, end = 4
sum = arr[1] + arr[2] + arr[4] = -1 + (-1) + 1 = -1 [sum > x]
- Move end to the left -> end = 3

start = 2, end = 3
sum = arr[1] + arr[2] + arr[3] = -1 + (-1) + 0 = -2 [sum == x]
- Count the number of occurrences of arr[start] and arr[end]
- count++ -> count = 3
- Move start to the right and end to the left -> start = 3, end = 2

# i = 2
 0, 1, 2, 3, 4, 5
[-3, -1, -1, 0, 1, 2]

start = 3, end = 5
sum = arr[2] + arr[3] + arr[5] = -1 + 0 + 2 = 1 [sum > x]
- Move end to the left -> end = 4

start = 3, end = 4
sum = arr[2] + arr[3] + arr[4] = -1 + 0 + 1 = 0 [sum > x]
- Move end to the left -> end = 3

start = 3, end = 3
- Loop ends as start is not less than end

# i = 3
 0, 1, 2, 3, 4, 5
[-3, -1, -1, 0, 1, 2]

start = 4, end = 5
sum = arr[3] + arr[4] + arr[5] = 0 + 1 + 2 = 3 [sum > x]
- Move end to the left -> end = 4

start = 4, end = 4
- Loop ends as start is not less than end

# i = 4
 0, 1, 2, 3, 4, 5
[-3, -1, -1, 0, 1, 2]

start = 5, end = 5
- Loop ends as start is not less than end

# i = 5
 0, 1, 2, 3, 4, 5
[-3, -1, -1, 0, 1, 2]

start = 6, end = 5
- Loop ends as start is not less than end

So, in the end count = 4

Return count = 4;


Let's take one more example:
arr[] = [1, 1, 1, 1, 1, 1] and x = 3

i -> [0, arr.size() - 1] -> [0, 5]
count = 0

# i = 0
 0, 1, 2, 3, 4, 5
[1, 1, 1, 1, 1, 1]

start = 1, end = 5
sum = arr[0] + arr[1] + arr[5] = 1 + 1 + 1 = 3 [sum == x]
- Count the number of occurrences of arr[start] and arr[end]
- c1 = 5, c2 = 1
- count += c1 * c2 -> count = 5
- Move start to the right and end to the left -> start = 6, end = 4

# i = 1
 0, 1, 2, 3, 4, 5
[1, 1, 1, 1, 1, 1]

start = 2, end = 5
sum = arr[1] + arr[2] + arr[5] = 1 + 1 + 1 = 3 [sum == x]
- Count the number of occurrences of arr[start] and arr[end]
- c1 = 4, c2 = 1
- count += c1 * c2 -> count = 9
- Move start to the right and end to the left -> start = 6, end = 4

# i = 2
 0, 1, 2, 3, 4, 5
[1, 1, 1, 1, 1, 1]

start = 3, end = 5
sum = arr[2] + arr[3] + arr[5] = 1 + 1 + 1 = 3 [sum == x]
- Count the number of occurrences of arr[start] and arr[end]
- c1 = 3, c2 = 1
- count += c1 * c2 -> count = 12
- Move start to the right and end to the left -> start = 6, end = 4

# i = 3
 0, 1, 2, 3, 4, 5
[1, 1, 1, 1, 1, 1]

start = 4, end = 5
sum = arr[3] + arr[4] + arr[5] = 1 + 1 + 1 = 3 [sum == x]
- Count the number of occurrences of arr[start] and arr[end]
- c1 = 2, c2 = 1
- count += c1 * c2 -> count = 14
- Move start to the right and end to the left -> start = 6, end = 4

# i = 4
 0, 1, 2, 3, 4, 5
[1, 1, 1, 1, 1, 1]

start = 5, end = 5
sum = arr[4] + arr[5] + arr[5] = 1 + 1 + 1 = 3 [sum == x]
- Count the number of occurrences of arr[start] and arr[end]
- c1 = 1, c2 = 1
- count += c1 * c2 -> count = 15
- Move start to the right and end to the left -> start = 6, end = 4

# i = 5
 0, 1, 2, 3, 4, 5
[1, 1, 1, 1, 1, 1]

start = 6, end = 5
- Loop ends as start is not less than end

So, in the end count = 20

Return count = 20;


*/
#include<bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> &arr, int x) {
    int count = 0;

    for(int i = 0; i <= arr.size() - 3; i++) {
        for(int j = i + 1; j <= arr.size() - 2; j++) {
            for(int k = j + 1; k <= arr.size() - 1; k++) {
                if(arr[i] + arr[j] + arr[k] == x) {
                    count++;
                }
            }
        }
    }

    return count;

    /*
    Time Complexity: O(N^3)
    Space Complexity : O(1)
    */
}



int optimized(vector<int> &arr, int x) {
    int count = 0;

    int n = arr.size();

    for(int i = 0; i < n ; i++) {
        int start = i + 1, end = n - 1;
        while(start < end) {
            int sum = arr[i] + arr[start] + arr[end];

            if(sum < x) {
                start++;
            } 

            else if (sum > x) {
                end--;
            } 
            
            else {
                int e1 = arr[start], e2 = arr[end], c1 = 0, c2 = 0;

                while(start <= end && arr[start] == e1) {
                    c1++;
                    start++;
                }

                while(start <= end && arr[end] == e2) {
                    c2++;
                    end--;
                }

                if(e1 == e2) {
                    count += (c1 * (c1 - 1)) / 2;
                } else {
                    count += c1 * c2;
                }
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

    // cout << bruteForce(arr, k);
    cout << optimized(arr, k);
     
    return 0;
}