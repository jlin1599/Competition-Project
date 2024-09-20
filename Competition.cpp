#include <iostream>
#include "Competition.hpp"
#include <cstdlib>
using namespace std;

Competition::Competition() : rabbit(), tor(), lane() {
    // rabbit with default constructor of Hare class
    // tor with default constructor of Tortoise class
    // lane with default constructor of Road class
}

Competition::Competition(Hare coney, Tortoise cooter, int length)
    : rabbit(coney), tor(cooter), lane(length) {
    // rabbit with coney
    // tor with cooter
    // lane with length
}
void Competition::play() {
    int round = 1;
    int lastBlock = lane.length() - 1;

    while(rabbit.getPosition() < lastBlock && tor.getPosition() < lastBlock){
        rabbit.move();
        rabbit.setPosition(max(rabbit.getPosition(),0));
        rabbit.setPosition(min(rabbit.getPosition(),lastBlock));
        lane.mark(rabbit.getPosition(), 'H');

        tor.move();
        tor.setPosition(max(tor.getPosition(),0));
        tor.setPosition(min(tor.getPosition(),lastBlock));
        lane.mark(tor.getPosition(), 'T');

        cout << "Round " << round << ": ";
        lane.display();

        if(rabbit.getPosition() == tor.getPosition()){
            cout << "Ouch! Tortoise bites hare." << endl;
        }
        lane.mark(rabbit.getPosition(), ' ');
        lane.mark(tor.getPosition(), ' ');
        round++;
    }
    if(rabbit.getPosition() == lastBlock){
        cout << " Yuck, hare wins. " << endl;
    }else if(tor.getPosition() == lastBlock){
        cout << "Tortoise wins!" << endl;
    }else{
        cout << "It is a tie." << endl;
    }
    
}
