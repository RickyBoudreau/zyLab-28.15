#include <iostream>
#include <iomanip>
#include "PlaylistNode.h" 
using namespace std;

//for copying reference easily
//PlaylistNode::

    PlaylistNode::PlaylistNode()
    {
        uniqueID = "none";
        songName = "none";
        artistName = "none";
        songLength = 0;
        nextNodePtr = nullptr;
    }

    PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) {
        this->uniqueID = uniqueID;
        this->songName = songName;
        this->artistName = artistName;
        this->songLength = songLength;
        nextNodePtr = nullptr;
    }


    string PlaylistNode::GetID() const{return uniqueID;}
    string PlaylistNode::GetSongName() const{return songName;}
    string PlaylistNode::GetArtistName() const{return artistName;}
    int PlaylistNode::GetSongLength() const{return songLength;}
    PlaylistNode* PlaylistNode::GetNext() const{return nextNodePtr;}


    void PlaylistNode::InsertAfter(PlaylistNode* nodePtr){
        PlaylistNode* tmpNext = nextNodePtr;
        nextNodePtr = nodePtr;
        nodePtr->nextNodePtr = tmpNext;
    }
    void PlaylistNode::SetNext(PlaylistNode* nodePtr) {nextNodePtr = nodePtr;}

    void PlaylistNode::PrintPlaylistNode() const{
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Song Name: " << songName << endl;
        cout << "Artist Name: " << artistName << endl;
        cout << "Song Length (in seconds): " << songLength << endl;
    }
