/*************************************************************************
	> File Name: demo1.c
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2021年04月29日 星期四 01时35分04秒
 ************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define true 1
#define false 0
typedef unsigned int bool;
//size_t function( void *ptr, size_t size, size_t nmemb, void *stream)
size_t readData( void *ptr, size_t size, size_t nmemb, void *stream)
{
	char buf[10240] = {'\0'};
	strncpy(buf, ptr, 1024);
	printf("========get data============\n");
	printf("%s\n",buf);
}

bool postUrl()
{
    CURL *curl;
    CURLcode res;
	char *postString ;
    char img1[12];
	char img2[12];

	char *key = "7ob5UUBALgGWe823YBDiwB";
	char *secret = "e62a4b2344d24fab82eb397e4fd3c660";
	int typeId = 21;
	char *format = "xml";
	
	postString = (char *)malloc(strlen(key) + strlen(secret) + 2048);
	
	sprintf(postString, "img1=%s&img2=%s&key=%s&secret=%s&typeID=%d&format=%s", "", "",key, secret, 21, format);
	
	system("base64 iu1.JPG > tmpFile");
	int fd = open("./tmpFile", O_RDWR);
	int filelen = (fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	char *buf = (char *)malloc(filelen + 10);
	memset(buf, 0, filelen + 10);
	read(fd, buf, filelen);
	printf("file=%s\n",buf);
	close(fd);
/*
	system("base64 047_2.JPG > tmpFile");
	fd = open("./tmpFile", O_RDWR);
	filelen = (fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	char *bufpic2 = (char *)malloc(filelen + 10);
	memset(bufpic2, 0, filelen + 10);
	read(fd, bufpic2, filelen);
	close(fd);	
	int len = strlen(key) + strlen(secret) + strlen(bufpic1) + strlen(bufpic1) + 124;
	postString = (char *)malloc(len);
	memset(postString, '\0', len);
	sprintf(postString, "img1=%s&img2=%s&key=%s&secret=%s&typeID=%d&format=%s", "bufpic1", "bufpic2",key, secret, 21, format);
*/	
    curl = curl_easy_init();
	if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/tmp/cookie.txt"); // 指定cookie文件
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postString);    // 指定post内容
        curl_easy_setopt(curl, CURLOPT_URL, "https://netocr.com/api/faceliu.do");   // 指定翔云的url
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, readData); //将返回的http头输出到fp指向的文件
        res = curl_easy_perform(curl);
		printf("OK:%d\n",res);

        curl_easy_cleanup(curl);
    }
    return true;
}
int main(void)
{
    postUrl();
	return 0;
}
