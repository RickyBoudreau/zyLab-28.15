//github repo link: https://github.com/RickyBoudreau/zyLab-28.15.git
//Ricky Boudreau
//davey/david bair

#include <iostream>
#include "PlaylistNode.h"
using namespace std;
//skip step number 9




void PrintMenu(const string playlistTitle) {
   
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song\nd - Remove song\nc - Change position of song\ns - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no - Output full playlist\nq - Quit" << endl;
   
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {

   //step 4: make this function do the thing the user selected
   
   if(option == 'o') {

      if(headNode == nullptr)
      {
         cout << "\nPlaylist is empty" << endl << endl;

         return headNode;
      }
      

      cout << playlistTitle << " - OUTPUT FULL PLAYLIST";

      PlaylistNode* curr = headNode->GetNext();
      
      if(curr == nullptr)
      {
         cout << "\nPlaylist is empty" << endl << endl;
         
         return headNode;
      }
      
      cout << endl;
      
      int songNum = 1;
      while(curr != nullptr)
      {
         cout << songNum << ".\n";
         curr->PrintPlaylistNode();
         cout << endl; 
         
         songNum++;
         curr = curr->GetNext();
      }

      
   }else if (option == 'a') {

      string dummyRead = ""; //used to read the newline characters which are messing w things (int reads dont eat them up like string reads)
      
    PlaylistNode* curr = headNode;
    while (curr->GetNext() != nullptr) {
        curr = curr->GetNext();
    }

    string songID, songName, artistName, songLength;

    cout << "ADD SONG\nEnter song's unique ID:\n";
    cin >> songID;
    getline(cin, dummyRead);

    cout << "Enter song's name:\n";
    getline(cin, songName);

    cout << "Enter artist's name:\n";
    getline(cin, artistName);

    cout << "Enter song's length (in seconds):\n";
    cin >> songLength;
    getline(cin, dummyRead);

    curr->SetNext(new PlaylistNode(songID, songName, artistName, stoi(songLength))); //stoi????

    cout << endl;
}


   else if(option == 'd') {
      string songID;
      cout << "REMOVE SONG\nEnter song's unique ID:\n";
      cin >> songID;

      PlaylistNode* curr = headNode;
      while(curr->GetNext() != nullptr) {
         if(curr->GetNext()->GetID() == songID) {
            cout << "\"" << curr->GetNext()->GetSongName() << "\" removed.\n\n";

            curr->SetNext(curr->GetNext()->GetNext());

         } else {
            curr = curr->GetNext();
         }
      }
      //cout << "Error: PlaylistNode for ID " << songID << " not found\n"; //over-engineered (dont actually need for this program)
   }

   else if(option == 's') {
      string dummyRead; //used for getting rid of newline char
      string name;
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST\nEnter artist's name:\n\n";
      getline(cin, dummyRead);
      getline(cin, name);

      PlaylistNode* curr = headNode->GetNext(); 
      int songNum = 1; 
      while(curr != nullptr) {
         if(curr->GetArtistName() == name) {
            cout << songNum << ".\n";

            curr->PrintPlaylistNode();

            cout << endl; 
         }
         
         songNum++;
         curr = curr->GetNext();
      }
   }

   else if(option == 't') {
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\nTotal time: ";

      PlaylistNode* curr = headNode->GetNext(); 
      int timeSum = 0; 
      while(curr != nullptr) {
         timeSum += curr->GetSongLength();
         
         curr = curr->GetNext();
      }

      cout << timeSum << " seconds\n\n";
   }
   return headNode;
}

int main() {

   //step 2: records name of playlist from user
   string playlistName;
   cout << "Enter playlist's title:" << endl;
   getline(cin, playlistName);

   cout << endl;  
   
   PlaylistNode* headNode = new PlaylistNode();
   
   
   char userChoice = '0';
   while(userChoice != 'q') {
      //step 3: implement and call this function
      PrintMenu(playlistName);

      //step 5: show user the options for the menu (step 3) and record selection
   
      cout << "\nChoose an option:\n";
      cin >> userChoice;

      


      ExecuteMenu(userChoice, playlistName, headNode);
   }

   PlaylistNode* curr = headNode;
    while (curr != nullptr) {
        PlaylistNode* temp = curr;
        curr = curr->GetNext();
        delete temp;
    }
   
   return 0;
}
