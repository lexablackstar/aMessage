#include <iostream>
#include "NetworkManager.h"

using namespace std;

int main(int argc, char* argv[]){

    if (argc != 2) {
        cout << "Usage: Server <hostname> "<<endl;
        return 0;
    }

    char ip[64];
    NetworkManager nm;
    if (nm.getIpByName(argv[1], ip) != 0)
        cout << "ERROR: receiving ip." << endl;
    else 
        cout << "IP: " << ip << endl;    


    return 0;
}