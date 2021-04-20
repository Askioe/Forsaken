#pragma once


class DiscordRequests {
public:
	//int JoinServer(std::string Token, std::string Invite);

	//int DiscordSendMessage(std::string token, std::string channel, std::string message);

	int WebhookSendMessage(std::string webhook, std::string message);
};