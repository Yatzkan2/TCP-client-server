#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, newsockfd;
    struct sockaddr_in my_addr, client_addr;
    char buffer[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 



    memset(&my_addr, 0, sizeof(struct sockaddr_in));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(9090);

    bind(sockfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr_in));

    listen(sockfd, 5);
    printf("Listening on port: %d\n", ntohs(my_addr.sin_port));

    int client_len = sizeof(client_addr);

    while (1)
    {
        newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
        int pid = fork();
        if (pid == 0)
        {
            close(sockfd);
            while (1)
            {
                memset(buffer, 0, sizeof(buffer));
                int len = read(newsockfd, buffer, 100);
                if (len <= 0)
                {
                    break;
                }
                printf("#########\n");
                printf("Data length %d\n", len);
                printf("Recieved data: %s", buffer);
                printf("from client on IP: %s\n", inet_ntoa(client_addr.sin_addr));
                printf("connected on socket %d\n", newsockfd);
                printf("PID: %d\n", getpid());

            }
            close(newsockfd);
            return 0;
        }
        else
        {
            close(newsockfd);
        }
    }
    return 0;
}