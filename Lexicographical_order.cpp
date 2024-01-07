#include <bits/stdc++.h>
using namespace std;
int compare_chars(char arr1[], char arr2[]) { //strcmp
    int i = 0;

    while (arr1[i] != '\0' && arr2[i] != '\0') {
        if (arr1[i] != arr2[i]) {
            return (arr1[i] - arr2[i]);
        }
        i++;
    }

    return (arr1[i] - arr2[i]);
}
void copy_char(char arr1[], char arr2[]) { //strcpy
    int i = 0;
    while (arr2[i] != '\0') { 
        arr1[i] = arr2[i];    
        i++;
    }

    arr1[i] = '\0';
}


void sort_char() {
    char str[4][1000]; 
    char temp[1000];
     for (int i = 0; i < 4; ++i) {
        int n;
        cin >> n;

        cin.ignore();
        cin.getline(str[i], n + 1);  // Read only n characters
   }
    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
         if (compare_chars(str[i], str[j]) > 0) {
            copy_char(temp, str[i]);
            copy_char(str[i], str[j]);
            copy_char(str[j], temp);
         }
      }
   }
    for (int i = 0; i < 4; ++i) {
      cout<<str[i]<<endl;
   }
}
    

int main() {
    freopen("input.txt", "r", stdin); // input: 4 abcd '\n' 4 aacd '\n' 3 Aacd 
    freopen("output.txt", "w", stdout);// output: Aacd '\n' aacd '\n' abcd 
    sort_char();
    return 0;
}
