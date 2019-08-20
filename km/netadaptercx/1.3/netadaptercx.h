/*++

Copyright (c) Microsoft Corporation

Module Name:
    NetAdapterCx.h

Abstract:
    The NdisCx client includes this file in its code.
    This file includes all the necessary NDIS files needed for the NdisCx client.

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _NETADAPTERCX_H_
#define _NETADAPTERCX_H_

#ifndef WDF_EXTERN_C
  #ifdef __cplusplus
    #define WDF_EXTERN_C       extern "C"
    #define WDF_EXTERN_C_START extern "C" {
    #define WDF_EXTERN_C_END   }
  #else
    #define WDF_EXTERN_C
    #define WDF_EXTERN_C_START
    #define WDF_EXTERN_C_END
  #endif
#endif

WDF_EXTERN_C_START



#if !defined(WDFAPI)
#error Include wdf.h first
#endif

#if defined(NET_ADAPTER_CX_1_0)
#error Redefinition of NetAdapterCx reserved macro NET_ADAPTER_CX_1_0
#endif

#if defined(NET_ADAPTER_CX_1_1)
#error Redefinition of NetAdapterCx reserved macro NET_ADAPTER_CX_1_1
#endif

#if defined(NET_ADAPTER_CX_1_2)
#error Redefinition of NetAdapterCx reserved macro NET_ADAPTER_CX_1_2
#endif

#if defined(NET_ADAPTER_CX_1_3)
#error Redefinition of NetAdapterCx reserved macro NET_ADAPTER_CX_1_3
#endif

#define NET_ADAPTER_CX_1_3 1


#include <ndis.h>

#pragma warning(push)
#pragma warning(disable:4201) // 'nonstandard extension used: nameless struct/union'

#include <netringbuffer.h>
#include <netpacket.h>
#include <netdatapathdescriptor.h>

#pragma warning(disable:4214) // 'nonstandard extension used : bit field types other than int'

#include <netadaptercxtypes.h>
#include <netadaptercxfuncenum.h>
#include <netdevice.h>

#include <netadapterpacket.h>
#include <nettxqueue.h>
#include <netrxqueue.h>
#include <netadapter.h>
#include <netconfiguration.h>
#include <netrequest.h>
#include <netrequestqueue.h>
#include <netpowersettings.h>

#pragma warning(pop)

WDF_EXTERN_C_END

#endif // _NETADAPTERCX_H_

