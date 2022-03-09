#ifndef WORDLEBOTC___WORDLIST_H
#define WORDLEBOTC___WORDLIST_H

#include <vector>
#include <fstream>
#include <iostream>

class wordList {
public:
    std::vector<std::string> wordlist;
    std::vector<double> wordEntropy;

    void copyWordList(std::vector<std::string> wl) {
        this->wordlist=wl;

    // REQUIRES
    //
    // PROMISES
    //   Copies given wordlist to object's internal list

    }

    void initWordList()
    {
        std::ifstream in("wordList.txt");
        std::string str;

        while (std::getline(in, str)) {
            if(str.size() > 0)
                this->wordlist.push_back(str);
        }
        in.close();

        // REQUIRES
        //
        // PROMISES
        //   Copies full wordList.txt to internal wordlist
    }

    void printWordList() {
        for (int i = 0; i < this->wordlist.size(); i++) {
            std::cout << this->wordlist[i] <<'\n';
        }

        // REQUIRES
        //
        // PROMISES
        //   Prints internal wordlist
    }
    void printWordAndEntList() {
        for (int i = 0; i < this->wordlist.size(); i++) {
            std::cout << this->wordlist[i] << ' ' << this->wordEntropy[i] <<'\n';
        }

        // REQUIRES
        //
        // PROMISES
        //   Prints internal wordlist and entropy list
        //   See function shouldIGuess(std::string guess, wordList *wl) in wordListData for more details on entropy
    }

    void printEntropyList() {
        for (int i = 0; i < this->wordlist.size(); i++) {
            std::cout << this->wordEntropy[i] <<'\n';
        }

        // REQUIRES
        //
        // PROMISES
        //   Prints internal entropy list
    }


    void lowerCase() {
        for (int i = 0; i < this->wordlist.size(); i++){
            for (int j = 0; j < 5; j++) {
                if (this->wordlist[i][j] < 91)
                    this->wordlist[i][j] = this->wordlist[i][j]  + 32;
            }
        }

        // REQUIRES
        //
        // PROMISES
        //   Ensures entire wordlist is lowercase
    }

    void removeHasLetter(char letter) { //Grey
        int j = 0;
        int size = this->wordlist.size();
        for (int i = 0; i < size; i++) {
            int p = this->wordlist[i - j].find(letter);
            if (p != -1) {
                this->wordlist.erase(this->wordlist.begin() + i - j);
                j++;
            }
        }

        // REQUIRES
        //
        // PROMISES
        //   Removes every word from list containing the given letter
    }

    void removeHasLetterInPos(char letter, int pos) { //Yellow
        int j = 0;
        int size = this->wordlist.size();
        for (int i = 0; i < size; i++) {
            int p = this->wordlist[i - j].find(letter);
            if (p == pos - 1) {
                this->wordlist.erase(this->wordlist.begin() + i - j);
                j++;
            }
        }

        // REQUIRES
        //   Position goes 1 -> 5
        // PROMISES
        //   Removes every word from list containing the given letter in the given position
    }

    void removeNotHasLetter(char letter) { //Yellow
        int j = 0;
        int size = this->wordlist.size();
        for (int i = 0; i < size; i++) {
            int p = this->wordlist[i - j].find(letter);
            if (p == -1) {
                this->wordlist.erase(this->wordlist.begin() + i - j);
                j++;
            }
        }

        // REQUIRES
        //
        // PROMISES
        //   Removes every word from list that doesn't contain the given letter
    }

    void removeNotHasLetterInPos(char letter, int pos) { //Green
        int j = 0;
        int size = this->wordlist.size();
        for (int i = 0; i < size; i++) {
            int p = this->wordlist[i - j].find(letter);
            if (p != pos - 1) {
                this->wordlist.erase(this->wordlist.begin() + i - j);
                j++;
            }
        }

        // REQUIRES
        //   Position goes 1 -> 5
        // PROMISES
        //   Removes every word from list that doesn't contain the given letter in the given position
    }

    void updateWordList(int infoTable[26][8]) {
        for (int i = 0; i < 26; i++) {
            if (infoTable[i][0] == 1) {
                this->removeHasLetter(i + 97);
            }
            if (infoTable[i][1] == 1) {
                this->removeHasLetterInPos(i + 97, infoTable[i][2]);
                this->removeNotHasLetter(i + 97);
            }
            for (int j = 3; j < 8; j++) {
                if (infoTable[i][j] == 1) {
                    this->removeNotHasLetterInPos(i + 97, j - 2);
                }
            }
        }

        // INFO
        //   from an earlier draft so organized differently than wordListData but still functional
        //   Used with Word object from WordleWord.h
        //   Used to manually prune wordList
        //   infoTable contents inform function what letters to cut or not
        //   Need Word to be specified
        //   Used in debugging
        //
        // REQUIRES
        //
        // PROMISES
        //   Word list pruned based on infoTable
    }

    std::vector<std::string> wordListCopy() {
        return this->wordlist;

        // REQUIRES
        //
        // PROMISES
        //   Returns internal word list
    }

    void greenInPos(int pos, std::string guess) {
        removeNotHasLetterInPos(guess[pos - 1], pos);

        // REQUIRES
        //   pos goes from 1 -> 5
        // PROMISES
        //   Removes every word without containing guess[pos - 1] in position pos
    }
    void yellowInPos(int pos, std::string guess) {
        removeHasLetterInPos(guess[pos - 1], pos);
        removeNotHasLetter(guess[pos - 1]);

        // REQUIRES
        //   pos goes from 1 -> 5
        // PROMISES
        //   Removes every word without containing guess[pos - 1]
        //   Also removes every word with guess[pos - 1] in position pos
    }
    void greyInPos(int pos, std::string guess) {
        removeHasLetter(guess[pos - 1]);

        // REQUIRES
        //   pos goes from 1 -> 5
        // PROMISES
        //   Removes every word that contains guess[pos - 1]
    }


};

#endif //WORDLEBOTC___WORDLIST_H
