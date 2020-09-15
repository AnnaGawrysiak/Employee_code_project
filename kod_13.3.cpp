/*
Napisz program, który pobierze od uzytkownika imie pracownika i pokój do którego chce sie udac i zwrotnie,
na podstawie kodu pracownika, przydzieli mu dostep do danego pomieszczenia, badz mu tego dostepu odmowi.
*/

#include <utility>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool FindCharacter(int code, int searched_digit)
{
     vector < int > arr;

    do
    {
        int digit = code % 10;
        arr.push_back( digit );
        code = code / 10;
    } while (code > 0);


   vector<int>::iterator it;
   for( it = arr.begin(); it!= arr.end(); ++it )
   {
      if (*it == 9 || *it == searched_digit)
        return true;
   }

   return false;

}

bool room_of_silence(int & occupation)
{
    if (occupation == 0)
    {
        occupation = 1;
        return false;
    }

    if (occupation == 1)
    {
        occupation = 0;
        return true;
    }
}

int room_occupied = 0;

int main()
{
 map <string, int> AccessMap;

    AccessMap["Sabrina"] = 9999;
    AccessMap["Bonifacy"] = 6400;
    AccessMap["Armenia"] = 7430;
    AccessMap["Suszek"] = 3000;
    AccessMap["Wawrzyniec"] = 8764;

string name = "Aleks";

cout << "Please type in your name:";
cin >> name;

int access = 0;

// znajdz mi imie. mapa szuka imienia przez iterator. kiedy go znajdzie zwraca ten wskaznik na konkretny element, ktory znalazl
// poniewaz mamy wskaznik na element, ktory zostal znaleziony mozemu go usunac, wyswietlic, wziac wartosc.

auto temp = AccessMap.find(name); // zwraca iterator . jesli znajdzie da nam iterator, jesli nie, da nam AccessMap.end

if (temp != AccessMap.end())
    access = (*temp).second;

int room = 0;

map<int, string> layout_of_rooms;

layout_of_rooms.insert(make_pair(8, "Main Office"));
layout_of_rooms.insert(make_pair(7, "Maintenance Room"));
layout_of_rooms.insert(make_pair(6, "Control Room"));
layout_of_rooms.insert(make_pair(5, "Pantry"));
layout_of_rooms.insert(make_pair(4, "Room of Silence"));
layout_of_rooms.insert(make_pair(3, "Accountancy"));
layout_of_rooms.insert(make_pair(2, "Canteen"));

 map<int, string>::iterator it;

cout << "Choose from the list and type in code of the room, to which you would like to gain access: " << endl;

    for (it = layout_of_rooms.begin(); it!=layout_of_rooms.end(); ++it)
        cout << it->first << "->" << it->second << endl;

cin >> room;

if (room == 4 && FindCharacter(access, room)== true && room_of_silence(room_occupied) == false)
    {
        cout << "Access granted. " << endl;
    }

else if (room == 2 || room != 4 && FindCharacter(access, room)== true)
    {
        cout << "Access denied. " << endl;
    }

else
        cout << "Access denied. " << endl;

        cout << endl;

cout << " Database. Press the appropraite key: \n1.- Adding new employee to the list.\n2.- Erasing data of the employee\n3.- Modification of access code\n4.-exit" << endl;

    int answer = 0;

    do
    {
        cin >> answer;

        switch(  answer )
        {
        case 1:


            {
            string employee_surname = "Daniel";
            int the_code;
            cout << "Type in surname of the employee, whose profile your would like to add to the database: ";
            cin >> employee_surname;
            cout << "Please type in employee's access code " << employee_surname << " : ";
            cin >> the_code;
            AccessMap.insert ( pair<string,int>(employee_surname, the_code) );

            break;

            }


        case 2:

            {
            string employee_surname2 = "Damian";
            cout << "Type in surname of the employee, whose profile your would like to erase from the database:  ";
            cin >> employee_surname2;
            AccessMap.erase(employee_surname2);

            break;
            }

        case 3:

            {
            string employee_surname3 = "Wozniak";
            cout << "Type in surname of the employee, whose access code your would like to modify: ";
            cin >> employee_surname3;

            int changed_code = 0;
            cout << "Type in code of a new employee: " << employee_surname3 << " : ";
            cin >> changed_code;

            AccessMap[employee_surname3] = changed_code;
            //cout << " after modification: " << AccessMap["Sabrina"] << endl;

            }

        }

    cout <<  "Database. Press the appropraite key: \n1.- Adding new employee to the list.\n2.- Erasing data of the employee\n3.- Modification of access code\n4.-exit" << endl;

    } while(  answer != 4 );


    return 0;
}
