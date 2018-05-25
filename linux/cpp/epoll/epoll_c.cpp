#include <stdio.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using namespace std;

const int BUFFER_SIZE = 40;
const string SERVER_IP = "127.0.0.1";
const int SERVER_PORT = 9000;

int main(int argc, char *argv[]) {   
    int client_sockfd;   
    int len;   
    //server internet address struct
    struct sockaddr_in remote_addr;
    char buf[BUFFER_SIZE];   
    memset(&remote_addr,0,sizeof(remote_addr));
    remote_addr.sin_family=AF_INET; //mean ip commucation
    remote_addr.sin_addr.s_addr=inet_addr(SERVER_IP.c_str()); 
    remote_addr.sin_port=htons(SERVER_PORT);
    //create clinet socket, IPv4 protocol
    //SOCK_STREAM mean tcp
    if((client_sockfd=socket(PF_INET,SOCK_STREAM,0))<0) {
        perror("client socket creation failed");   
        exit(EXIT_FAILURE);
    }   
    //bind client sockdf to remote server adress
    if(connect(client_sockfd,(struct sockaddr *)&remote_addr,sizeof(struct sockaddr))<0) {   
        perror("connect to server failed");   
        exit(EXIT_FAILURE);
    }  
    while(1) {
		cout<<"Please input the message:";
		scanf("%s",buf);
		if(strcmp(buf,"exit")==0) {
			break;
		}
		send(client_sockfd,buf,BUFFER_SIZE,0);
		//rece server msg
	 	len=recv(client_sockfd,buf,BUFFER_SIZE,0);
		cout<<"receive from server:"<<buf<<endl;
		if(len<0) {
			perror("receive from server failed");
			exit(EXIT_FAILURE);
		}
	}
    close(client_sockfd);
    return 0;
}
