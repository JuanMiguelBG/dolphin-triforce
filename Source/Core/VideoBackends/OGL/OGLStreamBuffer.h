// Copyright 2008 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <array>
#include <memory>
#include <utility>

#include "Common/CommonTypes.h"
#include "Common/GL/GLUtil.h"

namespace OGL
{
class StreamBuffer
{
public:
  static std::unique_ptr<StreamBuffer> Create(u32 type, u32 size);
  virtual ~StreamBuffer();

  u32 GetGLBufferId() const { return m_buffer; }
  u32 GetSize() const { return m_size; }
  u32 GetCurrentOffset() const { return m_iterator; }

  /* This mapping function will return a pair of:
   * - the pointer to the mapped buffer
   * - the offset into the real GPU buffer (always multiple of stride)
   * On mapping, the maximum of size for allocation has to be set.
   * The size really pushed into this fifo only has to be known on Unmapping.
   * Mapping invalidates the current buffer content,
   * so it isn't allowed to access the old content any more.
   */
  virtual std::pair<u8*, u32> Map(u32 size) = 0;
  virtual void Unmap(u32 used_size) = 0;

  std::pair<u8*, u32> Map(u32 size, u32 stride)
  {
    u32 padding = m_iterator % stride;
    if (padding)
    {
      m_iterator += stride - padding;
    }
    return Map(size);
  }

  const u32 m_buffer;

protected:
  StreamBuffer(u32 type, u32 size);
  void CreateFences();
  void DeleteFences();
  void AllocMemory(u32 size);

  const u32 m_buffertype;
  const u32 m_size;

  u32 m_iterator;
  u32 m_used_iterator;
  u32 m_free_iterator;

private:
  static constexpr int SYNC_POINTS = 16;
  int Slot(u32 x) const { return x >> m_bit_per_slot; }
  const int m_bit_per_slot;

  std::array<GLsync, SYNC_POINTS> m_fences{};
};
}  // namespace OGL
