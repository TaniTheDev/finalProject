#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "libcurl.lib")

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "appdev.h"
#include <curl/curl.h>


int main(void) {
	rock r;
	srand(time(NULL));
	printf("Application Developers rock! \n");
	printf("Enter you name: ");
	scanf_s("%s", r.rname, (unsigned)_countof(r.rname));
	r.max = rand() % 50 + 51; //rand() print out a number between 0-4m, and % 50 will = 0 - 49
	r.min = rand() % 50 + 1;

	send_data(r);
	printf("Rock 'Roll \n");
	return 0;

}

void send_data(rock  r) {
	CURL* curl;
	CURLcode res;
	char poststr[100];

	sprintf(poststr, "min=%d&max=%d&user=%s", r.min, r.max, r.rname);

	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.cc.puv.fi/~e2202761/appdev.php");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, poststr);
		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
		{
			printf("post to server is faile \n");
			return 1;
		}

		curl_easy_cleanup(curl);
	}
}


