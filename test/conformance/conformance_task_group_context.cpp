/*
    Copyright (c) 2020 Intel Corporation

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include <tbb/task_group.h>

#include "common/test.h"
#include "common/utils.h"

//! \file conformance_task_group_context.cpp
//! \brief Test for [task_group_context] specification

//! Test construction
//! \brief \ref interface
TEST_CASE("Test construction") {
    {
        tbb::task_group_context ctx;
        utils::suppress_unused_warning(ctx);
    }
    {
        tbb::task_group_context ctx{ tbb::task_group_context::bound };
        utils::suppress_unused_warning(ctx);
    }
    {
        tbb::task_group_context ctx{ tbb::task_group_context::isolated
            , tbb::task_group_context::default_traits | tbb::task_group_context::fp_settings | tbb::task_group_context::concurrent_wait };
        utils::suppress_unused_warning(ctx);
    }
}

//! Test methods
//! \brief \ref interface \ref requirement
TEST_CASE("Test methods") {
    tbb::task_group_context ctx{ tbb::task_group_context::bound, tbb::task_group_context::default_traits };
    ctx.capture_fp_settings();
    CHECK_FALSE(ctx.is_group_execution_cancelled());
    CHECK(ctx.cancel_group_execution());
    CHECK(ctx.is_group_execution_cancelled());
    ctx.reset();
    CHECK_FALSE(ctx.is_group_execution_cancelled());
    ctx.traits();
}
