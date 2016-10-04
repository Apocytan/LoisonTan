/* 
   
 */

#ifndef _ElementFactory_hh_
#define _ElementFactory_hh_

class ElementFactory {

  protected:
    std :: map<char, AElementAlloc*> list;


  public:
    virtual ~ElementFactory() = 0;
    Element* const newInstance(char id);
    void registerType(char id, AElementAlloc* a);


};

#endif /* _ElementFactory_hh_ */

