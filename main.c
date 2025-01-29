#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>

int
main(int argc, char* argv[]){
 if(argv[1] == NULL) printf("%s (FILE | DIRECTORY)...\n", argv[0]);
 int ret = 0;
 struct stat buf;
 while(--argc){
  char* path = argv[argc];
  if(ret = stat(path, &buf)) {
   perror("stat()"); return ret;
  }
  printf(\
   "%s\n"\
   "ID of device containing file: x%x\n"\
   "Inode number: %i\n"\
   "File type and mode: o%o\n"\
   "Number of hard links: %i\n"\
   "User ID of owner: x%x\n"\
   "Group ID of owner: x%x\n"\
   "Device ID: x%x\n"\
   "Total size: %i Bytes\n"\
   "Block size for filesystem I/O: %i Bytes\n"\
   "Number of 512 Byte blocks allocated: %i\n"\
   "Last access: %llu ns\n"\
   "Last modification: %llu ns\n"\
   "Last status change: %llu ns\n\n",\
   argv[argc],\
   buf.st_dev,\
   buf.st_ino,\
   buf.st_mode,\
   buf.st_nlink,\
   buf.st_uid,\
   buf.st_gid,\
   buf.st_rdev,\
   buf.st_size,\
   buf.st_blksize,\
   buf.st_blocks,\
   buf.st_atim.tv_nsec,\
   buf.st_mtim.tv_nsec,\
   buf.st_ctim.tv_nsec\
  );
 }
 return 0;
}
