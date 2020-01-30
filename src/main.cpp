/*
 * MIT License
 *
 * Copyright (c) 2020 Alexander Chumakov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>

/**
 * Define the structure for the items in the test custom section
 */
struct TEntryA {
  int a;
  int b;
  const char *c;
};

/**
 * Add some test items to the custom seciton
 */
TEntryA entry1 __attribute__((section("my_custom_section"))) = {
  1, 200, "hello"
};
TEntryA entry2 __attribute__((section("my_custom_section"))) = {
  2, 209, "new"
};
TEntryA entry3 __attribute__((section("my_custom_section"))) = {
  3, 211, "old"
};

/**
 * These simbols will point to the start and stop of the custom section
 */
extern void *__stop_my_custom_section;
extern void *__start_my_custom_section;

int main(int argc, char **argv)
{
  // Print some basic test info
  printf("Size: %zu\n", sizeof (TEntryA));
  printf("Pointers: %p, %p\n", &__start_my_custom_section, &__stop_my_custom_section);

  // Iterate though the section printsing information in its items
  const TEntryA *iter = reinterpret_cast<const TEntryA *>(&__start_my_custom_section);
  const TEntryA *const iterEnd = reinterpret_cast<const TEntryA *>(&__stop_my_custom_section);
  for (; iter < iterEnd; ++ iter) {
    printf("Entry: %d, %d, [%s]\n", iter->a, iter->b, iter->c);
  }

  return 0;
}
