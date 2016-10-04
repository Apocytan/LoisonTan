/* 
   
 */

#ifndef _AElementAlloc_hh_
#define _AElementAlloc_hh_

class AElementAlloc {


  public:
    virtual ~AElementAlloc();
    virtual Element* newInstance();


};

#endif /* _AElementAlloc_hh_ */

