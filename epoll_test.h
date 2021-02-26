#ifndef _EPOLL_TEST_H
#define _EPOLL_TEST_H
#include <pthread.h>   
#include <string.h>   
#include <stdlib.h>   
#include <unistd.h>   
#include <stdio.h>   
#include <fcntl.h> 

#include <sys/epoll.h>   
#include <sys/errno.h>  
#include <sys/socket.h>   
#define THREAD_POLL_SIZE   600
#define EPOLL_SIZE         65536

class tcpServer
{
public:
	tcpServer();
	~tcpServer();
    void init();
	void run();
	void init_threadpoll(int size);
private:
	int epfd;
	int listenfd;
	epoll_event events[1024];
	char recvBuf[1024];
}


#endif
