//
// Created by nickr on 2022-02-18.
//

#ifndef WORDLEBOTC___WORDLEWORD_H
#define WORDLEBOTC___WORDLEWORD_H

#include <string>
#include <iostream>

#include "wordList.h"

#define IGNOREVAL 10

class WordleWord {
public:
    std::string word;
    int infoTable[26][8] = {0};

    void makeAGuess(std::string guess, wordList *wl) {
        int infoTable[26][8] = {0};
        for (int i = 0; i < 5; i++) {
            int guessMadeFlag = 0;
            for (int j = 0; j < 5; j++) {
                if (word[j] == guess[i]) { //letter and pos
                    if (i == j) { //letter and pos
                        this->info2Table(1, i + 1, 1, word[j]); // add code for double letters
                        guessMadeFlag = 1;
                        break;
                    }
                    if (i != j) { //letter and not pos
                        this->info2Table(0, i + 1, 1, word[j]);
                        guessMadeFlag = 1;
                        break;
                    }
                }
            }
            if (guessMadeFlag == 0) {
                guessMadeFlag = 0;
                this->info2Table(0, 0, 0, guess[i]);
                //none of the guess word letters match word 1etters
            }
        }
        wl->updateWordList(this->infoTable);
    }

    void info2Table (int posKnown, int pos, int letterCorrect, char letter) {
        int charvalue;
        if (letter > 96) {
            charvalue = letter - 97;
        }
        else
            charvalue = letter - 65;

        if (posKnown && letterCorrect) { // Green
            this->infoTable[charvalue][pos + 2] = 1;

        }
        if (!posKnown && letterCorrect) {
            this->infoTable[charvalue][1] = 1;
            this->infoTable[charvalue][2] = pos;

        }
        if (!letterCorrect) {
            this->infoTable[charvalue][0] = 1;
        }
    }

    void initWord(std::string setWord) {
        this->word = setWord;
    }

    void randWord(wordList *wl) {
        this->initWord(wl->wordlist[rand() % (wl->wordlist.size())]);
    }

    void printArray() {
        for (int i = 0; i < 26; i++) {
            std::cout << (char) (i + 97) << ' ';
            for (int j = 0; j < 8; j++) {
                std::cout << this->infoTable[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

};


#endif WORDLEBOTC___WORDLEWORD_H
