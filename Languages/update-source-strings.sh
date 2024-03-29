#!/bin/bash

# This script updates the dolphin-triforce.pot file to match the strings in
# the source code.

cd "$(dirname "$0")/.."

# Scan the source code for strings and put them in dolphin-triforce.pot
SRCDIR=Source
find $SRCDIR -name '*.cpp' -o -name '*.h' -o -name '*.c' | \
	xgettext -s -p ./Languages/po -o dolphin-triforce.pot --package-name="Dolphin Triforce Emulator" \
	--keyword=_ \
	--keyword=AskYesNoFmtT \
	--keyword=CriticalAlertFmtT \
	--keyword=PanicAlertFmtT \
	--keyword=PanicYesNoFmtT \
	--keyword=SuccessAlertFmtT \
	--keyword=GetStringT \
	--keyword=_trans \
	--keyword=tr:1,1t \
	--keyword=tr:1,2c \
	--keyword=QT_TR_NOOP \
	--keyword=FmtFormatT \
	--add-comments=i18n --from-code=utf-8 -f -

# Copy strings from qt-strings.pot to dolphin-triforce.pot
xgettext -s -p ./Languages/po -o dolphin-triforce.pot --package-name="Dolphin Triforce Emulator" \
  -j ./Languages/po/qt-strings.pot

sed -i "s/SOME DESCRIPTIVE TITLE\./Translation of dolphin-triforce.pot to LANGUAGE/" Languages/po/dolphin-triforce.pot
sed -i "s/YEAR THE PACKAGE'S COPYRIGHT HOLDER/2003-2013/" Languages/po/dolphin-triforce.pot
sed -i "s/license as the PACKAGE package/license as the dolphin-triforce package/" Languages/po/dolphin-triforce.pot
