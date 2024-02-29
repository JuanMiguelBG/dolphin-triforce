// Copyright 2018 Dolphin Triforce Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <QObject>

class QSocketNotifier;

// Loosely based on https://doc.qt.io/qt-5.9/unix-signals.html
class SignalDaemon : public QObject
{
  Q_OBJECT

public:
  explicit SignalDaemon(QObject* parent);
  ~SignalDaemon();

  static void HandleInterrupt(int);

signals:
  void InterruptReceived();

private:
  void OnNotifierActivated();

  static int s_sigterm_fd[2];

  QSocketNotifier* m_term;
};
