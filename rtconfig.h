/* RT-Thread config file */
#ifndef __RTTHREAD_CFG_H__
#define __RTTHREAD_CFG_H__

// <RDTConfigurator URL="http://www.rt-thread.com/eclipse">

// <integer name="RT_NAME_MAX" description="Maximal size of kernel object name length" default="6" />
#define RT_NAME_MAX				16
// <integer name="RT_ALIGN_SIZE" description="Alignment size for CPU architecture data access" default="4" />
#define RT_ALIGN_SIZE				4
// <integer name="RT_THREAD_PRIORITY_MAX" description="Maximal level of thread priority" default="32">
// <item description="8">8</item>
// <item description="32">32</item>
// <item description="256">256</item>
// </integer>
#define RT_THREAD_PRIORITY_MAX		256
// <integer name="RT_TICK_PER_SECOND" description="OS tick per second" default="100" />
#define RT_TICK_PER_SECOND			100
// <integer name="IDLE_THREAD_STACK_SIZE" description="The stack size of idle thread" default="512" />
#define IDLE_THREAD_STACK_SIZE		512

#define RT_DEBUG
// <bool name="RT_THREAD_DEBUG" description="Thread debug enable" default="false" />
// #define RT_THREAD_DEBUG
// <bool name="RT_USING_OVERFLOW_CHECK" description="Thread stack over flow detect" default="true" />
#define RT_USING_OVERFLOW_CHECK
// </section>

// <bool name="RT_USING_HOOK" description="Using hook functions" default="true" />
#define RT_USING_HOOK
// <section name="RT_USING_TIMER_SOFT" description="Using software timer which will start a thread to handle soft-timer" default="true" >
// #define RT_USING_TIMER_SOFT
// <integer name="RT_TIMER_THREAD_PRIO" description="The priority level of timer thread" default="4" />
#define RT_TIMER_THREAD_PRIO	4
// <integer name="RT_TIMER_THREAD_STACK_SIZE" description="The stack size of timer thread" default="512" />
#define RT_TIMER_THREAD_STACK_SIZE	512
// <integer name="RT_TIMER_TICK_PER_SECOND" description="The soft-timer tick per second" default="10" />
#define RT_TIMER_TICK_PER_SECOND	100
// </section>

// <section name="IPC" description="Inter-Thread communication" default="always" >
// <bool name="RT_USING_SEMAPHORE" description="Using semaphore in the system" default="true" />
#define RT_USING_SEMAPHORE
// <bool name="RT_USING_MUTEX" description="Using mutex in the system" default="true" />
#define RT_USING_MUTEX
// <bool name="RT_USING_EVENT" description="Using event group in the system" default="true" />
#define RT_USING_EVENT
// <bool name="RT_USING_MAILBOX" description="Using mailbox in the system" default="true" />
#define RT_USING_MAILBOX
// <bool name="RT_USING_MESSAGEQUEUE" description="Using message queue in the system" default="true" />
#define RT_USING_MESSAGEQUEUE
// </section>

// <section name="MM" description="Memory Management" default="always" >
// <bool name="RT_USING_MEMPOOL" description="Using Memory Pool Management in the system" default="true" />
#define RT_USING_MEMPOOL
// <bool name="RT_USING_MEMHEAP" description="Using Memory Heap Object in the system" default="true" />
#define RT_USING_MEMHEAP
// <bool name="RT_USING_HEAP" description="Using Dynamic Heap Management in the system" default="true" />
#define RT_USING_HEAP
// <bool name="RT_USING_SMALL_MEM" description="Optimizing for small memory" default="false" />
#define RT_USING_SMALL_MEM
// <bool name="RT_USING_SLAB" description="Using SLAB memory management for large memory" default="false" />
 // #define RT_USING_SLAB
// </section>

// <section name="RT_USING_DEVICE" description="Using Device Driver Framework" default="true" >
#define RT_USING_DEVICE
// <bool name=RT_USING_DEVICE_IPC description="Using IPC in Device Driver Framework" default="true" />
#define RT_USING_DEVICE_IPC
// <bool name="RT_USING_SERIAL" description="Using Serial Device Driver Framework" default="true" />
#define RT_USING_SERIAL
// <integer name="RT_UART_RX_BUFFER_SIZE" description="The buffer size for UART reception" default="64" />
#define RT_UART_RX_BUFFER_SIZE    64

// </section>
// <integer name="RT_MMCSD_THREAD_PREORITY" description="The prority of mmcsd thread" default="15" />
#define RT_MMCSD_THREAD_PREORITY	15
// <section name="RT_USING_CONSOLE" description="Using console" default="true" >
#define RT_USING_CONSOLE
// <integer name="RT_CONSOLEBUF_SIZE" description="The buffer size for console output" default="128" />
#define RT_CONSOLEBUF_SIZE			2048
// <string name="RT_CONSOLE_DEVICE_NAME" description="The device name for console" default="uart" />
#define RT_CONSOLE_DEVICE_NAME		"uart1"
// </section>


// <section name="RT_USING_FINSH" description="Using finsh as shell, which is a C-Express shell" default="true" >
#define RT_USING_FINSH
// <bool name="FINSH_USING_SYMTAB" description="Using symbol table in finsh shell" default="true" />
#define FINSH_USING_SYMTAB
// <bool name="FINSH_USING_DESCRIPTION" description="Keeping description in symbol table" default="true" />
#define FINSH_USING_DESCRIPTION
// <integer name="FINSH_THREAD_STACK_SIZE" description="The stack size for finsh thread" default="4096" />
#define FINSH_THREAD_STACK_SIZE	(4096 * 2)
// <bool name="FINSH_USING_MSH" description="Using msh shell" default="true" />
#define FINSH_USING_MSH
// <bool name="FINSH_USING_MSH_DEFAULT" description="use msh as the default shell" default="true" />
#define FINSH_USING_MSH_DEFAULT
// </section>

// <section name="LIBC" description="C Runtime library setting" default="always" >
// <bool name="RT_USING_LIBC" description="Using C library" default="true" />
#define RT_USING_LIBC
// <bool name="RT_USING_PTHREADS" description="Using POSIX threads library" default="true" />
#define RT_USING_PTHREADS
// <bool name="RT_USING_CPLUSPLUS" description="Support C++ programming language" default="true" />
#define RT_USING_CPLUSPLUS

// <bool name="RT_USING_COMPONENTS_INIT" description="Using RT-Thread components initialization" default="true" />
#define RT_USING_COMPONENTS_INIT
// <bool name="RT_USING_USER_MAIN" description="Using main() as user entry" default="true" />
#define RT_USING_USER_MAIN

// <bool name="RT_USING_MODULE" description="Using Application Module" default="true" />
#define RT_USING_MODULE
#define RT_USING_LIBDL

// </section>

// <section name="RT_USING_DFS" description="Device file system" default="true" >
#define RT_USING_DFS
// <bool name="DFS_USING_WORKDIR" description="Using working directory" default="true" />
#define DFS_USING_WORKDIR
// <integer name="DFS_FILESYSTEMS_MAX" description="The maximal number of mounted file system" default="4" />
#define DFS_FILESYSTEMS_MAX	4
// <integer name="DFS_FD_MAX" description="The maximal number of opened files" default="4" />
#define DFS_FD_MAX	16
// <bool name="RT_USING_DFS_ELMFAT" description="Using ELM FatFs" default="true" />
#define RT_USING_DFS_ELMFAT
// <integer name="RT_DFS_ELM_DRIVES" description="The maximal number of drives of FatFs" default="4" />
#define RT_DFS_ELM_DRIVES    4
// <bool name="RT_DFS_ELM_REENTRANT" description="Support reentrant" default="true" />
#define RT_DFS_ELM_REENTRANT
// <integer name="RT_DFS_ELM_USE_LFN" description="Support long file name" default="0">
// <item description="LFN with static LFN working buffer">1</item>
// <item description="LFN with dynamic LFN working buffer on the stack">2</item>
// <item description="LFN with dynamic LFN working buffer on the heap">3</item>
// </integer>
#define RT_DFS_ELM_USE_LFN		3
// <integer name="RT_DFS_ELM_CODE_PAGE" description="OEM code page" default="936">
#define RT_DFS_ELM_CODE_PAGE	437
// <integer name="RT_DFS_ELM_MAX_LFN" description="Maximal size of file name length" default="256" />
#define RT_DFS_ELM_MAX_LFN	256
// <integer name="RT_DFS_ELM_MAX_SECTOR_SIZE" description="Maximal size of sector" default="512" />
#define RT_DFS_ELM_MAX_SECTOR_SIZE  4096
// <bool name="RT_USING_DFS_YAFFS2" description="Using YAFFS2" default="false" />
// #define RT_USING_DFS_YAFFS2
// <bool name="RT_USING_DFS_UFFS" description="Using UFFS" default="false" />
// #define RT_USING_DFS_UFFS
// <bool name="RT_USING_DFS_DEVFS" description="Using devfs for device objects" default="true" />
#define RT_USING_DFS_DEVFS
// <bool name="RT_USING_DFS_ROMFS" description="Using ROMFS" default="false" />
//#define RT_USING_DFS_ROMFS
// </section>

// <section name="RT_USING_LWIP" description="lwip, a lightweight TCP/IP protocol stack" default="true" >
#define RT_USING_LWIP
#define RT_USING_LWIP200

// <bool name="RT_LWIP_ICMP" description="Enable ICMP protocol" default="true" />
#define RT_LWIP_ICMP
// <bool name="RT_LWIP_IGMP" description="Enable IGMP protocol" default="false" />
#define RT_LWIP_IGMP
// <bool name="RT_LWIP_UDP" description="Enable UDP protocol" default="true" />
#define RT_LWIP_UDP
// <bool name="RT_LWIP_TCP" description="Enable TCP protocol" default="true" />
#define RT_LWIP_TCP
// <bool name="RT_LWIP_DNS" description="Enable DNS protocol" default="true" />
#define RT_LWIP_DNS
// <bool name="RT_LWIP_SNMP" description="Enable SNMP protocol" default="false" />
// #define RT_LWIP_SNMP
// <bool name="RT_LWIP_DHCP" description="Enable DHCP client to get IP address" default="false" />
#define RT_LWIP_DHCP

#define LWIP_USING_DHCPD
#define DHCP_DEBUG_PRINTF

// <integer name="RT_LWIP_TCPTHREAD_PRIORITY" description="the thread priority of TCP thread" default="128" />
#define RT_LWIP_TCPTHREAD_PRIORITY	12
// <integer name="RT_LWIP_TCPTHREAD_MBOX_SIZE" description="the mail box size of TCP thread to wait for" default="32" />
#define RT_LWIP_TCPTHREAD_MBOX_SIZE	8
// <integer name="RT_LWIP_TCPTHREAD_STACKSIZE" description="the thread stack size of TCP thread" default="4096" />
#define RT_LWIP_TCPTHREAD_STACKSIZE	4096
// <integer name="RT_LWIP_ETHTHREAD_PRIORITY" description="the thread priority of ethnetif thread" default="144" />
#define RT_LWIP_ETHTHREAD_PRIORITY	14
// <integer name="RT_LWIP_ETHTHREAD_MBOX_SIZE" description="the mail box size of ethnetif thread to wait for" default="8" />
#define RT_LWIP_ETHTHREAD_MBOX_SIZE	8
// <integer name="RT_LWIP_ETHTHREAD_STACKSIZE" description="the stack size of ethnetif thread" default="512" />
#define RT_LWIP_ETHTHREAD_STACKSIZE	512
// <ipaddr name="RT_LWIP_IPADDR" description="IP address of device" default="192.168.1.30" />
#define RT_LWIP_IPADDR0 192
#define RT_LWIP_IPADDR1 168
#define RT_LWIP_IPADDR2 1
#define RT_LWIP_IPADDR3 30
// <ipaddr name="RT_LWIP_GWADDR" description="Gateway address of device" default="192.168.1.1" />
#define RT_LWIP_GWADDR0 192
#define RT_LWIP_GWADDR1 168
#define RT_LWIP_GWADDR2 1
#define RT_LWIP_GWADDR3 1
// <ipaddr name="RT_LWIP_MSKADDR" description="Mask address of device" default="255.255.255.0" />
#define RT_LWIP_MSKADDR0 255
#define RT_LWIP_MSKADDR1 255
#define RT_LWIP_MSKADDR2 255
#define RT_LWIP_MSKADDR3 0
// </section>

// </RDTConfigurator>
// <bool name="RT_USING_CPU_FFS" description="Using CPU instructions for ffs function" default="true" />
#define RT_USING_CPU_FFS

/*
 * Board Config
 */
#define CONFIG_BOARD_IOTCAM
#define CONFIG_CHIP_FH8620
#define CONFIG_PLAT_V2
#define RT_USING_DMA_MEM

#define RT_USING_SDIO
#define RT_USING_SPI
#define RT_USING_I2C
#define RT_USING_WDT
#define RT_USING_GD
#define RT_USING_W25QXX

#define RT_USING_GC1024

/*
 * APP Config
 */
#define WIFI_USING_AP6181

#define RT_USING_LIBVLC
#define RT_USING_SAMPLE_OVERLAY
#define RT_USING_SAMPLE_VENC
#define RT_USING_SAMPLE_VLCVIEW
#define RT_USING_SAMPLE_MJPEG
#define RT_APP_THREAD_PRIORITY        130

/* the number of simultaneously active TCP connections*/
#define RT_LWIP_TCP_PCB_NUM						16
/* TCP sender buffer space */
#define RT_LWIP_TCP_SND_BUF						1024*10
/* TCP receive window. */
#define RT_LWIP_TCP_WND							1024*8

#define RT_LWIP_UDP_PCB_NUM						16
#define MEMP_NUM_NETCONN						32

#ifdef RT_LWIP_DHCP
    #define IP_SOF_BROADCAST                     1
    #define IP_SOF_BROADCAST_RECV                0
#endif
/* the number of blocks for pbuf */
#define RT_LWIP_PBUF_NUM						32
/* the number of simultaneously queued TCP */
#define RT_LWIP_TCP_SEG_NUM   					40

#define LWIP_TCP_KEEPALIVE						1

/* LWIP_SO_RCVBUF==1: Enable SO_RCVBUF processing.*/
#define LWIP_SO_RCVBUF           			  	1

/* If LWIP_SO_RCVBUF is used, this is the default value for recv_bufsize.*/
#define RECV_BUFSIZE_DEFAULT       			8192
#define SO_REUSE                              	1

#ifndef __ASSEMBLY__
#include "platform_def.h"
#endif

#define RT_USING_LUA
#define RT_LUA_OPTRAM
#define LUA_NUMBER_INTEGRAL

//#define RT_LUALIB_UNSING_USER_NET

#define RT_USING_WIFI

#endif
