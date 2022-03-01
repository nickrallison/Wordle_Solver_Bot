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
    wl.greenInPos(5, "soare");

    wl.greenInPos(1, "clone");
    wl.greyInPos(2, "clone");
    wl.greenInPos(3, "clone");
    wl.greyInPos(4, "clone");
    wl.greenInPos(5, "clone");




    //WordleWord word;
    //word.randWord(&wl);
    //word.makeAGuess("crane", &wl);
    //word.makeAGuess("inert", &wl);

    wordListData wld;
    wld.fillWordEntropy(&wl);

    wl.printWordAndEntList();

    wld.findBestWord(&wl);

}
