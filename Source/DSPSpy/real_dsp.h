// Copyright 2008 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "dsp_interface.h"

class RealDSP : public IDSP
{
public:
  virtual void Init();
  virtual void Reset();
  virtual u32 CheckMailTo();
  virtual void SendMailTo(u32 mail);
};
