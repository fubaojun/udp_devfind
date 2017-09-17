#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <rtthread.h>

#include "types/type_def.h"

static FH_SINT32 g_exit = 1;

void sample_udp_devfind_exit()
{
    udp_devfind_stop_server();
}

int udp_devfind(int port)
{

    if (!g_exit) {
        printf("udp_devfind_server is running!\n");
        return 0;
    }
    g_exit = 0;
    udp_devfind_start_server(port);

    return 0;

    /******************************************
     step  10: exit process
    ******************************************/
err_exit:
    sample_udp_devfind_exit();

    return -1;
}

void udp_devfind_exit(void)
{
    printf("udp_devfind_exit is not working correct now!\n");
    return;
    if (!g_exit) {
        g_exit = 1;
        sample_udp_devfind_exit();
    } else {
        printf("vlcview is not running!\n");
    }
}

void udp_devfind_usage(void)
{
	printf("udp_devfind start [port]\n");
	printf("udp_devfind stop\n");
}

int udp_devfind_main(int argc, char ** argv)
{
	int port = 80;

	if (argc == 1)
	{
		//udp_devfind(port);
		udp_devfind_usage();
		return 0;
	}

	if (strcmp(argv[1], "start") == 0)
	{
		if (argc == 3) port = atoi(argv[2]);

		udp_devfind(port);
	}
	else if (strcmp(argv[1], "stop") == 0)
	{
		udp_devfind_exit();
	}
	else
	{
		udp_devfind_usage();
	}

	return 0;
}

#ifdef RT_USING_FINSH
#include <finsh.h>
FINSH_FUNCTION_EXPORT_ALIAS(udp_devfind_main, __cmd_udp_devfind, udp_devfind program);
#endif
