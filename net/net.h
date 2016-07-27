#ifndef NET_H
#define NET_H


#ifdef __cplusplus
extern "C" {
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

#include "def.h"

#define SRV_TIMEOUT	2000
#define NET_NAME_LEN	64

typedef enum {
	CTYPE_EMPTY = 0,
	CTYPE_CONN_INFO
} CType;

typedef struct {
	uint32_t type;		// What type of data is sent
	uint32_t payload;	// How many bytes are sent
} CPacket;

typedef struct {
	IPaddress ip;
	TCPsocket socket;

	char name[NET_NAME_LEN];
} Client;

bool clnConnect(const char* ip, int port, const char* name);

void srvMain();

void netMain();
void netQuit();

#ifdef __cplusplus
}
#endif


#endif // NET_H
