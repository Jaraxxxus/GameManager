#define CURL_STATICLIB
//◊“Œ “Œ Õ≈ “Œ — ÷≈Õ¿Ã»
#include <iostream>
#include<curl\curl.h>
#include<vector>
#include <algorithm>
#include "windows.h"
//#pragma comment(lib,"libcurl.lib")

using namespace std;



string find_Steam_price(string page) {
	int start;
	int finish;
	string res;


	start = page.find("game_purchase_action_bg");
	page = page.substr(start);

	start = page.find("discount_original_price");
	if (start != -1) {
		finish = page.find("discount_final_price", start);
		res = page.substr(start + 25, finish - start - 50);
		return res;
	}

	start = page.find("game_purchase_price price");
	finish = page.find("div class=\"btn_addtocart\">", start);



	if (start != -1 && finish != -1) {
		res = page.substr(start, finish - start);
		start = 0;
		finish = res.find(">");
		res = res.substr(45, finish - 48);
	}
	else res = "0";
	return res;
}


string find_Steam_rate(string page) {
	int start;
	int finish;
	start = page.find("<div class=\"user_reviews_summary_row\"") + 121;
	finish = page.find("% of the");
	string res;
	if (start != -1 || finish != -1) {
		res = page.substr(start + 7, finish - start - 7);
	}


	if (start != -1 && finish == -1) {
		if (res.find("No user reviews") != -1)
			res = "No user reviews";
	}
	cout << res << endl;
	return res;
};

string find_Steam_name(string page) {

	int start;
	int finish;
	start = page.find("<div id=\"appHubAppName\" class=\"apphub_AppName\">");
	finish = page.find("</div>", start);
	//cout << page;
	//start = page.find("<title>");
	//finish = page.find("on Steam");
	string res;
	if (start != -1 || finish != -1) {
		//res = page.substr(start + 7, finish - start - 7);
		res = page.substr(start + 47, finish - start - 47);
	}
	else  return "-1";
	return res;

};


size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
	size_t written = fwrite(ptr, size, nmemb, stream);
	return written;
}



static size_t getResponsetoString(void* contents, size_t size, size_t nmemb, void* userp) {

	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}



std::string downloadHTML(std::string source) {
	CURL* curl;
	CURLcode response;
	std::string str_responce;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, source.c_str());

	Sleep(100);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponsetoString);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_responce);
	response = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	//cout << str_responce << endl;
	string s = str_responce;
	return s;
}




string GetMetaLink(string source) {

	string res;
	string link = source;

	reverse(link.begin(), link.end());

	link = link.substr(1);
	int finish = link.find("/");
	link = link.substr(0, finish);
	reverse(link.begin(), link.end());
	std::transform(link.begin(), link.end(), link.begin(),
		[](unsigned char c) { return std::tolower(c); });
	for (size_t i = 0; i < link.size(); i++) {
		if (link[i] == '_')
			link[i] = '-';


	}
	res = "https://www.metacritic.com/game/pc/" + link;

	return res;


}



vector<string> parse_meta(string source) {
	string link = GetMetaLink(source);
	string page = downloadHTML(link);
	//cout << page << endl;
	int start;
	int finish;
	vector<string> res;
	start = page.find("ratingValue");//+160;
	if (start == -1) {
		res.push_back("no data");

		res.push_back("no data");
		return res;
	}
	string partansw = page.substr(start);
	finish = partansw.find(",");
	start = 0;
	string metascore;
	if (start != -1 || finish != -1) {
		metascore = partansw.substr(start + 16, finish - 50);

	}




	//cout << page;
	start = page.find("<div class=\"metascore_w user");
	if (start != -1) {
		partansw = page.substr(start);

	}
	else {
		res.push_back("no data");

		res.push_back("no data");
		return res;
	}
	start = partansw.find("\">");
	//finish = partansw.find("div");

	string userscore;
	if (start != -1 || finish != -1) {
		userscore = partansw.substr(start + 2, 3);

	}
	res.push_back(metascore);
	res.push_back(userscore);

	//cout << userscore << endl;
	return res;


}




string GetqubicLink(string source) {

	string res;
	string link = source;

	reverse(link.begin(), link.end());

	link = link.substr(1);
	int finish = link.find("/");
	link = link.substr(0, finish);
	reverse(link.begin(), link.end());
	std::transform(link.begin(), link.end(), link.begin(),
		[](unsigned char c) { return std::tolower(c); });
	for (size_t i = 0; i < link.size(); i++) {
		if (link[i] == '_')
			link[i] = '-';


	}
	res = "https://cubiq.ru/gametime/" + link;
	//cout << res;
	return res;


}


vector<string> parsecubiq(string source)
{
	string link = GetqubicLink(source);
	string page = downloadHTML(link);
	int start;
	int finish;
	vector<string> ans;
	//cout << page;
	start = page.find("<meta name=\"description\" content=\"");
	if (start == -1) {
		ans.push_back("no data");
		ans.push_back("no data");
		return ans;
	}
	string partansw = page.substr(start);
	start = partansw.find(".");
	partansw = partansw.substr(start);
	finish = partansw.find("á");
	//˜‡ÒÓ‚ ÏÓÊÂÚ ·˚Ú¸ ·ÓÎ¸¯Â 2ı
	string length1 = partansw.substr(51, finish - 53);
	length1.append(" h. ");
	length1.append(partansw.substr(finish + 3, 2));
	length1.append(" min. ");
	start = partansw.find("∞", 112);
	partansw = partansw.substr(start + 1);
	finish = partansw.find("á");
	string length2 = partansw.substr(0, finish-2);
	length2.append(" h. ");
	length2.append(partansw.substr(finish + 3, 2));
	length2.append(" min. ");
	ans.push_back(length1);
	ans.push_back(length2);

	return ans;

}



string GetHl2b(string source) {

	string res;
	string link = source;

	reverse(link.begin(), link.end());

	link = link.substr(1);
	int finish = link.find("/");
	link = link.substr(0, finish);
	reverse(link.begin(), link.end());
	std::transform(link.begin(), link.end(), link.begin(),
		[](unsigned char c) { return std::tolower(c); });
	size_t j = 0;
	for (size_t i = 0; i < link.size(); i++) {
		if (link[j] == '_') {
			link[j] = '%';
			link.insert(2, "20");
			j += 2;

		}
		else j++;



	}

	string newlink = "howlongtobeat.com/?q=" + link + "#search";
	string page = downloadHTML(newlink);
	cout << page << endl;
	return page;


}

vector<string> parseall(std::string source) {
	auto checkstr = source;
	vector<string> parseresult;
	reverse(checkstr.begin(), checkstr.end());
	if (checkstr.find("/") != 0) {
		parseresult.push_back("-2");
		return parseresult;
	}
	
	string page = downloadHTML(source);
	parseresult.push_back(find_Steam_name(page));
	//cout << "aa";
	if (parseresult[0] == "-1") return parseresult;

	parseresult.push_back(find_Steam_price(page));
	parseresult.push_back(find_Steam_rate(page));
	vector<string> sabvect = parse_meta(source);
	parseresult.push_back(sabvect[0]);
	parseresult.push_back(sabvect[1]);
	sabvect.clear();
	sabvect = parsecubiq(source);
	parseresult.push_back(sabvect[0]);
	parseresult.push_back(sabvect[1]);
	return parseresult;
}






void DownloadBD(string path) {
	CURL* curl;
	FILE* fp;
	CURLcode res;
	char* url = "https://github.com/Jaraxxxus/GameManager/raw/main/myDB.mdb";
	char outfilename[FILENAME_MAX]="";
	strcat(outfilename, path.c_str());
	curl = curl_easy_init();
	if (curl) {
		fp = fopen(outfilename, "wb");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);
		/* always cleanup */
		curl_easy_cleanup(curl);
		fclose(fp);
	}

}
