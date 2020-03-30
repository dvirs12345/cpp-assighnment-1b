// Author - Dvir Sadon

#include "doctest.h"
#include "PhoneticFinder.hpp"
#include <string>

using namespace phonetic;
using namespace std;



TEST_CASE("Test replacement of p and b and f") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
	CHECK(find(text, "haffy") == string("happy"));
	CHECK(find(text, "hafpy") == string("happy"));
	CHECK(find(text, "habfy") == string("happy"));
	
	text = "belly up";
    CHECK(find(text, "pelly") == string("belly"));
	CHECK(find(text, "ub") == string("up"));
	CHECK(find(text, "belly") == string("belly"));
	CHECK(find(text, "up") == string("up"));
	CHECK(find(text, "felly") == string("belly"));
	CHECK(find(text, "uf") == string("up"));
	
	text = "bbq is good";
	CHECK(find(text, "ppq") == string("bbq"));
	CHECK(find(text, "bpq") == string("bbq"));
	CHECK(find(text, "pbq") == string("bbq"));
	CHECK(find(text, "bbq") == string("bbq"));
	CHECK(find(text, "ffq") == string("bbq"));
	CHECK(find(text, "fbq") == string("bbq"));
	CHECK(find(text, "bfq") == string("bbq"));
	
	text = "forks are good";
	CHECK(find(text, "forks") == string("forks"));
	CHECK(find(text, "porks") == string("forks"));
	CHECK(find(text, "borks") == string("forks"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    
	text = "Hey this is fun";
	CHECK(find(text, "hEY") == string("Hey"));
	CHECK(find(text, "HEY") == string("Hey"));
	CHECK(find(text, "hEy") == string("Hey"));
	CHECK(find(text, "hey") == string("Hey"));
	
	text = "Its CORONA time";
	CHECK(find(text, "ITS") == string("Its"));
	CHECK(find(text, "CORONA") == string("CORONA"));
	CHECK(find(text, "cORONA") == string("CORONA"));
	CHECK(find(text, "CoRONA") == string("CORONA"));
	CHECK(find(text, "cORONa") == string("CORONA"));
	CHECK(find(text, "CoRoNa") == string("CORONA"));
	CHECK(find(text, "COrONA") == string("CORONA"));
}

TEST_CASE("Test replacement of v and w") {
	string text = "welcome to the vet";
    CHECK(find(text, "velcome") == string("welcome"));
    CHECK(find(text, "welcome") == string("welcome"));
    CHECK(find(text, "wet") == string("vet"));
    CHECK(find(text, "vet") == string("vet"));
	
	text = "well then";
	CHECK(find(text, "well") == string("well"));
	CHECK(find(text, "vell") == string("well"));
}

TEST_CASE("Test replacement of g and j"){
	string text = "go jump";
	CHECK(find(text, "jump") == string("jump"));
	CHECK(find(text, "gump") == string("jump"));
	CHECK(find(text, "go") == string("go"));
	CHECK(find(text, "jo") == string("go"));
	
	text = "gj man";
	CHECK(find(text, "gj") == string("gj"));
	CHECK(find(text, "jj") == string("gj"));
	CHECK(find(text, "gg") == string("gj"));
	CHECK(find(text, "jg") == string("gj"));
}

TEST_CASE("Test replacement of c and k and q"){
	string text = "kings and queens";
	CHECK(find(text, "kings") == string("kings"));
	CHECK(find(text, "qings") == string("kings"));
	CHECK(find(text, "cings") == string("kings"));
	CHECK(find(text, "queens") == string("queens"));
	CHECK(find(text, "kueens") == string("queens"));
	CHECK(find(text, "cueens") == string("queens"));
}

TEST_CASE("Test replacement of s and z"){
	string text = "i would love to snooze";
	CHECK(find(text, "snooze") == string("snooze"));
	CHECK(find(text, "znooze") == string("snooze"));
	CHECK(find(text, "snoose") == string("snooze"));
	CHECK(find(text, "znoose") == string("snooze"));
	
	text = "zeus is a god";
	CHECK(find(text, "zeus") == string("zeus"));
	CHECK(find(text, "seus") == string("zeus"));
	CHECK(find(text, "zeuz") == string("zeus"));
	CHECK(find(text, "seuz") == string("zeus"));
}

TEST_CASE("Test replacement of d and t"){
	string text = "yes doctor";
	CHECK(find(text, "doctor") == string("doctor"));
	CHECK(find(text, "toctor") == string("doctor"));
	CHECK(find(text, "docdor") == string("doctor"));
	CHECK(find(text, "tocdor") == string("doctor"));
	
	text = "i doubt that";
	CHECK(find(text, "doubt") == string("doubt"));
	CHECK(find(text, "toubt") == string("doubt"));
	CHECK(find(text, "doubd") == string("doubt"));
	CHECK(find(text, "toubd") == string("doubt"));
	CHECK(find(text, "that") == string("that"));
	CHECK(find(text, "dhat") == string("that"));
	CHECK(find(text, "thad") == string("that"));
	CHECK(find(text, "dhad") == string("that"));
}

TEST_CASE("Test replacement of o and u"){
	string text = "about that";
	CHECK(find(text, "about") == string("about"));
	CHECK(find(text, "abuut") == string("about"));
	CHECK(find(text, "aboot") == string("about"));
	CHECK(find(text, "abuot") == string("about"));
	
	text = "i doubt that";
	CHECK(find(text, "doubt") == string("doubt"));
	CHECK(find(text, "duubt") == string("doubt"));
	CHECK(find(text, "doobt") == string("doubt"));
	CHECK(find(text, "duobt") == string("doubt"));
}

TEST_CASE("Test replacement of i and y"){
	string text = "strictly platonic";
	CHECK(find(text, "strictly") == string("strictly"));
	CHECK(find(text, "stryctly") == string("strictly"));
	CHECK(find(text, "strictli") == string("strictly"));
	CHECK(find(text, "stryctli") == string("strictly"));
	
	text = "this is dirty";
	CHECK(find(text, "dirty") == string("dirty"));
	CHECK(find(text, "dyrty") == string("dirty"));
	CHECK(find(text, "dirti") == string("dirty"));
	CHECK(find(text, "dyrti") == string("dirty"));
}

TEST_CASE("Test for strings that should raise an error"){
	CHECK_THROWS_AS(find("hello there sir", ""), ruleViolaition);
	CHECK_THROWS_AS(find("hello there sir", "12"), ruleViolaition);
	CHECK_THROWS_AS(find("hello there sir", "1hello2"), ruleViolaition);
	CHECK_THROWS_AS(find("hello there sir", "hello there"), ruleViolaition);
	CHECK_THROWS_AS(find("hello there sir", "there sir"), ruleViolaition);
	CHECK_THROWS_AS(find("hello there sir,@@", "hello"), ruleViolaition);
	CHECK_THROWS_AS(find("hello there sir", "!!"), ruleViolaition);
	CHECK_THROWS_AS(find("hello there sir", "hello!!"), ruleViolaition);
	CHECK_THROWS_AS(find("hello there sir", "vdj"), notFound);
	CHECK_THROWS_AS(find("hello there sir", "llk"), notFound);
	CHECK_THROWS_AS(find("hello there sir", "pacsn"), notFound);
	CHECK_THROWS_AS(find("hello there sir123", "hello"), ruleViolaition);
}
