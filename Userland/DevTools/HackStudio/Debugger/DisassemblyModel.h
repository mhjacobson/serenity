/*
 * Copyright (c) 2020, Luke Wilde <luke.wilde@live.co.uk>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Vector.h>
#include <LibGUI/Model.h>
#include <LibX86/Instruction.h>
#include <sys/arch/i386/regs.h>

namespace Debug {

class DebugSession;

}

namespace HackStudio {

struct InstructionData {
    X86::Instruction insn;
    String disassembly;
    StringView bytes;
    FlatPtr address { 0 };
};

class DisassemblyModel final : public GUI::Model {
public:
    static NonnullRefPtr<DisassemblyModel> create(const Debug::DebugSession& debug_session, const PtraceRegisters& regs)
    {
        return adopt(*new DisassemblyModel(debug_session, regs));
    }

    enum Column {
        Address,
        InstructionBytes,
        Disassembly,
        __Count
    };

    virtual ~DisassemblyModel() override;

    virtual int row_count(const GUI::ModelIndex& = GUI::ModelIndex()) const override;
    virtual int column_count(const GUI::ModelIndex& = GUI::ModelIndex()) const override { return Column::__Count; }
    virtual String column_name(int) const override;
    virtual GUI::Variant data(const GUI::ModelIndex&, GUI::ModelRole) const override;
    virtual void update() override;

private:
    DisassemblyModel(const Debug::DebugSession&, const PtraceRegisters&);

    Vector<InstructionData> m_instructions;
};

}
