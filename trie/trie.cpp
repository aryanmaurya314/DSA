// if n >>>> k then TC = O(1)
#include <iostream>
#include <vector>
using namespace std;

struct TrieNode
{
    char value;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char value)
    {
        this->value = value;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

// TC: O(length of word)
void insertWord(TrieNode *&root, string word)
{
    // base case
    if (word.size() == 0)
    {
        root->isTerminal = true;
        return;
    }

    // cout << "recieved word: " << word << " for insertion" << endl;

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        // present
        child = root->children[index];
    }
    else
    {
        // absent
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion
    insertWord(child, word.substr(1));
}

// TC: O(length of word)
bool findWord(TrieNode *&root, string word)
{
    // base case
    if (word.size() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child = root->children[index];

    return child ? findWord(child, word.substr(1)) : false;
}

// TC: O(length of word)
void deleteWord(TrieNode *&root, string word)
{
    // base case
    if (word.size() == 0)
    {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child = root->children[index];

    if (child)
    {
        deleteWord(child, word.substr(1));
    }
}

TrieNode *findLastNode(TrieNode *&root, string word)
{
    // base case
    if (word.size() == 0)
    {
        return root;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child = root->children[index];

    return child ? findLastNode(child, word.substr(1)) : NULL;
}

bool hasChildren(TrieNode *&root)
{
    for (auto &child : root->children)
    {
        if (child)
        {
            return true;
        }
    }
    return false;
}

void words(TrieNode *&root, string currWord, vector<string> &ans)
{
    if (!hasChildren(root))
    {
        ans.push_back(currWord);
        return;
    }

    if (root->isTerminal)
    {
        ans.push_back(currWord);
    }

    for (auto &child : root->children)
    {
        if (child)
        {
            words(child, currWord + child->value, ans);
        }
    }
}

vector<string> findSuggestions(TrieNode *&root, string key)
{
    vector<string> suggestions;
    TrieNode *interNode = findLastNode(root, key);
    if (interNode == NULL)
    {
        return suggestions;
    }
    words(interNode, key, suggestions);

    return suggestions;
}

vector<vector<string>> getAllSuggestions(TrieNode *&root, string key)
{
    vector<vector<string>> ans;
    for (int i = 1; i <= key.size(); i++)
    {
        ans.push_back(findSuggestions(root, key.substr(0, i)));
    }
    return ans;
}

void printPara(vector<string> &para)
{
    for (auto &p : para)
    {
        for (char &ch : p)
        {
            cout << ch;
        }
        cout << " ";
    }
    cout << endl;
}

int main()
{
    TrieNode *root = new TrieNode('-');

    string para[] = {"cater", "care", "com", "lover", "loved", "load", "like", "lov", "bat", "cat", "car"};
    // 1. insert a para
    for (const string &word : para)
    {
        insertWord(root, word);
    }

    // 2. find a word
    // string searchWord = "care";
    // cout << "is '" << searchWord << "' present: " << findWord(root, searchWord) << endl;

    // 3. delete a word
    // deleteWord(root, searchWord);
    // verify deletion
    // cout << "is '" << searchWord << "' present: " << findWord(root, searchWord) << endl;

    // 4. print suggestions
    string key = "loa";
    vector<string> suggestions = findSuggestions(root, key);
    printPara(suggestions);

    vector<vector<string>> allSuggestions = getAllSuggestions(root, key);
    int i = 0;
    for (auto &sugg : allSuggestions)
    {
        cout << i++ << " -> ";
        printPara(sugg);
    }

    return 0;
}