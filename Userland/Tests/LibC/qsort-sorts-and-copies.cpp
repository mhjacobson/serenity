/*
 * Copyright (c) 2020, Sahan Fernando <sahan.h.fernando@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <AK/QuickSort.h>
#include <AK/String.h>
#include <AK/Vector.h>
#include <stdio.h>
#include <stdlib.h>

const size_t NUM_RUNS = 100;

struct SortableObject {
    int m_key;
    int m_payload;
};

static int compare_sortable_object(const void* a, const void* b)
{
    const int key1 = static_cast<const SortableObject*>(a)->m_key;
    const int key2 = static_cast<const SortableObject*>(b)->m_key;
    if (key1 < key2) {
        return -1;
    } else if (key1 == key2) {
        return 0;
    } else {
        return 1;
    }
}

static int calc_payload_for_pos(size_t pos)
{
    pos *= 231;
    return pos ^ (pos << 8) ^ (pos << 16) ^ (pos << 24);
}

static void shuffle_vec(Vector<SortableObject>& test_objects)
{
    for (size_t i = 0; i < test_objects.size() * 3; ++i) {
        auto i1 = rand() % test_objects.size();
        auto i2 = rand() % test_objects.size();
        swap(test_objects[i1], test_objects[i2]);
    }
}

int main()
{
    // Generate vector of SortableObjects in sorted order, with payloads determined by their sorted positions
    Vector<SortableObject> test_objects;
    for (auto i = 0; i < 1024; ++i) {
        test_objects.append({ i * 137, calc_payload_for_pos(i) });
    }
    for (size_t i = 0; i < NUM_RUNS; i++) {
        // Shuffle the vector, then sort it again
        shuffle_vec(test_objects);
        qsort(test_objects.data(), test_objects.size(), sizeof(SortableObject), compare_sortable_object);
        // Check that the objects are sorted by key
        for (auto i = 0u; i + 1 < test_objects.size(); ++i) {
            const auto& key1 = test_objects[i].m_key;
            const auto& key2 = test_objects[i + 1].m_key;
            if (key1 > key2) {
                printf("\x1b[01;35mTests failed: saw key %d before key %d\n", key1, key2);
                return 1;
            }
        }
        // Check that the object's payloads have not been corrupted
        for (auto i = 0u; i < test_objects.size(); ++i) {
            const auto expected = calc_payload_for_pos(i);
            const auto payload = test_objects[i].m_payload;
            if (payload != expected) {
                printf("\x1b[01;35mTests failed: expected payload %d for pos %u, got payload %d\n", expected, i, payload);
                return 1;
            }
        }
    }
    printf("PASS\n");
    return 0;
}
