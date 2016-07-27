#include <stdlib.h>
#include <stdio.h>

#include "net.h"

Client client = {0};

bool clnConnect(const char* ip, int port, const char* name) {
	printf("Attempting to connect to %s:%d as %s... \n", ip, port, name);
	fflush(stdout);

	// Get server ip from name
	IPaddress server = {0};
	int r = SDLNet_ResolveHost(&server, ip, port);
	if (r == -1)
		return false;

	// Attempt to connect
	client.socket = SDLNet_TCP_Open(&server);

	if (client.socket == NULL) 
		return false;

	strcat(client.name, name);

	CPacket connInfo = {CTYPE_CONN_INFO, NET_NAME_LEN};
	SDLNet_TCP_Send(client.socket, &connInfo, sizeof(CPacket));
	SDLNet_TCP_Send(client.socket, client.name, NET_NAME_LEN);

	printf("Done!\n");
	return true;
}

