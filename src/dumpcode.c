#include <ch.h>
#include <chprintf.h>

static int isprintable(unsigned char c)
{
  if(0x20 <= c && 0x7E >=c)
    return 1;
  return 0;
}

static void printchar(BaseSequentialStream *chp, unsigned char c)
{
  if(isprintable(c))
    chprintf(chp, "%c",c);
  else
    chprintf(chp, ".");
}

void dumpcode(BaseSequentialStream *chp, void *buf, int len)
{
  int i;
  unsigned char *buff = (unsigned char*) buf;
  chprintf(chp, "----------BEGIN DUMP----------\r\n");
   
  for(i=0;i<len;i++) {
    if(i%16==0) {
#if UINTPTR_MAX == 0xFFFFFFFFFFFFFFFF
      chprintf(chp, "0x%016X  ", (void*)&buff[i]);
#elif UINTPTR_MAX == 0xFFFFFFFF
      chprintf(chp, "0x%08X  ", (void*)&buff[i]);
#else
      chprintf(chp, "%p  ", (void*)&buff[i]);
#endif
    }
    chprintf(chp, "%02X ", buff[i] & 0xFF);
    if(i%16-15==0) {
      int j;
      chprintf(chp, "  ");
      for(j=i-15;j<=i;j++)
        printchar(chp, buff[j]);
      chprintf(chp, "\r\n");
    }
  }
  if(i%16!=0) {
    int j;
    int spaces=(len-i+16-i%16)*3+2;
    for(j=0;j<spaces;j++)
      chprintf(chp, " ");
    for(j=i-i%16;j<len;j++)
      printchar(chp, buff[j]);
    chprintf(chp, "\r\n");
  }
  chprintf(chp, "---------- END DUMP ----------\r\n");
}
