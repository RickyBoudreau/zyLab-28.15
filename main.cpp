//github repo link: https://github.com/RickyBoudreau/zyLab-28.15.git
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
   
   if(option == 'o') //output full playlist
   {
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;

      PlaylistNode* curr = headNode->GetNext();
      int songNum = 1;
      while(curr != nullptr)
      {
         cout << songNum << ".\n";
         curr->PrintPlaylistNode();
         cout << endl << endl; //might need more endl's for whitespace
         
         songNum++;
         curr = curr->GetNext();
      }

      
   }else if(option == 'a') //adds song to the end of the playlist
   {
      PlaylistNode* curr = headNode;
      while(curr != nullptr) //gets the last node in the list
      {
         curr = curr->GetNext();
      }

      //gets user input for info
      string songID, songName, artistName, songLength;

      cout << "ADD SONG\nEnter song's unique ID:\n";
      cin >> songID;

      cout << "Enter song's name:\n";
      cin >> songName;

      cout << "Enter artist's name:\n"
      cin >> artistName;

      cout << "Enter song's length (in seconds):\n";
      cin >> songLength;

      //add new PlaylistNode to the end of the list
      curr->SetNext(new PlaylistNode(songID, songName, artistName, songLength));
   }

   else if(option == 'd') //remove a song (given ID)
   {
      string songID;
      cout << "REMOVE SONG\nEnter song's unique ID:\n";
      cin >> songID;

      //find and remove the song
      PlaylistNode* curr = headNode;
      while(curr->GetNext() != nullptr)
      {
         if(curr->GetNext()->GetID() == songID) //IDs match - remove song
         {
            cout << "\"" << curr->GetNext()->GetSongName() << "\" removed.";

            curr->SetNext(curr->GetNext->GetNext);

            return; //might need to be break instead
         }else //IDs don't match - move to next song
         {
            curr = curr->GetNext();
         }
      }

      cout << "Error: PlaylistNode for ID " << songID << " not found\n";
      
   }

   else if(option == 's')
   {
      string name;
      cout << "OUTPUT SONGS BY A SPECIFIC ARTIST\nEnter artist's name:\n";
      cin >> name;

      //find and print songs
      PlaylistNode* curr = headNode->GetNext(); 
      int songNum = 1; //keeps track of what place the current song is at in the list
      while(curr != nullptr)
      {
         if(curr->GetArtistName() == name)
         {
            cout << songNum << ".\n";

            curr->PrintPlaylistNode();

            cout << endl << endl; //might need more endl depending on whitespace
         }

         //get next song
         songNum++;
         curr = curr->GetNext();
      }
   }

   else if(option == 't') //find and print total time of playlist
   {
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\nTotal time: ";

      PlaylistNode* curr = headNode->GetNext(); 
      int timeSum = 0; //tracks total play time of playlist
      while(curr != nullptr) //total up play time
      {
         timeSum += curr->GetSongLenght();
         
         //get next song
         curr = curr->GetNext();
      }

      //print total playlist time
      cout << timeSum << " seconds";
   }
   

   //----END OF IF/ELSE BRANCHES----
   
}

int main() {
   /* Type your code here */

   //step 2: records name of playlist from user
   string playlistName;
   cout << "Enter playlist's title:" << endl;
   cin >> playlistName;

   cout << endl;  //might need to adjust how many endl appear here for correct whitespace

   //create the head node for the linked list
   //it is a dummy node and should be skipped over in function actions (do still pass it in to the call, but ignore it in the actual implementation)
   PlaylistNode headNode = new PlaylistNode();
   
   /*
         ----LIKELY TO BE A WHILE LOOP AROUND THE REST OF THE CODE BELOW----
   */
   
   char userChoice = '0';
   while(userChoice != 'q') //loop over menu options and actions until user quits
   {
      //step 3: implement and call this function
      PrintMenu(playlistName);

      //step 5: show user the options for the menu (step 3) and record selection
   
      cout << "\n\nChoose an option: ";
      cin >> userChoice;

      ExecuteMenu(userChoice, playlistName, headNode);
   }
   
   return 0;
}

