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
    }

    void printWordList() {
        for (int i = 0; i < this->wordlist.size(); i++) {
            std::cout << this->wordlist[i] <<'\n';
        }
    }
    void printWordAndEntList() {
        for (int i = 0; i < this->wordlist.size(); i++) {
            std::cout << this->wordlist[i] << ' ' << this->wordEntropy[i] <<'\n';
        }
    }

    void printEntropyList() {
        for (int i = 0; i < this->wordlist.size(); i++) {
            std::cout << this->wordEntropy[i] <<'\n';
        }
    }


    void lowerCase() {
        for (int i = 0; i < this->wordlist.size(); i++){
            for (int j = 0; j < 5; j++) {
                if (this->wordlist[i][j] < 91)
                    this->wordlist[i][j] = this->wordlist[i][j]  + 32;
            }
        }
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
    }

    std::vector<std::string> wordListCopy() {
        return this->wordlist;
    }

    void greenInPos(int pos, std::string guess) {
        removeNotHasLetterInPos(guess[pos - 1], pos);
    }
    void yellowInPos(int pos, std::string guess) {
        removeHasLetterInPos(guess[pos - 1], pos);
        removeNotHasLetter(guess[pos - 1]);
    }
    void greyInPos(int pos, std::string guess) {
        removeHasLetter(guess[pos - 1]);
    }


};

#endif //WORDLEBOTC___WORDLIST_H
