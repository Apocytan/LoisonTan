/* 
   
 */

#ifndef _ElementALloc_hh_
#define _ElementALloc_hh_

class ElementALloc {

  protected:
    ID id;


  public:
    ElementAlloc(ID id);
    Element* newInstance();


};

#endif /* _ElementALloc_hh_ */

