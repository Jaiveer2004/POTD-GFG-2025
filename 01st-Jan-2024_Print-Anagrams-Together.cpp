/*
Question : Print Anagrams Together
Link : https://www.geeksforgeeks.org/problems/print-anagrams-together/1

Problem Statement: 
We are given with a array of strings. The array contains string which are anagram of one of another. We have to create an array of array of strings, So that all the matching anagrams get together.

For Example:
Input: arr[] = ["act", "god", "cat", "dog", "tac"]
Output: [["act", "cat", "tac"], ["god", "dog"]]
Here, "act", "cat" and "tac" have the same charachter in them while "god" and "dog" have same charachter in them.

Logic: 
We can check for each string by converting them into a charachter array and then sorting it.
Then we can add a referal string as the key and then add all the other matching string as the value of that key.

Steps to Solve:
1. Create an unordered_map with string as key and vector<string> as the value.
2. Start iterating on the array given.
3. Keep the word reserved in a variable and then sort the word.
4. Check if the sorted word already exists as the key, if yes then add it to the vector of strings while if no then create a vector<string> with sortedWord as the key.
5. In the end, add all the vector<string> to a vector<string> named answer and then return it.

A Solved Testcase for clearity:
Lets take an array
arr[] = ["act", "god", "cat", "dog", "tac"]
* Step 1 is to create an unordered_map with string as key and vector<string> as the value.

* Step 2 is to iterate through the array.
* i = 0 to i = arr.size() - 1;

# i = 0, arr[i] = arr[0] = "act"
- Sort the word, while keeping it reserved in a variable.
SortedWord = s;
sort -> SortedWord
After Sorting, the word becomes : "act"

- Check it for the condition if is already NOT existed as the key in the map.
if(!(hash.count(SortedWord)))
If yes (Means key didn't existed) : Then add it as the key and make an array of string for that key
hash[SortedWord] = vector<string>();

- Then push back "s" which was reserved before to the same string.
hash["act"] = ["act"]

# i = 1, arr[i] = arr[1] = "god"
- After Sorting, it becomes : "dgo"
- When it check if it exists as key or not, it will enter the if condition and would make an array of string.
hash["dgo"] = vector<string>();

- Then push back "s" which was reserved before to the same string.
hash["dgo"] = ["dog"]

# i = 2, arr[2] = "cat"
- After sorting, it becomes : "act"
- Now, when it checks for the condition it would ignore it as the if condition would fail and it would just get pushed back in the array of sortedWord.
- hash["act"] = ["act", "cat"]

# i = 3, arr[i] = arr[3] = "dog"
- After sorting, it becomes: "dgo".
- When it checks for the condition if(!(hash.count(SortedWord))), it would fail because "dgo" already exists as a key.
- It will simply push back "s" (original string before sorting) into the vector for "dgo".
- hash["dgo"] = ["god", "dog"].

# i = 4, arr[i] = arr[4] = "tac"
- After sorting, it becomes: "act".
- When it checks for the condition if(!(hash.count(SortedWord))), it would fail because "act" already exists as a key.
- It will simply push back "s" into the vector for "act".
- hash["act"] = ["act", "cat", "tac"].

---

# Final Step:
- Iterate through the unordered_map hash.
- For every key-value pair in hash, push the value (vector of strings) into the answer vector.
- Example: answer = [["act", "cat", "tac"], ["god", "dog"]].

# Return the answer vector, which now contains all the grouped anagrams together.

*/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        
        unordered_map<string, vector<string>> mp;
        
        for(string s : arr) {
            string sortedWord = s;
            sort(sortedWord.begin(), sortedWord.end());
            
            if(!(mp.count(sortedWord))) {
                mp[sortedWord] = vector<string>();
            }
            mp[sortedWord].push_back(s);
        }
        
        vector<vector<string>> answer;
        
        for(auto pair : mp) {
            answer.push_back(pair.second);
        }
        
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
