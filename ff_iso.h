#ifndef _FF_ISO_H
#define _FF_ISO_H

/*
 *	Author:     Nima Askari
 *	WebSite:    https://www.github.com/NimaLTD
 *	Instagram:  https://www.instagram.com/github.NimaLTD
 *	LinkedIn:   https://www.linkedin.com/in/NimaLTD
 *	Youtube:    https://www.youtube.com/channel/UCUhY7qY1klJm1d2kulr9ckw
 */

/*
 * Version:	1.0.0
 *
 * History:
 *
 * (1.0.0):	First release
 */
 
#include "ff.h"
#include "cmsis_os.h"

typedef enum
{
  FF_ISO_IDLE = 0,
  FF_ISO_MOUNT,
  FF_ISO_OPEN,
  FF_ISO_CLOSE,
  FF_ISO_READ,
  FF_ISO_WRITE,
  FF_ISO_PUTS,
  FF_ISO_GETS,
  FF_ISO_OPENDIR,
  FF_ISO_CLOSEDIR,
  FF_ISO_READDIR,
  FF_ISO_FINDFIRST,
  FF_ISO_FINDNEXT,
  FF_ISO_MKDIR,
  FF_ISO_UNLINK,
  FF_ISO_RENAME,
  
}ff_func_t;

typedef struct
{
  uint8_t     end;
  ff_func_t   func;
  FRESULT     res;
  FATFS       *fs;
  TCHAR       *path;
  BYTE        opt;
  BYTE        mode;
  FIL         *fp;
  void        *buff;
  TCHAR       *tbuff;
  UINT        *ptr;
  UINT        len;
  int         int32;
  DIR         *dp;
  FILINFO     *fno;
  
}ff_iso_t;

//##############################################################################################################
FRESULT ff_init(void);
void    ff_loop(void);

FRESULT ff_mount(FATFS* fs, const TCHAR* path, BYTE opt);                                 /* Mount/Unmount a logical drive */
FRESULT ff_open(FIL* fp, const TCHAR* path, BYTE mode);                                   /* Open or create a file */
FRESULT ff_close(FIL* fp);                                                                /* Close an open file object */
FRESULT ff_read(FIL* fp, void* buff, UINT btr, UINT* br);                                 /* Read data from the file */
FRESULT ff_write(FIL* fp, const void* buff, UINT btw, UINT* bw);                          /* Write data to the file */
int     ff_puts(const TCHAR* str, FIL* cp);                                               /* Put a string to the file */
TCHAR*  ff_gets(TCHAR* buff, int len, FIL* fp);                                           /* Get a string from the file */
FRESULT ff_opendir(DIR* dp, const TCHAR* path);                                           /* Open a directory */
FRESULT ff_closedir(DIR* dp);                                                             /* Close an open directory */
FRESULT ff_readdir(DIR* dp, FILINFO* fno);                                                /* Read a directory item */
FRESULT ff_findfirst(DIR* dp, FILINFO* fno, const TCHAR* path, const TCHAR* pattern);     /* Find first file */
FRESULT ff_findnext(DIR* dp, FILINFO* fno);                                               /* Find next file */
FRESULT ff_mkdir(const TCHAR* path);                                                      /* Create a sub directory */
FRESULT ff_unlink(const TCHAR* path);                                                     /* Delete an existing file or directory */
FRESULT ff_rename(const TCHAR* path_old, const TCHAR* path_new);                          /* Rename/Move a file or directory */

#endif
