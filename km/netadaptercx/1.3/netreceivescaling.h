// Copyright (C) Microsoft Corporation. All rights reserved.

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _NETRECEIVESCALING_H_
#define _NETRECEIVESCALING_H_

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


// Copyright (C) Microsoft Corporation. All rights reserved.

typedef enum _NET_ADAPTER_RECEIVE_SCALING_UNHASHED_TARGET_TYPE {
    // 
    // Indicates the device does not distribute unhashed frames
    // to a specific index.
    // 
    NetAdapterReceiveScalingUnhashedTargetTypeUnspecified = 0,
    // 
    // Indicates the device distributes unhashed frames to a
    // specific index. The index used is specified with the
    // UnhashedTargetIndex value.
    // 
    NetAdapterReceiveScalingUnhashedTargetTypeHashIndex,
} NET_ADAPTER_RECEIVE_SCALING_UNHASHED_TARGET_TYPE;

typedef enum _NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE {
    NetAdapterReceiveScalingHashTypeNone = 0x00000000,
    // 
    // Indicates support for the Toeplitz hashing function.
    // 
    NetAdapterReceiveScalingHashTypeToeplitz = 0x00000001,
} NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE;

typedef enum _NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE {
    NetAdapterReceiveScalingProtocolTypeNone = 0x00000000,
    // 
    // Indicates that the hardware can calculate hashes for IPv4 packets.
    // 
    NetAdapterReceiveScalingProtocolTypeIPv4 = 0x00000001,
    // 
    // Indicates hardware understands IPv4 options.
    // 
    // Requires NetAdapterReceiveScalingProtocolTypeIPv4.
    // 
    NetAdapterReceiveScalingProtocolTypeIPv4Options = 0x00000002,
    // 
    // Indicates hardware can calculate hashes for IPv6 packets.
    // 
    NetAdapterReceiveScalingProtocolTypeIPv6 = 0x00000004,
    // 
    // Indicates hardware understands IPv6 extension headers
    // 
    // Requires NetAdapterReceiveScalingProtocolTypeIPv6.
    // 
    NetAdapterReceiveScalingProtocolTypeIPv6Extensions = 0x00000008,
    // 
    // Indicates hardware supports 4-tuple TCP header hash calculation
    // 
    NetAdapterReceiveScalingProtocolTypeTcp = 0x00000010,
    // 
    // Indicates hardware supports 4-tuple UDP header hash calculation
    // 
    NetAdapterReceiveScalingProtocolTypeUdp = 0x00000020,
} NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE;

typedef enum _NET_ADAPTER_RECEIVE_SCALING_ENCAPSULATION_TYPE {
    NetAdapterReceiveScalingEncapsulationTypeNone = 0x00000000,
    // 
    // Indicates hardware understands how to bypass NV-GRE
    // encapsulation.
    // 
    NetAdapterReceiveScalingEncapsulationTypeNVGre = 0x00000001,
    // 
    // Indicates hardware understands how to bypass VXLan
    // encapsulation.
    // 
    NetAdapterReceiveScalingEncapsulationTypeVXLan = 0x00000002,
    // 
    // Indicates hardware understands how to bypass VLan
    // encapsulation.
    // 
    NetAdapterReceiveScalingEncapsulationTypeVLan = 0x00000004,
} NET_ADAPTER_RECEIVE_SCALING_ENCAPSULATION_TYPE;



DEFINE_ENUM_FLAG_OPERATORS(NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE);
DEFINE_ENUM_FLAG_OPERATORS(NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE);
DEFINE_ENUM_FLAG_OPERATORS(NET_ADAPTER_RECEIVE_SCALING_ENCAPSULATION_TYPE);

typedef struct _NET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY
{
    _Field_size_full_(Length) UINT8 * Key;
    SIZE_T Length;
} NET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY, *PNET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY;

typedef NET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY const * PCNET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY;

typedef struct _NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRY
{
    NETPACKETQUEUE Queue;
    NTSTATUS Status;
    UINT32 Index;
} NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRY;

typedef struct _NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRIES
{
    _Field_size_full_(Length) NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRY * Entries;
    SIZE_T Length;
} NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRIES, *PNET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRIES;

typedef
_Function_class_(EVT_NET_ADAPTER_RECEIVE_SCALING_ENABLE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
EVT_NET_ADAPTER_RECEIVE_SCALING_ENABLE(
    _In_
    NETADAPTER Adapter,
    _In_
    NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE HashType,
    _In_
    NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE ProtocolType
    );

typedef EVT_NET_ADAPTER_RECEIVE_SCALING_ENABLE *PFN_NET_ADAPTER_RECEIVE_SCALING_ENABLE;

typedef
_Function_class_(EVT_NET_ADAPTER_RECEIVE_SCALING_DISABLE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
VOID
EVT_NET_ADAPTER_RECEIVE_SCALING_DISABLE(
    _In_
    NETADAPTER Adapter
    );

typedef EVT_NET_ADAPTER_RECEIVE_SCALING_DISABLE *PFN_NET_ADAPTER_RECEIVE_SCALING_DISABLE;

typedef
_Function_class_(EVT_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
EVT_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY(
    _In_
    NETADAPTER Adapter,
    _In_
    PCNET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY HashSecretKey
    );

typedef EVT_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY *PFN_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY;

typedef
_Function_class_(EVT_NET_ADAPTER_RECEIVE_SCALING_SET_INDIRECTION_ENTRIES)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
EVT_NET_ADAPTER_RECEIVE_SCALING_SET_INDIRECTION_ENTRIES(
    _In_
    NETADAPTER Adapter,
    _Inout_
    PNET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRIES IndirectionEntries
    );

typedef EVT_NET_ADAPTER_RECEIVE_SCALING_SET_INDIRECTION_ENTRIES *PFN_NET_ADAPTER_RECEIVE_SCALING_SET_INDIRECTION_ENTRIES;

typedef struct _NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES {
    //
    // Size of structure.
    //
    ULONG Size;

    //
    // Number of hardware receive queues.
    // Shall be a power of 2.
    //
    SIZE_T NumberOfQueues;

    //
    // Number of indirection table entries.
    // Shall be a power of 2.
    //
    SIZE_T IndirectionTableSize;

    //
    // Default index used for unhashed frames.
    //
    // Depends on the UnhashedTargetType.
    //
    // When UnhashedTargetType is NetAdapterReceiveScalingUnhashedTargetHashIndex
    // UnhashedTargetIndex specifies a hash index.
    //
    SIZE_T UnhashedTargetIndex;

    //
    // Indicates the type of handling for unhashed frames.
    //
    // If NetAdapterReceiveScalingUnhashedTargetNone then UnhashedTargetIndex
    // is ignored UnhashedTargetIndex defaults to 0.
    //
    // If NetAdapterReceiveScalingUnhashedTargetTypeHashIndex then UnhashedTargetIndex
    // indicates the target hash index.
    //
    // UnhashedTargetIndex shall be N where 0 <= N < IndirectionTableSize.
    //
    NET_ADAPTER_RECEIVE_SCALING_UNHASHED_TARGET_TYPE UnhashedTargetType;

    //
    // Supported hash types.
    //
    NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE ReceiveScalingHashTypes;

    //
    // Supported RSS protocol types.
    //
    NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE ReceiveScalingProtocolTypes;

    //
    // Indicates which encapsulation technologies the hardware is capable of
    // bypassing.
    //
    struct _RECEIEVE_SCALING_ENCAPSULATION {
        NET_ADAPTER_RECEIVE_SCALING_ENCAPSULATION_TYPE Outer;
        NET_ADAPTER_RECEIVE_SCALING_ENCAPSULATION_TYPE Inner;
    } ReceiveScalingEncapsulationTypes;

    //
    // When true requests that calls to EvtAdapterReceiveScalingSetIndirectionEntries
    // be synchronized. Default is false.
    //
    BOOLEAN SynchronizeSetIndirectionEntries;

    PFN_NET_ADAPTER_RECEIVE_SCALING_ENABLE EvtAdapterReceiveScalingEnable;
    PFN_NET_ADAPTER_RECEIVE_SCALING_DISABLE EvtAdapterReceiveScalingDisable;
    PFN_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY EvtAdapterReceiveScalingSetHashSecretKey;
    PFN_NET_ADAPTER_RECEIVE_SCALING_SET_INDIRECTION_ENTRIES EvtAdapterReceiveScalingSetIndirectionEntries;

} NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES;

typedef NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES const * PCNET_ADAPTER_RECEIVE_SCALING_CAPABILITIES;

FORCEINLINE
VOID
NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES_INIT(
    _Out_ NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES * Capabilities,
    _In_ SIZE_T NumberOfQueues,
    _In_ NET_ADAPTER_RECEIVE_SCALING_UNHASHED_TARGET_TYPE UnhashedTargetType,
    _In_ NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE HashTypes,
    _In_ NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE ProtocolTypes,
    _In_ PFN_NET_ADAPTER_RECEIVE_SCALING_ENABLE Enable,
    _In_ PFN_NET_ADAPTER_RECEIVE_SCALING_DISABLE Disable,
    _In_ PFN_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY SetHashSecretKey,
    _In_ PFN_NET_ADAPTER_RECEIVE_SCALING_SET_INDIRECTION_ENTRIES SetIndirectionEntries
    )
{
    RtlZeroMemory(Capabilities, sizeof(NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES));
    Capabilities->Size = sizeof(NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES);
    Capabilities->NumberOfQueues = NumberOfQueues;
    Capabilities->UnhashedTargetType = UnhashedTargetType;
    Capabilities->IndirectionTableSize = NDIS_RSS_INDIRECTION_TABLE_MAX_SIZE_REVISION_1;
    Capabilities->ReceiveScalingHashTypes = HashTypes;
    Capabilities->ReceiveScalingProtocolTypes = ProtocolTypes;
    Capabilities->ReceiveScalingEncapsulationTypes.Outer = NetAdapterReceiveScalingEncapsulationTypeNone;
    Capabilities->ReceiveScalingEncapsulationTypes.Inner = NetAdapterReceiveScalingEncapsulationTypeNone;
    Capabilities->SynchronizeSetIndirectionEntries = FALSE;
    Capabilities->EvtAdapterReceiveScalingEnable = Enable;
    Capabilities->EvtAdapterReceiveScalingDisable = Disable;
    Capabilities->EvtAdapterReceiveScalingSetHashSecretKey = SetHashSecretKey;
    Capabilities->EvtAdapterReceiveScalingSetIndirectionEntries = SetIndirectionEntries;
}

//
// NET Function: NetAdapterSetReceiveScalingCapabilities
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
VOID
(*PFN_NETADAPTERSETRECEIVESCALINGCAPABILITIES)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER Adapter,
    _In_
    PCNET_ADAPTER_RECEIVE_SCALING_CAPABILITIES Capabilities
    );

_IRQL_requires_(PASSIVE_LEVEL)
VOID
FORCEINLINE
NetAdapterSetReceiveScalingCapabilities(
    _In_
    NETADAPTER Adapter,
    _In_
    PCNET_ADAPTER_RECEIVE_SCALING_CAPABILITIES Capabilities
    )
{
    ((PFN_NETADAPTERSETRECEIVESCALINGCAPABILITIES) NetFunctions[NetAdapterSetReceiveScalingCapabilitiesTableIndex])(NetDriverGlobals, Adapter, Capabilities);
}




WDF_EXTERN_C_END

#endif // _NETRECEIVESCALING_H_

