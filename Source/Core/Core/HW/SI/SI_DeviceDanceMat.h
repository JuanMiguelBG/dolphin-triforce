// Copyright 2008 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "Common/CommonTypes.h"
#include "Core/HW/SI/SI_DeviceGCController.h"

struct GCPadStatus;

namespace SerialInterface
{
class CSIDevice_DanceMat : public CSIDevice_GCController
{
public:
  CSIDevice_DanceMat(SIDevices device, int device_number);

  int RunBuffer(u8* buffer, int request_length) override;
  u32 MapPadStatus(const GCPadStatus& pad_status) override;
  bool GetData(u32& hi, u32& low) override;
};
}  // namespace SerialInterface
