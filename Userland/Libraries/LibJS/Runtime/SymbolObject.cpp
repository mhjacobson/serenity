/*
 * Copyright (c) 2020, Matthew Olsson <matthewcolsson@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibJS/Heap/Heap.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/Symbol.h>
#include <LibJS/Runtime/SymbolObject.h>
#include <LibJS/Runtime/SymbolPrototype.h>
#include <LibJS/Runtime/Value.h>

namespace JS {

SymbolObject* SymbolObject::create(GlobalObject& global_object, Symbol& primitive_symbol)
{
    return global_object.heap().allocate<SymbolObject>(global_object, primitive_symbol, *global_object.symbol_prototype());
}

SymbolObject::SymbolObject(Symbol& symbol, Object& prototype)
    : Object(prototype)
    , m_symbol(symbol)
{
}

SymbolObject::~SymbolObject()
{
}

void SymbolObject::visit_edges(Cell::Visitor& visitor)
{
    Object::visit_edges(visitor);
    visitor.visit(&m_symbol);
}

}
