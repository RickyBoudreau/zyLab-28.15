//github repo link: https://github.com/RickyBoudreau/zyLab-28.15.git
//Ricky Boudreau
//davey bair

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
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;

      PlaylistNode* curr = headNode->GetNext();
      int songNum = 1;
      while(curr != nullptr)
      {
         cout << songNum << ".\n";
         curr->PrintPlaylistNode();
         cout << endl << endl; 
         
         songNum++;
         curr = curr->GetNext();
      }

      
   }else if(option == 'a') {
      PlaylistNode* curr = headNode;
      while(curr != nullptr) {
         curr = curr->GetNext();
      }

      
      string songID, songName, artistName, songLength;

      cout << "ADD SONG\nEnter song's unique ID:\n";
      cin >> songID;

      cout << "Enter song's name:\n";
      cin >> songName;

      cout << "Enter artist's name:\n";
      cin >> artistName;

      cout << "Enter song's length (in seconds):\n";
      cin >> songLength;

   
      curr->SetNext(new PlaylistNode(songID, songName, artistName, stoi(songLength)));
   }

   else if(option == 'd') {
      string songID;
      cout << "REMOVE SONG\nEnter song's unique ID:\n";
      cin >> songID;

      PlaylistNode* curr = headNode;
      while(curr->GetNext() != nullptr) {
         if(curr->GetNext()->GetID() == songID) {
            cout << "\"" << curr->GetNext()->GetSongName() << "\" removed.";

            curr->SetNext(curr->GetNext()->GetNext());

            return; 
         } else {
            curr = curr->GetNext();
         }
      }
      cout << "Error: PlaylistNode for ID " << songID << " not found\n";
   }

   else if(option == 's') {
      string name;
      cout << "OUTPUT SONGS BY A SPECIFIC ARTIST\nEnter artist's name:\n";
      cin >> name;

      PlaylistNode* curr = headNode->GetNext(); 
      int songNum = 1; 
      while(curr != nullptr) {
         if(curr->GetArtistName() == name) {
            cout << songNum << ".\n";

            curr->PrintPlaylistNode();

            cout << endl << endl; 
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
         timeSum += curr->GetSongLenght();
         
         curr = curr->GetNext();
      }

      cout << timeSum << " seconds";
   }
   
}

int main() {

   //step 2: records name of playlist from user
   string playlistName;
   cout << "Enter playlist's title:" << endl;
   cin >> playlistName;

   cout << endl;  
   
   PlaylistNode* headNode = new PlaylistNode();
   
   
   char userChoice = '0';
   while(userChoice != 'q') {
      //step 3: implement and call this function
      PrintMenu(playlistName);

      //step 5: show user the options for the menu (step 3) and record selection
   
      cout << "\n\nChoose an option: ";
      cin >> userChoice;

      ExecuteMenu(userChoice, playlistName, headNode);
   }
   
   return 0;
}

