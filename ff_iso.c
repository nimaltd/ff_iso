#include "ff_iso.h"

#if (osCMSIS < 0x20000U)
osMutexId ffMutexID;
#else
osMutexId_t ffMutexID;
#endif
ff_iso_t ff_iso;

//##############################################################################################################
FRESULT ff_mount(FATFS *fs, const TCHAR *path, BYTE opt)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.fs = fs;
  ff_iso.path = (TCHAR*) path;
  ff_iso.opt = opt;
  ff_iso.func = FF_ISO_MOUNT;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
FRESULT ff_open(FIL *fp, const TCHAR *path, BYTE mode)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.fp = fp;
  ff_iso.path = (TCHAR*) path;
  ff_iso.mode = mode;
  ff_iso.func = FF_ISO_OPEN;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
FRESULT ff_close(FIL *fp)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.func = FF_ISO_CLOSE;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
FRESULT ff_read(FIL *fp, void *buff, UINT btr, UINT *br)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.fp = fp;
  ff_iso.buff = buff;
  ff_iso.len = btr;
  ff_iso.ptr = br;
  ff_iso.func = FF_ISO_READ;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}

//##############################################################################################################
FRESULT ff_write(FIL *fp, const void *buff, UINT btw, UINT *bw)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.fp = fp;
  ff_iso.buff = (void*) buff;
  ff_iso.len = btw;
  ff_iso.ptr = bw;
  ff_iso.func = FF_ISO_WRITE;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
int ff_puts(const TCHAR *str, FIL *cp)
{
  int res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.fp = cp;
  ff_iso.tbuff = (TCHAR*) str;
  ff_iso.func = FF_ISO_PUTS;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.int32;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
FRESULT ff_opendir(DIR *dp, const TCHAR *path)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.dp = dp;
  ff_iso.path = (TCHAR*) path;
  ff_iso.func = FF_ISO_OPENDIR;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
FRESULT ff_closedir(DIR *dp)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.dp = dp;
  ff_iso.func = FF_ISO_CLOSEDIR;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
FRESULT ff_readdir(DIR *dp, FILINFO *fno)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.dp = dp;
  ff_iso.fno = fno;
  ff_iso.func = FF_ISO_READDIR;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
FRESULT ff_findfirst(DIR *dp, FILINFO *fno, const TCHAR *path, const TCHAR *pattern)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.dp = dp;
  ff_iso.fno = fno;
  ff_iso.path = (TCHAR*) path;
  ff_iso.tbuff = (TCHAR*) pattern;
  ff_iso.func = FF_ISO_FINDFIRST;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
FRESULT ff_findnext(DIR *dp, FILINFO *fno)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.dp = dp;
  ff_iso.fno = fno;
  ff_iso.func = FF_ISO_FINDNEXT;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
FRESULT ff_mkdir(const TCHAR *path)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.path = (TCHAR*) path;
  ff_iso.func = FF_ISO_MKDIR;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
FRESULT ff_unlink(const TCHAR *path)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.path = (TCHAR*) path;
  ff_iso.func = FF_ISO_UNLINK;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
FRESULT ff_rename(const TCHAR *path_old, const TCHAR *path_new)
{
  FRESULT res;
  osMutexWait(ffMutexID, portMAX_DELAY);
  ff_iso.end = 0;
  ff_iso.path = (TCHAR*) path_old;
  ff_iso.tbuff = (TCHAR*) path_new;
  ff_iso.func = FF_ISO_RENAME;
  while (ff_iso.end == 0)
    osDelay(1);
  res = ff_iso.res;
  osMutexRelease(ffMutexID);
  return res;
}
//##############################################################################################################
//##############################################################################################################
//##############################################################################################################
void ff_loop(void)
{
  switch (ff_iso.func)
  {
  case FF_ISO_IDLE:

    break;
  case FF_ISO_MOUNT:
    ff_iso.res = f_mount(ff_iso.fs, ff_iso.path, ff_iso.opt);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_OPEN:
    ff_iso.res = f_open(ff_iso.fp, ff_iso.path, ff_iso.mode);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_CLOSE:
    ff_iso.res = f_close(ff_iso.fp);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_READ:
    ff_iso.res = f_read(ff_iso.fp, ff_iso.buff, ff_iso.len, ff_iso.ptr);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_WRITE:
    ff_iso.res = f_write(ff_iso.fp, ff_iso.buff, ff_iso.len, ff_iso.ptr);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_PUTS:
    ff_iso.int32 = f_puts(ff_iso.tbuff, ff_iso.fp);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_OPENDIR:
    ff_iso.res = f_opendir(ff_iso.dp, ff_iso.path);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_CLOSEDIR:
    ff_iso.res = f_closedir(ff_iso.dp);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_READDIR:
    ff_iso.res = f_readdir(ff_iso.dp, ff_iso.fno);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_FINDFIRST:
    ff_iso.res = f_findfirst(ff_iso.dp, ff_iso.fno, ff_iso.path, ff_iso.tbuff);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_FINDNEXT:
    ff_iso.res = f_findnext(ff_iso.dp, ff_iso.fno);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_MKDIR:
    ff_iso.res = f_mkdir(ff_iso.path);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_UNLINK:
    ff_iso.res = f_unlink(ff_iso.path);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  case FF_ISO_RENAME:
    ff_iso.res = f_rename(ff_iso.path, ff_iso.tbuff);
    ff_iso.end = 1;
    ff_iso.func = FF_ISO_IDLE;
    break;
  }
  osDelay(1);
}
//##############################################################################################################
FRESULT ff_init(void)
{
  osMutexDef(ffMutex);
#if (osCMSIS < 0x20000U)
  ffMutexID = osMutexCreate(osMutex(ffMutex));
#else
  ffMutexID = osMutexNew(osMutex(ffMutex));
#endif
  if (ffMutexID != NULL)
    return FR_OK;
  else
    return FR_NOT_ENABLED;
}
//##############################################################################################################
