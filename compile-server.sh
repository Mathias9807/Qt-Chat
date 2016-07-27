#!/bin/sh

gcc -o Server net/main.c net/server.c net/def.c `pkg-config --cflags --libs sdl2` -lSDL2_net -std=c99
