#include <iostream>
using namespace std;

/**
 * string: a data type where char array is a data structure
 * string also contains null character at the end
 */

int main()
{
    string str;
    // cin >> str;
    // getline(cin, str);
    str = "hello";

    // 1. Length of string
    cout << "Length: " << str.length() << endl;

    // 2. Is empty
    cout << "Is empty: " << str.empty() << endl;

    // 3. Add in the end
    str.push_back('w');
    cout << "str after push_back: " << str << endl;

    // 4. Remove from the end
    str.pop_back();
    cout << "str after pop_back: " << str << endl;

    // 5. Find substring
    // substr(index, length)
    // !length refers to rest all
    cout << "substring: " << str.substr(0, 4) << endl;

    // 6. compare two strings
    /**
     * 0: if both strings are equal
     * <0, >0: if both strings are not equal
     * <0: if corresponding first character is smaller
     * >0: if corresponding first character is larger
     */
    string a = "Aryan";
    string b = "Aryan";
    cout << "Is a == b: " << a.compare(b) << endl;

    // 7. find substring : return starting index of text wherever found else npos
    string line = "Hello mai yaha hoon";
    string text = "z";
    if (line.find(text) != string::npos)
    {
        cout << "Is text found: " << line.find(text) << endl;
    }
    else
    {
        cout << "Not found!"
             << " npos: " << line.find(text) << endl;
    }

    // 8. replace:
    string sent = "Hello Ram, how are you doing ?";
    string nam = "Mohan";
    cout << "Before replace: " << sent << endl;
    // sent.replace(6, 3, nam);       // (replaceStartIndex, numberOfReplace, withWhatToReplace)
    // sent.replace(6, 3, nam, 2, 3); // (replaceStartIndex, numberOfReplace, withWhatToReplace, replaceStringIndex, noOfReplaceString)
    sent.replace(6, 3, 2, '!'); // (replaceStartIndex, numberOfReplace, noOfCharsToReplace, char)
    cout << "After replace: " << sent << endl;

    // 9. erase:
    string intro = "My name are is Aryan.";
    cout << "Before erase: " << intro << endl;
    intro.erase(8, 4); // (startIndex, numberOfChars)
    cout << "After erase: " << intro << endl;
    string p = "23:00";
    cout << stoi(p.substr(0, 2)) * 60 << " -- " << stoi(p.substr(3, 2)) << endl;

    return 0;
}