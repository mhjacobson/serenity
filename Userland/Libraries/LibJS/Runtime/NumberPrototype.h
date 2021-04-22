/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/NumberObject.h>

namespace JS {

class NumberPrototype final : public NumberObject {
    JS_OBJECT(NumberPrototype, NumberObject);

public:
    explicit NumberPrototype(GlobalObject&);
    virtual void initialize(GlobalObject&) override;
    virtual ~NumberPrototype() override;

    JS_DECLARE_NATIVE_FUNCTION(to_string);
};

}
