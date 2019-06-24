#include<iostream>
#include<string.h>

//using namespace std; 
//  
//void removeDupWord(string str) 
//{ 
//   string word = " "; 
//   for (int x=0;x<str.length();x++) 
//   { 
//       if (str[x] == ' ') 
//       { 
//           cout << word << endl; 
//           word = ""; 
//       } 
//       else
//       { 
//           word = word + str[x]; 
//       } 
//   }  
//   cout << word << endl; 
//} 
//  
//// Driver function 
//int main() 
//{ 
//    string str = "Geeks for Geeks hello"; 
//    removeDupWord(str); 
//    return 0; 
//}



using namespace std; 
  
void removeDupWord(string str) 
{ 
    // Used to split string around spaces. 
    istringstream ss(str); 
  
    // Traverse through all words 
    do { 
        // Read a word 
        string word; 
        ss >> word; 
  
        // Print the read word 
        cout << word << endl; 
  
        // While there is more to read 
    } while (ss); 
} 
  
// Driver function 
int main() 
{ 
    string str = "Geeks for Geeks"; 
    removeDupWord(str); 
    return 0; 
}  
