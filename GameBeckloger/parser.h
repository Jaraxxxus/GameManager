#pragma once
#define CURL_STATICLIB

#include <iostream>
#include<curl\curl.h>
#include<vector>
using namespace std;

string find_Steam_price(string page);

string find_Steam_rate(string page);

string find_Steam_name(string page);

static size_t getResponsetoString(void* contents, size_t size, size_t nmemb, void* userp);

std::string downloadHTML(std::string source);

string GetMetaLink(string source);

vector<string> parse_meta(string source);

string GetqubicLink(string source);

vector<string> parsecubiq(string source);

vector<string> parseall(std::string source);

void DownloadBD(string path);