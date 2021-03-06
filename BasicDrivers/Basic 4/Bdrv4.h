/*--

    Copyright (c) Santos Merino del Pozo.  All rights reserved.
    Use of this source code is governed by a MIT-style license which can be
    found in the LICENSE file.

    Module Name:

        Bdrv4.h

    Summary:

        This header contains definitions for Bdrv4.c

    Author:

        Santos Merino del Pozo (@santitox) - Initial version

    Contact:

        santos.research@gmail.com

--*/

#pragma once
//
// Use old-style declarators (when compiling with /W4 flag), see:
// https://msdn.microsoft.com/en-us/library/b92s55e9.aspx
//
#pragma warning(disable:4131)

#include <ntddk.h>
#include "..\Basic 3\Common.h"
#include "TimeInterval.h"

#define FILE_DEVICE_BASIC 0x00002a7b

//
// Global (constant) variables
//
LPCWSTR g_pszDeviceName = L"\\Device\\basicDevice";
LPCWSTR g_pszDeviceLink = L"\\DosDevices\\basicDevice";

//
// Function prototypes and role type declarations
//
_Function_class_(DRIVER_DISPATCH)
NTSTATUS
Bdrv4DefaultDispatch (
    _Inout_ PDEVICE_OBJECT pDeviceObject,
    _Inout_ PIRP pIrp
    );

_Dispatch_type_(IRP_MJ_DEVICE_CONTROL)
_Function_class_(DRIVER_DISPATCH)
NTSTATUS
Bdrv4DispatchDeviceControl (
    _Inout_ PDEVICE_OBJECT pDeviceObject,
    _Inout_ PIRP pIrp
    );

VOID
Bdrv4HandleIoctlSayHello (
    _In_ PVOID pStartContext
    );

_Function_class_(DRIVER_UNLOAD)
VOID
Bdrv4DriverUnload (
    _In_ PDRIVER_OBJECT pDriverObject
    );

_Function_class_(DRIVER_INITIALIZE)
NTSTATUS
DriverEntry (
    _In_ PDRIVER_OBJECT pDriverObject,
    _In_ PUNICODE_STRING pRegistryPath
    );
// EoF