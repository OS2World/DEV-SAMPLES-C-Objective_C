#ifndef _DBTYPES_H_
#define _DBTYPES_H_

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

typedef  struct dbase_head {
  unsigned char   version;    /*03 for dbIII and 83 for dbIII w/memo file*/
  unsigned char   l_update[3];/*yymmdd for last update*/
  unsigned long   count;      /*number of records in file*/
  unsigned short int header;  /*length of the header
			       *includes the \r at end
			       */
  unsigned short int    lrecl;/*length of a record
			       *includes the delete
			       *byte
			       */
  unsigned char   reserv[20];
} DBHEADER;

typedef struct dbase_fld {
  char    name[11];                               /*field name*/
  char    type;                                   /*field type*/
#define DB_FLD_CHAR  'C'
#define DB_FLD_NUM   'N'
#define DB_FLD_LOGIC 'L'
#define DB_FLD_MEMO  'M'
#define DB_FLD_DATE  'D'
  /* A-T uses large data model but drop it for now */
  char            *data_ptr;                      /*pointer into buffer*/
  unsigned char   length;                         /*field length*/
  unsigned char   dec_point;                      /*field decimal point*/
  unsigned char   fill[14];
} DBFIELD;
#endif
