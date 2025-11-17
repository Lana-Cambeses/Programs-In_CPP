#ifndef PLAYLISTLINKEDLIST_H
#define PLAYLISTLINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

// Helper functions to calculate length and copy char arrays
int CalculateLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void CopyCharArray(const char* source, char* destination, int length) {
    for (int i = 0; i < length; ++i) {
        destination[i] = source[i];
    }
    destination[length] = '\0'; // Null-terminate the string, ensuring it is a valid C-style string (easy to print!)
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
}

class Song {
public:
    char* title; // Title of the song
    char* artist; // Artist of the song
    static const int MAX_LENGTH = 100; // Maximum length for title and artist
    Song* next; // Pointer to the next song in the linked list

    Song(){
        title = new char[1];
        artist = new char[1];
        title[0] = '\0'; // Initialize to empty string
        artist[0] = '\0'; // Initialize to empty string
        next = nullptr; // Initialize next pointer to null
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
        next = nullptr; // Initialize next pointer to null
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
        if(other.next != nullptr) {
            // Deep copy the next song if it exists (eventually all next songs will be deep copied)
            // complete the code
        } else {
            next = nullptr; // Otherwise, set next to null
        }
    }
    ~Song() {
        delete[] title;
        delete[] artist;
    }
    Song& operator=(const Song& other) {
        if (this != &other) { // Check for self-assignment
            delete[] title; // Free existing memory
            delete[] artist; // Free existing memory

            int titleLength = CalculateLength(other.title);
            int artistLength = CalculateLength(other.artist);
            title = new char[titleLength + 1];
            artist = new char[artistLength + 1];
            CopyCharArray(other.title, title, titleLength);
            CopyCharArray(other.artist, artist, artistLength);
            title[titleLength] = '\0'; // Null-terminate the title
            artist[artistLength] = '\0'; // Null-terminate the artist
            if(other.next != nullptr) {
                // Deep copy the next song if it exists (eventually all next songs will be deep copied)
                // complete the code
            } else {
                next = nullptr; // Otherwise, set next to null
            }
        }
        return *this;
    }
    
    bool operator==(const Song& other) const {
        return (IsEqual(title, other.title) && IsEqual(artist, other.artist));
    }
};

ostream& operator<<(ostream& os, const Song& s) {
    os << "Title: " << s.title << ", Artist: " << s.artist;
    return os;
}

class Playlist {
    friend ostream& operator<<(ostream& os, const Playlist& p);
private:
    Song* first; // Pointer to the first song in the playlist
    Song* last; // Pointer to the last song in the playlist

public:
    Playlist() {
        first = last = nullptr; // empty playlist
    }

    // Write a deep copy constructor
    // This constructor will create a new playlist that is a deep copy of the other playlist
    // It will iterate through the songs in the other playlist
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this constructor and write it in Big O notation.
    Playlist(const Playlist& other) {  
        // Complete the code      
    }

    // Destructor to free the memory allocated for the playlist
    // It should delete all songs in the playlist
    // This will ensure that there are no memory leaks when the playlist is destroyed
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this destructor and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the deletion
    // analyze the time complexity of the recursive helper functions using recurrence relations
    ~Playlist() {
        // Complete the code
        
    }

    // function to check if the playlist is empty
    bool IsEmpty() const {
        return first == nullptr; // If first is null, the playlist is empty
    }

    // function to calculate the size of the playlist
    int getSize() const {
        int size = 0;
        Song* current = first; // Start from the first song
        while (current != nullptr) {
            size++; // Increment size for each song
            current = current->next; // Move to the next song
        }
        return size; // Return the total size of the playlist   
    }

    // overload the assignment operator
    // check for self-assignment
    // This operator will create a deep copy of the other playlist
    // It will free the existing memory of songs in *this
    // and then copy the songs from the other playlist
    // It will return *this so that we can chain assignments
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the deep copy
    // analyze the time complexity of the recursive helper functions using recurrence relations
    Playlist& operator=(const Playlist& other) {
        // Complete the code
    }

    // overload the += operator to add a song to the end of the playlist
    // Note: This operator should modify the original playlist
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the addition
    // analyze the time complexity of the recursive helper functions using recurrence relations
    Playlist& operator+=(const Song& song) {
        // complete the code
    }

    // overload the += operator to add all songs from an array of songs
    // assume the array of songs ends with a song with an empty title and artist (i.e. Song("", ""))
    // Note: This operator should modify the original playlist
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the addition
    // analyze the time complexity of the recursive helper functions using recurrence relations
    Playlist& operator+=(const Song* songArray) {
        // complete the code
    }

    // overload the + operator to concatenate two playlists
    // Return a new playlist that contains all songs from both playlists (songs from *this followed by songs from other)
    // Note: This operator should not modify the original playlists
    // Complexity Analysis: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the concatenation
    // analyze the time complexity of the recursive helper functions using recurrence relations
    Playlist operator+(const Playlist& other) const {
        // complete the code
    }

    // overload the += operator to concatenate another playlist
    Playlist& operator+=(const Playlist& other) {
        *this = *this + other; // Use the + operator to concatenate
        return *this; // Return the updated playlist
    }

    // overload the [] operator to access a song by index
    // If the index is out of bounds, return the first song
    // If the playlist is empty, output an error message and return a default song
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the access
    // analyze the time complexity of the recursive helper functions using recurrence relations
    const Song& operator[](int index) const {
        // complete the code
    }

    // overload the -= operator to remove the last occurrence of a song from the playlist
    // If the song is not found, do nothing
    // Note: This operator should modify the original playlist
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the removal
    // analyze the time complexity of the recursive helper functions using recurrence relations
    Playlist& operator-=(const Song& song) {
        // Complete the code
        
    }

    // overload the /= operator to remove all songs by a specific artist
    // If no songs by that artist are found, do nothing
    // Note: This operator should modify the original playlist
    // COMPLEXITY ANALYSIS: Calculate the time complexity of this operator and write it in Big O notation.
    // FURTHER PRACTICE:
    // use recursive helper functions instead of loops to implement the removal
    // analyze the time complexity of the recursive helper functions using recurrence relations
    Playlist& operator/=(const char* artist) {
        // Complete the code
    }
};

ostream& operator<<(ostream& os, const Playlist& p) {
    if (p.IsEmpty()) {
        os << "Playlist is empty." << endl;
    } else {
        os << "Playlist contents:" << endl;
        Song* current = p.first; // Start from the first song
        int i = 0; // Index for song numbering
        while (current != nullptr) {
            os << "Position " << i << ": " << *current << endl; // Print each song
            current = current->next; // Move to the next song
            i++;
        }
    }
    return os; // Return the output stream
}

#endif