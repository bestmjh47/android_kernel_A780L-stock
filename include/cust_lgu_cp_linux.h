#ifndef __CUST_LGU_CP_LINUX_H
#define __CUST_LGU_CP_LINUX_H

/* =============================================================================
FILE: cust_lgu_cp_linux.h

Copyright (c) 2010 by PANTECH Incorporated.  All Rights Reserved.

============================================================================= */

/*************************************************/
/*                     COMMON                    */
/*************************************************/

#define FEATURE_LGU_CP_OEM_QMI_ACCESS

#define FEATURE_LGU_CP_OEM_COMMANDS_WITH_QMI
#define FEATURE_LGU_CP_COMMON_LOCAL_DB_WITH_QMI
#define FEATURE_LGU_CP_COMMON_NVIO_WITH_QMI

#define FEATURE_LGU_CP_MANAGER_DAEMON_INTERFACE
#ifdef FEATURE_LGU_CP_MANAGER_DAEMON_INTERFACE
#define FEATURE_LGU_COMMON_TELEPHONY_IF
#endif /* FEATURE_LGU_CP_MANAGER_DAEMON_INTERFACE */
#define FEATURE_LGU_CP_AUTOANSWER_INTERFACE

#define FEATURE_LGU_CP_COMMON_SIMPLE_NAM_WITH_QMI

/* Phone Operation Mode setting (lpm, offline, online .. ) */
#define FEATURE_LGU_CP_COMMON_PHONE_OPERATION_MODE

#define FEATURE_LGU_CP_RIL_FW_ANDROID_REQUEST_HNDL_MAX_EVT_ID_FIX
#define FEATURE_LGU_CP_OEM_API
#define FEATURE_LGU_CP_COMMON_RUDE_WAKEUP
#define FEATURE_LGU_CP_COMMON_RSSI

#define FEATURE_LGU_CP_COMMON_ENG_STATISTIC // ds1_cp_eng_statistic_log

#define FEATURE_LGU_CP_COMMON_OPENING_DAY
#ifdef FEATURE_LGU_CP_COMMON_OPENING_DAY
#define FEATURE_SKY_CP_NEW_OPENING_DAY
#define FEATURE_SKY_CP_OEM_PH_EVENT_WITH_QMI
#endif /* FEATURE_LGU_CP_COMMON_OPENING_DAY */

/*************************************************/
/*                     1X                        */
/*************************************************/

#define FEATURE_LGU_CP_1X_DEFAULT_SETUP

#define FEATURE_LGU_CP_1X_LOCAL_DB_WITH_QMI
#define FEATURE_LGU_CP_OEM_API
#define FEATURE_LGU_CP_1X_SYSLOST_MONITOR
#define FEATURE_LGU_CP_1X_PRL_VERSION

#define FEATURE_LGU_CP_1X_REG_STATE_UPDATE
#define FEATURE_LGU_CP_1X_REJ_DISPLAY

#define FEATURE_LGU_CP_1X_TEST_CALL_SO
#define FEATURE_LGU_CP_1X_8BIT_CHAR_SUPPORT

#define FEATURE_LGU_CP_1X_AKEY_INPUT
#define FEATURE_LGU_CP_1X_PRL_INFO_DISPLAY
#define FEATURE_LGU_CP_SKIP_TOA_CHECK
#define FEATURE_LGU_CP_1X_MISSED_CALL_BUG_FIX
#define FEATURE_LGU_CP_1X_FACTORY_INIT // ds1_cp_eng_statistic_log
/*************************************************/
/*                1X from EF35L                  */
/*************************************************/
#define FEATURE_LGU_CP_1X_MCCMNC_API_SUPPORT //ds1_cp_mcc_mnc_api_support_for_lgt
#define FEATURE_LGU_CP_1X_CURR_OPERATOR_INFO //ds1_cp_current_operator_info

#define FEATURE_LGU_CP_1X_ROAMING_IND_DISPLAY // ds1_cp_roaming_indicator_display
#define FEATURE_LGU_CP_1X_CAVE_ENABLE_MENU // ds1_cp_cave_auth_enabled_menu
#define FEATURE_LGU_CP_1X_FAKE_ROAMING_MENU // ds1_cp_roaming_fake_setting
#define FEATURE_LGU_CP_1X_LTS_SETTING_MENU // ds1_cp_lts_mccmnc_setting
#define FEATURE_LGU_CP_1X_OTASP // ds1_cp_lgt_ota_prl_download_progress
/*************************************************/
/*                    EVDO                       */
/*************************************************/

#define FEATURE_LGU_CP_EVDO_DB_QMI
#define FEATURE_LGU_CP_EVDO_DEBUG_SCREEN
#define FEATURE_LGU_CP_EVDO_ERROR_REASON_CODE_WITH_QMI

/*************************************************/
/*                   LBS(GPS)                    */
/*************************************************/
#define FEATURE_LGU_CP_GPS


#endif /* __CUST_LGU_CP_LINUX_H */

