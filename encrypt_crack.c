#include <crypt.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void usage(char *program_name) {
    printf("Usage: %s <wordlist> <hash>\n", program_name);
    exit(0);
}

int main(int argc, char *argv[]) {

    FILE *wordlist;
    char hash[30], word[49], salt[3];


    if (argc < 2) {
        usage(argv[0]);
        exit(0);
    }

    strncpy(salt, argv[2], 2);

    salt[2] = '\0';

    if ((wordlist = fopen(argv[1], "r")) == NULL) {
        printf("Error in trying to open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(word, 49, wordlist) != NULL) {
        word[strlen(word) -1] = '\0';


        strcpy(hash, crypt(word, salt));
        printf("Trying the word %30s => hash is %10s\n", word, hash);
        if (strcmp(hash, argv[2]) == 0) {
            printf("The word for the hash %s is %s\n", argv[2], word);
            fclose(wordlist);
            exit(0);
        }


    }
    printf("Unable to find the word for the hash %s\n", argv[2]);
    fclose(wordlist);
// mtJZvVrVPALN.
    
}

/*
Now to increase the odds of finding the correct password a bigger dictionary should be used. 
Although this will take longer time to be processed

Now for execessive brute force attacks. 
this is the one that tries every single combination of letters and words and symbols like that. 

this will take hundreds of years tho. 
but actually if a small length of password is used 
it's easire to guess the correct answer in a smaller time

*/



/*
When two computer talk to each other, they need to speak the same language
The structure of this language is described in layers by the osi model. 
The osi model provides standards that allow hardware, such as routers and firewalls, to focus
on one particular aspect of communication that applies to them and ignore others. 
The osi model is broken down into conceptual layers of communication. 
This way, routing and firewall can focus on passing data at the lower layers, ignoring the higher layers of data encapsulation used by running encapsulations. 



*/
