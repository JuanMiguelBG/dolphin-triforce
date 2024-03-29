// Copyright 2008 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <memory>
#include <string>
#include "Common/CommonTypes.h"

class HostDisassembler
{
public:
  virtual ~HostDisassembler() {}
  virtual std::string DisassembleHostBlock(const u8* code_start, const u32 code_size,
                                           u32* host_instructions_count, u64 starting_pc)
  {
    return "(No disassembler)";
  }
};

struct DisassembleResult
{
  std::string text;
  u32 entry_address;
  u32 instruction_count;
  u32 code_size;
};

std::unique_ptr<HostDisassembler> GetNewDisassembler(const std::string& arch);
DisassembleResult DisassembleBlock(HostDisassembler* disasm, u32 address);
