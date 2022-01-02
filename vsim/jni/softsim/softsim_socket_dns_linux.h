/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of TGT Limited. (C) 2016
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("TGT SOFTWARE")
*  RECEIVED FROM TGT AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. TGT EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES TGT PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE TGT SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. TGT SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY TGT SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND TGT'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE TGT SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT TGT'S OPTION, TO REVISE OR REPLACE THE TGT SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  TGT FOR SUCH TGT SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/


/*****************************************************************************
 *
 * Filename: softsim_socket_dns_linux.h
 *
 * Description:
 *
 * Author: chuan.mei
 * 
 * Date: 2016-07-23
 ******************************************************************************/
#ifndef __SOFTSIM_SOCKET_DNS_LINUX_H__
#define __SOFTSIM_SOCKET_DNS_LINUX_H__

#ifdef __cplusplus
extern "C"{
#endif

/*****************************************************************************
* Include																	   
*****************************************************************************/
#include "softsim_include.h"

#if defined(__SOFTSIM_ANDROID__)
#include <sys/system_properties.h>
#endif
/*****************************************************************************
* Define																	   
*****************************************************************************/
#if defined(__SOFTSIM_ANDROID__)
#define PROP_VALUE_MAX_LEN	(PROP_VALUE_MAX+1)
#else
#define PROP_VALUE_MAX_LEN	(100+1)
#endif

#define PROP_DNS				"net.dns1"
#define PROP_RSIM_DNS			"net.ppp0.dns1"

/*****************************************************************************
* Typedef																	   
*****************************************************************************/

/*****************************************************************************
* Static Local Variable															  
*****************************************************************************/
	 
/*****************************************************************************
* Global Variable														 
*****************************************************************************/
	 
/*****************************************************************************
* Extern Global Variable															
*****************************************************************************/

/*****************************************************************************
* Static Local Function															  
*****************************************************************************/

/*****************************************************************************
* Global Function														
*****************************************************************************/

/*****************************************************************************
* Extern Global Function													  
*****************************************************************************/
extern s32 softsim_get_host_by_name(s32 socket_fd, const char * ifname, const char *domain_name);
extern void softsim_socket_dns_init(SoftsimGetHostNameFunctionCallBack parse_domain_notify);
/****************************************************************************
* Function
****************************************************************************/

#ifdef __cplusplus
		}
#endif

#endif /*__SOFTSIM_SOCKET_DNS_LINUX_H__*/


