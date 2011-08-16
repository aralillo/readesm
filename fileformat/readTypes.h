/* Copyright 2009 Andreas Gölzer

 This file is part of readESM.

 readESM is free software: you can redistribute it and/or modify it under the
 terms of the GNU General Public License as published by the Free Software
 Foundation, either version 3 of the License, or (at your option) any later
 version.

 readESM is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with
 readESM.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef READTYPES_H
#define READTYPES_H

#include "constDataPointer.h"

#include <QtCore/QString>

QString codepageStringCombination(const constDataPointer& start, int length);
QString fixedString(const constDataPointer& start, int length);

int readBigEndianInt1(const constDataPointer& start);
int readBigEndianInt2(const constDataPointer& start);
int readBigEndianInt3(const constDataPointer& start);
int readBigEndianInt4(const constDataPointer& start);


QString bcdbyte(unsigned char start);

// inline int LEInt32(const constDataPointer& start) {
// 	return (start[3] << 24) + (start[2] << 16) + (start[1] << 8) + start[0];
// }

#endif
