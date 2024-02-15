#include <stdio.h>
#include <string.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(int argc, char* argv[])
{

    int sockfd;
    struct sockaddr_in dest;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&dest, 0, sizeof(struct sockaddr_in));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(9090);
    dest.sin_addr.s_addr = inet_addr("10.0.2.6");

    if (connect(sockfd, (struct sockaddr*)&dest, sizeof(struct sockaddr_in)))
    {
        perror("connect");
        return -1;
    }
    printf("connected to server\n");


    char buffer[100];

    while (1)
    {
        printf("Enter a message: ");
        fgets(buffer, 100, stdin);

        if (strcmp(buffer, "\n") == 0)
        {
            break;
        }

        write(sockfd, buffer, strlen(buffer));
    }


    close(sockfd);

    return 0;


}