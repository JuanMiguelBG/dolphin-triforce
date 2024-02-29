// Copyright 2008 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "Common/CommonTypes.h"
#include "DiscIO/Volume.h"

namespace FileMonitor
{
class FileLogger
{
public:
  FileLogger();
  ~FileLogger();

  void Log(const DiscIO::Volume& volume, const DiscIO::Partition& partition, u64 offset);

private:
  DiscIO::Partition m_previous_partition;
  u64 m_previous_file_offset;
};
}  // namespace FileMonitor
