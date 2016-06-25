/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Jan 20 23:07:41 2009
 */
/* Compiler settings for E:\Á»Î°(ÎðÉ¾)\12\ÊéÖÐÊµÀý\HTML1\HTML1.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID LIBID_HTML1Lib = {0xD3CB3CB9,0xA777,0x4C2A,{0x9F,0x8D,0x13,0x04,0x10,0x33,0xB6,0xF5}};


#ifdef __cplusplus
}
#endif

