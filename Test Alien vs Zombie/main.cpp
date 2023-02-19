// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT5L
// Names: ALYSHA NAILI BINTI KAMARULZAMAN | NUR ARISYA BINTI MOHD YASAK | AZMI BIN MOHD SAHI 
// IDs: 1221303351 | 1221303288 | 1221303866 
// Emails: 1221303351@student.mmu.edu.my | 1221303288@student.mmu.edu.my | 1221303866@student.mmu.edu.my 
// Phones: ALYSHA_0128050501 | ARISYA_0142175890 | AZMI_0174588593 
// ********************************************************* 

//#include "pf/helper.h"
//#include <iostream>
//using namespace std;

//int main()
//{
    //cout << "Assignment (Part 1)" << endl;
    //cout << "Let's Get Started!" << endl;
    //pf::Pause();
//}

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

class Board
{
private:
    
    vector<vector<char>> map_; // convention to put trailing underscore
    int Column_, Row_;          // to indicate private data

public:

    int column, row, zombie;
    int col_ , row_ , zom_;

    Board(int column = 9, int row = 5);
    void init(int column, int row);
    void display() const;
    
    void oddNums(int num_);
    void settings(int col_, int row_, int zom_);
    void displayGameBoard(int column, int row, int zombie);
    void custGameBoard() const;
    void quitGame() const;

    void setObject(int x, int y, char ch);
    char getObject(int x, int y, int z) const;
    int getColumn() const;
    int getRow() const;
};

void Board::setObject(int x, int y, char ch)
{
   map_[-(y-5)][x-1] = ch;
}

int Board::getColumn() const
{
    return Column_;
}
int Board::getRow() const
{
    return Row_;
}


Board::Board(int column, int row)
{
    init(column, row);
}

void Board::init(int column, int row)
{

    Column_ = column;
    Row_ = row;
    
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', '^', 'v', '<', '>' , 'h' , 'p' , 'r','.'};
    int noOfObjects = 14; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(Column_); // create empty rows

    for (int i = 0; i < Row_; ++i)
    {
        map_[i].resize(Column_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < Row_; ++i)
    {
        for (int j = 0; j < Column_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }

    /*int RowAlien;
    int ColumnAlien;
    char A;
    A = RowAlien, ColumnAlien;

    RowAlien = row/2;
    cin >> A;

    ColumnAlien = column/2;
    cin >> A;/*/
}

//default gameboard
void Board::display() const
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << ".: Alien vs Zombie :." << endl;

    // for each row
    for (int i = 0; i < Row_; ++i) 
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < Column_; ++j) 
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(2) << (Row_ - i);  

        // display cell content and border of each column
        for (int j = 0; j < Column_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;

    }

        // display lower border of the last row
        cout << " ";
        for (int j = 0; j < Column_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display column number
        cout << " ";
        for (int j = 0; j < Column_; ++j)
        {
            int digit = (j + 1) / 10;
            cout << " ";
            if (digit == 0)
               cout << " ";
            else
               cout << digit;
        }
        cout << endl;
        cout << " ";
        
        for (int j = 0; j < Column_; ++j)
        {
             cout << " " << (j + 1) % 10;
        }
        
   cout << endl << endl;
 }


void test1_1()
{
    Board board;
    board.display();
}

//customize gameboard
void Board::custGameBoard() const      
{     
        int Row;
        int Column;
        int Zombies;
        vector<vector<string>> map_; // convention to put trailing underscore

        cout << "Board Settings" << endl;
        cout << "---------------" << endl;
        cout << "Enter number of rows" << endl;
        cin >> Row;
        cout << "Enter number of columns" << endl;
        cin >> Column;
        cout << "Zombie Settings" << endl;
        cout << "-----------------" << endl;
        cout << "Enter number of zombies" << endl;
        cin >> Zombies;
        cout << "Settings updated" << endl;
        int table[Row][Column];
        
        cout << endl;
        map_.resize(Row,vector<string>(Column," "));
        cout << ".: Alien vs Zombie :." << endl;

        for (int i = 0; i < Row; ++i)
        {
            cout << " ";
            for (int j = 0; j < Column; ++j)
            {
               cout << "+-";
            }
             cout << "+" << endl;   
             cout << setw(2)<< (Row - i);

             // display cell content and border of each column
            for (int j = 0; j < Column; ++j)
             {
                cout << "|" << map_[i][j];
             }
             cout << "|" << endl;
        }
            // display lower border of the last row
             cout << " ";
             for (int j = 0; j < Column; ++j)
            {
                 cout << "+-";
            }
             cout << "+" << endl;

             // display column number 
             cout << " ";
             for (int j = 0; j < Column; ++j)
            {
                int digit = (j + 1) / 10;
                cout << " ";
                if ( digit == 0)
                    cout <<  " ";
                else
                    cout << digit;
             }
            cout << endl;
            cout << " ";
            for ( int j = 0; j < Column; ++j)
            {
                cout << " " << ( j + 1 ) % 10;
            }
            cout << endl
                 << endl;
            
            Board board;
            board.init(column, row);
}

void test1_2()
{
    Board board;
    board.custGameBoard();
}

void Board::quitGame() const
{
   char userDecide;

   cout << "Quit the game? (y/n) " << endl;
   cin >> userDecide;
   if (userDecide == 'y' || userDecide == 'Y')
   {
      // Save game data
   }
   else if (userDecide == 'n' || userDecide == 'N')
   {
      // gameEnd = false;
   }
}

void test1_3()
{
    Board board;
    board.quitGame();
}



void Board::oddNums(int num_) // to only get odd numbers
{
    do
    { 
       cin >> num_;
       if (num_ %  2 != 0)
       {
           break;
       }
        else
       {
           cout << "Enter ODD NUMBERS only =>  ";
       }
    }while (num_ % 2 == 0);
    return;
}

//change gameboard settings
void Board::settings(int col_, int row_, int zom_)
{
        
        cout << "  Board Settings  " << endl;
        cout << "-------------------" << endl;
        cout << "Please enter odd numbers only..." << endl;

        cout << "Enter number of rows : " << endl;
        oddNums(row);
        cout << "Enter number of columns : " << endl;
        oddNums(column);
        cout << endl;

        cout << "  Zombie Settings  " << endl;
        cout << "-------------------" << endl;
        cout << "Enter number of zombies : " << endl;
        cin >> zom_;
        cout << endl;

        cout << "Settings Updated" << endl;

        
}

//gameboard settings
void Board::displayGameBoard(int column, int row, int zombie)
{   
    
    char username[15];

    cout << "\t Welcome to Alien vs Zombie" << endl;
    cout << "\t Enter your username >>" << endl;
    cin >> username;

    cout << "\t Hello,signed in as "  << username << endl;
    cout << endl;
    cout << "\t Let's get started!"<< endl;

    string choice;
    cout << endl;
    
    cout << "Default Game Settings" << endl;
    cout << "-----------------------" << endl;
    cout << "Board Rows : 5" << endl;
    cout << "Board Columns : 9" << endl;
    cout << "Zombie Count : 1" << endl;

    cout << "Do you wish to change the game settings (y/n)? ==>  ";

    cin >> choice;
    cout << endl;

    if (choice == "y")
    {
        test1_2();      //Board board;
                        //board.init(column,row);
        test1_3();
    }
        
    else if (choice == "n")
    {
        cout << " Default Settings Maintained. " << endl;  
        test1_1();  
        test1_3();
    }

    else
    {
        cout << "Error! Please choose either y (yes) or n (no)." << endl;
        cout << endl;
        displayGameBoard(column, row, zombie); 
        cout << endl;
        test1_3();
    }
    cout << endl;
}


int main()
{
   int row;
   int column;
   int zombie;

   Board board; 
   board.displayGameBoard(row, column, zombie);

   //srand(1); // use this for fixed map during testing 
   // srand(time(NULL)); // try this for random map
   
   test1_3();

}

