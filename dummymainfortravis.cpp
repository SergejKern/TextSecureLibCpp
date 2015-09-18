void * operator new(std::size_t n)
{
  void * const p = std::malloc(n);
  // handle p == 0
  return p;
}

void operator delete(void * p) // or delete(void *, std::size_t)
{
  std::free(p);
}

#include "lib/api/messages/TextSecureGroup.h"
#include "lib/api/messages/TextSecureAttachment.h"
#include "lib/api/push/TextSecureAddress.h"

int main(void)
{
  return 0;
}
