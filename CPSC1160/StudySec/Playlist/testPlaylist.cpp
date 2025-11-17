#include <iostream>
#include "Playlist.h"
using namespace std;

int main() {
    /////////////////////////////////////////////////////
    ////// SAMPLE OUTPUT AFTER THE MAIN FUNNCTION ///////
    //////////////// CHECK THE OUTPUT ///////////////////
    /////////////////////////////////////////////////////

    // Create a playlist
    Playlist playlist;

    // Add songs to the playlist
    playlist += Song("Song A", "Artist 1");
    playlist += Song("Song B", "Artist 2");
    playlist += Song("Song C", "Artist 1");
    playlist += Song("Song A", "Artist 1");
    playlist += Song("Song D", "Artist 3");
    playlist += Song("Song B", "Artist 2");
    playlist += Song("Song E", "Artist 2");
    playlist += Song("Song F", "Artist 1");
    playlist += Song("Song A", "Artist 1");
    playlist += Song("Song G", "Artist 3");


    // Display the playlist
    cout << playlist;

    // Display the size of the playlist
    cout << "Size of the playlist: " << playlist.getSize() << endl;

    // Access a song by index
    cout << "Accessing song at index 2: " << playlist[2] << endl;
    // Attempt to access an out-of-bounds index
    cout << "Accessing song at index 100 (out of bounds): " << playlist[100] << endl;

    // Remove the last occurrence of a song
    playlist -= Song("Song A", "Artist 1");
    cout << "After removing last occurrence of 'Song A':" << endl;
    cout << playlist;

    // Remove all songs by an artist
    playlist /= "Artist 2";
    cout << "After removing all songs by 'Artist 2':" << endl;
    cout << playlist;

    // Concatenate another playlist
    Playlist anotherPlaylist;
    anotherPlaylist += Song("Song H", "Artist 4");
    anotherPlaylist += Song("Song I", "Artist 5");
    cout << "Another playlist:" << endl;
    cout << anotherPlaylist;
    playlist += anotherPlaylist;
    cout << "After concatenating another playlist:" << endl;
    cout << playlist;

    // test the copy constructor
    Playlist copiedPlaylist(playlist);
    copiedPlaylist += Song("Song J", "Artist 6");
    cout << "Original playlist after copy:" << endl;
    cout << playlist;
    // Display the copied playlist
    cout << "Copied playlist:" << endl; 
    cout << copiedPlaylist;

    // test += array of songs
    Song songArray[] = {
        Song("Song K", "Artist 7"),
        Song("Song L", "Artist 8"),
        Song("Song M", "Artist 9"),
        Song("", "") // End marker for the array
    };
    playlist += songArray;
    cout << "After adding an array of songs:" << endl;
    cout << playlist;

    return 0;
}

/* sample output:
Playlist contains 10 songs:
Postion 0: Title: Song A, Artist: Artist 1
Postion 1: Title: Song B, Artist: Artist 2
Postion 2: Title: Song C, Artist: Artist 1
Postion 3: Title: Song A, Artist: Artist 1
Postion 4: Title: Song D, Artist: Artist 3
Postion 5: Title: Song B, Artist: Artist 2
Postion 6: Title: Song E, Artist: Artist 2
Postion 7: Title: Song F, Artist: Artist 1
Postion 8: Title: Song A, Artist: Artist 1
Postion 9: Title: Song G, Artist: Artist 3
Size of the playlist: 10
Accessing song at index 2: Title: Song C, Artist: Artist 1
Accessing song at index 100 (out of bounds): Index out of bounds. Returning the first song.
Title: Song A, Artist: Artist 1
After removing last occurrence of 'Song A':
Playlist contains 9 songs:
Postion 0: Title: Song A, Artist: Artist 1
Postion 1: Title: Song B, Artist: Artist 2
Postion 2: Title: Song C, Artist: Artist 1
Postion 3: Title: Song A, Artist: Artist 1
Postion 4: Title: Song D, Artist: Artist 3
Postion 5: Title: Song B, Artist: Artist 2
Postion 6: Title: Song E, Artist: Artist 2
Postion 7: Title: Song F, Artist: Artist 1
Postion 8: Title: Song G, Artist: Artist 3
After removing all songs by 'Artist 2':
Playlist contains 6 songs:
Postion 0: Title: Song A, Artist: Artist 1
Postion 1: Title: Song C, Artist: Artist 1
Postion 2: Title: Song A, Artist: Artist 1
Postion 3: Title: Song D, Artist: Artist 3
Postion 4: Title: Song F, Artist: Artist 1
Postion 5: Title: Song G, Artist: Artist 3
Another playlist:
Playlist contains 2 songs:
Postion 0: Title: Song H, Artist: Artist 4
Postion 1: Title: Song I, Artist: Artist 5
After concatenating another playlist:
Playlist contains 8 songs:
Postion 0: Title: Song A, Artist: Artist 1
Postion 1: Title: Song C, Artist: Artist 1
Postion 2: Title: Song A, Artist: Artist 1
Postion 3: Title: Song D, Artist: Artist 3
Postion 4: Title: Song F, Artist: Artist 1
Postion 5: Title: Song G, Artist: Artist 3
Postion 6: Title: Song H, Artist: Artist 4
Postion 7: Title: Song I, Artist: Artist 5
Original playlist after copy:
Playlist contains 8 songs:
Postion 0: Title: Song A, Artist: Artist 1
Postion 1: Title: Song C, Artist: Artist 1
Postion 2: Title: Song A, Artist: Artist 1
Postion 3: Title: Song D, Artist: Artist 3
Postion 4: Title: Song F, Artist: Artist 1
Postion 5: Title: Song G, Artist: Artist 3
Postion 6: Title: Song H, Artist: Artist 4
Postion 7: Title: Song I, Artist: Artist 5
Copied playlist:
Playlist contains 9 songs:
Postion 0: Title: Song A, Artist: Artist 1
Postion 1: Title: Song C, Artist: Artist 1
Postion 2: Title: Song A, Artist: Artist 1
Postion 3: Title: Song D, Artist: Artist 3
Postion 4: Title: Song F, Artist: Artist 1
Postion 5: Title: Song G, Artist: Artist 3
Postion 6: Title: Song H, Artist: Artist 4
Postion 7: Title: Song I, Artist: Artist 5
Postion 8: Title: Song J, Artist: Artist 6
After adding an array of songs:
Playlist contains 11 songs:
Postion 0: Title: Song A, Artist: Artist 1
Postion 1: Title: Song C, Artist: Artist 1
Postion 2: Title: Song A, Artist: Artist 1
Postion 3: Title: Song D, Artist: Artist 3
Postion 4: Title: Song F, Artist: Artist 1
Postion 5: Title: Song G, Artist: Artist 3
Postion 6: Title: Song H, Artist: Artist 4
Postion 7: Title: Song I, Artist: Artist 5
Postion 8: Title: Song K, Artist: Artist 7
Postion 9: Title: Song L, Artist: Artist 8
Postion 10: Title: Song M, Artist: Artist 9
*/