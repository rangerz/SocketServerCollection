#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define HOST "127.0.0.1" //IP only
#define PORT 5000
#define BUF_SIZE 1024

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *msg = "Hello, I'm Client";
    char buffer[BUF_SIZE] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    inet_pton(AF_INET, HOST, &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	printf("Connected\n");

    send(sock , msg , strlen(msg) , 0);
    valread = read(sock , buffer, BUF_SIZE);
    printf("Received: %s\n", buffer);
    close(sock);

    return 0;
}
