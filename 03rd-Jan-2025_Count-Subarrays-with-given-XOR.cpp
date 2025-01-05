/*
Question: Count Subarrays with given XOR
Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

Problem Statement:
Provided an array and an integer "k", find the number of subarrays whose XOR of elements in that subarray is equal to the given integer "k".

# BRUTE FORCE:
Create sub arrays by using an outer and inner loop and then check if its XOR is equal to the given number.

# OPTIMIZED APPROACH:
We will use prefix XOR and Unordered Map to solve this problem.

Logic: 
Consider the property of XOR,
                            If       a ^ b = c
                            Then     a ^ c = b

Similarly we are calculating the XOR of each element in a subarray.

                            If      arr[i] ^ arr[i + 1] = k
                            Then    arr[i] ^ k = arr[i + 1]
We can use this property to find if the element (arr[i + 1]) exists before by using (arr[i] ^ k)

Lets understand it using a testcase:
arr[] = [4, 2, 2, 6, 4] and k = 6

i -> [0, arr.size() - 1] -> [0, 4]
currentXOR = 0, mp = {}, count = 0

# i = 0
 0, 1, 2, 3, 4
[4, 2, 2, 6, 4]

currentXOR ^= arr[i] = currentXOR ^ arr[0] = 0 ^ 4 = 4 [currentXOR = 4]
- if(currentXOR == k) -> False
For calculation, lets calculate currentXOR ^ k = 0 ^ 6 = 6 [currentXOR ^ k = 6]
- if(currentXOR ^ k exists in map, add it the number of times it has occurerd) -> False, as the map is still empty

mp[currentXOR]++; -> mp = {4 : 1}

# i = 1
 0, 1, 2, 3, 4
[4, 2, 2, 6, 4]

currentXOR ^= arr[i] = currentXOR ^ arr[1] = 4 ^ 2 = 6 [currentXOR = 6]
- if(currentXOR == k) -> True, count++ [count = 1]
For calculation, lets calculate currentXOR ^ k = 6 ^ 6 = 0 [currentXOR ^ k = 0]
- if(currentXOR ^ k exists in map, add it the number of times it has occurerd) -> False, as it in not in the map

map[currentXOR]++; -> mp = {4 : 1, 6 : 1}

# i = 2
 0, 1, 2, 3, 4
[4, 2, 2, 6, 4]

currentXOR ^= arr[i] = currentXOR ^ arr[2] = 6 ^ 2 = 4 [currentXOR = 4]
- if(currentXOR == k) -> False -> [count = 1]
For calculation, lets calculate currentXOR ^ k = 4 ^ 6 = 2 [currentXOR ^ k = 2]
- if(currentXOR ^ k exists in map, add it the number of times it has occurerd) -> False, as it in not in the map
[count = 1]

map[currentXOR]++; -> mp = {4 : 2, 6 : 1}

# i = 3
 0, 1, 2, 3, 4
[4, 2, 2, 6, 4]

currentXOR ^= arr[i] = currentXOR ^ arr[3] = 4 ^ 6 = 2 [currentXOR = 2]
- if(currentXOR == k) -> False
For calculation, lets calculate currentXOR ^ k = 2 ^ 6 = 4 [currentXOR ^ k = 4]
- if(currentXOR ^ k exists in map, add it the number of times it has occurerd) -> True, it is in the map,
So, add the number of times it has occured in count
count += map[currentXOR] = count + map[currentXOR] = 1 + 2 = 3; [count = 3] 

mp[currentXOR]++; -> mp = {4 : 2, 6 : 1, 2 : 1}

# i = 4
 0, 1, 2, 3, 4
[4, 2, 2, 6, 4]

currentXOR ^= arr[i] = currentXOR ^ arr[4] = 2 ^ 4 = 6 [currentXOR = 6]
- if(currentXOR == k) -> True -> count++ -> [count = 4]
For calculation, lets calculate currentXOR ^ k = 6 ^ 6 = 0 [currentXOR ^ k = 0]
- if(currentXOR ^ k exists in map, add it the number of times it has occurerd) -> False

mp[currentXOR]++; -> mp = {4 : 2, 6 : 1, 2 : 1, 0 : 1}

So, in the end count = 4

Return count = 4;

*/
#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH

int bruteForce(vector<int> &arr, int k) {
    int size = arr.size();
    int count = 0;

    for(int i = 0; i < size - 1; i++) {
        int xorSum = 0;
        for(int j = i ; j < size; j++) {
            xorSum ^= arr[j];
            if(xorSum == k) {
                count++;
            }
        }
    }

    return count;
}

// Optimized Approach 
int optimized(vector<int> &arr, int k) {
    unordered_map<int, int> mp;
    int count = 0;
    int currentXOR = 0;

    for(int num : arr) {
        currentXOR ^= num;

        if(currentXOR == k) {
            count++;
        }

        if(mp.find(currentXOR ^ k) != mp.end()) {
            count += mp[currentXOR ^ k];
        }

        mp[currentXOR]++;
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

    cout << bruteForce(arr, k) << endl;
    cout << optimized(arr, k) ;
    
    return 0;
}