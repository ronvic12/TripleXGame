#include<iostream>
#include<ctime>

using namespace std;

void GameTitle()
{
    cout<<"Welcome to TripleX Game\n\n";
}
void PrintIntroduction(int Difficulty)
{
//Print Welcome messages to terminal
    cout<<"You are a secret agent breaking into a level " << Difficulty;
    cout<<"\nsecure server room in order to save the president...\nEnter the correct codes to continue...\n\n";

}
bool PlayGame(int Difficulty)
{
    
    PrintIntroduction(Difficulty);

    // Declare 3 random number code
    const int CodeA=rand()%Difficulty+Difficulty;
    const int CodeB=rand()%Difficulty+Difficulty;
    const int CodeC=rand()%Difficulty+Difficulty;
   
   
    const int CodeSum= CodeA + CodeB + CodeC;
    const int CodeProduct= CodeA * CodeB * CodeC;


    // Print CodeSum and CodeProduct to the terminal
    cout<<"\n";
    cout<<"+ There are 3 numbers in th code"<<"\n";
    cout<<"+ The codes add-up to: "<<CodeSum<<"\n";
    cout<<"+ The codes multiply to give: "<<CodeProduct<<"\n";
    
    

   //Store Player Guess
    int GuessA,GuessB,GuessC;
    cin>> GuessA >> GuessB >> GuessC;
    cout<< "You entered: "<< GuessA << GuessB << GuessC<<"\n";


    // Sum and product of user guesses
    int GuessSum = GuessA +GuessB +GuessC;
    int GuessProduct= GuessA * GuessB *GuessC;

//In order to win, guess and code sum and product must be true.
    if(GuessSum==CodeSum && GuessProduct==CodeProduct)
    {
        cout<<"\n***Good job Agent! Move on to the next file!***\n";
        return true;
    }
  else
  {
      cout<<"\n***Careful Agent! Enter the right codes!***\n";
      return false;
  }
 cout<<"\n";

}
int main()
{
    GameTitle();
    srand(time(NULL));// create new random sequence based on time of day
    int LevelDifficulty=1;
    int const MaxDifficulty=10;
 while (LevelDifficulty<=MaxDifficulty) //Loop game until all levels are  completed
 {
     
     bool bLevelComplete=PlayGame(LevelDifficulty);
    cin.clear();// Clears any errors
    cin.ignore(); //Discards the buffer

    if (bLevelComplete)
    {
        //increase the level difficulty
        ++LevelDifficulty;
    }
    cout<<endl;
   
 }
  cout<<"\n *** Great Work Agent! You got all the files! Now get out of here!***\n"<<endl;
    
 
    return 0;
}