// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT5L
// Names: ALYSHA NAILI BINTI KAMARULZAMAN | NUR ARISYA BINTI MOHD YASAK | MEMBER_NAME_3 
// IDs: 1221303351 | 1221303288 | MEMBER_ID_3 
// Emails: 1221303351@student.mmu.edu.my | 1221303288@student.mmu.edu.my | MEMBER_EMAIL_3 
// Phones: MEMBER_PHONE_1 | MEMBER_PHONE_2 | MEMBER_PHONE_3 
// ********************************************************* 

// TODO: Fill in the missing information above and delete this line.

//#include "pf/helper.h"
//#include <iostream>
//using namespace std;

//int main()
//{
    //cout << "Assignment (Part 1)" << endl;
    //cout << "Let's Get Started!" << endl;
    //pf::Pause();
//}

//        open in terminal
//        g++ pf\*.cpp main.cpp -o main 
//        ./main.exe

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
    Board(int Column, int Row);
    void init(int Column, int Row);
    void display() const;
    int getColumn() const;
    int getRow() const;
    char getObject(int x, int y) const;
    void setObject(int x, int y, char ch);
};

void Board::setObject(int x, int y, char ch)
{
    map_[-(y - 5)][x - 1] = ch;
}

int Board::getColumn() const
{
    return Column_;
}
int Board::getRow() const
{
    return Row_;
}
Board::Board(int Column, int Row)
{
    init(Column, Row);
}
void Board::init(int Column, int Row)
{
    Column_ = Column;
    Row_ = Row;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', '^', 'v', '<', '>' , 'h' , 'p' , 'r','.'};
    int noOfObjects = 14; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(Row_); // create empty rows
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
}

int main()
{
    cout << "Default Game Settings" << endl;
    cout << "-----------------------" << endl;
    cout << "Board Rows : 5" << endl;
    cout << "Board Columns : 9" << endl;
    cout << "Zombie Count : 1" << endl;

    string choice;

    cout << "Do you wish to change the game settings (y/n)? ==>" << endl;
    cin >> choice;
    if (choice == "y")
    {
        int Row;
        int Column;
        int Zombies;
        //vector<vector<string>> map_; // convention to put trailing underscore

        cout << "Board Settings" << endl;
        cout << "---------------" << endl;
        cout << "Enter rows" << endl;
        cin >> Row;
        cout << "Enter columns" << endl;
        cin >> Column;
        cout << "Zombie Settings" << endl;
        cout << "-----------------" << endl;
        cout << "Enter number of zombies" << endl;
        cin >> Zombies;
        cout << "Settings updated" << endl;
        int table[Row][Column];

        cout << ".: Alien vs Zombie :." << endl;
        for (int i = 0; i < Column; i++)
        {
            for (int j = 0; j < Row; j++)
            {
                std::cout << "|_|";
            }

            std::cout << std::endl;
        }

    }
    
}