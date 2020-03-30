// Author - Dvir Sadon
#pragma once
#include <string>
using namespace std;
namespace phonetic
{
	class ruleViolaition: public exception
	{
	  virtual const char* what() const throw()
	  {
		return "One of the rules for crafting the string was violated";
	  }
	};
	
	class notFound: public exception
	{
	  virtual const char* what() const throw()
	  {
		return "Could not find the word specified";
	  }
	};
	string find(string a, string b);
}
