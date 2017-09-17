/*
 *  This file is part of FH8620 BSP for RT-Thread distribution.
 *
 *	Copyright (c) 2016 Shanghai Fullhan Microelectronics Co., Ltd.
 *	All rights reserved
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *	Visit http://www.fullhan.com to get contact with Fullhan.
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include <msh.h>

//for eth
#include "lwip/netif.h"
void print_if(void);

int main(int argc, char** argv)
{
	int ret = 0;
	int fd;
	int fd_sd;
	char cmd[]		= "/init.sh";
	char cmd_sd[]	= "/sdcard/init.sh";

	char author[] = "baojun.fu";
	char e_mail[] = "fubaojun2006@139.com";
	printf("***********************************************************\n");
	printf("\n");
	printf("   Hello      Compiled by %s      \n", author);           
	printf("   IOT        E-mail: %s       \n", e_mail);              
	printf("   Camera     Compile at: %s %s \n", __DATE__, __TIME__); 
	printf("------======Startup Success======--------                  \n");
	printf("***********************************************************\n");

	fd = open(cmd, O_RDONLY, 0);
	fd_sd = open(cmd_sd, O_RDONLY, 0);
	if (fd >= 0)
	{
		close(fd);

		printf("exec %s ...\n", cmd);
		msh_exec(cmd, sizeof(cmd));
	}else if (fd_sd >= 0)
	{
		close(fd_sd);

		printf("exec %s ...\n", cmd_sd);
		msh_exec(cmd_sd, sizeof(cmd_sd));
	}
	else
	{
		ret = -1;
		printf("Can not exec %s and %s. Something is ERROR!\n\n", cmd, cmd_sd);
	}

	if (ret==0)
	{
		printf("\n------======exec main init Success======--------\n");
	}
	sys_msleep(2000);//sleep here , wait for wifi IP address
	print_if();

	return 0;
}

void print_if(void)
{
    rt_ubase_t index;
    struct netif * netif;

    rt_enter_critical();

    netif = netif_list;

    while( netif != RT_NULL )
    {
        rt_kprintf("network interface: %c%c%s\n",
                   netif->name[0],
                   netif->name[1],
                   (netif == netif_default)?" (Default)":"");
        rt_kprintf("MTU: %d\n", netif->mtu);
        rt_kprintf("MAC: ");
        for (index = 0; index < netif->hwaddr_len; index ++)
            rt_kprintf("%02x ", netif->hwaddr[index]);
        rt_kprintf("\nFLAGS:");
        if (netif->flags & NETIF_FLAG_UP) rt_kprintf(" UP");
        else rt_kprintf(" DOWN");
        if (netif->flags & NETIF_FLAG_LINK_UP) rt_kprintf(" LINK_UP");
        else rt_kprintf(" LINK_DOWN");
        if (netif->flags & NETIF_FLAG_ETHARP) rt_kprintf(" ETHARP");
        if (netif->flags & NETIF_FLAG_IGMP) rt_kprintf(" IGMP");
        rt_kprintf("\n");
        rt_kprintf("ip address: %s\n", ipaddr_ntoa(&(netif->ip_addr)));
        rt_kprintf("gw address: %s\n", ipaddr_ntoa(&(netif->gw)));
        rt_kprintf("net mask  : %s\n", ipaddr_ntoa(&(netif->netmask)));
        rt_kprintf("\r\n");

        netif = netif->next;
    }

    rt_exit_critical();
}
