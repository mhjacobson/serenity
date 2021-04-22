/*
 * Copyright (c) 2020, The SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/HTML/HTMLTrackElement.h>

namespace Web::HTML {

HTMLTrackElement::HTMLTrackElement(DOM::Document& document, QualifiedName qualified_name)
    : HTMLElement(document, move(qualified_name))
{
}

HTMLTrackElement::~HTMLTrackElement()
{
}

}
