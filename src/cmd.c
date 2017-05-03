#include <ch.h>
#include <hal.h>
#include <shell.h>

#include "cmd.h"

#include "cmdlet/ps.h"
#include "cmdlet/free.h"
#include "cmdlet/peek.h"

static const ShellCommand commands[] = {
  {"peek", cmd_peek},
  {"poke", NULL},
  {"ps", cmd_ps},
  {"free", cmd_free},
  {NULL, NULL}
};

const ShellConfig shellcfg = {
  (BaseSequentialStream *) &SD1,
  commands
};
