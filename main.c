#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace( char base[], char from[], char to[] ){

    // Error check
    if ( base == NULL || from == NULL || to == NULL ){
        return;
    }

    if ( strlen( from ) != strlen( to ) ){
        printf("No same size FROM and TO\n");
        return;
    }

    if ( strlen( base ) < strlen( from ) ){
        printf("FROM string larger than BASE string\n");
        return;
    }
    // Iterate the base string
    for ( int i = 0; i < strlen( base ); ++i ) {
        // Find the first match
        if ( from[0] == base[i] ){
            // count the match
            int counter = 0;
            int j = i;
            // Iterate from the first match to the len of the FROM string
            for ( int k = 0; k < strlen(from); ++k ) {
                if ( from[k] == base[j] ){
                    counter++;
                } else{
                    break;
                }
                j++;
            }
            // If all matches FROM string are correct replace with TO string
            if ( counter == strlen( from ) && counter != 0 ){
                for ( int k = 0; k < strlen( from ); ++k ) {
                    base[i]= to[k];
                    i++;
                }
                i=i-1; // Iterator relocate to the last match
            }
        }
    }
}
int main(){

    char base[] = "Msissisippi";
    char from[] = "sis";
    char to[] = "iss";
    replace( base, from, to );
    printf("%s\n",base);

    return EXIT_SUCCESS;
}
