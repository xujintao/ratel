#include "BaseHandler.h"


BaseHandler::BaseHandler()
{
}


BaseHandler::~BaseHandler()
{
}

void BaseHandler::ResponseError()
{
	out << \
		"Status: 500 Internal Server Error\n"\
		"Content-Type: text/html; charset=utf-8\r\n\r\n"\
		"<!DOCTYPE html>"\
		"<html lang='en'>"\
		"<head>"\
		"<title>ERR_NO_API</title>"\
		"</head>"\
		"<body>"\
		"<h1>ERR_NO_API</h1>"\
		"</body>"\
		"</html>";
}

void BaseHandler::ResponseOpenAPI()
{
	out << \
		"Status: 200 OK\n"\
		"Content-Type: text/html; charset=utf-8\r\n\r\n"\
		"<!DOCTYPE html>"\
		"<html lang='en'>"\
		"<head>"\
		"<title>/OpenAPI/WeTest</title>"\
		"</head>"\
		"<body>"\
		"<h1>/OpenAPI/WeTest</h1>"\
		"</body>"\
		"</html>";
}

void BaseHandler::ResponseUserAuth()
{
	out << \
		"Status: 200 OK\n"\
		"Content-Type: text/html; charset=utf-8\r\n\r\n"\
		"<!DOCTYPE html>"\
		"<html lang='en'>"\
		"<head>"\
		"<title>/UserAuth/LoginByToken</title>"\
		"</head>"\
		"<body>"\
		"<h1>/UserAuth/LoginByToken</h1>"\
		"</body>"\
		"</html>";
}