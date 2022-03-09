//
// Created by nickr on 2022-02-24.
//

#ifndef WORDLEBOTC___WORDLISTDATA_H
#define WORDLEBOTC___WORDLISTDATA_H

#include <string>
#include <iostream>
#include <cmath>

#include "wordList.h"

class wordListData {
public:
    // INFO
    //   Manipulates data on given wordList object
    //   Data IO is to and from that object


    double shouldIGuess(std::string guess, wordList *wl) {
        int guessArray[5];
        double guessEntropyAvg = 0;
        double guessPercentAvg = 0;
        std::vector<std::string> sampleWordList;
        wordList samplewl;
        samplewl.copyWordList(wl->wordlist);
        int newlen;
        int oldlen = wl->wordlist.size();
        double guessPercent;

        for (int a = 0; a < 3; a++) {                   //
            for (int b = 0; b < 3; b++) {               //
                for (int c = 0; c < 3; c++) {           //
                    for (int d = 0; d < 3; d++) {       //
                        for (int e = 0; e < 3; e++) {   // Loops through every Color Possibility
                            samplewl.copyWordList(wl->wordlist);
                            if (0) {
                                ;
                            }
                            else {
                                guessArray[4] = a;
                                guessArray[3] = b;
                                guessArray[2] = c;
                                guessArray[1] = d;
                                guessArray[0] = e;

                                for (int i = 0; i < 5; i++) {       //Loops Letter Spots
                                    if (guessArray[i] == 0) {
                                        samplewl.removeHasLetter(guess[i]);
                                    }
                                    if (guessArray[i] == 1) {
                                        samplewl.removeNotHasLetter(guess[i]);
                                        samplewl.removeHasLetterInPos(guess[i], i);
                                    }
                                    if (guessArray[i] == 2) {
                                        samplewl.removeNotHasLetterInPos(guess[i], i);
                                    }
                                }
                            }
                            newlen = samplewl.wordlist.size();
                            guessPercent = (double) newlen / (double) oldlen;
                            if (guessPercent != 0) {
                                guessEntropyAvg += -1 * log2(guessPercent) * guessPercent;
                                guessPercentAvg += guessPercent;
                            }
                        }
                    }
                }
            }
        }
        return guessEntropyAvg;

        // INFO
        //   Goes through every possible color combination of the given word and reduces the word list from that color
        //   The connection to entropy in the formula often used in statistical mechanics -1 * prob * log(prob)
        //   The above formula is used to calculate how many times the word list is cut in half times (This is the unit entropy)
        //
        //
        // REQUIRES
        //
        // PROMISES
        //   Returns average expected entropy of the guessed word
    }

    void findBestWord(wordList *wl) {
        int bestIndex = 0;
        std::string bestWord;
        for (int i = 0; i < wl->wordlist.size(); i++) {
            if (wl->wordEntropy[i] > wl->wordEntropy[bestIndex]) {
                bestIndex = i;
            }
        }
        bestWord = wl->wordlist[bestIndex];
        std::cout << "Best Word: " << bestWord;

        // REQUIRES
        //   Entropy list must be populated
        // PROMISES
        //   Prints word with the highest entropy
        //   (Highest expected reduction of wordlist)
    }

    void fillWordEntropy(wordList *wl) {
        std::vector<double> wordEntropy;
        for (int i = 0; i < wl->wordlist.size(); i++) {
            std::cout << i<< '\n';
            wl->wordEntropy.push_back(shouldIGuess(wl->wordlist[i], wl));
        }
        wl->wordEntropy = wordEntropy;
    }

    // REQUIRES
    //   Entropy list must be populated
    // PROMISES
    //   Performs shouldIGuess(std::string guess, wordList *wl) on every word in its list and sends entropy to wordEntropy list in wordList object


};

#endif //WORDLEBOTC___WORDLISTDATA_H
