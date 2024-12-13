#include <iostream>
using namespace std;

int main() {
	//extremely baisc ad blocker
	//block any http requests that come from a url that contains the word "ad" in it
	string HTTPREQUEST = "GET / HTTP/1.1 Host: www.examade.com User - Agent : Mozilla / 5.0 Accept : text / html, application / xhtml + xml, application / xml;q = 0.9, image / avif, image / webp, */*;q=0.8 Accept-Language: en-GB,en;q=0.5 Accept-Encoding: gzip, deflate, br Connection: keep-alive";
	int begOfURL = HTTPREQUEST.find("Host: ") + 6;
	string rest = HTTPREQUEST.substr(begOfURL, HTTPREQUEST.length() - begOfURL);
	int spaceAfterURL = rest.find(" ")+ HTTPREQUEST.find(rest) + 1; //.find(rest) = beginning of req,
	int lengthOfURL = spaceAfterURL - begOfURL;
	string review = HTTPREQUEST.substr(HTTPREQUEST.find("Host: ") + 6, lengthOfURL);
	if (review.find("ad") != string::npos) {
		cout << "blocked";
	}
	else {
		cout << "passed";
	}
	
	
	return 0;
}