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
    int credibility;
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
        "Franky"
    };


    Case c;
    c.crime = getRandomElement(crimes);
    c.suspect = getRandomElement(suspects);
    c.witness = getRandomElement(witnesses);
    
    
    c.guilty = rand() % 2;

    if (c.guilty)
    {
        vector<string> strongEvidence =
        {
            "fingerprints discovered at the crime scene",
            "DNA evidence linking the suspect to the victim",
            "surveillance footage showing the suspect near the crime scene",
            "eyewitness testimony identifying the suspect",
            "confession made by the suspect",
            "motive for the crime"
        };
        c.evidence = getRandomElement(strongEvidence);
        c.credibility = 75+ rand() % 26;
    }
    else
    {
        vector<string> weakEvidence =
        {
            "alibi provided by the suspect",
            "lack of physical evidence linking the suspect to the crime",
            "inconsistencies in witness statements",
            "absence of motive for the crime",
            "character references supporting the suspect's innocence"
        };
        c.evidence = getRandomElement(weakEvidence);
        c.credibility = 30 + rand() % 41; 
    }
    return c;
};

void showCase(const Case& c)
{
   cout <<"\n===================\n";
   cout << "     court case\n";
   cout <<"\n===================\n";
   
   cout << "Accusation:\n";
   cout << c.suspect << " is accused of " << c.crime << ".\n";

    cout << "Witness: " << c.witness;
    cout << "\nEvidence: " << c.evidence;


}

void crossexamineWitness(const Case& c)
{
    int choice;

    cout << "\nCross-examine the witness?:\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nYou choose to cross-examine the witness.\n";
        if (c.guilty
            && c.credibility > 70)
        {
            cout << c.witness << " the witness says he clearly saw " << c.suspect << " commit the crime.\n";
        }
        else if (c.guilty && c.credibility <= 70)
        {
            cout << c.witness << " the witness says he thinks he saw " << c.suspect << " commit the crime, but he's not sure.\n";
        }
        else
        {
            cout << c.witness << " the witness says he doesn't remember seeing anything clearly.\n";
        }
    }

   
}

int main()
{
    srand(time(0));

    int score = 0;
    const int totalCases = 5;

    cout <<"====================\n";
    cout <<"   Justice is served\n";
    cout <<"====================\n";
    cout << "Welcome to the Justice is Served!\n";

    for (int i = 0; i < totalCases; ++i)
    {
        Case c = generateRandomCase();
        showCase(c);
        crossexamineWitness(c);

        int verdict;
        cout << "\nWhat is your verdict?\n";
        cout << "1. Guilty\n";
        cout << "2. Not Guilty\n";
        cout << "Enter your choice: ";
        cin >> verdict;

        if ((verdict == 1 && c.guilty) || (verdict == 2 && !c.guilty))
        {
            cout << "Correct! justice is served!.\n";
            score++;
        }
        else
        {
            cout << "Wrong! Justice has not been served.\n";
        }
        cout << "Current Score: " << score << "/" << (i + 1) << "\n";
    }
    cout << "=====================\n";
    cout << "      Game over!\n";
    cout << "=====================\n";
    cout << "Your final score: " << score << "/" << totalCases << "\n";

    if (score == totalCases)
    {
        cout << "you are just and righteous!\n";
    }
    else if (score >= totalCases / 2)
    {
        cout << "Good job! You have a strong sense of justice!\n";
    }
    else
    {
        cout << "Better luck next time!\n";
    }
    cout << "Thank you for playing Justice is Served!\n";
    return 0;
};