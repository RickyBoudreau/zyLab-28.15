#include <iostream>
#include <iomanip>
#include "PlaylistNode.h" 
using namespace std;

//for copying reference easily
//PlaylistNode::

    PlaylistNode::PlaylistNode()
    {
        uniqueID = "";
        songName = "";
        artistName = "";
        songLength = -1;
        nextNodePtr = nullptr;
    }

    PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength);


    string PlaylistNode::GetID() const;
    string PlaylistNode::GetSongName() const;
    string PlaylistNode::GetArtistName() const;
    int PlaylistNode::GetSongLength() const;
    PlaylistNode* PlaylistNode::GetNext() const;


    void PlaylistNode::InsertAfter(PlaylistNode* nodePtr);
    void PlaylistNode::SetNext(PlaylistNode* nodePtr);

    void PlaylistNode::PrintPlaylistNode() const;
