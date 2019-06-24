#include<iostream>
#include<set>
#include<unordered_set>
using namespace std; 
  
// Returns first repeating character in str. 
char firstRepeating(string &str) 
{ 
    // Creates an empty hashset 
    unordered_set<char> h; 
  
    // Traverse the input array from left to right 
    for (int i=0; i<str.length(); i++) 
    { 
        char c = str[i]; 
  
        // If element is already in hash set, update x 
        // and then break 
        if (h.find(c) != h.end()) 
            return c; 
  
        else // Else add element to hash set
            {
            cout<<c<<endl;
            h.insert(c); 
            }
    } 
  
    // If there was no repeated character 
    return '\0'; 
} 

// Driver method to test above method 
int main () 
{ 
    string str = "geeksforgeeks"; 
    cout << firstRepeating(str); 
    return 0; 
} 
