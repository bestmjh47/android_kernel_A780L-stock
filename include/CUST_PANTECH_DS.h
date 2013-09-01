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
  	Reason -LCD 가 켜질 경우 data 연결되어 있지 않으면 data 연결 시도하며(setup 조건체크는 trysetupdata에서 처리되므로 state 관련 체크만 수행함.), LCD on 상태이고 data 연결시도 가능한 경우 이면 fail 처리 부분에서 retry timer 를 reset 시켜서 retry timer 값이 크게 증가되지 않게함.
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
- ACTION_ANY_DATA_CONNECTION_STATE_CHANGED 를 phoneStateListener 보다 우선 처리되도록 변경.
- PhoneStateListener처리에서 syncronized 이후 intent action broadcasting 되지 않는 경우 1회 발생.
- TelephonyRegistry.java
*/
#define FEATURE_LGT_DS_DATA_CON_INTENT_FAST_BROADCASTING


/*
//20111111 sjm
- startUsingNetworkFeature에서 Reconnect 호출시 Fail이 발생하여도 Phone.APN_REQUEST_STARTED을 리턴하여 Application에 혼동을 제공함
- ConnectivityService.java
*/
#define FEATURE_LGT_DS_BUG_FIX_STARTUSINGNETWORKFEATURE

/*
    - status bar 에 LTE 에서 1xICON 보여지는 문제.
    - 3G/4G 데이터 연결 상태 유지중인데 1xRTT 혹은 UNKNOWN 으로 오는 경우 이전 상태값 유지하고, state change 된 후 noti하도록 처리.
   - telephonyregistry.java
   - LGU+는 1xRTT 지원하지 않으므로 삭제 하자!!!
   - 65l merge

*/
#define FEATURE_LGT_DS_DATA_AVOID_1X_ICON_DURING_4G_CONNECTED

/*
    Item:  cdmaltesetvicestate  관련 수정 
    Commnet -20120613 jsmin
    Reason  - cmdaServicestate 로 변경시 radio tech evdo 안올라오는 현상 
                - dun 프로파일로 동작 하는 관련 파일 삭제

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
 	Reason - 1.QualcommSetting 디렉토리에 있는 파일들은 user mode 시 실행되지 않으므로, dun, sync manager, data manger, curi explore가 실행되지 않음.
        			2./dev/pantech에 File Write 권한 부여 시 CTS Fail 발생하여 /dev/pantech 권한 삭제 
        			3. DUN_FIFO_FILE for DUN /data/dun -> /dev/pantech/dun
        			4.QualcommSetting 내 파일이 patch로 인해 수정되었다면, 이동된 파일들도 같이 수정해 주어야 함.   
        			5.  dun service start 하고, Dun_Autoboot.java에서는 서비스 start 하는 부분을 막음.

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
    Reason - 간헐적으로 radio tech 1x 상태 chap fail6회  팝업 표시 안되는 문제
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
	              - EFS Erase 후에 3G Menu Popup 에서 차단 선택하여도 Data Connection 되는 문제 수정
                     - isReadyForData 체크 함수에서 Preferred_Data_network 체크하는 부분 추가 함.
                      - Radio On 및 Data Radio 가 Unknown이 아닌 경우에만 Popup 발생하도록 Check routine을 isReadyForData()로 변경

	Modified files - CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),
*/
#define FEATURE_LGT_DS_3G_DATA_MENU_POPUP_BUG_FIX


#define FEATURE_LGT_DATA_EZSETTING

/*
    Item : 3G  Boot-up pop not display 

	Commnet - 20120525 jsmin
	Reason - Fix & add something at FEATURE_LGT_DS_3G_DATA_MENU_POPUP
	              - try setupdata 호출시 radio tech가 1x 상태에서 이후에 evdo로 변경 되는데  부팅 팝업이 표시 되지 않아서 
	                 다시  try setupdata 호출 하도록 처리함 
	              - 부팅 팝업 표시 안하는 경우도 동일하게 1x 상태에서  trysetupdata 호출이 먼저 한후 차후에 evdo 변경되어 데이타 연결 안되는 현상 발생   

	Commnet - 20120613 jsmin
	Reason - 비행중 모드후  evdo 로 radio tech 시  다시  try setupdata 호출 하도록 처리함 
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
	Reason-Phone Interface를 접근 못하는 APP를 위하여 AIDL을 추가  

	Modified files - Android.mk(LINUX\android\frameworks\base), 
			         service_manager.c(LINUX\android\frameworks\base\cmds\servicemanager),
				  DataConnectionTracker.java (\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)
				           
	Added files - ISkyDataConnection.aidl (LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony),
			      SkyDataConInterfaceManager.java (LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_ADD_DATA_AIDL



/* Item : CNE
 	Commnet - 20120105 Alice
 	Reason - ConnectivityService의 handleConnectivityChanged()함수내에서 CNE가 구동되는 지 체크하여 addDefaultRoute()함수 대신에 addSourceRoute()호출되어 Default Route가 세팅되지 않아서 발생
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
 	Reason - dns check 부분에서 null_ip 를 0.0.0.0 인 경우 만 체크하는 문제, null 인 경우(length가 0)도 체크하도록 수정. 
 	Modified files - CdmaDataConnection.java(\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma)
*/
#define FEATURE_LGT_DS_PS_NULL_DNS_CHECK

/* Item : Data Connection
 	Commnet - 20120111 Alice
 	Reason - - data connection fail cause 에 대해 처리되지 않는 문제 
                     - fail 발생시 cause query 하도록 수정.
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
 	Reason - - data disconnect 된 순간_test_dns check 수행해서 mms 전송하려고 Inetaddress.getbyname 하면 unknown host exception 발생하는 문제
 	Modified files - getaddrinfo.c(android\bionic\libc\netbsd\net)
*/
#define FEATURE_LGT_DS_DISABLE_TEST_DNS

/*   Item : Data Connection
 	Commnet - 20120113 Alice
 	Reason - VT(startusingnetworkfeature(), TYPE_DUN) 사용시
 			    "168.126.63.1"/"168.126.63.2" 에 대해서 ROUTE TABLE 등록 하지 않음.
 	Modified files -\android\frameworks\base\services\java\com\android\server\ConnectivityService.java
*/
#define FEATURE_LGU_DS_3G_DNS_REMOVE_IN_ROUTETABLE


/* Item: WIFI+VT

    - From 35GB  merge
    - Wifi connected시에 3g icon을 숨기지만 mms 등 default나 dun의 경우가 아닌 service type을 이용해 3g를 통해 data 전송이 이루어질 경우에 3g icon 표시. 
    - mms 전송 시는  3g 표시 

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
 	Reason  - wifi on시  defult 삭제후 다시 wifi off 시  3g default 가 올라 오지 않아서  라우트에 다시 추가 하는 코드로 수정 
 	            -  wifi on 시   vt  regi 유지로 3g defult 가 2개 잡히는 현상 발생  
 	Modified files - \android\frameworks\base\services\java\com\android\server\ConnectivityService.java

*/

#define FEATURE_LGU_DS_REMOVE_DEFAULT_ROUTE


/*
      Item : APN switch  동작 막음 
 	Commnet - 20120613 jsmin
 	Reason -  apn  switch시  teardown 동작 후 다시 붙는 현상 발생 
 	
 	Modified files - \android\frameworks\base\telephony\java\com\android\internal\telephony\cdma\cdmaDataConnectionTracker.java

*/

#define FEATURE_LGT_DS_NOT_APN_SWITCH



/* Item : RADIO
	Commnet - 20120113 Alice
   Reason - RADIO Tech媛� Data Connection state, qcril�떒 �젙蹂댁�� �씪移� �븯吏� �븡�뒗 寃쎌슦.
*/
#define FEATURE_LGU_DS_UNKNOWN_RADIO

#ifdef FEATURE_LGU_DS_UNKNOWN_RADIO
/* Item : RADIO
	Commnet - 20120113 Alice
	Reason  - preferred data radio tech 중 eHRPD 가 QMI_WDS 에서 전달되지 않아 Preferred mode change 시 LTE 값 
                    유지하고, 이로인해 pdt_modem_id  에러 처리되는 문제 수정.

	Modified files - qcril_arb.c(android\vendor\qcom\proprietary\qcril\qcril_fusion), 
*/
//#define FEATURE_LGT_DS_PS_UNKNOWN_RADIO_TECH

/* Item : RADIO
	Commnet - 20120113 Alice
	Reason - OOS(Out of Service) �씤 寃쎌슦(RADIO TECH UNKNOWK), Framework�뿉�꽌  networkinfo.available() �씠
	             false濡� �꽕�젙�릺�뼱 AMSS媛� �떎�젣 Network �뿰寃� �긽�깭, 利� �뜲�씠�꽣 �뿰寃� 以묒엫�뿉�룄
	             App.�뿉�꽌 �뿰寃곗씠 �걡�뼱吏� 寃껋쑝濡� �씤�떇�븯�뒗 臾몄젣 �닔�젙.
	Modified files - MobileDataStateTracker.java(\android\frameworks\base\core\java\android\net),	
				 NetworkController.java (android\frameworks\base\packages\systemui\src\com\android\systemui\statusbar\policy)	 
*/
#define FEATURE_LGT_DS_AVOID_OOS_FOR_APP

/* Item : RADIO
	Commnet - 20120227 Alice
	Reason - OOS 吏꾩엯�떆 OOS Timer start. Expired �떆�젏�뿉 �떎�떆 data connection state �솗�씤.
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
    - Fast Dormancy 기능 규현
    - LGU+ 시나리오 : LCD ON Fast Dormant 지원 안함, LCD OFF시 3초 후 Dormant 진입
    - aArm : LCD ON/OFF 정보를 mArm으로 전달하도록 수정
    - mArm : FEATURE_SKT_DS_FAST_DORMANCY 참고  
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
  Reaseon - qmi 인터페이스 동작을 안해서 변경 
  
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
  Reaseon -qos  qmi 인터페이스 동작   
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
reaseon- 1.qos qmi 관련 해서 vt qos 어플 을  확인해 본결과 리눅스에서 보내는 port 값이 다르게 전송 되는 현상 수정
              2.cpmgr 이벤트를 보낼고 모뎀에 이벤트가 안내려오는 현상 수정
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
                  - EF13L 망연동 문제점 : EF13L의 경우 Data Roaming을 지원하지 않으므로 Data Roaming관련 '알림'을 표시하면 안됨
                  - Data Roaming 관련 '알림'을 표시 안하도록 수정
                   - Roaming시 Data 시도 안하도록 수정
     Modified Files -PhoneApp.java,
                           CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),   
   
*/
#define FEATURE_LGT_DISABLE_DATA_ROAMING_NOTI


/* Item : Datacall
    Comment -20120508 jsmin
    Reason -EF35L GB merge
    -EF35L GB feature -DS1_DS_CONTROL_DATACALL_WITH_1X_REG
   - LGT 요구 사항으로 1X Registration 이전에는 Data호를 막음
   - EVDO Only의 경우 1X Regi와 관계 없이 Data호를 시도
   modifed file - DataConnectionTracker.java (\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)

*/
#define FEATURE_LGT_DS_CONTROL_DATACALL_WITH_1X_REG

/*20111005 sjm
- ACTION_ANY_DATA_CONNECTION_STATE_CHANGED 를 phoneStateListener 보다 우선 처리되도록 변경.
- PhoneStateListener처리에서 syncronized 이후 intent action broadcasting 되지 않는 경우 1회 발생.
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
	Reason - radio tech rev.B 인경우 DATA 지원 가능 하도록 수정
      Modified files - CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),   
                            CdmaServiceStateTracker.java(\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma)
*/
#define FEATURE_LGT_DS_REV_B



/*......................................................................................................................................
  Merge ING~
.........................................................................................................................................*/
/* Item : RADIO

  Commnet  20120105 Alice
  Reason  - Preferred data tech는 1x이지만 MDM은 LTE로 동작하는 경우가 발생하여 LTE Service available이면 Radio tech을 LTE로 수정 
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
     Reason  -UDP프로토콜 이용할 때, DL속도 저하 문제 
                  (https://android-review.googlesource.com/#/c/37471/)
                  
     Modified files -
    \LINUX\android\libcore\luni\src\main\java\java\net\DatagramPacket.java
    \LINUX\android\libcore\luni\src\main\java\java\net\DatagramSocket.java
    \LINUX\android\libcore\luni\src\main\java\libcore\io\IoBridge.java
    \LINUX\android\libcore\luni\src\test\java\libcore\java\net\OldDatagramSocketTest.java

*/



#endif/* __CUST_PANTECH_DS_H__ */


