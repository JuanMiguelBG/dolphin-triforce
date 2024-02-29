// Copyright 2008 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "Common/CommonTypes.h"

namespace IOS::HLE
{
const u8* GetAttribPacket(u32 serviceHandle, u32 cont, u32& _size);
}  // namespace IOS::HLE
