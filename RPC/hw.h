/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _HW_H_RPCGEN
#define _HW_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


#define HELLO_WORLD_PROG 0x30009998
#define HELLO_WOLRD_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define HW 1
extern  char ** hw_1(void *, CLIENT *);
extern  char ** hw_1_svc(void *, struct svc_req *);
#define getid 2
extern  int * getid_1(char **, CLIENT *);
extern  int * getid_1_svc(char **, struct svc_req *);
#define newmessage 3
extern  void * newmessage_1(char **, CLIENT *);
extern  void * newmessage_1_svc(char **, struct svc_req *);
#define getmessage 4
extern  char ** getmessage_1(int *, CLIENT *);
extern  char ** getmessage_1_svc(int *, struct svc_req *);
extern int hello_world_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define HW 1
extern  char ** hw_1();
extern  char ** hw_1_svc();
#define getid 2
extern  int * getid_1();
extern  int * getid_1_svc();
#define newmessage 3
extern  void * newmessage_1();
extern  void * newmessage_1_svc();
#define getmessage 4
extern  char ** getmessage_1();
extern  char ** getmessage_1_svc();
extern int hello_world_prog_1_freeresult ();
#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_HW_H_RPCGEN */
