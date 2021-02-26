#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "epoll_test.h"

using namespace std;


void tcpServer::init()
{
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &sock_op, sizeof(sock_op));

	memset(&address, 0, sizeof(address));
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(8006);
	bind(listenfd, (struct sockaddr*)&address, sizeof(address));
	listen(listenfd, 1024);
	fd_Setnonblocking(listenfd);

	epfd = epoll_create(EPOLL_SIZE);
	epoll_event event;
	eent.data.fd = listenfd;
	event.events = EPOLLIN | EPOLLET;
	epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &event);
}

void tcpServer::run()
{
	epoll_event event;
	while (1){
		int n = epoll_wait(epfd, events, 4096, -1);
		if (n > 0){
			for (int i = 0; i < n; i++){
				if (events[i].data.fd == listenfd){
					event.data.fd = accept(listenfd, NULL, NULL);
					if (event.data.fd > 0){
						fd_Setnonblocking(event.data.fd);
						event.events = EPOLLIN | EPOLLET;
						epoll_ctl(epfd, EPOLL_CTL_ADD, event.data.fd, &event);
					}
				}
				else{
					recv(events[n].data.fd, recvBuf, 1024, 0);// 接受客户端消息
				}
			}
		}
	}
}

void tcpServer::init_threadpoll(int size)
{

}





void main()
{
	tcpServer  m_server;
	m_server.init_threadpoll(THREAD_POLL_SIZE);
	m_server.init();
	m_server.run();
}

