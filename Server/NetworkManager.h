#ifndef __NETWORK_MANAGER_H__
#define __NETWORK_MANAGER_H__

class NetworkManager {

public: 
    NetworkManager();

    int getIpByName(char* hostname, char* ip);
};

#endif