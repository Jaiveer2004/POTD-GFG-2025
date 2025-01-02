/*
QUESTION: Subarrays with sum k
LINK: https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

Problem Statement: We are given an unsorted array and an integer "k", and we have to find the count of the subarrays such that there sum is equal to k.

For Example: 
Input: arr = [10, 2, -2, -20, 10], k = -10
Output: 3
Explanation: The subbarrays arr[0 to 3], arr[1 to 4], arr[3 to 4] have sum exactly equal to -10.
arr[0 to 3] = 10 + 2 + -2 + -20 = -10
arr[1 to 4] = 2 + -2 + -20 + 10 = -10
arr[3 to 4] = -20 + 10 = -10

Brute Force Approach:
Check for each subarray if its sum is equal to the give k, if yes then add to count
1. Start with an outer loop as the starting point of the subarray and an inner loop which will mark the end of the subarray.
2. Add arr[j] with each iteration and check if it is equal to "k".
3. Reset sum to arr[i] with each iteration of i.

Explanation with a test case:
Given an arr = [10, 2, -2, -20, 10] and k = -10, Let's solve it using the brute force approach.
* i -> [0, size - 2] and j -> [i + 1, size - 1]
# i = 0 and j = 1
 0,  1,  2,  3,  4 
[10, 2, -2, -20, 10]
  i  j 

Outer Loop : sum = arr[i] = arr[0] = 10
Inner Loop : sum += arr[j] = arr[1] = sum + 2 = 10 + 2 = 12
Checking the condition : if(sum == k) False -> j++

# i = 0 and j = 2
 0,  1,  2,  3,  4 
[10, 2, -2, -20, 10]
  i      j

Inner Loop : sum += arr[j] = arr[2] = sum + -2 = 12 - 2 = 10
Checking the condition : if(sum == k) False -> j++

# i = 0 and j = 3
 0,  1,  2,  3,  4 
[10, 2, -2, -20, 10]
  i          j

Inner Loop : sum += arr[j] = arr[3] = sum + -20 = 10 - 20 = -10
Checking the condition : if(sum == k) True -> count++ -> (count = 1) -> i++

# i = 1 and j = 2
 0,  1,  2,  3,  4 
[10, 2, -2, -20, 10]
     i   j 

Outer Loop : sum = arr[i] = arr[1] = 2
Inner Loop : sum += arr[j] = arr[2] = sum + -2 = 2 - 2 = 0
Checking the condition : if(sum == k) False -> j++

# i = 1 and j = 3
 0,  1,  2,  3,  4 
[10, 2, -2, -20, 10]
     i       j

Inner Loop : sum += arr[j] = arr[3] = sum + -20 = 0 - 20 = -20
Checking the condition : if(sum == k) False -> j++

# i = 1 and j = 4
 0,  1,  2,  3,  4 
[10, 2, -2, -20, 10]
     i           j

Inner Loop : sum += arr[j] = arr[4] = sum + 10 = -20 + 10 = -10
Checking the condition : if(sum == k) True -> count++ -> (count = 2) -> i++

# i = 2 and j = 3
 0,  1,  2,  3,  4 
[10, 2, -2, -20, 10]
         i   j 

Outer Loop : sum = arr[i] = arr[2] = -2
Inner Loop : sum += arr[j] = arr[3] = sum + -20 = -2 - 20 = -22
Checking the condition : if(sum == k) False -> j++

# i = 2 and j = 4
 0,  1,  2,  3,  4 
[10, 2, -2, -20, 10]
         i        j

Inner Loop : sum += arr[j] = arr[4] = sum + 10 = -22 + 10 = -12
Checking the condition : if(sum == k) False -> i++

# i = 3 and j = 4
 0,  1,  2,  3,  4 
[10, 2, -2, -20, 10]
              i   j

Outer Loop : sum = arr[i] = arr[3] = -20
Inner Loop : sum += arr[j] = arr[4] = sum + 10 = -20 + 10 = -10
Checking the condition : if(sum == k) True -> count++ -> (count = 3) -> i++

i exceeds size - 1, so outer loop stops

In the end it return count = 3.

Time Complexity: As the it is nested loop and array is iterated twice in each iteration, its Time Complexity is O(N)
Space Complexity : As no additional space has been taken, its space complexity is O(1).

Now, we need to optimize the solution to make the Time Complexity to O(N).

OPTIMIZED SOLUTION:
Logic:

* Prefix Sum: Prefix sum is the running sum of the elements of the array.
For Example: arr = [10, 1, 2, 7, 3]
prefixSum[0] = 10
prefixSum[1] = 10 + 1 = 11
prefixSum[2] = 11 + 2 = 13
prefixSum[3] = 13 + 7 = 20
prefixSum[4] = 20 + 3 = 23  
                                         [10,  1,  2,  7,  3]
So, the prefixSum array would look like: [10, 11, 13, 20, 23]

So, if we want to calculate the sum of [i...j], we need to calculate the prefix sum of i and j and then check if it is equal to k or not.
For Example, we need to calculate [0...3]:
arr[0...3] = arr[0] + arr[1] + arr[2] + arr[3]

Similary if we want to calculate [1...3]:
We can do so by subtracting arr[0] from it.

arr[1...3] = arr[1] + arr[2] + arr[3] - arr[0]

So, in general form

        k = prefixSum[j] - prefixSum[i - 1]

Now, what does prefixSum[j] and prefixSum[i - 1] means:
prefixSum[j]: Sum till arr[j]
prefixSum[i - 1]: Sum till arr[i]

We need to subtract it to equal the equation

For Example:

arr[1...3] = (arr[1] + arr[2] + arr[3]) - (arr[0])
                    prefixSum[j]           prefixSum[i - 1]
Here, prefixSum[j] = prefixSum[3] = Sum till arr[3]
and prefixSum[i - 1] = prefixSum[1 - 1] = prefixSum[0] = Sum till 0.

We need to subtract it to get the result

Now, we know that 

        k = prefixSum[j] - prefixSum[i - 1]

Modifying it for convinince we get

        prefixSum[i - 1] = prefixSum[j] - k
        target = prefixSum[j] - k, where target = prefixSum[i - 1]


So, we would be using an unordered map to store this prefixSum.
Reason: 
We are storing prefixSum in an unordered_map, so that we can check if prefixSum[i - 1] already exists in our map which means that there is a subarray starting from i - 1 and ending at j and with sum k
It also helps in constant time lookups in the storage providing O(1) time complexity.

Solving it for a testcase will give more clearity:
arr[] = [10, 2, -2, -20, 10] k = -10
prefixMap[0] = 1, prefixSum = 0, count = 0, target;
prefixMap is initalized with 0:1 so that the zeroth index gets covered

*i -> [0, size - 1]

# i = 0
[10, 2, -2, -20, 10]
  i
prefixSum += arr[i] = prefixSum + arr[0] = 0 + 10 = 10 [prefixSum = 10]
target = prefixSum - k = 10 - (-10) = 20 [target = 20]

- if(target exists in prefixMap) count += prefixMap[prefixSum] 
Now, here target is 20, which doesn't exist 
So, this step is skipped.
[count = 0]

prefixMap[prefixSum]++; -> prefixMap = {0 : 1, 10 : 1}

# i = 1
[10, 2, -2, -20, 10]
     i 
prefixSum += arr[i] = prefixSum + arr[1] = 10 + 2 = 12 [prefixSum = 12]
target = prefixSum - k = 12 - (-10) = 12 + 10 = 22 [target = 22]

- if(target exists in prefixMap) count += prefixMap[prefixSum] 
Now, here target is 22, which doesn't exist 
So, this step is skipped.
[count = 0]

prefixMap[prefixSum]++; -> prefixMap = {0 : 1, 10 : 1, 12 : 1}

# i = 2
[10, 2, -2, -20, 10]
         i

prefixSum += arr[i] = prefixSum + arr[2] = 12 + (-2) = 10 [prefixSum = 10]
target = prefixSum - k = 10 - (-10) = 0 [target = 0]

- if(target exists in prefixMap) count += prefixMap[prefixSum] 
Here, target = 0, which has already appeard in the hashMap. So, count gets incremented
count += prefixMap[prefixSum] = count + prefixMap[10] = 0 + 1 = 1

prefixMap[prefixSum]++; -> prefixMap = {0 : 1, 10 : 2, 12 : 1}

# i = 3
[10, 2, -2, -20, 10]
             i

prefixSum += arr[i] = prefixSum + arr[3] = 10 + (-20) = 10 - 20 = -10 [prefixSum = -10]
target = prefixSum - k = -10 - 10 = -20 [target = -20] 

- if(target exists in prefixMap) count += prefixMap[prefixSum] 
Now, here target is -20, which doesn't exist 
So, this step is skipped.
[count = 1]

prefixMap[prefixSum]++; -> prefixMap = {0 : 1, 10 : 2, 12 : 1, -10 : 1}


# i = 4
[10, 2, -2, -20, 10]
                  i

prefixSum += arr[i] = prefixSum + arr[4] = -10 + 10 = 0 [prefixSum = 0]
target = prefixSum - k = 0 - (-10) = 0 + 10 = 10

- if(target exists in prefixMap) count += prefixMap[prefixSum] 
Here, target = 0, which has already appeard in the hashMap. So, count gets incremented
count += prefixMap[prefixSum] = count + prefixMap[10] = 0 + 2 = 3


- It would return value 3.

*/

#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> arr, int k) {
    int sum, size = arr.size();
    int count = 0;
    for(int i = 0; i < size - 1; i++) {
        sum = arr[i];
        for(int j = i + 1; j < size; j++) {
            sum += arr[j];
            if(sum == k) {
                count++;
            }
        }
    }

    return count;
}

int optimizedSolution(vector<int> arr, int k) {
    int count = 0;
    int prefixSum = 0;
    int size = arr.size();
    unordered_map<int, int> prefixMap;

    prefixMap[0] = 1;

    for(int i = 0; i < size; i++) {
        prefixSum += arr[i];

        int target = prefixSum - k;

        if(prefixMap.find(target) != prefixMap.end()) {
            count += prefixMap[target];
        }

        prefixMap[prefixSum]++; 
    }

    return count;
}

int main() {
	// your code goes here

    int size;
    cin >> size;

    vector<int> arr(size);

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << bruteForce(arr, k) << endl;
    cout << optimizedSolution(arr, k);
    

}
