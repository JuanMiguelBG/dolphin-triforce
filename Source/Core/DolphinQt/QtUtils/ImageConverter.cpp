// Copyright 2018 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "DolphinQt/QtUtils/ImageConverter.h"

#include <vector>

#include <QPixmap>

#include "Common/CommonTypes.h"
#include "UICommon/GameFile.h"

QPixmap ToQPixmap(const UICommon::GameBanner& banner)
{
  return ToQPixmap(banner.buffer, banner.width, banner.height);
}

QPixmap ToQPixmap(const std::vector<u32>& buffer, int width, int height)
{
  QImage image(width, height, QImage::Format_RGB888);
  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      const u32 color = buffer[y * width + x];
      image.setPixel(
          x, y, qRgb((color & 0xFF0000) >> 16, (color & 0x00FF00) >> 8, (color & 0x0000FF) >> 0));
    }
  }

  return QPixmap::fromImage(image);
}
