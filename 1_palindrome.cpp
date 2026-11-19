#include <iostream>
#include <string>
using namespace std;

bool isNumberPalindrome(int number) {
    if (number < 0) return false;

    int original = number;
    long long reversed = 0;

    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return original == reversed;
}

bool isStringPalindrome(const string& str) {
    int left = 0;
    int right = static_cast<int>(str.length()) - 1;

    while (left < right) {
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    int number;
    string text;

    cout << "Enter a number: ";
    cin >> number;

    cout << "Enter a string (without spaces): ";
    cin >> text;

    if (isNumberPalindrome(number))
        cout << number << " is a number palindrome.\\n";
    else
        cout << number << " is not a number palindrome.\\n";

    if (isStringPalindrome(text))
        cout << text << " is a string palindrome.\\n";
    else
        cout << text << " is not a string palindrome.\\n";

    return 0;
}

/*
SAMPLE OUTPUT:

Enter a number: 121
Enter a string (without spaces): madam
121 is a number palindrome.
madam is a string palindrome.
*/
