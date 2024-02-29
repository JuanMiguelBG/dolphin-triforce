// Copyright 2008 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

namespace HLE_OS
{
void HLE_GeneralDebugPrint();
void HLE_GeneralDebugVPrint();
void HLE_write_console();
void HLE_OSPanic();
void HLE_LogDPrint();
void HLE_LogVDPrint();
void HLE_LogFPrint();
void HLE_LogVFPrint();
}  // namespace HLE_OS
