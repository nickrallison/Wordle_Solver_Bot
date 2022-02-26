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

    wl.greyInPos(1, "crane");
    wl.greyInPos(2, "crane");
    wl.greyInPos(3, "crane");
    wl.greyInPos(4, "crane");
    wl.greyInPos(5, "crane");

    wl.greyInPos(1, "blots");
    wl.yellowInPos(2, "blots");
    wl.greyInPos(3, "blots");
    wl.greyInPos(4, "blots");
    wl.yellowInPos(5, "blots");

    wl.greyInPos(1, "blots");
    wl.yellowInPos(2, "blots");
    wl.greyInPos(3, "blots");
    wl.greyInPos(4, "blots");
    wl.yellowInPos(5, "blots");

    wl.greenInPos(1, "skill");
    wl.greyInPos(2, "skill");
    wl.greenInPos(3, "skill");
    wl.greenInPos(4, "skill");
    //wl.greenInPos(5, "skill");




    //WordleWord word;
    //word.randWord(&wl);
    //word.makeAGuess("crane", &wl);
    //word.makeAGuess("inert", &wl);

    wordListData wld;
    wld.fillWordEntropy(&wl);

    wl.printWordAndEntList();

    wld.findBestWord(&wl);

}
