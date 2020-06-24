//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2020
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "td/utils/buffer.h"
#include "td/utils/SharedSlice.h"
#include "td/utils/Slice.h"
#include "td/utils/SharedSlice.h"
#include "td/utils/Status.h"

namespace td {

Result<BufferSlice> read_file(CSlice path, int64 size = -1, int64 offset = 0);
Result<string> read_file_str(CSlice path, int64 size = -1, int64 offset = 0);
Result<SecureString> read_file_secure(CSlice path, int64 size = -1, int64 offset = 0);

Status copy_file(CSlice from, CSlice to, int64 size = -1) TD_WARN_UNUSED_RESULT;

struct WriteFileOptions {
  bool need_sync = true;
  bool need_lock = true;
};
Status write_file(CSlice to, Slice data, WriteFileOptions options = {}) TD_WARN_UNUSED_RESULT;

string clean_filename(CSlice name);

// write file and ensure that it either fully overriden with new data, or left intact.
// Uses path_tmp to temporary storat data, than calls rename
Status atomic_write_file(CSlice path, Slice data, CSlice path_tmp = {});

}  // namespace td
