#include <signal.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#define	BLKSIZE	4096
#define	NBLK	2047
#define	FNSIZE	128
#define	LBSIZE	4096
#define	ESIZE	256
#define	GBSIZE	256
#define	NBRA	5
#define	KSIZE	9
#define	CBRA	1
#define	CCHR	2
#define	CDOT	4
#define	CCL	6
#define	NCCL	8
#define	CDOL	10
#define	CEOF	11
#define	CKET	12
#define	CBACK	14
#define	CCIRC	15
#define	STAR	01
char	Q[]	= "",T[]	= "TMP";
#define	READ	0
#define	WRITE	1
int	peekc,lastc;
char savedfile[FNSIZE],file[FNSIZE],linebuf[LBSIZE],rhsbuf[LBSIZE/2],expbuf[ESIZE+4];
int	given;
unsigned int *addr1, *addr2,	*dot, *dol, *zero;
char	genbuf[LBSIZE],*nextip,*linebp;
long	count;
int	ninbuf,io,pflag;
long lseek(int, long, int);
int	open(char *, int),creat(char *, int),read(int, char*, int),write(int, char*, int),close(int),fork(void),execl(char *, ...),wait(int *),unlink(char *);
int	vflag	= 1,oflag,listf,listn,col;
char	*globp;
int	tfile	= -1,	tline;
char	*tfname,*loc1,*loc2,ibuff[BLKSIZE];
int	iblock	= -1;
char	obuff[BLKSIZE];
int	oblock	= -1,ichanged,nleft;
char WRERR[]	= "WRITE ERROR";
int	names[26],anymarks;
char *braslist[NBRA],*braelist[NBRA];
int	nbra,subnewa,subolda,fchange,wrapp,bpagesize = 20;
unsigned nlall = 128;
char *mktemp(char *),tmpXXXXX[50] = "/tmp/eXXXXX",*getblock(unsigned int atl, int iof),*_getline(unsigned int tl);
int advance(char *lp, char *ep),append(int (*f)(void), unsigned int *a),backref(int i, char *lp);
void blkio(int b, char *buf, int (*iofcn)(int, char*, int));
int cclass(char *set, int c, int af);
void commands(void),compile(int eof),error(char *s);
int execute(unsigned int *addr),getchr(void),getfile(void),getnum(void),putline(void);
void exfile(void),filename(int comm),global(int k),init(void),newline(void), print(void), putd(void), putfile(void),quit(int n),setwide(void),squeeze(int i);
jmp_buf	savej;
unsigned int *address(void);
typedef void	(*SIG_TYP)(int);
SIG_TYP	oldhup;
SIG_TYP	oldquit;
#define	SIGHUP	1	
#define	SIGQUIT	3	
char	line[70];
char	*linp	= line;
