/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <WCDB/Lang.h>

namespace WCDB {

namespace Lang {

CopyOnWriteString PragmaSTMT::SQL() const
{
    std::string description("PRAGMA ");
    if (schemaName.isNull()) {
        description.append(mainSchema() + ".");
    } else if (!schemaName.get().empty()) {
        description.append(schemaName.get() + ".");
    }
    if (!pragmaName.empty()) {
        description.append(pragmaName.get());
    }
    if (!value.empty()) {
        description.append(" = " + value.description().get());
    }
    return description;
}

STMT::Type PragmaSTMT::getSTMTType() const
{
    return STMT::Type::Pragma;
}

STMT::Type PragmaSTMT::getType()
{
    return STMT::Type::Pragma;
}

} // namespace Lang

} // namespace WCDB
