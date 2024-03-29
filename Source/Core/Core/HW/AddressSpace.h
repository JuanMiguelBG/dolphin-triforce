// Copyright 2011 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <optional>

#include "Common/CommonTypes.h"

namespace AddressSpace
{
enum class Type
{
  Effective,
  Auxiliary,
  Physical,
  Mem1,
  Mem2,
  Fake,
};

struct Accessors
{
  using iterator = const u8*;

  virtual bool IsValidAddress(u32 address) const = 0;
  virtual u8 ReadU8(u32 address) const = 0;
  virtual void WriteU8(u32 address, u8 value) = 0;

  // overrideable naive implementations of below are defined
  virtual u16 ReadU16(u32 address) const;
  virtual void WriteU16(u32 address, u16 value);
  virtual u32 ReadU32(u32 address) const;
  virtual void WriteU32(u32 address, u32 value);
  virtual u64 ReadU64(u32 address) const;
  virtual void WriteU64(u32 address, u64 value);
  virtual float ReadF32(u32 address) const;

  virtual iterator begin() const;
  virtual iterator end() const;

  virtual std::optional<u32> Search(u32 haystack_offset, const u8* needle_start,
                                    std::size_t needle_size, bool forward) const;
  virtual ~Accessors();
};

Accessors* GetAccessors(Type address_space);

void Init();
void Shutdown();

}  // namespace AddressSpace
