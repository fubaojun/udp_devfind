#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <rtthread.h>
#include <lwip/sockets.h>
#include <lwip/ip4_addr.h>
//for eth
#include "lwip/netif.h"
#include "wrap.h" 
#define MAXLINE 80 
#define IOT_DEV_FIND_SERV_PORT 1025 

#define BUFSZ	1024

//#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
#  define debug rt_kprintf
#else
#  define debug
#endif

const char *device_find_request = "Are You Smart IOT House Device?";

#define MAC2STR(a) (a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
#define MACSTR "%02x:%02x:%02x:%02x:%02x:%02x"

#define IPSTR "%s"

#define DEVICE_FIND_RESPONSE_HEADER "I'm %s." // %s ===> device_find_response_type
const char *device_find_response_type = "IOT_Camera";

struct udp_devfind_client_context {
    int fd;
    struct sockaddr_in addr;
    int start_play;
};

struct udp_devfind_server_context {
    int stop;
    int fd;
    rt_thread_t thread_id;
    int port;
    struct udp_devfind_client_context *client;
};

static struct udp_devfind_server_context g_server;
static char g_send_buf[1024];

void get_default_if_addr(unsigned char *local_hwaddr,   ip_addr_t *local_ip_addr)
{
    rt_ubase_t index;
    struct netif * netif;

    rt_enter_critical();

    netif = netif_list;

    while( netif != RT_NULL )
    {
        debug("network interface: %c%c%s\n",
                   netif->name[0],
                   netif->name[1],
                   (netif == netif_default)?" (Default)":"");

        debug("\r\n");

        if	(netif == netif_default)
        {
            debug("MAC: ");
            for (index = 0; index < netif->hwaddr_len; index ++)
            {
                debug("%02x ", netif->hwaddr[index]);
                local_hwaddr[index]=netif->hwaddr[index];
            }
            debug("\r\n");

            local_ip_addr->addr = netif->ip_addr.addr;
            debug("ip address: %s\n", ipaddr_ntoa(local_ip_addr));
            debug("\r\n");
        }

        netif = netif->next;
    }

    rt_exit_critical();
}
//station: 00:9a:cd:23:93:ce join, AID = 1
//I'm Light.18:fe:34:fe:a8:64 0.0.0.0
//I'm Light.1a:fe:34:fe:a8:64 192.168.4.1
//I'm Light.1a:fe:34:fe:a8:64 192.168.4.1

void iot_device_find_response(char *prespBuff)
{
    unsigned char hwaddr[6] = {0x11,0x22,0x33,0x99,0x88,0x77};
    ip_addr_t ip_addr;

     // get  MAC ADDR
    get_default_if_addr(hwaddr,   &ip_addr);

    if (prespBuff == NULL) {
        return;
    }

	sprintf(prespBuff, DEVICE_FIND_RESPONSE_HEADER MACSTR " " IPSTR, device_find_response_type,
        MAC2STR(hwaddr), ipaddr_ntoa(&ip_addr));
}

void udp_devfind_server_thread(void *arg)
{ 
    struct udp_devfind_server_context *server = (struct udp_devfind_server_context *) arg;

	struct sockaddr_in servaddr, cliaddr; 
	socklen_t cliaddr_len;
	int sockfd; 
	char buf[MAXLINE]; 
	char str[INET_ADDRSTRLEN]; 
	int i, n; 
	unsigned char flag_broadcast_right = 0;
	
	char DeviceBuffer[80] = "I'm Light.1a:fe:34:12:34:56 192.168.1.230";//this is a demo.
	unsigned short length;
	
	sockfd = Socket(AF_INET, SOCK_DGRAM, 0); 
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(IOT_DEV_FIND_SERV_PORT); 
	Bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)); 
	debug("Accepting connections ...\n"); 
	debug("   UDP     Compile at: %s %s \n", __DATE__, __TIME__);
	while (1)
	{ 
		debug("wait for recv ...\n"); 
		cliaddr_len = sizeof(cliaddr); 
		n = recvfrom(sockfd, buf, MAXLINE, 0, (struct sockaddr *)&cliaddr, &cliaddr_len); 
		if (n == -1) perr_exit("recvfrom error"); 
		debug("received from %s at PORT %d\n", 	\
			inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), \
			ntohs(cliaddr.sin_port));
		
		//查看接收内容
		flag_broadcast_right = 1;//set flag
		for (i = 0; i < n; i++)	{
			putchar(buf[i]); 
			if (buf[i] != device_find_request[i])
			{
				printf("\n\rUDP Server receive a wrong broadcast!\n\r"); 
				flag_broadcast_right = 0;
				break;
			}
		}
		if (flag_broadcast_right == 0)
		{
			continue;// next receive
		}
		printf("\n\rUDP Server receive a right broadcast! \n\r"); 
		iot_device_find_response(DeviceBuffer);
		length = strlen(DeviceBuffer);
		n = sendto(sockfd, DeviceBuffer, length, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr)); 
		if (n == -1) 
			perr_exit("sendto error");
		
		printf("Server response:%s\n\r", DeviceBuffer); 

	} 
	printf("UDP Server Closed !\n\r"); 
	Close(sockfd); 
}

int udp_devfind_start_server(int port)
{
    g_server.stop = 0;
    g_server.port = htons(port);
    g_server.thread_id = rt_thread_create("udp_devfind_server",
                                          udp_devfind_server_thread,
                                          &g_server,
                                          10240,
                                          17,
                                          10);
    if (g_server.thread_id != RT_NULL)
        rt_thread_startup(g_server.thread_id);
    else
        return -1;

    return 0;
}

void udp_devfind_stop_server()
{
	//no used here ,the code is from UDP demo
    g_server.stop = 1;
    if (g_server.client) {
        lwip_close(g_server.client->fd);
        rt_free(g_server.client);
        g_server.client = RT_NULL;
    }
    rt_thread_delete(g_server.thread_id);
    lwip_close(g_server.fd);
}
