/*
 * Copyright 2009-2011 Bjorn Fahller <bjorn@fahller.se>
 * All rights reserved

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <crpcut.hpp>

namespace crpcut { namespace heap { void show_objects(); } }
TESTSUITE(heap)
{
  TEST(should_succeed_allocation_leak)
  {
    size_t pre_bytes = crpcut::heap::allocated_bytes();
    size_t pre_objects = crpcut::heap::allocated_objects();

    void *p1 = malloc(100);
    INFO << "p1=" << p1;

    ASSERT_EQ(pre_bytes + 100, crpcut::heap::allocated_bytes());
    ASSERT_EQ(pre_objects + 1, crpcut::heap::allocated_objects());
  }

  TEST(should_fail_scope_leak_free)
  {
    ASSERT_SCOPE_HEAP_LEAK_FREE
    {
      void *p = malloc(100);
      INFO << "p=" << p;
    }
  }

  TEST(should_succeed_scope_leak_free)
  {
    class elem
    {
    public:
      elem(elem *p) : next(p) {}
      ~elem() { delete next; }
    private:
      elem *next;
    };
    ASSERT_SCOPE_HEAP_LEAK_FREE
    {
      elem *root = 0;
      for (int i = 0; i < 20; ++i)
      {
        root = new elem(root);
      }
      delete root;
    }
  }

  TEST(should_succeed_malloc_free_balance)
  {
    size_t pre = crpcut::heap::allocated_bytes();
    ASSERT_SCOPE_HEAP_LEAK_FREE
      {
        void *p1 = malloc(100);
        ASSERT_LE(pre + 100, crpcut::heap::allocated_bytes());
        void *p2 = malloc(150);
        ASSERT_LE(pre + 250, crpcut::heap::allocated_bytes());
        free(p1);
        free(p2);
      }
    ASSERT_EQ(pre, crpcut::heap::allocated_bytes());
  }

  TEST(should_fail_verify_scope_leak_free)
  {
    VERIFY_SCOPE_HEAP_LEAK_FREE
    {
      void *p = malloc(100);
      INFO << "p=" << p;
    }
    INFO << "after";
  }

  TEST(should_succeed_verify_scope_leak_free)
  {
    class elem
    {
    public:
      elem(elem *p) : next(p) {}
      ~elem() { delete next; }
    private:
      elem *next;
    };
    VERIFY_SCOPE_HEAP_LEAK_FREE
    {
      elem *root = 0;
      for (int i = 0; i < 20; ++i)
      {
        root = new elem(root);
      }
      delete root;
    }
    INFO << "after";
  }

  TEST(should_succeed_verify_malloc_free_balance)
  {
    size_t pre = crpcut::heap::allocated_bytes();
    VERIFY_SCOPE_HEAP_LEAK_FREE
      {
        void *p1 = malloc(100);
        VERIFY_LE(pre + 100, crpcut::heap::allocated_bytes());
        void *p2 = malloc(150);
        VERIFY_LE(pre + 250, crpcut::heap::allocated_bytes());
        free(p1);
        free(p2);
      }
    VERIFY_EQ(pre, crpcut::heap::allocated_bytes());
    INFO << "after";
  }


  struct no_leak_fixture
  {
    size_t pre;
    no_leak_fixture() : pre(crpcut::heap::allocated_bytes()) {}
    ~no_leak_fixture() { ASSERT_EQ(pre, crpcut::heap::allocated_bytes()); }
  };

  TEST(should_succeed_empty_balance_fix, no_leak_fixture)
  {
  }

  TEST(should_succeed_malloc_balance_fix, no_leak_fixture)
  {
    void *p = malloc(100);
    free(p);
  }

  TEST(should_succeed_worlds_worst_strcpy)
  {
    // Believe it or not, but I've actually seen an almost
    // verbatim copy of this code used in a real-world application.
    // The main difference is that the original was a bit worse...
    // Thought it might be handy to verify that realloc doesn't
    // corrupt anything.
    const size_t pre = crpcut::heap::allocated_bytes();
    const char orig[] = "blah blah blah bla blah 123456789123456379123456379";
    char *s = static_cast<char*>(malloc(strlen("")+1));
    s[0] = 0;
    for (const char *p = orig; *p; ++p)
      {
        s = static_cast<char *>(realloc(s, strlen(s) + 1 + strlen(" ")));
        s[strlen(s)+1] = 0;
        s[strlen(s)] = *p;
      }
    ASSERT_EQ(strcmp(s, orig), 0);
    free(s);
    ASSERT_EQ(pre, crpcut::heap::allocated_bytes());
  }

  TEST(should_succeed_malloc_blast_limit)
  {
    crpcut::heap::set_limit(crpcut::heap::allocated_bytes() + 100);
    void *p = malloc(101);
    ASSERT_EQ(p, 0);
  }

  struct an_array
  {
    char str[101];
  };
  TEST(should_succeed_new_blast_limit, EXPECT_EXCEPTION(std::bad_alloc))
  {
    crpcut::heap::set_limit(crpcut::heap::allocated_bytes() + 100);
    an_array * p = new an_array;
    INFO << p;
  }

  TEST(should_succeed_new_array_blast_limit, EXPECT_EXCEPTION(std::bad_alloc))
    {
    crpcut::heap::set_limit(crpcut::heap::allocated_bytes() + 100);
    char *p = new char[101];
    INFO << p;
    }

  TEST(should_succeed_new_nothrow_blast_limit)
  {
    crpcut::heap::set_limit(crpcut::heap::allocated_bytes() + 100);
    struct apa
    {
      char str[101];
    };
    apa *p = new(std::nothrow) apa;
    ASSERT_EQ((void*)p, 0);
  }

  TEST(should_succeed_new_array_nothrow_blast_limit)
  {
    crpcut::heap::set_limit(crpcut::heap::allocated_bytes() + 100);
    char *p = new(std::nothrow) char[101];
    ASSERT_EQ(p, 0);
  }

  TEST(should_succeed_blast_limit_with_string,
       EXPECT_EXCEPTION(std::bad_alloc))
  {
    crpcut::heap::set_limit(crpcut::heap::allocated_bytes() + 100);
    std::string s;
    for (int i = 0; i < 100; ++i)
      {
        s+=' ';
      }
  }

  TEST(should_fail_limit_too_low)
  {
    crpcut::heap::set_limit(crpcut::heap::allocated_bytes() - 2);
  }

  TEST(should_fail_cross_malloc_delete)
  {
    int *p = static_cast<int*>(malloc(sizeof(int)));
    delete p;
  }

  TEST(should_fail_cross_malloc_delete_array)
  {
    int *p = static_cast<int*>(malloc(sizeof(int)));
    delete[] p;
  }

  TEST(should_fail_cross_new_free)
  {
    int *p = new int;
    free(p);
  }

  TEST(should_fail_cross_new_delete_array)
  {
    int *p = new int;
    delete[] p;
  }

  TEST(should_fail_cross_new_array_free)
  {
    int *p = new int[1];
    free(p);
  }

  TEST(should_fail_cross_new_array_delete)
  {
    int *p = new int[1];
    delete p;
  }

  char *ballast;


  void stupid_new_handler()
  {
    if (!ballast) throw std::bad_alloc();
    delete[] ballast;
    ballast = 0;
  }

  TEST(should_succeed_new_handler)
  {
    const size_t bytes = crpcut::heap::allocated_bytes();
    crpcut::heap::set_limit(bytes + 120);
    std::set_new_handler(stupid_new_handler);
    ballast = new char[100];
    char *p = new char[50];
    ASSERT_EQ(crpcut::heap::allocated_bytes(), bytes + 50);
    ASSERT_EQ(ballast, 0);
    delete[] p;
    ASSERT_EQ(crpcut::heap::allocated_bytes(), bytes);
  }

  TEST(should_succeed_new_handler_no_ballast)
  {
    crpcut::heap::set_limit(crpcut::heap::allocated_bytes() + 99);
    std::set_new_handler(stupid_new_handler);
    ASSERT_THROW((void)new char[100], std::bad_alloc); // leak if alloc succeeds
  }

  TEST(should_succeed_nothrow_new_handler)
  {
    const size_t bytes = crpcut::heap::allocated_bytes();
    crpcut::heap::set_limit(bytes + 120);
    std::set_new_handler(stupid_new_handler);
    ballast = new char[100];
    char *p = new (std::nothrow) char[50];
    ASSERT_EQ(crpcut::heap::allocated_bytes(), bytes + 50);
    ASSERT_EQ(ballast, 0);
    ASSERT_NE(p, 0);
    delete[] p;
    ASSERT_EQ(crpcut::heap::allocated_bytes(), bytes);
  }

  TEST(should_succeed_nothrow_new_handler_no_ballast)
  {
    crpcut::heap::set_limit(crpcut::heap::allocated_bytes() + 99);
    std::set_new_handler(stupid_new_handler);
    void *p = new (std::nothrow) char[100];
    ASSERT_EQ(p, 0);
  }
}

