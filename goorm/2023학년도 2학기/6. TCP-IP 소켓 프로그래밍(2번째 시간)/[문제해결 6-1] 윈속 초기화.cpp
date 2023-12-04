#include <WinSock2.h>
#include <stdio.h>
#include <iostream>
#pragma comment(lib, "ws2_32")

typedef struct WSAData {
    WORD    wVersion;
    WORD    wHighVersion;
    char    szDescription[WSADESCRIPTION_LEN + 1];
    char    szSystemStatus[WSASYS_STATUS_LEN + 1];
    unsigned short iMaxSockets;
    unsigned short iMaxUdpDg;
    char FAR* IpVendorInfo;
} WSADATA, FAR* LPWSADATA;

using namespace std;

int main() {
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);  // Fix the typo here, change "wasdata" to "wsadata"

    cout << "wHighVersion:" << hex << wsadata.wHighVersion << endl;
    cout << "wVersion:" << hex << wsadata.wVersion << endl;
    cout << "szDescription:" << wsadata.szDescription << endl;
    cout << "szSystemStatus:" << wsadata.szSystemStatus << endl;

    cout << "iMaxSocket:" << dec << wsadata.iMaxSockets << endl;  // Use "dec" for decimal output
    cout << "iMaxUdpDg:" << dec << wsadata.iMaxUdpDg << endl;  // Use "dec" for decimal output

    WSACleanup();
    return 0;
}
