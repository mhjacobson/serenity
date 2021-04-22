/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGUI/Widget.h>

namespace GUI {

class SeparatorWidget : public Widget {
    C_OBJECT(SeparatorWidget);

public:
    virtual ~SeparatorWidget() override;

protected:
    explicit SeparatorWidget(Gfx::Orientation);

private:
    virtual void paint_event(PaintEvent&) override;

    const Gfx::Orientation m_orientation;
};

class VerticalSeparator final : public SeparatorWidget {
    C_OBJECT(VerticalSeparator)
public:
    virtual ~VerticalSeparator() override { }

private:
    VerticalSeparator()
        : SeparatorWidget(Gfx::Orientation::Vertical)
    {
    }
};

class HorizontalSeparator final : public SeparatorWidget {
    C_OBJECT(HorizontalSeparator)
public:
    virtual ~HorizontalSeparator() override { }

private:
    HorizontalSeparator()
        : SeparatorWidget(Gfx::Orientation::Horizontal)
    {
    }
};

}
