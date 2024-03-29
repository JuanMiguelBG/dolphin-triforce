// Copyright 2019 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <QObject>

class FileOpenEventFilter : public QObject
{
  Q_OBJECT
public:
  explicit FileOpenEventFilter(QObject* event_source);

signals:
  void fileOpened(const QString& file_name);

private:
  bool eventFilter(QObject* object, QEvent* event) override;
};
