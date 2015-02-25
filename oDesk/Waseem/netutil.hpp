#ifndef __NET_UTIL_H__
#define __NET_UTIL_H__

extern "C" {
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>

#include <stdio.h>

}

#include <string>

#define PRO_LABEL "DISTRIB2015"
#define PRO_LABEL_LEN 11

#define PRO_DEBUG 'D'
#define PRO_NORMAL 'N'
#define PRO_AUTH1 '1'

#define PRO_TCP_HEADER_LEN 14

#define debug(fmt,...) do {                                         \
    fprintf(stderr,"[ DEBUG ] : [ %s, %d ] ",__FILE__,__LINE__);    \
    fprintf(stderr,fmt,##__VA_ARGS__);                              \
    fprintf(stderr,"\n");                                           \
} while(0)

struct Command {
	char status;
	char sha[64];
	char mode;
	uint16_t step;

	uint32_t sid;
	uint32_t rn;
	std::string user;
	std::string pwd;

	Command(char m) :
			mode(m) {
		rn = get_random_number();
	}

	uint32_t get_random_number();

	void update_sha();

	int serialize(char* buf);
	int deserialize(const char* buf);
};

struct TcpMessage {
	uint16_t len;
	char label[11];
	char mode;
	Command cmd;

	TcpMessage(char m) :
			mode(m), cmd(m), len(-1) {
		memcpy(label, "DISTRIB2015", 11);
	}

	int serialize(char* buf);
	int deserialize(const char* buf, int len);

};

struct UdpMessage {

};

class UdpSocket {
public:
	UdpSocket();
	~UdpSocket();

	int connect(const char * host, int port);

	int get_port();

	int send(const void* buf, int len);
	int recv(void* buf, int len);
private:
	int sockfd;
	int port;
	struct sockaddr_in peer;
};

class Connection {
public:
	Connection(int skt);
	Connection(const char* hostname, int port);

	~Connection();

	int send(void* buf, int len);
	int recv(void* buf, int len);

private:
	int sockfd;
};

class ServerSocket {
public:
	/*
	 * The constructor of ServerSocket; it will start a server socket at port
	 */
	ServerSocket(int port);
	/*
	 * The de-constructor of ServerSocket, it will close the socket
	 */
	~ServerSocket();
	// The accept function that waiting client to connect
	int accept();
private:
	int sockfd;
};

#endif
