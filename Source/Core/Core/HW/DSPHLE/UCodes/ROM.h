// Copyright 2008 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "Common/CommonTypes.h"
#include "Core/HW/DSPHLE/UCodes/UCodes.h"

namespace DSP::HLE
{
class DSPHLE;

class ROMUCode final : public UCodeInterface
{
public:
  ROMUCode(DSPHLE* dsphle, u32 crc);

  void Initialize() override;
  void HandleMail(u32 mail) override;
  void Update() override;

  void DoState(PointerWrap& p) override;

private:
  struct UCodeBootInfo
  {
    u32 m_ram_address;
    u32 m_length;
    u32 m_imem_address;
    u32 m_dmem_length;
    u32 m_start_pc;
  };
  UCodeBootInfo m_current_ucode;
  int m_boot_task_num_steps;

  u32 m_next_parameter;

  void BootUCode();
};
}  // namespace DSP::HLE
