# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>
# include <ctime>

using namespace std;

struct Case
{
    string crime;
    string suspect;
    string witness;
    string evidence;
    bool guilty;
};

string getRandomElement(const vector<string>& elements)
{
    int index = rand() % elements.size();
    return elements[index];
}

Case generateRandomCase()
{
    vector<string> crimes = 
    {
        "murder",
        "theft", 
        "fraud",
        "arson",
        "kidnapping",
        "assault",
        "vandalism",
        "man slaughter",
        "embezzlement",
        "cybercrime"
    
    };
    

vector<string> suspects = 
{
    "sherlock moriaty",
    "gehrman sparrow",
    "dwanye dantes",
    "rover hayworth",
    "will auceptin",
    "sara seiger",
    "nishikawa ishida",
    "john smith",
    "kim dokja",
    "Noh- doh hwa"
};

vector<string> witnesses = 
{
     "Fors Wall",
    "Leonard Mitchell",
    "Azik Eggers",
    "Amon",
    "Adam",
    "Will Auceptin",
    "Medici",
     "Monkey D. Luffy",
    "Roronoa Zoro",
    "Nami",
    "Usopp",
    "Sanji",
    "Tony Tony Chopper",
    "Nico Robin",
    "Franky",
};  

vector<string> evidences = 
{
    "fingerprints",
    "DNA",
    "surveillance footage",
    "eyewitness testimony",
    "weapon",
    "alibi",
    "motive",
    "confession",
    "forensic analysis",
    "digital evidence"
};

