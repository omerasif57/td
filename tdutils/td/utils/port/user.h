//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2020
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include "td/utils/Slice.h"
#include "td/utils/Status.h"

namespace td {
Status change_user(CSlice username, CSlice groupname = CSlice());
}
