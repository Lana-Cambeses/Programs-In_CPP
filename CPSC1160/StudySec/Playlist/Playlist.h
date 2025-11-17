#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

// Helper functions for cstring operations
int CalculateLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;

    /*
    Calculate the time complexity of this function in terms of n
    where n is the length of the string str.
    Pick a reasonable operator to count for the time complexity, for example, the number of comparisons.
    Write the time complexity in Big O notation. 
    */
}

void CopyCharArray(const char* source, char* destination, int length) {
    for (int i = 0; i < length; ++i) {
        destination[i] = source[i];
    }
    destination[length] = '\0'; // Null-terminate the string, ensuring it is a valid C-style string (easy to print!)

    /*
    Calculate the time complexity of this function in terms of n
    where n is the length of the string source.
    Pick a reasonable operator to count for the time complexity, for example, the number of assignments.
    Write the time complexity in Big O notation.
    */
}

bool IsEqual(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false; // Strings are not equal
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0'); // Both strings must end at the same time to be equal

    /*
    Calculate the time complexity of this function in terms of n
    where n is the length of the shorter string between str1 and str2.
    Pick a reasonable operator to count for the time complexity, for example, the number of comparisons.
    Write the time complexity in Big O notation.
    */
}

class Song {
    friend class Playlist; // Allow Playlist to access private members of Song
    friend ostream& operator<<(ostream& os, const Song& s); // Allow ostream to access private members of Song
private:
    char* title; // Title of the song
    char* artist; // Artist of the song
    static const int MAX_LENGTH = 100; // Maximum length for title and artist

public:
    Song(){
        title = new char[1];
        artist = new char[1];
        title[0] = '\0'; // Initialize to empty string
        artist[0] = '\0'; // Initialize to empty string

        /*        
        Calculate the time complexity of this constructor and write it in Big O notation.
        */
    }
    Song(const char* t, const char* a) {
        int titleLength = CalculateLength(t);
        int artistLength = CalculateLength(a);
        if (titleLength >= MAX_LENGTH || artistLength >= MAX_LENGTH) {
            cout << "Error: Title or artist exceeds maximum length. Returning default song." << endl;
            title = new char[1];
            artist = new char[1];
            title[0] = '\0'; // Initialize to empty string
            artist[0] = '\0'; // Initialize to empty string
            return;
        }
        title = new char[titleLength + 1];
        artist = new char[artistLength + 1];
        CopyCharArray(t, title, titleLength);
        CopyCharArray(a, artist, artistLength);

        title[titleLength] = '\0'; // Null-terminate the title
        artist[artistLength] = '\0'; // Null-terminate the artist

        /*
        Calculate the time complexity of this constructor and write it in Big O notation.
        */
    }
    Song(const Song& other) {
        int titleLength = CalculateLength(other.title);
        int artistLength = CalculateLength(other.artist);
        title = new char[titleLength + 1];
        artist = new char[artistLength + 1];
        CopyCharArray(other.title, title, titleLength);
        CopyCharArray(other.artist, artist, artistLength);
        title[titleLength] = '\0'; // Null-terminate the title
        artist[artistLength] = '\0'; // Null-terminate the artist

        /*        
        Calculate the time complexity of this copy constructor and write it in Big O notation.
        */
    }
    ~Song() {
        delete[] title;
        delete[] artist;

        /*        
        Calculate the time complexity of this destructor and write it in Big O notation.
        */
    }

    // Overload the assignment operator
    // check for self-assignment
    // free the existing memory of title and artist in *this
    // *this will be a deep copy of other
    // return *this so that we can chain assignments
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this operator and write it in Big O notation.
    Song& operator=(const Song& other) {
        
    }
    // Overload the == operator to compare two songs
    // Two songs are considered equal if both their title and artist are equal
    // Return true if they are equal, false otherwise
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this operator and write it in Big O notation.
    bool operator==(const Song& other) const {
        
    }
};

ostream& operator<<(ostream& os, const Song& s) {
    os << "Title: " << s.title << ", Artist: " << s.artist;
    return os;
}

class Playlist {
    friend ostream& operator<<(ostream& os, const Playlist& p); // Allow ostream to access private members of Playlist
private:
    Song* songs; // Array of songs
    int size; // Number of songs in the playlist

public:
    Playlist() {
        size = 0;
        songs = nullptr;
    }

    // Write a deep copy constructor
    // It should allocate a new array of songs and copy the songs from the other playlist
    // If the other playlist is empty, the new playlist should also be empty
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this constructor and write it in Big O notation.
    Playlist(const Playlist& other) {
        
    }

    ~Playlist() {
        if(songs != nullptr) {
            delete[] songs; // Free the dynamically allocated array of songs
        }
        size = 0; // Reset size to 0
        songs = nullptr; // Reset pointer to null
    }

    // function to get the size of the playlist
    int getSize() const {
        return size; // Return the number of songs in the playlist
    }

    // overload the assignment operator
    // check for self-assignment
    // free the existing memory of songs in *this
    // *this will be a deep copy of other
    // return *this so that we can chain assignments
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE: 
    // use recursive helper functions instead of loops to implement the deep copy
    // analyze the time complexity of the recursive helper functions using recurrence relations
    // and write the time complexity in Big O notation.
    Playlist& operator=(const Playlist& other) {
          
    }

    // overload the += operator to add a song to the end of the playlist
    // Note: This operator should modify the original playlist
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the addition
    // analyze the time complexity of the recursive helper functions using recurrence relations
    // and write the time complexity in Big O notation.
    Playlist& operator+=(const Song& song) {
        
    }

    // overload the += operator to add all songs from an array of songs
    // assume the array of songs ends with a song with an empty title and artist (i.e. Song("", ""))
    // Note: This operator should modify the original playlist
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the addition
    // analyze the time complexity of the recursive helper functions using recurrence relations
    // and write the time complexity in Big O notation.
    Playlist& operator+=(const Song* songArray) {
        
    }

    // overload the + operator to concatenate two playlists
    // Return a new playlist that contains all songs from both playlists (songs from *this followed by songs from other)
    // Note: This operator should not modify the original playlists
    // Complexity Analysis: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the concatenation
    // analyze the time complexity of the recursive helper functions using recurrence relations
    // and write the time complexity in Big O notation.
    
    Playlist operator+(const Playlist& other) const {
        
    }

    // overload the += operator to concatenate another playlist
    // Note: This operator should modify the original playlist
    Playlist& operator+=(const Playlist& other) {
        
    }

    // overload the [] operator to access a song by index
    // If the index is out of bounds, output an error message and return the first song
    const Song& operator[](int index) const {
        
    }

    // overload the -= operator to remove the last occurrence of a song from the playlist
    // If the song is not found, do nothing
    // Note: This operator should modify the original playlist
    // Complexity Analysis: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the removal
    // analyze the time complexity of the recursive helper functions using recurrence relations
    // and write the time complexity in Big O notation.
    Playlist& operator-=(const Song& song) {
        
    }

    // overload the /= operator to remove all songs by a specific artist
    // If no songs by that artist are found, do nothing
    // Note: This operator should modify the original playlist
    // Complexity Analysis: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the removal
    // analyze the time complexity of the recursive helper functions using recurrence relations
    // and write the time complexity in Big O notation.
    Playlist& operator/=(const char* artist) {
        
    }
};

ostream& operator<<(ostream& os, const Playlist& p) {
    os << "Playlist contains " << p.size << " songs:" << endl;
    for (int i = 0; i < p.size; ++i) {
        os << "Postion " << i << ": " << p.songs[i] << endl; // Use the overloaded << operator for Song
    }
    return os;
}

#endif