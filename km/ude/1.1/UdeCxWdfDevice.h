/*++

Copyright (c) Microsoft Corporation. All Rights Reserved.

Module Name:

    UdecxWdfDevice.h

Abstract:

    This is the interface for UDECX WdfDevice.

Environment:

    kernel mode only

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _UDECXWDFDEVICE_H_
#define _UDECXWDFDEVICE_H_

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



typedef enum _UDECX_WDF_DEVICE_RESET_ACTION {
    UdecxWdfDeviceResetActionResetEachUsbDevice = 0,
    UdecxWdfDeviceResetActionResetWdfDevice,
} UDECX_WDF_DEVICE_RESET_ACTION, *PUDECX_WDF_DEVICE_RESET_ACTION;

typedef enum _UDECX_WDF_DEVICE_RESET_TYPE {
    UdecxWdfDeviceResetUndefined = 0,
    UdecxWdfDeviceResetAttemptFunctionLevelDeviceReset,
    UdecxWdfDeviceResetAttemptPlatformLevelDeviceReset,
} UDECX_WDF_DEVICE_RESET_TYPE, *PUDECX_WDF_DEVICE_RESET_TYPE;



typedef
_Function_class_(EVT_UDECX_WDF_DEVICE_QUERY_USB_CAPABILITY)
_IRQL_requires_same_
NTSTATUS
EVT_UDECX_WDF_DEVICE_QUERY_USB_CAPABILITY(
    _In_
        WDFDEVICE     UdecxWdfDevice,
    _In_ 
        PGUID         CapabilityType,
    _In_
        ULONG         OutputBufferLength,
    _Out_writes_to_opt_(OutputBufferLength, *ResultLength)
        PVOID         OutputBuffer,
    _Out_
        PULONG        ResultLength
    );

typedef EVT_UDECX_WDF_DEVICE_QUERY_USB_CAPABILITY *PFN_UDECX_WDF_DEVICE_QUERY_USB_CAPABILITY;

typedef
_Function_class_(EVT_UDECX_WDF_DEVICE_RESET)
_IRQL_requires_same_
VOID
EVT_UDECX_WDF_DEVICE_RESET(
    _In_
        WDFDEVICE     UdecxWdfDevice
    );

typedef EVT_UDECX_WDF_DEVICE_RESET *PFN_UDECX_WDF_DEVICE_RESET;

typedef struct _UDECX_WDF_DEVICE_CONFIG {

    ULONG                                       Size;

    //
    // Optional - default 1 each.
    // TODO: don't need this note anymore?
    // Specifying PortNumber in other APIs:
    //     2.0 ports are numbered (1, NumberOfUsb20Ports)
    //     3.0 ports are numbered (NumberOfUsb20Ports + 1, NumberOfUsb20Ports + NumberOfUsb30Ports)
    //
    USHORT                                      NumberOfUsb20Ports;
    USHORT                                      NumberOfUsb30Ports;

    //
    // Required.
    //
    PFN_UDECX_WDF_DEVICE_QUERY_USB_CAPABILITY     EvtUdecxWdfDeviceQueryUsbCapability;

    //
    // Optional - default UdecxWdfDeviceResetActionResetEachUsbDevice.
    //
    UDECX_WDF_DEVICE_RESET_ACTION                 ResetAction;

    //
    // Optional. Required if ResetAction == UdecxWdfDeviceResetActionResetWdfDevice.
    //
    PFN_UDECX_WDF_DEVICE_RESET                    EvtUdecxWdfDeviceReset;

} UDECX_WDF_DEVICE_CONFIG, *PUDECX_WDF_DEVICE_CONFIG;

FORCEINLINE
VOID
UDECX_WDF_DEVICE_CONFIG_INIT(
    _Out_
        PUDECX_WDF_DEVICE_CONFIG                      Config,
    _In_
        PFN_UDECX_WDF_DEVICE_QUERY_USB_CAPABILITY     EvtUdecxWdfDeviceQueryUsbCapability
    )
{
    Config->Size = sizeof(*Config);
    Config->NumberOfUsb20Ports = 1;
    Config->NumberOfUsb30Ports = 1;
    Config->EvtUdecxWdfDeviceQueryUsbCapability = EvtUdecxWdfDeviceQueryUsbCapability;
    Config->ResetAction = UdecxWdfDeviceResetActionResetEachUsbDevice;
    Config->EvtUdecxWdfDeviceReset = NULL;
}

//
// UDECX Function: UdecxInitializeWdfDeviceInit
//
typedef
_Must_inspect_result_
WDFAPI
NTSTATUS
(*PFN_UDECXINITIALIZEWDFDEVICEINIT)(
    _In_
    PUDECX_DRIVER_GLOBALS DriverGlobals,
    _Inout_
    PWDFDEVICE_INIT WdfDeviceInit
    );

_Must_inspect_result_
NTSTATUS
FORCEINLINE
UdecxInitializeWdfDeviceInit(
    _Inout_
    PWDFDEVICE_INIT WdfDeviceInit
    )
{
    return ((PFN_UDECXINITIALIZEWDFDEVICEINIT) UdecxFunctions[UdecxInitializeWdfDeviceInitTableIndex])(UdecxDriverGlobals, WdfDeviceInit);
}

//
// UDECX Function: UdecxWdfDeviceNeedsReset
//
typedef
WDFAPI
NTSTATUS
(*PFN_UDECXWDFDEVICENEEDSRESET)(
    _In_
    PUDECX_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE UdeWdfDevice,
    _In_
    UDECX_WDF_DEVICE_RESET_TYPE ResetType
    );

NTSTATUS
FORCEINLINE
UdecxWdfDeviceNeedsReset(
    _In_
    WDFDEVICE UdeWdfDevice,
    _In_
    UDECX_WDF_DEVICE_RESET_TYPE ResetType
    )
{
    return ((PFN_UDECXWDFDEVICENEEDSRESET) UdecxFunctions[UdecxWdfDeviceNeedsResetTableIndex])(UdecxDriverGlobals, UdeWdfDevice, ResetType);
}

//
// UDECX Function: UdecxWdfDeviceResetComplete
//
typedef
WDFAPI
VOID
(*PFN_UDECXWDFDEVICERESETCOMPLETE)(
    _In_
    PUDECX_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE UdeWdfDevice
    );

VOID
FORCEINLINE
UdecxWdfDeviceResetComplete(
    _In_
    WDFDEVICE UdeWdfDevice
    )
{
    ((PFN_UDECXWDFDEVICERESETCOMPLETE) UdecxFunctions[UdecxWdfDeviceResetCompleteTableIndex])(UdecxDriverGlobals, UdeWdfDevice);
}

//
// UDECX Function: UdecxWdfDeviceAddUsbDeviceEmulation
//
typedef
_Must_inspect_result_
WDFAPI
NTSTATUS
(*PFN_UDECXWDFDEVICEADDUSBDEVICEEMULATION)(
    _In_
    PUDECX_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE WdfDevice,
    _In_
    PUDECX_WDF_DEVICE_CONFIG Config
    );

_Must_inspect_result_
NTSTATUS
FORCEINLINE
UdecxWdfDeviceAddUsbDeviceEmulation(
    _In_
    WDFDEVICE WdfDevice,
    _In_
    PUDECX_WDF_DEVICE_CONFIG Config
    )
{
    return ((PFN_UDECXWDFDEVICEADDUSBDEVICEEMULATION) UdecxFunctions[UdecxWdfDeviceAddUsbDeviceEmulationTableIndex])(UdecxDriverGlobals, WdfDevice, Config);
}

//
// UDECX Function: UdecxWdfDeviceTryHandleUserIoctl
//
typedef
WDFAPI
BOOLEAN
(*PFN_UDECXWDFDEVICETRYHANDLEUSERIOCTL)(
    _In_
    PUDECX_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE UdecxWdfDevice,
    _In_
    WDFREQUEST Request
    );

BOOLEAN
FORCEINLINE
UdecxWdfDeviceTryHandleUserIoctl(
    _In_
    WDFDEVICE UdecxWdfDevice,
    _In_
    WDFREQUEST Request
    )
{
    return ((PFN_UDECXWDFDEVICETRYHANDLEUSERIOCTL) UdecxFunctions[UdecxWdfDeviceTryHandleUserIoctlTableIndex])(UdecxDriverGlobals, UdecxWdfDevice, Request);
}




WDF_EXTERN_C_END

#endif // _UDECXWDFDEVICE_H_

