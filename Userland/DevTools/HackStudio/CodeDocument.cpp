/*
 * Copyright (c) 2020, Itamar S. <itamar8910@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "CodeDocument.h"

namespace HackStudio {

NonnullRefPtr<CodeDocument> CodeDocument::create(const String& file_path, Client* client)
{
    return adopt(*new CodeDocument(file_path, client));
}

NonnullRefPtr<CodeDocument> CodeDocument::create(Client* client)
{
    return adopt(*new CodeDocument(client));
}

CodeDocument::CodeDocument(const String& file_path, Client* client)
    : TextDocument(client)
    , m_file_path(file_path)
{
    m_language = language_from_file_extension(LexicalPath { file_path }.extension());
}

CodeDocument::CodeDocument(Client* client)
    : TextDocument(client)
{
}

CodeDocument::~CodeDocument()
{
}

}
