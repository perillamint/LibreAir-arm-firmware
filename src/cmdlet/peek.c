#include <ch.h>
#include <chprintf.h>
#include <stdlib.h>

#include "../dumpcode.h"
#include "peek.h"

int cmd_peek(BaseSequentialStream *chp, int argc, char *argv[]) {
  int ret;
  void *addr;
  size_t size;

  if(argc != 2) {
    chprintf(chp, "Usage: peek 0xdeadbeef size\r\n");
    return -1;
  }

  if(strncmp(argv[0], "0x", 2) != 0) {
    chprintf(chp, "Address must starts with 0x.\r\n");
    return -1;
  }

  ret = sscanf(argv[0] + 2, "%x", (unsigned int*)&addr);
  if(ret < 0) {
    chprintf(chp, "Invalid address format.\r\n");
    return -1;
  }

  ret = sscanf(argv[1], "%d", &size);
  if(ret < 0) {
    chprintf(chp, "Invalid size format.\r\n");
    return -1;
  }

  dumpcode(addr, size);
}
