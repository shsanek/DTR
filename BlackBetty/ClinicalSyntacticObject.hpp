//
//  ClinicalSyntacticObject.hpp
//  BlackBetty
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef ClinicalSyntacticObject_hpp
#define ClinicalSyntacticObject_hpp

#include <stdio.h>
#include "BBAllLexems.h"
#include "BBSyntacticObject.hpp"
#include "TokenAnalyzerCreater.hpp"

namespace BB {
    class ClinicalSyntacticObject:public SyntacticObject{
    public:
        class CurrentSyntacticResultObject:public SyntacticResultObject{
        public:
            CurrentSyntacticResultObject(LexemString lexem);
            
            CurrentSyntacticResultObject(string name,
                                         list<SyntacticResultObject_ptr> subobjects,
                                         list<SyntacticResultObject_ptr> headerObjects);
            
            virtual void getData(SyntacticResultObjectData* inputData) ;
        };
        
        ClinicalSyntacticObject(int priority);
        
        virtual SyntacticResultObject_ptr resultObject(string name,
                                                               list<SyntacticResultObject_ptr> subobjects,
                                                               list<SyntacticResultObject_ptr> headerObjects);
    };
}

#endif /* ClinicalSyntacticObject_hpp */