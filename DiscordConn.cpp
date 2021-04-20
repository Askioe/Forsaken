#include "cpr/cpr.h"
#include <string>
#include "DiscordConn.h"
using cpr::Header;
using cpr::Url;
using cpr::Response;
using cpr::Payload;
using cpr::Post;
using cpr::Get;

//Allows for token to connect to Discord and attempts to join an invite via cpr and url.
//int DiscordRequests::JoinServer(std::string Token, std::string Invite)
//{
//    const char* url = "https://discord.com/api/v7/invite/";
//    std::string buf(url);
//    buf.append(Invite);
//    buf.append("?with_counts=true");
//    Header blahtoken = Header{ { "Authorization", Token } };
//    Response r = Post(Url{ buf }, Header{ {"content-type", "application/json"} }, blahtoken);
//    return r.status_code;
//}
//
////Allows for token to connect to Discord and sending messages with https
//int DiscordRequests::DiscordSendMessage(std::string Token, std::string channel, std::string message)
//{
//    const char* url2 = "https://discord.com/api/v6/channels/";
//    std::string combined(url2);
//    combined.append(channel);
//    combined.append("/messages");
//    Header blahtoken = Header{ { "Authorization", Token } };
//
//    Payload paymoneywubby = Payload{ {"content", message} };
//    Response r = Post(Url{ combined }, Header{ {"content-type", "application/json"} }, blahtoken, paymoneywubby);
//    return r.status_code;
//}


int DiscordRequests::WebhookSendMessage(std::string webhook, std::string message)
{

    //Payload paymoneywubby = Payload{ {"content", message} };
    Response r = Post(Url{ webhook }, Payload{ {"content", message}}); //Header{ {"content-type", "application/json"} }, paymoneywubby);
    return r.status_code;
}
