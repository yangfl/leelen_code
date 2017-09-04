/********************************************************************************
**
** �ļ���:     leelen_protocol.h
** ��Ȩ����:   (c) 2015 �������ֿƼ����޹�˾
** �ļ�����:   ʵ��ͨѶЭ�鹦��
**
*********************************************************************************
**             �޸���ʷ��¼
**===============================================================================
**| ����       | ����   |  �޸ļ�¼
**===============================================================================
**| 2015/09/28 | zzh    |  �������ļ�
**
*********************************************************************************/

#ifndef LEELEN_PROTOCOL_H
#define LEELEN_PROTOCOL_H

#ifdef __cplusplus
extern "C" {
#endif



/*
********************************************************************************
* ����status
********************************************************************************
*/
#define STS_RUNNING     0x80              /* ����״̬ */


/*
********************************************************************************
* �������ݽṹ
********************************************************************************
*/
typedef struct {
    uint8_t   status;                    /* ״̬ */
    void      (*informer)(RESULT_E);     /* �ص�֪ͨ���� */ 
} protoco_send_t;


typedef struct {
    uint8_t   *loc_usr;                  /* �����û� */
    uint8_t   *loc_ip;                   /* ����IP   */
    uint8_t   *rem_usr;                  /* �Է��û� */
    uint8_t   *rem_ip;                   /* ����IP   */
} addr_info_t;


typedef struct {
    uint8_t       name_len;              /* ���Ƴ��� */
    uint8_t       *name;                 /* ���� */
} name_t;


/*
********************************************************************************
* ����ö�ٽṹ
********************************************************************************
*/
typedef enum
{
    UDP_CALLBACK_REMOTE_SET_SECURITY = 0x453a0002,
    UDP_CALLBACK_INFO = 0X453A0504
}UDP_CALLBACK_E;

typedef void (*udp_callback)(UDP_CALLBACK_E,unsigned long);
/*******************************************************************
** ������:     get_version
** ��������:   �汾��,����Э��̽��
** ����:       ��
** ����:       ��
********************************************************************/
uint8_t* get_version(void);

/*******************************************************************
** ������:     init_protocol
** ��������:   ģ���ʼ������
** ����:       [in] ver:  ϵͳ�汾��,����Э��̽��
**            [in]callback���ص�֪ͨ����
** ����:       ��
********************************************************************/
void init_protocol(char *version,udp_callback callback);

/*******************************************************************
** ������:     uninit_protocol
** ��������:   ģ��ȥʼ������
** ����:       ��
** ����:       ��
********************************************************************/
void uninit_protocol(void);

#ifdef __cplusplus
}
#endif

#endif          /* end of LEELEN_PROTOCOL_H */
