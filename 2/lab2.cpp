/*
* author : Christian Schmiedel
* date: 9/3/24
* purpose: 
*
* 
*/

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
const char fname[] = "/home/fac/gordon/public_html/3350/dictionary.txt";
const int line_length = 80; //to set maximum length to avoid wrapping

bool is_ordered(const char* word) {
    int len = strlen(word);
    for (int i = 1; i < len; ++i)  {
        if (word[i] < word[i -1])   {
            return false;
            //not in alphabetical order
        }
     }
    return true;
}

void print_words(const char* word, int& current_width) {
    int word_len = strlen(word);
    if (current_width + word_len + 1 > line_length) {
        cout << endl;
        current_width = 0; //reset the width for the new line
    }
    if (current_width > 0) {
        cout << " "; 
    }
    cout << word;
    current_width += word_len + 1;// update current width
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << "Usage: " << argv[0] << " <word_length>" << endl;
        return 1;
    }
    int wlen = atoi(argv[1]);
    
    int n = 0;
    
    int current_width = 0; //track width of the current line

    ifstream fin(fname);
    char word[100];

    fin >> word;
    while (!fin.eof()) {
        if ((int)strlen(word) == wlen) {
            //if word letters are in lexicographic order
            // call a function that will return true or false
        if (is_ordered(word)) {
            ++n;
            print_words(word, current_width);

        }
      }
      fin >> word;

    } 
    cout <<  "\nn words:" << n << endl;

    //if no command line arguments

    //show usage: statement

    //end prog

    fin.close();
    return 0;
}
