/* Test program for 3rd mandatory assignment.
 *
 * A process writes ITS integers to /dev/dm510-0 while
 * another process read ITS integers from /dev/dm510-1.
 * A checksum of the written data is compared with a
 * checksum of the read data.
 *
 * This is done in both directions.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/ioctl.h>

#define DM510_IOC_MAGIC  'q'
#define DM510_SET_BUFFER _IOWR(DM510_IOC_MAGIC,   0, int)

int main(int argc, char *argv[])
{
    int fd;
    fd = open("/dev/dm510-1", O_RDONLY);
    perror("r open dm510-1");

    ioctl(fd, DM510_SET_BUFFER, 42);

    return 0;
}
