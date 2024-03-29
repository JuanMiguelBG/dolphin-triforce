// Copyright 2014 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <vector>

#include "Common/CommonTypes.h"
#include "Core/PowerPC/CachedInterpreter/InterpreterBlockCache.h"
#include "Core/PowerPC/JitCommon/JitBase.h"
#include "Core/PowerPC/PPCAnalyst.h"

class CachedInterpreter : public JitBase
{
public:
  CachedInterpreter();
  ~CachedInterpreter();

  void Init() override;
  void Shutdown() override;

  bool HandleFault(uintptr_t access_address, SContext* ctx) override { return false; }
  void ClearCache() override;

  void Run() override;
  void SingleStep() override;

  void Jit(u32 address) override;

  JitBaseBlockCache* GetBlockCache() override { return &m_block_cache; }
  const char* GetName() const override { return "Cached Interpreter"; }
  const CommonAsmRoutinesBase* GetAsmRoutines() override { return nullptr; }

private:
  struct Instruction;

  u8* GetCodePtr();
  void ExecuteOneBlock();

  bool HandleFunctionHooking(u32 address);

  BlockCache m_block_cache{*this};
  std::vector<Instruction> m_code;
};
