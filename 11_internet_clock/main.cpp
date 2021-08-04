#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include "ntp.hpp"
#include <netdb.h>
#include <arpa/inet.h>
#include <ctime>

int other(int argc, char const *argv[])
{
    if(argc != 3)
    {
        printf("You need to provide a time server and a port number.\n");
        exit(1);
    }

    const char* host = argv[1];
    int port = std::stoi(argv[2]);
    int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // init sockaddr
    sockaddr_in address;
    std::memset(&address, 0, sizeof(address));

    // resolve address
    address.sin_family=AF_INET;
    address.sin_addr.s_addr = inet_addr(host);
    address.sin_port = htons(port);

    // init msg
    ntp_message msg;
    msg.version = 3;
    msg.mode = 3;
    memset(&msg, 0, sizeof(ntp_message));

    // send the msg
    int s = sendto(sock, (char*)&msg, sizeof(ntp_message), 0, (sockaddr*)&address, sizeof(address));

    printf("%d\n", s);

    // recv the msg
    ntp_message response = recv_ntp(sock);
    auto timestamp = response.transmit_time.to_time_t();
    printf("The time is %s.\n", ctime(&timestamp));

    return 0;
}