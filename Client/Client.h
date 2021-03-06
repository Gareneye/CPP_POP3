#pragma once

#include <map>
#include <vector>
#include <functional>
#include <string>
#include <iostream>

#include "NetworkClient.h"
#include "Utilities.h"

#define MOTD "== Welcome in POP3 Client ==\n[Client is running]\n[Type /help for more info]\n\n"
#define SERVER_IP "localhost"
#define DEBUG TRUE

class Client;

typedef void(*Command)(Client *, std::vector<std::string>);

class Client
{
public:
	Client();
	virtual ~Client() {};

	void disable();

	static void userCmd(Client*, std::vector<std::string>);
	static void helpCmd(Client*, std::vector<std::string>);
	static void quitCmd(Client*, std::vector<std::string>);
	static void noopCmd(Client*, std::vector<std::string>);
	static void connectCmd(Client*, std::vector<std::string>);
	static void passCmd(Client*, std::vector<std::string>);
	static void listCmd(Client*, std::vector<std::string>);
	static void statCmd(Client*, std::vector<std::string>);
	static void retrCmd(Client*, std::vector<std::string>);
	static void deleCmd(Client *, std::vector<std::string>);
	static void rsetCmd(Client *, std::vector<std::string>);

	enum Status { AUTHORIZATION, TRANSACTION, UPDATE };

private:
	bool isWorking;
	NetworkClient network;
	Status status;
};

