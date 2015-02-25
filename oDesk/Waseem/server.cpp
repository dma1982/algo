extern "C" {
#include <signal.h>
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
}

#include <iostream>
#include <cstdlib>

#include "netutil.hpp"

#define MAX_RUNTIME 60*60  /* one hour in seconds */

static void watchdog(int signro) {
	exit(signro); /* process will exit when the timer signal arrives */
}

/**
 * --port T where number T defines the port number where the server listens to connections (both TCP and UDP)
 * ONE of these parametes must be specified:
 *	--debug server is running in debug mode (only the DEBUG parts of the protocol are implemented)
 *	--normal server is running in normal operating mode (AUTH1 parts implemented)
 *	--authN server implements extra functionality, where number N is chosen by the project team
 */

static int port = -1;
static int mode = -1;

static int usage(char* name) {
	std::cout << "Usage: " << name << " --port port --debug|normal|auth1"
			<< std::endl;
	exit(1);
}

static void parseArgs(int argc, char** argv) {

	if (argc != 4) {
		usage(argv[0]);
	}

	while (1) {
		int c, option_index;
		static struct option long_options[] = { { "port", required_argument, 0,
				0 }, { "debug", no_argument, 0, 0 }, { "normal",
		required_argument, 0, 0 }, { "auth1",
		no_argument, 0, 0 }, { 0, 0, 0, 0 } };

		c = getopt_long(argc, argv, "p:dna", long_options, &option_index);
		if (c == -1)
			break;

		if (strcmp(long_options[option_index].name, "port") == 0) {
			port = atoi(optarg);
		} else if (strcmp(long_options[option_index].name, "debug") == 0) {
			if (mode != -1)
				usage(argv[0]);
			mode = PRO_DEBUG;
		} else if (strcmp(long_options[option_index].name, "normal") == 0) {
			if (mode != -1)
				usage(argv[0]);
			mode = PRO_NORMAL;
		} else if (strcmp(long_options[option_index].name, "auth1") == 0) {
			if (mode != -1)
				usage(argv[0]);
			mode = PRO_AUTH1;
		}
	}

	debug("port: <%d>, mode: <%c>", port, mode);

}

int main(int argc, char** argv) {
	if (signal(SIGALRM, watchdog) == SIG_ERR) {
		exit(2); /* something went wrong in setting signal */
	}

	alarm( MAX_RUNTIME); /* after this time the program will always exit */

	/* This location would contain the rest of the program.
	 * In this example we'll just pause the program (to wait for the alarm signal)
	 */

	parseArgs(argc, argv);

	ServerSocket srvSkt(port);

	// setup udp socket
	UdpSocket udpSkt;

	int sockfd;

	while ((sockfd = srvSkt.accept()) > 0) {
		char buf[256] = {0};
		int len;
		TcpMessage msg(mode);

		debug("Get connection from client, start authentication.");

		Connection conn(sockfd);

		len = conn.recv(buf, 256);

		debug("Get A0 command from client");
		msg.deserialize(buf, len);


		// A1 command: A1 32bit-random-number
		debug("Send A1 command to client");

		msg.cmd.step = 1;
		len = msg.serialize(buf);
		conn.send(buf, len);
		// A1 command -- end


		debug("Get A2 command from client");
		len = conn.recv(buf, 256);

		msg.deserialize(buf, len);

		debug("Send A3 command to client");

		msg.cmd.step = 3;
		msg.cmd.status = 0;

		// if auth successfully, setup UDP for query
		if (msg.cmd.status == 0)
		{
			msg.cmd.sid = udpSkt.get_port(); // should be udp port
		}

		len = msg.serialize(buf);
		conn.send(buf, len);

		len = udpSkt.recv(buf, 256);

		printf("%s", buf);

		udpSkt.send("hello", 5);

		printf("\n");
	}
	return 0;
}

