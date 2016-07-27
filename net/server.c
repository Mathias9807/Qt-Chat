#include <stdlib.h>
#include <stdio.h>

#include "net.h"

List clients = {0};
SDLNet_SocketSet sockets = NULL;

IPaddress srcIP = {0};
TCPsocket srvSocket = NULL;

void checkConnectionRequests() {
	TCPsocket socket = SDLNet_TCP_Accept(srvSocket);
	if (socket == NULL) return;

	IPaddress* cIP = SDLNet_TCP_GetPeerAddress(socket);

	Client* c = calloc(1, sizeof(Client));
	c->socket = socket;
	SDLNet_TCP_AddSocket(sockets, socket);
	if (cIP != NULL) memcpy(&c->ip, cIP, sizeof(IPaddress));

	ListAdd(&clients, c);

	// Read connection info
	CPacket connInfo;
	SDLNet_TCP_Recv(socket, &connInfo, sizeof(CPacket));

	SDLNet_TCP_Recv(socket, &c->name, NET_NAME_LEN);

	printf("%s\n", c->name);
}

void processActivity() {
	int activity = SDLNet_CheckSockets(sockets, SRV_TIMEOUT);

	for (int i = 0; i < clients.size; i++) {
		if (activity <= 0) break;

		Client* c = ListGet(&clients, i);

		if (SDLNet_SocketReady(c->socket) == 0) break;

		activity--;
		CPacket p = {0};
		int r = SDLNet_TCP_Recv(c->socket, &p, sizeof(CPacket));
		if (r <= 0) {
			ListRemove(&clients, i);
			i--;
			continue;
		}
	}
}

void srvMain() {
	sockets = SDLNet_AllocSocketSet(16);

	SDLNet_ResolveHost(&srcIP, INADDR_ANY, 63636);

	srvSocket = SDLNet_TCP_Open(&srcIP);

	while (1) {
		checkConnectionRequests();

		processActivity();
	}

	netQuit();
}

void netMain() {
	SDL_Init(0);
	SDLNet_Init();
}

void netQuit() {
	SDLNet_Quit();
	SDL_Quit();
}

