// Copyright 2008 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <string>

#include "Common/CommonTypes.h"
#include "Common/SymbolDB.h"

namespace DSP
{
struct SDSP;
}

namespace DSP::Symbols
{
void AutoDisassembly(const SDSP& dsp, u16 start_addr, u16 end_addr);

void Clear();

int Addr2Line(u16 address);
int Line2Addr(int line);  // -1 for not found

const char* GetLineText(int line);
}  // namespace DSP::Symbols
