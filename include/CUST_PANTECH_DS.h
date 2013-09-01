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
  	Reason -LCD ∞° ƒ—¡˙ ∞ÊøÏ data ø¨∞·µ«æÓ ¿÷¡ˆ æ ¿∏∏È data ø¨∞· Ω√µµ«œ∏Á(setup ¡∂∞«√º≈©¥¬ trysetupdataø°º≠ √≥∏Æµ«π«∑Œ state ∞¸∑√ √º≈©∏∏ ºˆ«‡«‘.), LCD on ªÛ≈¬¿Ã∞Ì data ø¨∞·Ω√µµ ∞°¥…«— ∞ÊøÏ ¿Ã∏È fail √≥∏Æ ∫Œ∫–ø°º≠ retry timer ∏¶ reset Ω√ƒ—º≠ retry timer ∞™¿Ã ≈©∞‘ ¡ı∞°µ«¡ˆ æ ∞‘«‘.
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
- ACTION_ANY_DATA_CONNECTION_STATE_CHANGED ∏¶ phoneStateListener ∫∏¥Ÿ øÏº± √≥∏Æµ«µµ∑œ ∫Ø∞Ê.
- PhoneStateListener√≥∏Æø°º≠ syncronized ¿Ã»ƒ intent action broadcasting µ«¡ˆ æ ¥¬ ∞ÊøÏ 1»∏ πﬂª˝.
- TelephonyRegistry.java
*/
#define FEATURE_LGT_DS_DATA_CON_INTENT_FAST_BROADCASTING


/*
//20111111 sjm
- startUsingNetworkFeatureø°º≠ Reconnect »£√‚Ω√ Fail¿Ã πﬂª˝«œø©µµ Phone.APN_REQUEST_STARTED¿ª ∏Æ≈œ«œø© Applicationø° »•µø¿ª ¡¶∞¯«‘
- ConnectivityService.java
*/
#define FEATURE_LGT_DS_BUG_FIX_STARTUSINGNETWORKFEATURE

/*
    - status bar ø° LTE ø°º≠ 1xICON ∫∏ø©¡ˆ¥¬ πÆ¡¶.
    - 3G/4G µ•¿Ã≈Õ ø¨∞· ªÛ≈¬ ¿Ø¡ˆ¡ﬂ¿Œµ• 1xRTT »§¿∫ UNKNOWN ¿∏∑Œ ø¿¥¬ ∞ÊøÏ ¿Ã¿¸ ªÛ≈¬∞™ ¿Ø¡ˆ«œ∞Ì, state change µ» »ƒ noti«œµµ∑œ √≥∏Æ.
   - telephonyregistry.java
   - LGU+¥¬ 1xRTT ¡ˆø¯«œ¡ˆ æ ¿∏π«∑Œ ªË¡¶ «œ¿⁄!!!
   - 65l merge

*/
#define FEATURE_LGT_DS_DATA_AVOID_1X_ICON_DURING_4G_CONNECTED

/*
    Item:  cdmaltesetvicestate  ∞¸∑√ ºˆ¡§ 
    Commnet -20120613 jsmin
    Reason  - cmdaServicestate ∑Œ ∫Ø∞ÊΩ√ radio tech evdo æ»ø√∂Ûø¿¥¬ «ˆªÛ 
                - dun «¡∑Œ∆ƒ¿œ∑Œ µø¿€ «œ¥¬ ∞¸∑√ ∆ƒ¿œ ªË¡¶

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
 	Reason - 1.QualcommSetting µ∑∫≈‰∏Æø° ¿÷¥¬ ∆ƒ¿œµÈ¿∫ user mode Ω√ Ω««‡µ«¡ˆ æ ¿∏π«∑Œ, dun, sync manager, data manger, curi explore∞° Ω««‡µ«¡ˆ æ ¿Ω.
        			2./dev/pantechø° File Write ±««— ∫Œø© Ω√ CTS Fail πﬂª˝«œø© /dev/pantech ±««— ªË¡¶ 
        			3. DUN_FIFO_FILE for DUN /data/dun -> /dev/pantech/dun
        			4.QualcommSetting ≥ª ∆ƒ¿œ¿Ã patch∑Œ ¿Œ«ÿ ºˆ¡§µ«æ˙¥Ÿ∏È, ¿Ãµøµ» ∆ƒ¿œµÈµµ ∞∞¿Ã ºˆ¡§«ÿ ¡÷æÓæﬂ «‘.   
        			5.  dun service start «œ∞Ì, Dun_Autoboot.javaø°º≠¥¬ º≠∫ÒΩ∫ start «œ¥¬ ∫Œ∫–¿ª ∏∑¿Ω.

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
    Reason - ∞£«Ê¿˚¿∏∑Œ radio tech 1x ªÛ≈¬ chap fail6»∏  ∆Àæ˜ «•Ω√ æ»µ«¥¬ πÆ¡¶
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
	              - EFS Erase »ƒø° 3G Menu Popup ø°º≠ ¬˜¥‹ º±≈√«œø©µµ Data Connection µ«¥¬ πÆ¡¶ ºˆ¡§
                     - isReadyForData √º≈© «‘ºˆø°º≠ Preferred_Data_network √º≈©«œ¥¬ ∫Œ∫– √ﬂ∞° «‘.
                      - Radio On π◊ Data Radio ∞° Unknown¿Ã æ∆¥— ∞ÊøÏø°∏∏ Popup πﬂª˝«œµµ∑œ Check routine¿ª isReadyForData()∑Œ ∫Ø∞Ê

	Modified files - CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),
*/
#define FEATURE_LGT_DS_3G_DATA_MENU_POPUP_BUG_FIX


#define FEATURE_LGT_DATA_EZSETTING

/*
    Item : 3G  Boot-up pop not display 

	Commnet - 20120525 jsmin
	Reason - Fix & add something at FEATURE_LGT_DS_3G_DATA_MENU_POPUP
	              - try setupdata »£√‚Ω√ radio tech∞° 1x ªÛ≈¬ø°º≠ ¿Ã»ƒø° evdo∑Œ ∫Ø∞Ê µ«¥¬µ•  ∫Œ∆√ ∆Àæ˜¿Ã «•Ω√ µ«¡ˆ æ æ∆º≠ 
	                 ¥ŸΩ√  try setupdata »£√‚ «œµµ∑œ √≥∏Æ«‘ 
	              - ∫Œ∆√ ∆Àæ˜ «•Ω√ æ»«œ¥¬ ∞ÊøÏµµ µø¿œ«œ∞‘ 1x ªÛ≈¬ø°º≠  trysetupdata »£√‚¿Ã ∏’¿˙ «—»ƒ ¬˜»ƒø° evdo ∫Ø∞Êµ«æÓ µ•¿Ã≈∏ ø¨∞· æ»µ«¥¬ «ˆªÛ πﬂª˝   

	Commnet - 20120613 jsmin
	Reason - ∫Ò«‡¡ﬂ ∏µÂ»ƒ  evdo ∑Œ radio tech Ω√  ¥ŸΩ√  try setupdata »£√‚ «œµµ∑œ √≥∏Æ«‘ 
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
	Reason-Phone Interface∏¶ ¡¢±Ÿ ∏¯«œ¥¬ APP∏¶ ¿ß«œø© AIDL¿ª √ﬂ∞°  

	Modified files - Android.mk(LINUX\android\frameworks\base), 
			         service_manager.c(LINUX\android\frameworks\base\cmds\servicemanager),
				  DataConnectionTracker.java (\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)
				           
	Added files - ISkyDataConnection.aidl (LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony),
			      SkyDataConInterfaceManager.java (LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_ADD_DATA_AIDL



/* Item : CNE
 	Commnet - 20120105 Alice
 	Reason - ConnectivityService¿« handleConnectivityChanged()«‘ºˆ≥ªø°º≠ CNE∞° ±∏µøµ«¥¬ ¡ˆ √º≈©«œø© addDefaultRoute()«‘ºˆ ¥ÎΩ≈ø° addSourceRoute()»£√‚µ«æÓ Default Route∞° ºº∆√µ«¡ˆ æ æ∆º≠ πﬂª˝
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
 	Reason - dns check ∫Œ∫–ø°º≠ null_ip ∏¶ 0.0.0.0 ¿Œ ∞ÊøÏ ∏∏ √º≈©«œ¥¬ πÆ¡¶, null ¿Œ ∞ÊøÏ(length∞° 0)µµ √º≈©«œµµ∑œ ºˆ¡§. 
 	Modified files - CdmaDataConnection.java(\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma)
*/
#define FEATURE_LGT_DS_PS_NULL_DNS_CHECK

/* Item : Data Connection
 	Commnet - 20120111 Alice
 	Reason - - data connection fail cause ø° ¥Î«ÿ √≥∏Æµ«¡ˆ æ ¥¬ πÆ¡¶ 
                     - fail πﬂª˝Ω√ cause query «œµµ∑œ ºˆ¡§.
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
 	Reason - - data disconnect µ» º¯∞£_test_dns check ºˆ«‡«ÿº≠ mms ¿¸º€«œ∑¡∞Ì Inetaddress.getbyname «œ∏È unknown host exception πﬂª˝«œ¥¬ πÆ¡¶
 	Modified files - getaddrinfo.c(android\bionic\libc\netbsd\net)
*/
#define FEATURE_LGT_DS_DISABLE_TEST_DNS

/*   Item : Data Connection
 	Commnet - 20120113 Alice
 	Reason - VT(startusingnetworkfeature(), TYPE_DUN) ªÁøÎΩ√
 			    "168.126.63.1"/"168.126.63.2" ø° ¥Î«ÿº≠ ROUTE TABLE µÓ∑œ «œ¡ˆ æ ¿Ω.
 	Modified files -\android\frameworks\base\services\java\com\android\server\ConnectivityService.java
*/
#define FEATURE_LGU_DS_3G_DNS_REMOVE_IN_ROUTETABLE


/* Item: WIFI+VT

    - From 35GB  merge
    - Wifi connectedΩ√ø° 3g icon¿ª º˚±‚¡ˆ∏∏ mms µÓ default≥™ dun¿« ∞ÊøÏ∞° æ∆¥— service type¿ª ¿ÃøÎ«ÿ 3g∏¶ ≈Î«ÿ data ¿¸º€¿Ã ¿Ã∑ÁæÓ¡˙ ∞ÊøÏø° 3g icon «•Ω√. 
    - mms ¿¸º€ Ω√¥¬  3g «•Ω√ 

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
 	Reason  - wifi onΩ√  defult ªË¡¶»ƒ ¥ŸΩ√ wifi off Ω√  3g default ∞° ø√∂Û ø¿¡ˆ æ æ∆º≠  ∂ÛøÏ∆Æø° ¥ŸΩ√ √ﬂ∞° «œ¥¬ ƒ⁄µÂ∑Œ ºˆ¡§ 
 	            -  wifi on Ω√   vt  regi ¿Ø¡ˆ∑Œ 3g defult ∞° 2∞≥ ¿‚»˜¥¬ «ˆªÛ πﬂª˝  
 	Modified files - \android\frameworks\base\services\java\com\android\server\ConnectivityService.java

*/

#define FEATURE_LGU_DS_REMOVE_DEFAULT_ROUTE


/*
      Item : APN switch  µø¿€ ∏∑¿Ω 
 	Commnet - 20120613 jsmin
 	Reason -  apn  switchΩ√  teardown µø¿€ »ƒ ¥ŸΩ√ ∫Ÿ¥¬ «ˆªÛ πﬂª˝ 
 	
 	Modified files - \android\frameworks\base\telephony\java\com\android\internal\telephony\cdma\cdmaDataConnectionTracker.java

*/

#define FEATURE_LGT_DS_NOT_APN_SWITCH



/* Item : RADIO
	Commnet - 20120113 Alice
   Reason - RADIO TechÍ∞Ä Data Connection state, qcrilÎã® Ï†ïÎ≥¥ÏôÄ ÏùºÏπò ÌïòÏßÄ ÏïäÎäî Í≤ΩÏö∞.
*/
#define FEATURE_LGU_DS_UNKNOWN_RADIO

#ifdef FEATURE_LGU_DS_UNKNOWN_RADIO
/* Item : RADIO
	Commnet - 20120113 Alice
	Reason  - preferred data radio tech ¡ﬂ eHRPD ∞° QMI_WDS ø°º≠ ¿¸¥ﬁµ«¡ˆ æ æ∆ Preferred mode change Ω√ LTE ∞™ 
                    ¿Ø¡ˆ«œ∞Ì, ¿Ã∑Œ¿Œ«ÿ pdt_modem_id  ø°∑Ø √≥∏Æµ«¥¬ πÆ¡¶ ºˆ¡§.

	Modified files - qcril_arb.c(android\vendor\qcom\proprietary\qcril\qcril_fusion), 
*/
//#define FEATURE_LGT_DS_PS_UNKNOWN_RADIO_TECH

/* Item : RADIO
	Commnet - 20120113 Alice
	Reason - OOS(Out of Service) Ïù∏ Í≤ΩÏö∞(RADIO TECH UNKNOWK), FrameworkÏóêÏÑú  networkinfo.available() Ïù¥
	             falseÎ°ú ÏÑ§Ï†ïÎêòÏñ¥ AMSSÍ∞Ä Ïã§Ï†ú Network Ïó∞Í≤∞ ÏÉÅÌÉú, Ï¶â Îç∞Ïù¥ÌÑ∞ Ïó∞Í≤∞ Ï§ëÏûÑÏóêÎèÑ
	             App.ÏóêÏÑú Ïó∞Í≤∞Ïù¥ ÎÅäÏñ¥ÏßÑ Í≤ÉÏúºÎ°ú Ïù∏ÏãùÌïòÎäî Î¨∏Ï†ú ÏàòÏ†ï.
	Modified files - MobileDataStateTracker.java(\android\frameworks\base\core\java\android\net),	
				 NetworkController.java (android\frameworks\base\packages\systemui\src\com\android\systemui\statusbar\policy)	 
*/
#define FEATURE_LGT_DS_AVOID_OOS_FOR_APP

/* Item : RADIO
	Commnet - 20120227 Alice
	Reason - OOS ÏßÑÏûÖÏãú OOS Timer start. Expired ÏãúÏ†êÏóê Îã§Ïãú data connection state ÌôïÏù∏.
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
    - Fast Dormancy ±‚¥… ±‘«ˆ
    - LGU+ Ω√≥™∏Æø¿ : LCD ON Fast Dormant ¡ˆø¯ æ»«‘, LCD OFFΩ√ 3√  »ƒ Dormant ¡¯¿‘
    - aArm : LCD ON/OFF ¡§∫∏∏¶ mArm¿∏∑Œ ¿¸¥ﬁ«œµµ∑œ ºˆ¡§
    - mArm : FEATURE_SKT_DS_FAST_DORMANCY ¬¸∞Ì  
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
  Reaseon - qmi ¿Œ≈Õ∆‰¿ÃΩ∫ µø¿€¿ª æ»«ÿº≠ ∫Ø∞Ê 
  
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
  Reaseon -qos  qmi ¿Œ≈Õ∆‰¿ÃΩ∫ µø¿€   
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
reaseon- 1.qos qmi ∞¸∑√ «ÿº≠ vt qos æÓ«√ ¿ª  »Æ¿Œ«ÿ ∫ª∞·∞˙ ∏Æ¥™Ω∫ø°º≠ ∫∏≥ª¥¬ port ∞™¿Ã ¥Ÿ∏£∞‘ ¿¸º€ µ«¥¬ «ˆªÛ ºˆ¡§
              2.cpmgr ¿Ã∫•∆Æ∏¶ ∫∏≥æ∞Ì ∏µ©ø° ¿Ã∫•∆Æ∞° æ»≥ª∑¡ø¿¥¬ «ˆªÛ ºˆ¡§
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
                  - EF13L ∏¡ø¨µø πÆ¡¶¡° : EF13L¿« ∞ÊøÏ Data Roaming¿ª ¡ˆø¯«œ¡ˆ æ ¿∏π«∑Œ Data Roaming∞¸∑√ 'æÀ∏≤'¿ª «•Ω√«œ∏È æ»µ 
                  - Data Roaming ∞¸∑√ 'æÀ∏≤'¿ª «•Ω√ æ»«œµµ∑œ ºˆ¡§
                   - RoamingΩ√ Data Ω√µµ æ»«œµµ∑œ ºˆ¡§
     Modified Files -PhoneApp.java,
                           CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),   
   
*/
#define FEATURE_LGT_DISABLE_DATA_ROAMING_NOTI


/* Item : Datacall
    Comment -20120508 jsmin
    Reason -EF35L GB merge
    -EF35L GB feature -DS1_DS_CONTROL_DATACALL_WITH_1X_REG
   - LGT ø‰±∏ ªÁ«◊¿∏∑Œ 1X Registration ¿Ã¿¸ø°¥¬ Data»£∏¶ ∏∑¿Ω
   - EVDO Only¿« ∞ÊøÏ 1X RegiøÕ ∞¸∞Ë æ¯¿Ã Data»£∏¶ Ω√µµ
   modifed file - DataConnectionTracker.java (\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)

*/
#define FEATURE_LGT_DS_CONTROL_DATACALL_WITH_1X_REG

/*20111005 sjm
- ACTION_ANY_DATA_CONNECTION_STATE_CHANGED ∏¶ phoneStateListener ∫∏¥Ÿ øÏº± √≥∏Æµ«µµ∑œ ∫Ø∞Ê.
- PhoneStateListener√≥∏Æø°º≠ syncronized ¿Ã»ƒ intent action broadcasting µ«¡ˆ æ ¥¬ ∞ÊøÏ 1»∏ πﬂª˝.
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
	Reason - radio tech rev.B ¿Œ∞ÊøÏ DATA ¡ˆø¯ ∞°¥… «œµµ∑œ ºˆ¡§
      Modified files - CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),   
                            CdmaServiceStateTracker.java(\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma)
*/
#define FEATURE_LGT_DS_REV_B



/*......................................................................................................................................
  Merge ING~
.........................................................................................................................................*/
/* Item : RADIO

  Commnet  20120105 Alice
  Reason  - Preferred data tech¥¬ 1x¿Ã¡ˆ∏∏ MDM¿∫ LTE∑Œ µø¿€«œ¥¬ ∞ÊøÏ∞° πﬂª˝«œø© LTE Service available¿Ã∏È Radio tech¿ª LTE∑Œ ºˆ¡§ 
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
     Reason  -UDP«¡∑Œ≈‰ƒ› ¿ÃøÎ«“ ∂ß, DLº”µµ ¿˙«œ πÆ¡¶ 
                  (https://android-review.googlesource.com/#/c/37471/)
                  
     Modified files -
    \LINUX\android\libcore\luni\src\main\java\java\net\DatagramPacket.java
    \LINUX\android\libcore\luni\src\main\java\java\net\DatagramSocket.java
    \LINUX\android\libcore\luni\src\main\java\libcore\io\IoBridge.java
    \LINUX\android\libcore\luni\src\test\java\libcore\java\net\OldDatagramSocketTest.java

*/



#endif/* __CUST_PANTECH_DS_H__ */


