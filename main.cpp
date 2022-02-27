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

    wl.greenInPos(1, "crane");
    wl.greyInPos(2, "crane");
    wl.greenInPos(3, "crane");
    wl.greenInPos(4, "crane");
    wl.greyInPos(5, "crane");




    //WordleWord word;
    //word.randWord(&wl);
    //word.makeAGuess("crane", &wl);
    //word.makeAGuess("inert", &wl);

    wordListData wld;
    wld.fillWordEntropy(&wl);

    wl.printWordAndEntList();

    wld.findBestWord(&wl);

}
