/********************************************************************************
**
** 文件名:     leelen_hdlpkt.c
** 版权所有:   (c) 2015 厦门立林科技有限公司
** 文件描述:   实现对接收数据处理
**
*********************************************************************************
**             修改历史记录
**===============================================================================
**| 日期       | 作者   |  修改记录
**===============================================================================
**| 2015/09/28 | zzh    |  创建该文件
**
*********************************************************************************/


#include "leelen_comdef.h"
#include "leelen_packet.h"
#include "leelen_hdlpkt.h"


/*
********************************************************************************
* 参数定义
********************************************************************************
*/
#define MAX_HANDLER                          100     /* 注册表项的最大个数 */


/*
********************************************************************************
* 模块局部变量定义
********************************************************************************
*/
static int             s_used;
static handle_table_t  s_handle_table[MAX_HANDLER];



/*******************************************************************
** 函数名:     find_handler
** 函数描述:   在通过命令字注册表中查找处理函数
** 参数:       [in]  cmd_type: 命令字   
** 返回:       如找到, 则返回注册表中的索引号; 否则, 返回-1
********************************************************************/
static int find_handler(uint16_t cmd_type)
{
    int i;
    
    for (i = 0; i < s_used; i++) {
        if (cmd_type == s_handle_table[i].cmd_type){
            return i;
        }
    }
    return -1;
}

/*******************************************************************
** 函数名:     regist_pkt_handler
** 函数描述:   注册钩子处理函数
** 参数:       [in]  cmd_type:   命令字类型
**             [in]  param:      有参应答标志
**             [in]  handler:    数据处理函数
** 返回:       无
** 注意:       0x00业务类型保留用于网络寻址协议
********************************************************************/
void regist_pkt_handler(uint16_t cmd_type, bool_t param, uint8_t (*handler)(uint8_t *, int, packet_t *))
{
    LEE_ASSERT(handler != NULL);
    LEE_ASSERT(find_handler(cmd_type) == -1);                   /* 已存在处理函数 */
    LEE_ASSERT(s_used < MAX_HANDLER);

    s_handle_table[s_used].cmd_type = cmd_type;
    s_handle_table[s_used].param    = param;
    s_handle_table[s_used].handler  = handler;

    s_used++;
}

/*******************************************************************
** 函数名:     req_hdlparam
** 函数描述:   在通过命令字注册表中查找处理函数是有参数应答否
** 参数:       [in]  cmd_type: 命令字   
** 返回:       true需要,false不需要
********************************************************************/
bool_t req_hdlparam(uint16_t cmd_type)
{
    int i;
    
    for (i = 0; i < s_used; i++) {
        if (cmd_type == s_handle_table[i].cmd_type){
            return s_handle_table[i].param;
        }
    }
    return false;
}

/*******************************************************************
** 函数名:     req_hdlpkt
** 函数描述:   请求协议的处理
** 参数:       [in]data:      接收到的数据；
**             [in]data_len： 接收到数据的长度
**             [in]packet：   包参数
** 返回:       处理结果
** 注意:       返回0, 找不到处理协议函数或其他问题
********************************************************************/
uint8_t req_hdlpkt(uint8_t *data, int data_len, packet_t *packet)
{
    uint8_t result = 0;
    int index;

    LEE_ASSERT(data != NULL || data_len != 0);

    index = find_handler(packet->cmd_type);                                          /* 查找注册的处理函数 */
    if (index != -1) {   
        result = s_handle_table[index].handler(data, data_len, packet);
    }
    return result;
}


/*******************************************************************
** 函数名:     init_hdlpkt
** 函数描述:   模块初始化函数
** 参数:       无
** 返回:       无
********************************************************************/
void init_hdlpkt(void)
{
    s_used = 0;
}




