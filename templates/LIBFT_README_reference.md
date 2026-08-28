<div align="center">
  <img src=".assets/banner.png" width="100%" alt="libft banner" />

  <p>
    <b>A from-scratch reimplementation of the C standard library, the dependency every later 42 project builds on.</b>
  </p>

  <p>
    <a href="https://42lausanne.ch"><img src="https://img.shields.io/badge/42-Lausanne-000000?style=for-the-badge&logo=42&logoColor=white" alt="42 Lausanne" /></a>
    <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C" />
    <img src="https://img.shields.io/badge/Norminette-passing-2ea44f?style=for-the-badge" alt="Norm passing" />
    <img src="https://img.shields.io/badge/grade-125%2F100-5ec8c5?style=for-the-badge" alt="Grade 125/100" />
  </p>

  <p>
    <img src="https://img.shields.io/badge/-Overview-2b3137?style=flat-square" alt="Overview" />
    <img src="https://img.shields.io/badge/-Highlights-2b3137?style=flat-square" alt="Highlights" />
    <img src="https://img.shields.io/badge/-Build%20%26%20Usage-2b3137?style=flat-square" alt="Build & Usage" />
    <img src="https://img.shields.io/badge/-Design%20Notes-2b3137?style=flat-square" alt="Design Notes" />
    <img src="https://img.shields.io/badge/-Library%20Structure-2b3137?style=flat-square" alt="Library Structure" />
    <img src="https://img.shields.io/badge/-Function%20Reference-2b3137?style=flat-square" alt="Function Reference" />
    <img src="https://img.shields.io/badge/-Result-2b3137?style=flat-square" alt="Result" />
  </p>
</div>

<img src=".assets/divider.png" width="100%" alt="" />

<a name="overview"></a>
<h2 align="center">Overview</h2>

<div align="center">

No `strlen`, no `malloc` wrapper, no `memcpy`: just the man pages and a blank file. `libft` rebuilds the core of `string.h`, `stdlib.h`, and `ctype.h` byte by byte, then adds a linked-list toolkit and a `printf` engine on top. Every later project in this repo links against it.

The interesting part isn't reimplementing the easy 90%. It's the edge cases: what `strlcpy` returns versus what it actually copies, how `memmove` has to reason about overlapping memory instead of just looping, why `atoi` has to eat leading whitespace and a sign before it sees a digit. All of it under `-Wall -Wextra -Werror`, zero warnings tolerated.

**[Read the full subject](.assets/Libft.en.pdf)**

</div>

<img src=".assets/divider.png" width="100%" alt="" />

<a name="highlights"></a>
<h2 align="center">Highlights</h2>

`libft` isn't just "reimplement the man pages": the subject enforces a set of constraints that make the exercise harder than it looks:

- **56 functions, fully scoped.** Character classification, string manipulation, memory management, conversions, and fd-based output, split one function per file exactly as the Norm requires.
- **Zero tolerance for warnings or shortcuts.** The whole library compiles clean under `-Wall -Wextra -Werror`, with no `for` loops and one instruction per line allowed.
- **Every allocation is leak-checked at the failure path**, not just the happy path: if a `malloc` fails midway through building a string or a list, whatever was already allocated gets freed before returning `NULL`.
- **`get_next_line` and `ft_printf` are first-class citizens**, folded into the library from the start rather than bolted on as an afterthought, since almost every later project depends on both.

<img src=".assets/divider.png" width="100%" alt="" />

<a name="build--usage"></a>
<h2 align="center">Build & Usage</h2>

```bash
make        # builds libft.a (mandatory part + get_next_line + printf helper)
make bonus  # also builds the linked-list functions
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # fclean + all
```

To use the library in another project:

```c
#include "libft.h"
```

```bash
cc main.c -Ipath/to/libft -Lpath/to/libft -lft -o program
```

<img src=".assets/divider.png" width="100%" alt="" />

<a name="design-notes"></a>
<h2 align="center">Design Notes</h2>

`libft` is where several recurring 42 constraints first show up, and they shape how every function is written.

> [!NOTE]
> **No `for` loops.** The Norm only allows `while`, which changes how iteration and index bookkeeping are structured throughout the library.

> [!IMPORTANT]
> **One `malloc` per resource, one matching `free`.** Any function that allocates (`ft_strdup`, `ft_split`, `ft_substr`, `ft_lstnew`, ...) must also handle the failure path (`malloc` returning `NULL`) without leaking whatever it already allocated. This is where `ft_split_free` and the list's destructor callbacks come from.

> [!TIP]
> **Overlap safety in `ft_memmove`.** `ft_memcpy` assumes non-overlapping regions (as the standard allows); `ft_memmove` has to detect overlap and copy in the right direction to stay correct, reasoning about memory layout rather than just "copying bytes."

> [!WARNING]
> **BSD-style return values.** `ft_strlcpy`/`ft_strlcat` return the length they *would have needed*, not the length they wrote. Treat the return value as the actual copied length and you'll read past the buffer; this mirrors the real `strlcpy`/`strlcat` contract so truncation can be detected by the caller.

<img src=".assets/divider.png" width="100%" alt="" />

<a name="library-structure"></a>
<h2 align="center">Library Structure</h2>

```text
LIBFT/
├── libft.h                    # Public header: prototypes, includes, the t_list struct
├── Makefile                   # all / bonus / clean / fclean / re
├── ft_*.c                     # 56 files, one function each, see Function Reference below
├── GNL/                       # get_next_line, a separate 42 project folded in here
│   ├── get_next_line.c
│   ├── get_next_line_bonus.c
│   └── get_next_line_utils.c
└── .assets/                   # Subject PDF, banner, grade screenshot
```

<img src=".assets/divider.png" width="100%" alt="" />

<a name="function-reference"></a>
<h2 align="center">Function Reference</h2>

<div align="center">

| Category | Functions | Example |
| --- | :---: | --- |
| Character classification | 6 | `ft_isalpha` |
| String manipulation | 15 | `ft_strdup` |
| Memory management | 7 | `ft_memmove` |
| Conversions | 5 | `ft_itoa` |
| Output (fd-based) | 10 | `ft_putnbr_fd` |
| Linked list (bonus) | 9 | `ft_lstmap` |
| Extras (beyond the subject) | 4 | `get_next_line` |

</div>

<table width="100%">
<tr><th width="26%">Function</th><th>Purpose</th></tr>
<tr><td colspan="2" align="right"><img src=".assets/badges/char-classification.png" height="22" alt="Character Classification" /></td></tr>
<tr><td align="center"><a href="ft_isalpha.c"><code>ft_isalpha</code></a></td><td>Alphabetic character check</td></tr>
<tr><td align="center"><a href="ft_isdigit.c"><code>ft_isdigit</code></a></td><td>Decimal digit check</td></tr>
<tr><td align="center"><a href="ft_isalnum.c"><code>ft_isalnum</code></a></td><td>Alphanumeric check</td></tr>
<tr><td align="center"><a href="ft_isascii.c"><code>ft_isascii</code></a></td><td>7-bit ASCII range check</td></tr>
<tr><td align="center"><a href="ft_isprint.c"><code>ft_isprint</code></a></td><td>Printable character check</td></tr>
<tr><td align="center"><a href="ft_isnumber.c"><code>ft_isnumber</code></a></td><td>Whether a whole string represents a number</td></tr>

<tr><td colspan="2" align="right"><img src=".assets/badges/string-manipulation.png" height="22" alt="String Manipulation" /></td></tr>
<tr><td align="center"><a href="ft_strlen.c"><code>ft_strlen</code></a></td><td>String length</td></tr>
<tr><td align="center"><a href="ft_strlcpy.c"><code>ft_strlcpy</code></a></td><td>Bounded copy, BSD-style return value</td></tr>
<tr><td align="center"><a href="ft_strlcat.c"><code>ft_strlcat</code></a></td><td>Bounded concatenation, BSD-style return value</td></tr>
<tr><td align="center"><a href="ft_strchr.c"><code>ft_strchr</code></a> / <a href="ft_strrchr.c"><code>ft_strrchr</code></a></td><td>First / last occurrence of a character</td></tr>
<tr><td align="center"><a href="ft_strncmp.c"><code>ft_strncmp</code></a> / <a href="ft_strcmp.c"><code>ft_strcmp</code></a></td><td>Lexicographic comparison</td></tr>
<tr><td align="center"><a href="ft_strnstr.c"><code>ft_strnstr</code></a></td><td>Bounded substring search</td></tr>
<tr><td align="center"><a href="ft_strdup.c"><code>ft_strdup</code></a></td><td>Heap-allocated duplicate</td></tr>
<tr><td align="center"><a href="ft_substr.c"><code>ft_substr</code></a></td><td>Extract a substring into a new allocation</td></tr>
<tr><td align="center"><a href="ft_strjoin.c"><code>ft_strjoin</code></a></td><td>Concatenate two strings into a new allocation</td></tr>
<tr><td align="center"><a href="ft_strtrim.c"><code>ft_strtrim</code></a></td><td>Trim a set of characters from both ends</td></tr>
<tr><td align="center"><a href="ft_split.c"><code>ft_split</code></a></td><td>Split a string on a delimiter into a <code>NULL</code>-terminated array</td></tr>
<tr><td align="center"><a href="ft_strmapi.c"><code>ft_strmapi</code></a></td><td>Apply a function to each character, index-aware, into a new string</td></tr>
<tr><td align="center"><a href="ft_striteri.c"><code>ft_striteri</code></a></td><td>Apply a function to each character in place, index-aware</td></tr>

<tr><td colspan="2" align="right"><img src=".assets/badges/memory-management.png" height="22" alt="Memory Management" /></td></tr>
<tr><td align="center"><a href="ft_memset.c"><code>ft_memset</code></a></td><td>Fill a memory area with a byte value</td></tr>
<tr><td align="center"><a href="ft_bzero.c"><code>ft_bzero</code></a></td><td>Zero a memory area</td></tr>
<tr><td align="center"><a href="ft_memcpy.c"><code>ft_memcpy</code></a></td><td>Copy a non-overlapping memory area</td></tr>
<tr><td align="center"><a href="ft_memmove.c"><code>ft_memmove</code></a></td><td>Copy a memory area, safe for overlap</td></tr>
<tr><td align="center"><a href="ft_memchr.c"><code>ft_memchr</code></a></td><td>Find a byte in a memory area</td></tr>
<tr><td align="center"><a href="ft_memcmp.c"><code>ft_memcmp</code></a></td><td>Compare two memory areas</td></tr>
<tr><td align="center"><a href="ft_calloc.c"><code>ft_calloc</code></a></td><td>Allocate zero-initialized memory</td></tr>

<tr><td colspan="2" align="right"><img src=".assets/badges/conversions.png" height="22" alt="Conversions" /></td></tr>
<tr><td align="center"><a href="ft_atoi.c"><code>ft_atoi</code></a></td><td>String to <code>int</code></td></tr>
<tr><td align="center"><a href="ft_atol.c"><code>ft_atol</code></a></td><td>String to <code>long</code></td></tr>
<tr><td align="center"><a href="ft_itoa.c"><code>ft_itoa</code></a></td><td><code>int</code> to a heap-allocated string</td></tr>
<tr><td align="center"><a href="ft_tolower.c"><code>ft_tolower</code></a> / <a href="ft_toupper.c"><code>ft_toupper</code></a></td><td>Case conversion</td></tr>

<tr><td colspan="2" align="right"><img src=".assets/badges/output-fd.png" height="22" alt="Output (File-Descriptor Based)" /></td></tr>
<tr><td align="center"><a href="ft_putchar_fd.c"><code>ft_putchar_fd</code></a></td><td>Write a character</td></tr>
<tr><td align="center"><a href="ft_putstr_fd.c"><code>ft_putstr_fd</code></a></td><td>Write a string</td></tr>
<tr><td align="center"><a href="ft_putendl_fd.c"><code>ft_putendl_fd</code></a></td><td>Write a string followed by <code>\n</code></td></tr>
<tr><td align="center"><a href="ft_putnbr_fd.c"><code>ft_putnbr_fd</code></a></td><td>Write an <code>int</code> in base 10</td></tr>
<tr><td align="center"><a href="ft_putchar.c"><code>ft_putchar</code></a> / <a href="ft_putstr.c"><code>ft_putstr</code></a> / <a href="ft_putnbr.c"><code>ft_putnbr</code></a></td><td>Convenience wrappers writing to <code>stdout</code></td></tr>
<tr><td align="center"><a href="ft_putunbr.c"><code>ft_putunbr</code></a></td><td>Write an <code>unsigned int</code></td></tr>
<tr><td align="center"><a href="ft_puthex.c"><code>ft_puthex</code></a></td><td>Write a value in hexadecimal</td></tr>
<tr><td align="center"><a href="ft_putptr.c"><code>ft_putptr</code></a></td><td>Write a pointer address</td></tr>

<tr><td colspan="2" align="right"><img src=".assets/badges/linked-list.png" height="22" alt="Linked List (Bonus)" /></td></tr>
<tr><td align="center"><a href="ft_lstnew_bonus.c"><code>ft_lstnew</code></a></td><td>Allocate a new node</td></tr>
<tr><td align="center"><a href="ft_lstadd_front_bonus.c"><code>ft_lstadd_front</code></a> / <a href="ft_lstadd_back_bonus.c"><code>ft_lstadd_back</code></a></td><td>Insert at the head / tail</td></tr>
<tr><td align="center"><a href="ft_lstsize_bonus.c"><code>ft_lstsize</code></a></td><td>Count nodes</td></tr>
<tr><td align="center"><a href="ft_lstlast_bonus.c"><code>ft_lstlast</code></a></td><td>Return the last node</td></tr>
<tr><td align="center"><a href="ft_lstdelone_bonus.c"><code>ft_lstdelone</code></a></td><td>Free one node with a custom destructor</td></tr>
<tr><td align="center"><a href="ft_lstclear_bonus.c"><code>ft_lstclear</code></a></td><td>Free an entire list</td></tr>
<tr><td align="center"><a href="ft_lstiter_bonus.c"><code>ft_lstiter</code></a></td><td>Apply a function to every node</td></tr>
<tr><td align="center"><a href="ft_lstmap_bonus.c"><code>ft_lstmap</code></a></td><td>Build a new list by mapping a function over an existing one</td></tr>

<tr><td colspan="2" align="right"><img src=".assets/badges/extras.png" height="22" alt="Extras (Beyond the Subject)" /></td></tr>
<tr><td align="center"><a href="ft_swap.c"><code>ft_swap</code></a></td><td>Swap two integers</td></tr>
<tr><td align="center"><a href="ft_split_free.c"><code>ft_split_free</code></a></td><td>Free a <code>NULL</code>-terminated array produced by <code>ft_split</code></td></tr>
<tr><td align="center"><a href="GNL/get_next_line.c"><code>get_next_line</code></a></td><td>Read a file descriptor line by line (<a href="https://github.com/Nesplee/GNL">separate 42 project</a>)</td></tr>
<tr><td align="center"><a href="ft_printf.c"><code>ft_printf</code></a></td><td>Minimal <code>printf</code>-style formatter, precursor to the full <a href="https://github.com/Nesplee/FT_PRINTF"><code>ft_printf</code></a> project</td></tr>
</table>

<img src=".assets/divider.png" width="100%" alt="" />

<a name="skills-developed"></a>
<h2 align="center">Skills Developed</h2>

<table width="100%">
<tr><th>Learning Outcome</th><th width="28%">Piscine Skill Area</th></tr>
<tr><td>C fundamentals: pointers, arrays, string handling</td><td align="center">Algorithms & AI</td></tr>
<tr><td>Manual memory management and leak-free allocation patterns</td><td align="center">Imperative Programming</td></tr>
<tr><td>Reimplementing standard-library contracts precisely</td><td align="center">Unix</td></tr>
<tr><td>Working under a strict style checker (Norm) and a zero-warning build</td><td align="center">Rigor</td></tr>
</table>

<img src=".assets/divider.png" width="100%" alt="" />

<a name="result"></a>
<h2 align="center">Result</h2>

<div align="center">
  <img src=".assets/Note.png" alt="libft grade" width="220px" />
  <br/>
  <sup><i>Validated on October 11, 2024, ~70 hours</i></sup>
</div>

<img src=".assets/divider.png" width="100%" alt="" />

<div align="center">

<sub>42 Lausanne · Common Core</sub>

</div>
