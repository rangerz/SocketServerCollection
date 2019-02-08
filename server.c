#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define HOST "127.0.0.1" //IP only
#define PORT 5851
#define BUF_SIZE 1024

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUF_SIZE] = {0};
    char *msg = "Hello, I'm Server.";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(HOST);
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    printf("Server start...\n");

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    valread = read( new_socket , buffer, BUF_SIZE);
    printf("Client Message: %s\n", buffer);
    send(new_socket , msg , strlen(msg) , 0);
    close(new_socket);
    close(server_fd);

    return 0;
}