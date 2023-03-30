# Makefile for HackingMiniGames

Hack1: hack1/hack.c hack1/hack.h
	gcc -o Hack1 hack1/hack.c

all: hack1

clean:
	rm -f Hack1
