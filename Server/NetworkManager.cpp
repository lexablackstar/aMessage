#include "NetworkManager.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

NetworkManager::NetworkManager(){

}

int NetworkManager::getIpByName(/*IN*/char* hostname,/*OUT*/ char* ip) {

    addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(hostname, NULL, &hints, &res);
    if (status != 0)
        return status;

    void* addr;

    if (res->ai_family == AF_INET) {
        struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr; 
        addr = &(ipv4->sin_addr);
    } else {
        struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)res->ai_addr; 
        addr = &(ipv6->sin6_addr);
}

    inet_ntop(res->ai_family, addr, ip, sizeof(ip));

    freeaddrinfo(res);


    return 0;
}