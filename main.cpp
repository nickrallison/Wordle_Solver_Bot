#include "WordleWord.h"
#include "wordList.h"
#include "wordListData.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


int main() {
    wordList wl;
    wl.initWordList();
    wl.lowerCase();

    wl.greyInPos(1, "soare");
    wl.yellowInPos(2, "soare");
    wl.greyInPos(3, "soare");
    wl.greyInPos(4, "soare");
    wl.greyInPos(5, "soare");

    wl.greyInPos(1, "gluon");
    wl.greenInPos(2, "gluon");
    wl.greyInPos(3, "gluon");
    wl.yellowInPos(4, "gluon");
    wl.greyInPos(5, "gluon");

    wl.greyInPos(1, "block");
    wl.greenInPos(2, "block");
    wl.greenInPos(3, "block");
    wl.yellowInPos(4, "block");
    wl.greyInPos(5, "block");




    //WordleWord word;
    //word.randWord(&wl);
    //word.makeAGuess("crane", &wl);
    //word.makeAGuess("inert", &wl);

    wordListData wld;
    wld.fillWordEntropy(&wl);

    wl.printWordAndEntList();

    wld.findBestWord(&wl);

}
