// Author - Dvir Sadon
#include "PhoneticFinder.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace phonetic
{
	/* Creates the letter transformations 2D array */
	vector<vector<char>> updateletters() 
	{
		vector<char> v1{'v', 'w', 'V', 'W'};
		vector<char> v2{ 'b', 'f', 'p', 'B', 'F', 'P'};
		vector<char> v3{ 'g', 'j', 'G', 'J'};
		vector<char> v4{ 'c', 'k','q', 'C', 'K', 'Q'};
		vector<char> v5{ 's', 'z', 'S', 'Z'};
		vector<char> v6{ 'd', 't', 'D', 'T'};
		vector<char> v7{ 'o', 'u', 'O', 'U'};
		vector<char> v8{ 'i', 'y', 'I', 'Y'};
		vector<vector<char>> letters{v1,v2,v3,v4,v5,v6,v7,v8};
		return letters;
	}
	
	/* Gets an array and a char and returns true if the char is in the vector */
	bool inarr(vector<char> arr, char value)
    {
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == value)
                return true;
        return false;
    }
	
	/* Returns true if the two chars are on the same array in the 2D array given */
    bool in2DArr(vector<vector<char>> letters, char value, char value2)
    {
        if (value == value2)
            return true;
        for (int i = 0; i < letters.size(); i++)
            if (inarr(letters[i], value) && inarr(letters[i], value2))
                return true;
        return false;
    }

	string lowercase(string s)
	{
		string help = "";
		for(auto c : s)
			help += char(tolower(c));
		return help;
	}
	
    /* Returns true if the words match*/
    bool rightword(vector<vector<char>> letters, string word1, string tofind)
    {
		word1 = lowercase(word1);
		tofind = lowercase(tofind);
		if (word1.size() != tofind.size())
            return false;
        for (int i = 0; i < word1.size(); i++)
            if (!in2DArr(letters, word1[i], tofind[i]))
                return false;
        return true;
    }

	/* Returns true if  the char exists in a string */
    bool contains(string st, char tofind) 
    {
        for (auto c : st) 
            if (c == tofind)
                return true;
        return false;
    }
	
	/* Throws errors */
    void errorHandeling(string str, string str2) 
    {
        if (str2 == "" || str == "")
            throw phonetic::ruleViolaition();
        for (auto c : str) 
            if(!isalpha(c) && c != ' ')
                throw phonetic::ruleViolaition();
        for (auto c : str2)
            if(!isalpha(c) && c != ' ')
                throw phonetic::ruleViolaition();
		if(contains(str2, ' '))
			throw phonetic::ruleViolaition();
    }

	/* Gets two string, returns the string specified in the assighnment */
    string find(string str, string str2)
    {
        vector<vector<char>> letters = updateletters();
		errorHandeling(str, str2);
        string word = "";
        for (auto x : str)
        {
            if (x == ' ')
            {
                if (rightword(letters, word, str2))
                    return word;
                word = "";
            }
            else
                word += x;
        }
        if (rightword(letters, word, str2))
            return word;
        throw phonetic::notFound();
        return "ERROR";
    }
}