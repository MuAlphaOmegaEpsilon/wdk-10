//**********************************************************************`
//* This is an include file generated by Message Compiler.             *`
//*                                                                    *`
//* Copyright (c) Microsoft Corporation. All Rights Reserved.          *`
//**********************************************************************`
#pragma once

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Provider "Microsoft-Windows-D3DUmdLogging" event count 3
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Provider GUID = a688ee40-d8d9-4736-b6f9-6b74935ba3b1
EXTERN_C __declspec(selectany) const GUID UMDEtwProviderGuid = {0xa688ee40, 0xd8d9, 0x4736, {0xb6, 0xf9, 0x6b, 0x74, 0x93, 0x5b, 0xa3, 0xb1}};

#ifndef UMDEtwProviderGuid_Traits
#define UMDEtwProviderGuid_Traits NULL
#endif // UMDEtwProviderGuid_Traits

//
// Channel
//
#define UMDEtwChannel 0x10

//
// Tasks
//
#define UMDEtwProviderGuid_TASK_MapAllocation 0x1

//
// Keyword
//
#define MAPPING_KEYWORD 0x1

//
// Event Descriptors
//
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR MapAllocationEvent = {0x1, 0x0, 0x10, 0x0, 0x1, 0x1, 0x8000000000000001};
#define MapAllocationEvent_value 0x1
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR RundownAllocationEvent = {0x2, 0x0, 0x10, 0x0, 0x3, 0x1, 0x8000000000000001};
#define RundownAllocationEvent_value 0x2
EXTERN_C __declspec(selectany) const EVENT_DESCRIPTOR UnmapAllocationEvent = {0x3, 0x0, 0x10, 0x0, 0x2, 0x1, 0x8000000000000001};
#define UnmapAllocationEvent_value 0x3

#define MSG_Map_None                         0xD0000001L
#define MSG_Map_DmaBuffer                    0xD0000002L
#define MSG_Map_UploadStaging                0xD0000003L
#define MSG_Map_DownloadStaging              0xD0000004L
#define MSG_Map_ContextSave                  0xD0000005L
#define MSG_Map_Pack                         0xF0000001L
#define MSG_Map_Rename                       0xF0000002L
