//github link
//Ricky Boudreau
//team member 2

#include <iostream>
#include "PlaylistNode.h"

//skip step number 9


using namespace std;

void PrintMenu(const string playlistTitle) {
   /* Type your code here */

   //step 3: prints options for user to interact with the program
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song\nd - Remove song\nc - Change positionof song\ns - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no - Output full playlis\nq - Quit";
   
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   /* Type your code here */
   //step 4: make this function do the thing the user selected

   
}

int main() {
   /* Type your code here */

   //step 2: records name of playlist from user
   string playlistName;
   cout << "Enter playlist's title:" << endl;
   cin >> playlistName;

   //step 3: implement and call this function
   PrintMenu(playlistName);

   
   
   
   return 0;
}

