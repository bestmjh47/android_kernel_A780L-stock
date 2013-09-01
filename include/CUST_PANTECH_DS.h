#ifndef __CUST_PANTECH_DS_H__
#define __CUST_PANTECH_DS_H__
/* ========================================================================
FILE: cust_pantech_ds.h

Copyright (c) 2011 by PANTECH Incorporated.  All Rights Reserved.

USE the format "FEATURE_LGT_DS_XXXX"
=========================================================================== */ 

/*===========================================================================

                      EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  when        	who     what, where, why
--------   	---      ----------------------------------------------------------
11/09/30    sjm   	  initial
11/12/22    phi   	  move to EF46L from EF65L. 
11/12/30    Alice     delete some of feature not yet adapted.
12/01/13    Alice     change file name. : Cust_pantech_data_linux.h -> CUST_PANTECH_DS.h

===========================================================================*/

/*===========================================================================*/
  //4!!ATTENTION!!
/*===========================================================================*/
/*------------------------------------------------------------------------------------

  1. must record history in this file header when you modify this file.

  2. FEEATUR's name start with "FEATURE_LGT_DS_xxx".
  
  3. each FEATURE is need to detailed description. because this file is instad of Feature Specification.
        - Item, Comment(Date, Author), Reason, Modified Files, Added Files, Deleted Files.

  4. In Java Code, Feature' exprssion is comment.
        - Exmaple. // FEATURE_LGT_DS_COMMON
        
--------------------------------------------------------------------------------------*/

/*===========================================================================
    Data Service Features
===========================================================================*/

/* 20120105 Alice : Common import, include.. etc. */
#define FEATURE_LGT_DS_COMMON

#ifdef FEATURE_LGT_DS_COMMON
/* -----------------------------------------------------------------------------------*/
    //3 Android & QCT Bug Fix
/*-------------------------------------------------------------------------------------*/

/* Item : Method - startusingnetworkfeature()
       Commnet - 20120109 Alice
	Reason - return value check before reconnect() belong to  startUsingNetworkFeature().
	                 -> do not return Phone.APN_REQUEST_STARTED unconditional.
	Modified files - ConnectivityService.java(\android\frameworks\base\services\java\com\android\server)
*/
#define FEATURE_LGT_DS_BUG_FIX_STARTUSINGNETWORKFEATURE

/* Item : Settings >> Data Usage
 	Commnet - 20120224 phi
  	Reason - set to Data Usage >> Set mobile data limit >> Restrict background data,
                UID/SYS_UID's setting is processed one by one as android's source architetecture.
                on the way setting if user request App., occur ANR(Application Not Responsding).
  	           - merge from EF45K
 	Modified files - NetworkPolicyManagerService.java(android\frameworks\base\services\java\com\android\server\net)
*/
#define FEATURE_SKY_DS_BACKGROUND_RESTRICT_BUG_FIX

/* Item : IPTABLEV6
 	Commnet - 20120224 phi
  	Reason - /system/bin/iptables's permission is set to system permission. 
  	             on the other hands ip6tables's permission is set to shell permission.
  	             and change ip6tables's permission to system permission.
  	          - merge from EF45K
 	Modified files - android_filesystem_config.h (android\system\core\include\private)
*/
#define FEATURE_SKY_DS_IP6TABLE_UID_BUG_FIX

/* Item : Tethering, Hotspot
 	Commnet - 20120315 Yoonjunho
  	Reason - When we use USB Tethering or WIFI Hotspot service,
  	         if google dns address is used in that service then we can not connect to some web site
  	       - merge EF45K modification.
  	       - include FEATURE_P_VZW_DS_TETHERING_EXCEPTION
 	Modified files - ConnectivityService.java(\android\frameworks\base\services\java\com\android\server),
 	                      Tethering.java(\android\frameworks\base\services\java\com\android\server\connectivity)
*/
#define FEATURE_SKY_DS_SET_TETHERED_DNS

/* Item : Data Connection
 	Commnet - 20120315 Yoonjunho
  	Reason - When we start CS call, data state is changed to disconnect state
  	       - In qcril_qmi_nas_request_data_registration_state(), preferred data tech is changed from LTE to WCDMA
  	       - modified to reload preferred data tech just before use
  	       - merge EF47S modification
 	Modified files - qcril_qmi_nas.c(\android\vendor\qcom\proprietary\qcril\qcril_qmi)
*/
#define FEATURE_SKY_DS_FIX_RADIO_TECH_UNKOWN_IN_CS



/* Item : Data Connection
 	Commnet - 20120326 Yoonjunho
  	Reason -LCD �� ���� ��� data ����Ǿ� ���� ������ data ���� �õ��ϸ�(setup ����üũ�� trysetupdata���� ó���ǹǷ� state ���� üũ�� ������.), LCD on �����̰� data ����õ� ������ ��� �̸� fail ó�� �κп��� retry timer �� reset ���Ѽ� retry timer ���� ũ�� �������� �ʰ���.
  	            - merge EF45K modification
 	Modified files - DataConnectionTracker.java(\android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_SKY_DS_IMMEDIATE_SETUP


/* Item : DNS
 	Commnet - 20120404 Alice
  	Reason - Code Bug fix about DNS setting.
 	Modified files - ConnectivityService.java(\android\frameworks\base\services\java\com\android\server)
*/
#define FEATURE_LGT_DS_DNS_IDX_BUG_FIX



/*20111005 sjm
- ACTION_ANY_DATA_CONNECTION_STATE_CHANGED �� phoneStateListener ���� �켱 ó���ǵ��� ����.
- PhoneStateListeneró������ syncronized ���� intent action broadcasting ���� �ʴ� ��� 1ȸ �߻�.
- TelephonyRegistry.java
*/
#define FEATURE_LGT_DS_DATA_CON_INTENT_FAST_BROADCASTING


/*
//20111111 sjm
- startUsingNetworkFeature���� Reconnect ȣ��� Fail�� �߻��Ͽ��� Phone.APN_REQUEST_STARTED�� �����Ͽ� Application�� ȥ���� ������
- ConnectivityService.java
*/
#define FEATURE_LGT_DS_BUG_FIX_STARTUSINGNETWORKFEATURE

/*
    - status bar �� LTE ���� 1xICON �������� ����.
    - 3G/4G ������ ���� ���� �������ε� 1xRTT Ȥ�� UNKNOWN ���� ���� ��� ���� ���°� �����ϰ�, state change �� �� noti�ϵ��� ó��.
   - telephonyregistry.java
   - LGU+�� 1xRTT �������� �����Ƿ� ���� ����!!!
   - 65l merge

*/
#define FEATURE_LGT_DS_DATA_AVOID_1X_ICON_DURING_4G_CONNECTED

/*
    Item:  cdmaltesetvicestate  ���� ���� 
    Commnet -20120613 jsmin
    Reason  - cmdaServicestate �� ����� radio tech evdo �ȿö���� ���� 
                - dun �������Ϸ� ���� �ϴ� ���� ���� ����

 Modified fies-
                   \android\frameworks\base\telephony\java\com\android\internal\telephony\cdma\CdmaServiceStateTracker.java
                   \android\frameworks\base\telephony\java\com\android\internal\telephony\cdma\CdmaDataProfileTracker.java
*/
#define FEATURE_LGU_DS_RADIOTECH_EVDO

#define FEATURE_LGT_DS_RMNET_CRASH

#ifdef FEATURE_LGT_DS_RMNET_CRASH
/* Item : rmnet crash
	Commnet - 20120412 Alice
	Reason - rmnet crash, failure to establish data connection during voice testing.
	           - QCT SR Case 00821603 :CR 350813
	Modified files - netmgr_tc.c(android\linux\vendor\qcom\proprietary\data\netmgr\src)
*/
#define FEATURE_LGT_DS_RMNET_CRASH_CR350813

/* Item : rmnet crash
	Commnet - 20120413 Alice
	Reason - The main reason for these recent netmgrd crashes is because of enabling the QoS feature 
	             by default in recent builds. If the you don't require the QoS feature then disabling it 
	             in your build might be the quickest way to resolve these problems temporarily.
	           - persist.data.netmgrd.qos.enable = false
	           - From STARQ.
	Modified files - netmgr_main.c(android\linux\vendor\qcom\proprietary\data\netmgr\src)
*/
#define FEATURE_LGT_DS_RMNET_CRASH_PROPERTY_DISABLED

#endif /* FEATURE_LGT_DS_RMNET_CRASH */

/* Item : TCP Buffer
 	Commnet - 20120413 Alice
  	Reason - It doesn't exist TCP buffer size about EHRPD. 
  	             TCP Buffer size is choosen default size when connected to data in EHRPD.
  	             It's derived to change radio technology from EHRPD to LTE. because of keeping
  	             in Defualt TCP Buffer size.
  	          - modify to change TCP Buffer size
  	          - From EF45K.
 	Modified files - MobileDataStateTracker.c(\android\frameworks\base\core\java\android\net)
*/
#define FEATURE_SKY_DS_SET_TCPBUF_IN_RAT_CHANGE

/* -----------------------------------------------------------------------------------*/
    //3    LGU+ Request
/*-------------------------------------------------------------------------------------*/


/* Item : DHCP
	Commnet - 20120227 Alice
	Reason - Since default DHCP Lease Time is 1 hour, 
	             VPN, RMNET and android Tethering are disconnected frequently. 
	             So, Increase the DHCP Lease Time to 7 days
	Modified files - TetherController.cpp (android\system\netd) 
*/
#define FEATURE_LGT_DS_INCREASE_DHCP_LEASETIME

/* DUN */
#define FEATURE_LGT_DS_DUN

#ifdef FEATURE_LGT_DS_DUN

/* Item : TYPE_DUN Timer inactivity.
	Commnet - 20120105 Alice
	Reason - do not work Inactivity Timer when TYPE_DUN
	           - also TYPE_IMS
	Modified files - ConnectivityService.java(\android\frameworks\base\services\java\com\android\server)
*/
#undef FEATURE_LGT_DS_DISABLE_INACTIVITY_TIMER   //#define FEATURE_LGT_DS_DISABLE_INACTIVITY_TIMER



/*Item : DUN
 	Commnet - 20120111 Alice
 	Reason - 1.QualcommSetting ���丮�� �ִ� ���ϵ��� user mode �� ������� �����Ƿ�, dun, sync manager, data manger, curi explore�� ������� ����.
        			2./dev/pantech�� File Write ���� �ο� �� CTS Fail �߻��Ͽ� /dev/pantech ���� ���� 
        			3. DUN_FIFO_FILE for DUN /data/dun -> /dev/pantech/dun
        			4.QualcommSetting �� ������ patch�� ���� �����Ǿ��ٸ�, �̵��� ���ϵ鵵 ���� ������ �־�� ��.   
        			5.  dun service start �ϰ�, Dun_Autoboot.java������ ���� start �ϴ� �κ��� ����.

 	Modified files - init_EF46L.rc(android\system\core\rootdir), Android.mk(android\frameworks\base),
 				 AndroidManifest.xml (android\packages\apps\phone),
 				 DUN_Autoboot.java
 				 
	Added files - SkyPhoneBroadcastReceiver.java (android\packages\apps\phone\src\com\android\phone)
              		  IDun.aidl ->  ISkyDun.aidl (android\frameworks\base\telephony\java\com\android\internal\telephony),
              		  DunService.java -> SkyDunService.java (android\packages\apps\phone\src\com\android\phone)


   Commnet - 20120307 Alice
 	Reason - DUN service is working in user build mode. and this feature is unnecessariness.

 	Modified files - init_EF46L.rc(android\system\core\rootdir), Android.mk(android\frameworks\base),
           				 AndroidManifest.xml (android\packages\apps\phone),
           				 DUN_Autoboot.java (android\vendor\qcom\proprietary\qulacommsettings\src\com\android\qualcommsettings),
           				 SkyPhoneBroadcastReceiver.java (android\packages\apps\phone\src\com\android\phone)              		  
*/
#undef FEATURE_LGT_DS_DUN_USER_MODE//#define FEATURE_LGT_DS_DUN_USER_MODE

#endif /* FEATURE_LGT_DS_DUN */

/* Item : TCP sync retries
	Commnet - 20120104 Alice
	Reason - change RTO and TCP_SYN_RETRIES when TCP syn transfer
	           - tcp resync nymber is 5.(first transfer, 1s, 2s, 4s, 8s)
	Modified files - tcp.h(android\kernel\include\net),
	                      tcp_output.c(android\kernel\net\ipv4)
*/
#define FEATURE_LGT_DS_TCP_SYN_RETRANSMIT

/* Item : DNS
	Commnet - 20120111 Alice
	Reason - do not query DNS IPv6.
	Modified files - getaddrinfo.c(android\bionic\libc\netbsd\net)
*/
#define FEATURE_LGT_DS_IPV6_DNS_QUERY

/* EVDO/EHRPD Error */
#define FEATURE_LGT_DS_EVDO_ERROR

#ifdef FEATURE_LGT_DS_EVDO_ERROR
/* Item : EVDO/EHRPD Error
	Commnet - 20120113 Alice
	Reason - In AMSS side found out EVDO/EHRPD Error, 
	             write EVDO/EHRPD error cause to property_set(ril.cdma.errorcause) in QCRIL.
	Modified files - Dsc_qmi_wds.c(\android\vendor\qcom\proprietary\data\dss\src),
	                       Dsc_qmi_wds.h(\android\vendor\qcom\proprietary\data\dss\src),
	                       Qcril_data_netctrl.c(\android\vendor\qcom\proprietary\qcril\common\data), 
	                       Qmi_wds_srvc.h(\android\vendor\qcom\proprietary\qmi\inc)
*/
#define FEATURE_LGT_DS_EVDO_ERROR_REASON

/* Item : EVDO/EHRPD Error
	Commnet - 20120213 Alice
	Reason - after read EVDO/EHRPD Error casue in property(ril.cdma.errorcause) 
	             show the Pop-up Message or Toast and write Error cause to other property(ril.cdma.wipinetval).
	Modified files -  DataConnectionTracker.java,
	                     CdmaDataConnectionTracker.java,
	                     Strings_ds.xml (msm8960ics\linux\android\vendor\pantech\overlay\frameworks\base\core\res\res\values),
	                     Strings_ds.xml (msm8960ics\linux\android\vendor\pantech\overlay\frameworks\base\core\res\res\values-ko)
*/
#define FEATURE_LGT_DS_EVDO_ERROR_MESSAGE

/*
    Item : EVDO/EHRPD Error
    Commnet - 20120719 jsmin
    Reason - ���������� radio tech 1x ���� chap fail6ȸ  �˾� ǥ�� �ȵǴ� ����
     Modified files -  DataConnectionTracker.java,
*/

#define FEATURE_LGT_DS_EVDO_ERROR_MESSAGE_FIX

#endif /* FEATURE_LGT_DS_EVDO_ERROR */

/* Item : Emergency Call
	Commnet - 20120118 Alice
	Reason - keep connecting the Data Call after Emergency call end.
	Modified files - CdmaCallTracker.java(\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma)
*/
#define FEATURE_LGT_DS_NO_TEARDOWN_DATA_EMERGENCYCALL

/* Item : Connectivity
 	Commnet - 20120215 Alice
  	Reason - 1. only try to connect Data call when EVDO_REV_0/EVDO_REV_A 
  	                -> 1x Data call isn't possible.
  	             2. do not try to connect Data call IPV6 in LTE/EHRPD system.
  	                -> but possible aborad.
 	Modified files - CdmaDataConnection.java(\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),
*/
#define FEATURE_LGT_DS_RESTRICT_DATA_CALL

/* Item : Data On/off customize
	Commnet - 20120128 Ksg
	Reason - support data on/off for LG U+ request
	Modified files - DataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 Settings.java (android\packages\apps\Phone\src\com\android\phone),

	 added files-   SkyDataConInterfaceManager.java (android\frameworks\base\telephony\java\com\android\internal\telephony)
	                 ISkyDataConnection.aidl (android\frameworks\base\telephony\java\com\android\internal\telephony),

*/
#define FEATURE_LGT_DS_PS_DISABLE

/* Item : Data On/off Property
	Commnet - 20120128 Ksg
	Reason - Manage pantech's customized Data on/off property
	Modified files - ConnectivityService.java (android\frameworks\base\services\java\com\android\server),
	                 DatabaseHelper.java (android\frameworks\base\packages\SettingsProvider\src\com\android\providers\settings),
	                 DataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 GpsLocationProvider.java (android\frameworks\base\services\java\com\android\server\location),
	                 ISkyDataConnection.aidl (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 SkyDataConInterfaceManager.java (android\frameworks\base\telephony\java\com\android\internal\telephony)
	                 Settings.java(android\frameworks\base\core\java\android\provider)
*/
#define FEATURE_LGT_DS_GET_SECUREDB_FOR_LGT

/* Item : stop all using networks
	Commnet - 20120128 Ksg
	Reason - When disconnect Data, remove all networks.
	Modified files - ConnectivityService.java (android\frameworks\base\services\java\com\android\server),
	                 DataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 IConnectivityManager.aidl (android\frameworks\base\core\java\android\net)
	                 ConnectivityManager.java(\android\frameworks\base\core\java\android\net)
*/
#define FEATURE_LGT_DS_DISCONNECT_ALL_NETWORK_FEATURE

/* EasySetting : 3G ON/OFF menu */
#define FEATURE_LGT_DS_DATA_MENU_POPUP

#ifdef FEATURE_LGT_DS_DATA_MENU_POPUP

/* Item : 3G/4G data on/off toast
	Commnet - 20120128 Ksg
	Reason - Show Data Conn/Disconn info toast
	Modified files - DataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_DATA_MENU_TOAST

/* Item : 3G/4G boot-up Connection/Disconnection Dialog
	Commnet - 20120128 Ksg
	Reason - Show Boot-up Dialog that use for Data Conn/Disconn
	Modified files - CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),
	                 DatabaseHelper.java (android\frameworks\base\packages\SettingsProvider\src\com\android\providers\settings),
	                 DataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 ISkyDataConnection.aidl (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 Settings.java (android\frameworks\base\core\java\android\provider),
	                 SkyDataConInterfaceManager.java (android\frameworks\base\telephony\java\com\android\internal\telephony),
                         Strings_ds.xml (android\vendor\pantech\overlay\frameworks\base\core\res\res\values),
	                 Strings_ds.xml (android\vendor\pantech\overlay\frameworks\base\core\res\res\values-ko)
*/
#define FEATURE_LGT_DS_3G_DATA_MENU_POPUP

/* Item : 3G/4G Boot-up pop-up fix
	Commnet - 20120128 Ksg
	Reason - Fix & add something at FEATURE_LGT_DS_3G_DATA_MENU_POPUP
	              - EFS Erase �Ŀ� 3G Menu Popup ���� ���� �����Ͽ��� Data Connection �Ǵ� ���� ����
                     - isReadyForData üũ �Լ����� Preferred_Data_network üũ�ϴ� �κ� �߰� ��.
                      - Radio On �� Data Radio �� Unknown�� �ƴ� ��쿡�� Popup �߻��ϵ��� Check routine�� isReadyForData()�� ����

	Modified files - CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),
*/
#define FEATURE_LGT_DS_3G_DATA_MENU_POPUP_BUG_FIX


#define FEATURE_LGT_DATA_EZSETTING

/*
    Item : 3G  Boot-up pop not display 

	Commnet - 20120525 jsmin
	Reason - Fix & add something at FEATURE_LGT_DS_3G_DATA_MENU_POPUP
	              - try setupdata ȣ��� radio tech�� 1x ���¿��� ���Ŀ� evdo�� ���� �Ǵµ�  ���� �˾��� ǥ�� ���� �ʾƼ� 
	                 �ٽ�  try setupdata ȣ�� �ϵ��� ó���� 
	              - ���� �˾� ǥ�� ���ϴ� ��쵵 �����ϰ� 1x ���¿���  trysetupdata ȣ���� ���� ���� ���Ŀ� evdo ����Ǿ� ����Ÿ ���� �ȵǴ� ���� �߻�   

	Commnet - 20120613 jsmin
	Reason - ������ �����  evdo �� radio tech ��  �ٽ�  try setupdata ȣ�� �ϵ��� ó���� 
	Modified files -
	
	\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma\CdmaServiceStateTracker.java
       \android\frameworks\base\telephony\java\com\android\internal\telephony\DataConnectionTracker.java
       \android\frameworks\base\telephony\java\com\android\internal\telephony\ISkyDataConnection.aidl
       \android\frameworks\base\telephony\java\com\android\internal\telephony\SkyDataConInterfaceManager.java
                              
*/
#define FEATURE_LGT_DS_3G_DATA_POPUP_NOT


#endif /* FEATURE_LGT_DS_DATA_MENU_POPUP */


#define FEATURE_LGT_DS_CTS

#ifdef FEATURE_LGT_DS_CTS

/* Item : UID_STAT CONFIG
 	Commnet - 2012 ksg.
 	Reason - enable UID_STAT=y for TrafficStats(CTS TEST Fail)
       Modified files  - msm8660-perf-EF35L_defconfig  (\LINUX\android\kernel\arch\arm\configs)

*/
#define FEATURE_DS_UID_TRAFFIC_STATS_ENABLE
#endif /* FEATURE_LGT_DS_CTS */


/* Item : MMS
 	Commnet - 20120217 Alice
  	Reason - MMS App. Request.
            - added "isAvailableForMms" return to connection state of mobile_mms before "startUsingNetworkFeature" 
            - return true :: AlwaysOnSetting true, AuthFail false, DC.FailCause not permanantfail, In service.

            - added getServiceState:: for No service.
            - as 1x Data Disable return false when RadioTech is 1x
            
    Modified files - ISkyDataConnection.aidl, SkyDataConInterfaceManager.java,
 	                    MobileDataStateTracker.java, DataConnectionTracker.java
*/
#define FEATURE_LGT_DS_CHECK_NETWORK_AVAILABLE_FOR_MMS

/*......................................................................................................................................
  Merge ING~
.........................................................................................................................................*/

/* -----------------------------------------------------------------------------------*/
    //3 Issue Follow up
/*-------------------------------------------------------------------------------------*/
/* Item : Data Connection Interface, AIDL
	Commnet - 20120104 Alice
	Reason-Phone Interface�� ���� ���ϴ� APP�� ���Ͽ� AIDL�� �߰�  

	Modified files - Android.mk(LINUX\android\frameworks\base), 
			         service_manager.c(LINUX\android\frameworks\base\cmds\servicemanager),
				  DataConnectionTracker.java (\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)
				           
	Added files - ISkyDataConnection.aidl (LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony),
			      SkyDataConInterfaceManager.java (LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_ADD_DATA_AIDL



/* Item : CNE
 	Commnet - 20120105 Alice
 	Reason - ConnectivityService�� handleConnectivityChanged()�Լ������� CNE�� �����Ǵ� �� üũ�Ͽ� addDefaultRoute()�Լ� ��ſ� addSourceRoute()ȣ��Ǿ� Default Route�� ���õ��� �ʾƼ� �߻�
 	Modified files - init_EF35L.rc(LINUX\android\system\core\rootdir)
*/
#define FEATURE_LGT_DS_DISABLE_CNE
 
/* Item : Max windowsize/memsize for LTE
 	Commnet - 20120105 Alice, 20120202 Alice
 	Reason - change max windowsize/memsize for LTE
 	          -  FEATURE_SKY_DS_SET_TCPBUF_IN_RAT_CHANGE
 	Modified files - init_EF35L.rc(LINUX\android\system\core\rootdir)
*/
#define FEATURE_LGT_DS_TCP_BUFFER_FOR_LTE


/* Item : DNS
 	Commnet - 20120105 Alice
 	Reason - dns check �κп��� null_ip �� 0.0.0.0 �� ��� �� üũ�ϴ� ����, null �� ���(length�� 0)�� üũ�ϵ��� ����. 
 	Modified files - CdmaDataConnection.java(\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma)
*/
#define FEATURE_LGT_DS_PS_NULL_DNS_CHECK

/* Item : Data Connection
 	Commnet - 20120111 Alice
 	Reason - - data connection fail cause �� ���� ó������ �ʴ� ���� 
                     - fail �߻��� cause query �ϵ��� ����.
 	Modified files - DataConnection.java(android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_PS_FAIL_CAUSE

/* Item : Data Connection
 	Commnet - 20120111 Alice
 	Modified files - DataConnection.java(android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_PS_FAIL_CAUSE_FATAL_EXCEPTION

/* Item : DNS
 	Commnet - 20120113 Alice
 	Reason - - data disconnect �� ����_test_dns check �����ؼ� mms �����Ϸ��� Inetaddress.getbyname �ϸ� unknown host exception �߻��ϴ� ����
 	Modified files - getaddrinfo.c(android\bionic\libc\netbsd\net)
*/
#define FEATURE_LGT_DS_DISABLE_TEST_DNS

/*   Item : Data Connection
 	Commnet - 20120113 Alice
 	Reason - VT(startusingnetworkfeature(), TYPE_DUN) ����
 			    "168.126.63.1"/"168.126.63.2" �� ���ؼ� ROUTE TABLE ��� ���� ����.
 	Modified files -\android\frameworks\base\services\java\com\android\server\ConnectivityService.java
*/
#define FEATURE_LGU_DS_3G_DNS_REMOVE_IN_ROUTETABLE


/* Item: WIFI+VT

    - From 35GB  merge
    - Wifi connected�ÿ� 3g icon�� �������� mms �� default�� dun�� ��찡 �ƴ� service type�� �̿��� 3g�� ���� data ������ �̷���� ��쿡 3g icon ǥ��. 
    - mms ���� �ô�  3g ǥ�� 

       \android\frameworks\base\packages\SystemUI\src\com\android\systemui\statusbar\policy\NetworkController.java
       \android\frameworks\base\services\java\com\android\server\ConnectivityService.java
       \android\frameworks\base\telephony\java\com\android\internal\telephony\ITelephony.aidl
       \android\frameworks\base\telephony\java\com\android\internal\telephony\sip\SipPhoneBase.java
       \android\frameworks\base\telephony\java\com\android\internal\telephony\Phone.java
       \android\frameworks\base\telephony\java\com\android\internal\telephony\PhoneBase.java
       \android\frameworks\base\telephony\java\com\android\internal\telephony\PhoneProxy.java
       \android\frameworks\base\telephony\java\com\android\internal\telephony\DataConnectionTracker.java
       \android\packages\apps\Phone\src\com\android\phone\PhoneInterfaceManager.java
*/
#define FEATURE_LGT_DS_HIDE_3G_ICON_WHEN_WIFI_CONNECTED


/*
      Item : WIFI+VT
      
 	Commnet - 20120613 jsmin
 	Reason  - wifi on��  defult ������ �ٽ� wifi off ��  3g default �� �ö� ���� �ʾƼ�  ���Ʈ�� �ٽ� �߰� �ϴ� �ڵ�� ���� 
 	            -  wifi on ��   vt  regi ������ 3g defult �� 2�� ������ ���� �߻�  
 	Modified files - \android\frameworks\base\services\java\com\android\server\ConnectivityService.java

*/

#define FEATURE_LGU_DS_REMOVE_DEFAULT_ROUTE


/*
      Item : APN switch  ���� ���� 
 	Commnet - 20120613 jsmin
 	Reason -  apn  switch��  teardown ���� �� �ٽ� �ٴ� ���� �߻� 
 	
 	Modified files - \android\frameworks\base\telephony\java\com\android\internal\telephony\cdma\cdmaDataConnectionTracker.java

*/

#define FEATURE_LGT_DS_NOT_APN_SWITCH



/* Item : RADIO
	Commnet - 20120113 Alice
   Reason - RADIO Tech가 Data Connection state, qcril단 정보와 일치 하지 않는 경우.
*/
#define FEATURE_LGU_DS_UNKNOWN_RADIO

#ifdef FEATURE_LGU_DS_UNKNOWN_RADIO
/* Item : RADIO
	Commnet - 20120113 Alice
	Reason  - preferred data radio tech �� eHRPD �� QMI_WDS ���� ���޵��� �ʾ� Preferred mode change �� LTE �� 
                    �����ϰ�, �̷����� pdt_modem_id  ���� ó���Ǵ� ���� ����.

	Modified files - qcril_arb.c(android\vendor\qcom\proprietary\qcril\qcril_fusion), 
*/
//#define FEATURE_LGT_DS_PS_UNKNOWN_RADIO_TECH

/* Item : RADIO
	Commnet - 20120113 Alice
	Reason - OOS(Out of Service) 인 경우(RADIO TECH UNKNOWK), Framework에서  networkinfo.available() 이
	             false로 설정되어 AMSS가 실제 Network 연결 상태, 즉 데이터 연결 중임에도
	             App.에서 연결이 끊어진 것으로 인식하는 문제 수정.
	Modified files - MobileDataStateTracker.java(\android\frameworks\base\core\java\android\net),	
				 NetworkController.java (android\frameworks\base\packages\systemui\src\com\android\systemui\statusbar\policy)	 
*/
#define FEATURE_LGT_DS_AVOID_OOS_FOR_APP

/* Item : RADIO
	Commnet - 20120227 Alice
	Reason - OOS 진입시 OOS Timer start. Expired 시점에 다시 data connection state 확인.
	Modified files - ServiceState.java (android\frameworks\base\telephony\java\android\telephony),
			        ServiceStateTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony),		 
	                     CdmaServiceStateTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma)
*/
#define FEATURE_LGT_DS_OOS_TIMER

/* Item : RADIO
 	Commnet - 20120320 Alice
 	Reason - set to false "TelephonyProperties.PROPERTY_OOS_IS_DISCONNECT".
 	           - if mOosIsDisconnect == true, changed data connection to disconnection as soon as entering no-service.
 	           - cause confusion in App. layer.
 	           - merge from EF47S.
 	Modified files - PhoneBase.java(\android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
//#define FEATURE_LGT_DS_OOS_PROPERTY_INITIAL_VAL

#endif /* FEATURE_LGU_DS_UNKNOWN_RADIO */

/*Item : Fastdormancy
   comment -20120507 jsmin
   Reaseon - EF35L GB merge
      EF35L GB feature  -DS1_DS_FAST_DORMANCY
    - Fast Dormancy ��� ����
    - LGU+ �ó����� : LCD ON Fast Dormant ���� ����, LCD OFF�� 3�� �� Dormant ����
    - aArm : LCD ON/OFF ������ mArm���� �����ϵ��� ����
    - mArm : FEATURE_SKT_DS_FAST_DORMANCY ����  
    modifed file - cm.h(\vendor\qcom\proprietary\modem-apis\msm8660_surf\api\libs\remote_apis\cm\inc) ,
                        Qcril_cm.c(android\vendor\qcom\proprietary\qcril\qcril_fusion)
    addeed Forder - /cm  (android\vendor\qcom\proprietary\modem-apis\msm8660_surf\api\libs\remote_apis)
*/
//#define DS1_DS_FAST_DORMANCY

/*

Android.mk (android\vendor\qcom\proprietary\cpManager\cpmgrif)
cpmgrif.c(\android\vendor\qcom\proprietary\cpManager\cpmgrif)
cpmgrif.h (\android\vendor\qcom\proprietary\cpManager\cpmgrif)
oem_rapi.h(\android\vendor\qcom\proprietary\modem-apis\msm8660_surf\api\libs\remote_apis\oem_rapi\inc)

Android.mk(\android\vendor\qcom\proprietary\cpManager\cpmgrjn)
cpmgrnative.cpp(\android\vendor\qcom\proprietary\cpManager\cpmgrjni)

*/
#define FEATURE_LGT_DS_FAST_DORMANCY
/*

  comment -20120517 jsmin
  Reaseon - qmi �������̽� ������ ���ؼ� ���� 
  
  modifed file -Qcril_other.c (vendor\qcom\proprietary\qcril\qcril_qmi)
                     Qcril_qmi_nas.c (vendor\qcom\proprietary\qcril\qcril_qmi)
                     specific_absorption_rate_v01.h(LINUX\android\vendor\qcom\proprietary\qmi\services)
                     qmi_nas.c(\modem_proc\modem\mmode\qmi\src)
                     

                     qmi_voice.c(\modem_proc\modem\mmode\qmi\src)
                     qmi_voice_cm_if.c(\modem_proc\modem\mmode\qmi\src\)
                     qmi_voice_cm_if.h(\modem_proc\modem\mmode\qmi\inc)
                     cust_sky_ds.h(\modem_proc\build\cust)

                     qcril_qmi_voice.c(vendor\qcom\proprietary\qcril\qcril_qmi)
                     cpmgrif.c(\android\vendor\qcom\proprietary\cpManager\cpmgrif)
                     cpmgrif.h (\android\vendor\qcom\proprietary\cpManager\cpmgrif)
                     cpmgrnative.cpp(\android\vendor\qcom\proprietary\cpManager\cpmgrjni)
                     voice_service_v02.c(\LINUX\android\vendor\qcom\proprietary\qmi\services)
                     voice_service_v02.h(\LINUX\android\vendor\qcom\proprietary\qmi\services)

*/


#define FEATURE_LGT_DS_FAST_DORMANCY_QMI


/*
  comment -20120618 jsmin
  Reaseon -qos  qmi �������̽� ����   
  modifed file -

       \LINUX\android\vendor\qcom\proprietary\cpManager\cpmgrif\cpmgrif.c
       \LINUX\android\vendor\qcom\proprietary\cpManager\cpmgrif\cpmgrif.h
       \LINUX\android\vendor\qcom\proprietary\cpManager\cpmgrjni\cpmgrnative.cpp
       \LINUX\android\vendor\qcom\proprietary\qmi\services\voice_service_v02.c
       \LINUX\android\vendor\qcom\proprietary\qmi\services\voice_service_v02.h
       \LINUX\android\vendor\qcom\proprietary\qcril\qcril_qmi\qcril_qmi_voice.c
       \LINUX\android\frameworks\base\skytelephony\common\java\com\android\phone\SkyTelephonyInterfaceManager.java
       
        
        \modem_proc\modem\mmode\qmi\inc\qmi_voice_cm_if.h
        \modem_proc\modem\mmode\qmi\src\qmi_voice.c
        \modem_proc\modem\mmode\qmi\src\qmi_voice_cm_if.c

       modem feature: FEATURE_LGT_DS_VT_HDR_QOS_QMI

comment 20120621 jsmin
reaseon- 1.qos qmi ���� �ؼ� vt qos ���� ��  Ȯ���� ����� ���������� ������ port ���� �ٸ��� ���� �Ǵ� ���� ����
              2.cpmgr �̺�Ʈ�� ������ �𵩿� �̺�Ʈ�� �ȳ������� ���� ����
modified file-

       \LINUX\android\vendor\qcom\proprietary\cpManager\cpmgrif\cpmgrif.c
       \LINUX\android\vendor\qcom\proprietary\qmi\services\voice_service_v02.h
       \LINUX\android\vendor\qcom\proprietary\qmi\services\voice_service_v02.c
       \modem_proc\modem\mmode\qmi\src\qmi_voice.c

*/

#define FEATURE_LGT_DS_VT_HDR_QOS

/* Item: Data Roaming
     Comment -20120508  jsmin
     Reason - EF35L GB merge 
                  - Feature -DS1_DS_LGT_DISABLE_DATA_ROAMING_NOTI
                  - EF13L ������ ������ : EF13L�� ��� Data Roaming�� �������� �����Ƿ� Data Roaming���� '�˸�'�� ǥ���ϸ� �ȵ�
                  - Data Roaming ���� '�˸�'�� ǥ�� ���ϵ��� ����
                   - Roaming�� Data �õ� ���ϵ��� ����
     Modified Files -PhoneApp.java,
                           CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),   
   
*/
#define FEATURE_LGT_DISABLE_DATA_ROAMING_NOTI


/* Item : Datacall
    Comment -20120508 jsmin
    Reason -EF35L GB merge
    -EF35L GB feature -DS1_DS_CONTROL_DATACALL_WITH_1X_REG
   - LGT �䱸 �������� 1X Registration �������� Dataȣ�� ����
   - EVDO Only�� ��� 1X Regi�� ���� ���� Dataȣ�� �õ�
   modifed file - DataConnectionTracker.java (\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)

*/
#define FEATURE_LGT_DS_CONTROL_DATACALL_WITH_1X_REG

/*20111005 sjm
- ACTION_ANY_DATA_CONNECTION_STATE_CHANGED �� phoneStateListener ���� �켱 ó���ǵ��� ����.
- PhoneStateListeneró������ syncronized ���� intent action broadcasting ���� �ʴ� ��� 1ȸ �߻�.
- TelephonyRegistry.java
*/
#define FEATURE_LGT_DS_DATA_CON_INTENT_FAST_BROADCASTING
/* Item : VPN
 	Commnet - 20120117 Alice
 	Reason - VPN Editing -> Null check
 	Modified files - VpnDialog.java(\android\packages\apps\Settings\src\com\android\settings\vpn2)
*/
#define FEATURE_LGT_DS_VPN_SPACE_CHECK

/* Item : VPN
 	Commnet - 20120117 Alice, 20120217 Alice
 	Reason - 1. VPN BUG FIX :  just function execution's order change.
	              -> L2tp.c 	
 	Modified files  L2tp.c(LINUX\android\external\mtpd),
 	                   msm8660-perf-EF35L_defconfig(android\kernel\arch\arm\configs), 	   	
 */ 
#define FEATURE_LGT_DS_VPN_FIX

/* Item : MTU
 	Commnet - 20120703 jsmin
 	Reason - change MTU size for EVDO (1500)
 		    - deleted usb0 interface set MTU size and change TCP MSS for tethering by NAT
 		       (merged MirachJ)
 	Modified files - init_EF35L.rc(LINUX\android\system\core\rootdir),
                     msm8660-perf-EF35L_defconfig(LINUX\android\kernel\arch\arm\configs),
 			          NatController.cpp(\LINUX\android\system\netd\)
*/
#define FEATURE_LGT_DS_USB_KERNEL_MTU_SETTING


#define FEATURE_LGT_DS_NETWORK_TOOL

#ifdef FEATURE_LGT_DS_NETWORK_TOOL
/* Item : BUSYBOX 
	Commnet - 20120404 Alice
	Reason - busybox install for root(eng) version 1.19.0
	          - merge from STARQ
	Modified files - init_EF35L.rc (android\system\core\rootdir)
      Added files - busybox folder all (android\pantech\development\busybox)
*/
#define FEATURE_LGT_DS_BUSYBOX_INSTALL

/* Item : IPERF 
	Commnet - 20120404 Alice
	Reason - iperf install for root, version : 2.0.5 (08 Jul 2010)
	          - merge from STARQ	
	Modified files - init_EF35L.rc (android\system\core\rootdir)
   Added files - iperf folder all (android\pantech\development\iperf)
*/
#define FEATURE_LGT_DS_IPERF_INSTALL
#endif /* FEATURE_LGT_DS_NETWORK_TOOL */


/*    Item : radio tech
	Commnet - 20120806 jsmin
	Reason - radio tech rev.B �ΰ�� DATA ���� ���� �ϵ��� ����
      Modified files - CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),   
                            CdmaServiceStateTracker.java(\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma)
*/
#define FEATURE_LGT_DS_REV_B



/*......................................................................................................................................
  Merge ING~
.........................................................................................................................................*/
/* Item : RADIO

  Commnet  20120105 Alice
  Reason  - Preferred data tech�� 1x������ MDM�� LTE�� �����ϴ� ��찡 �߻��Ͽ� LTE Service available�̸� Radio tech�� LTE�� ���� 
  Modified files - qcril_cm.c(android\vendor\qcom\proprietary\qcril\qcril_fusion)
*/
//#define FEATURE_LGT_DS_DATA_RADIO_TECH_FIX



/* Item : Tethering 
	Commnet - 20120404 Alice
	Reason - enable DIAG port when usb tethering.
	          - merge from STARQ	
	Modified files - Tethering.java (frameworks\base\services\java\com\android\server\connectivity),
	                     UsbManager.java (frameworks\base\core\java\android\hardware\usb)
*/
#define FEATURE_LGT_DS_ADD_DIAG_PORT_WHEN_TETHERING


/* Item : Tethering
      Commnet - 20120719 jsmin(EF46L20120418 Alice)
  	Reason - at the same time USB tethering and WiFi Hotstop, DATA off -> DATA on -> WiFi on
  	             display both WiFi icon and DATA icon for a few seconds. maybe the longest 60 sec.
  	           - after startUsingNetworkFeature, don't call stopUsingNetworkFeature
  	              now, when IMS de-registration, call stopUsingNetworkFeature.
  	           - If IMS doesn't call stopUsingNetworkFeature, do stopUsingNetworkFeature.
 	Modified files - Tethering.java (frameworks\base\services\java\com\android\server\connectivity)
*/
#define FEATURE_LGT_DS_DISPLAY_WIFI_DATA_ICON_WHEN_TETHERING



/* Item : NetworkInfo
 	Commnet - 20120719 jsmin(EF46L20120417 Alice)
  	Reason - NetworkInfo isAvailable is false when APN State is failed
  	          - merge From STARQ, FEATURE_P_VZW_DS_APN_FAILED_STATE_BUG
 	Modified files - cdmaDataConnectionTracker.java
*/
#define FEATURE_LGT_DS_APN_FAILED_STATE_BUG



/* Item : Route
      Commnet - 20120719 jsmin(EF46L20120418 Alice)
  	Reason - Reconnect when routing add failed.
  	          - If occured failure to add Route, do tear down and try to reconnect after 3 sec.
  	          - merge From STARQ, FEATURE_P_VZW_DS_ROUTE_ADD_FAIL
 	Modified files - ConnectivityService.java(frameworks\base\services\java\com\android\server),
 	                     NetworkStateTracker.java (frameworks\base\core\java\android\net),
 	                     MobileDataStateTracker.java (frameworks\base\core\java\android\net),

  below files - implements NetworkStateTracker
  
                        BluetoothTetheringDataTracker.java (frameworks\base\core\java\android\bluetooth),
                        DummyDataStateTracker.java (frameworks\base\core\java\android\net)
                        EthernetDataTracker.java (frameworks\base\core\java\android\net),
 	                     WifiStateTracker.java (frameworks\base\wifi\java\android\net\wifi)
*/
#define FEATURE_LGT_DS_ROUTE_ADD_FAILURE




#endif /* FEATURE_LGT_DS_COMMON */

/*===========================================================================
    Others
===========================================================================*/

/* Item : Log change (Radio -> Main)
	Commnet - 20120119 hongss
	Reason - change buffer to print Data Framework log, RADIO BUFFER -> MAIN BUFFER.
	Modified files - connetivityservice.java, mobiledatastatetracker.java, networkmanagermentservice.java, logd_write.c
*/
#define FEATURE_LGT_DS_PS_CHANGE_RADIO_LOG


/*
     Commnet - 20120622 jsmin
     Reason  -UDP�������� �̿��� ��, DL�ӵ� ���� ���� 
                  (https://android-review.googlesource.com/#/c/37471/)
                  
     Modified files -
    \LINUX\android\libcore\luni\src\main\java\java\net\DatagramPacket.java
    \LINUX\android\libcore\luni\src\main\java\java\net\DatagramSocket.java
    \LINUX\android\libcore\luni\src\main\java\libcore\io\IoBridge.java
    \LINUX\android\libcore\luni\src\test\java\libcore\java\net\OldDatagramSocketTest.java

*/



#endif/* __CUST_PANTECH_DS_H__ */


