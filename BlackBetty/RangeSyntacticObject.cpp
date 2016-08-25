//
//  RangeSyntacticObject.cpp
//  BlackBetty
//  Created by Alexander Shipin on 17/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "RangeSyntacticObject.hpp"


RangeSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(LexemString lexem):SyntacticResultObject(lexem) {
}

RangeSyntacticObject::CurrentSyntacticResultObject::CurrentSyntacticResultObject(string name,
                             list<SyntacticResultObject_ptr> subobjects,
                             list<SyntacticResultObject_ptr> headerObjects):SyntacticResultObject(name,subobjects,headerObjects) {
}

void RangeSyntacticObject::CurrentSyntacticResultObject::getData(SyntacticResultObjectData* inputData) {
    TokenAnalyzerCreater* data = (TokenAnalyzerCreater*)inputData;
    if (this->subobjects.size() == 2) {
        string value1 = "";
        string value2 = "";
        if (this->subobjects.front()->name == "" &&
            this->subobjects.front()->lexem.lexemName == "const_string") {
            value1 = this->subobjects.front()->lexem.value;
        }
        if (this->subobjects.back()->name == "" &&
            this->subobjects.back()->lexem.lexemName == "const_string") {
            value2 = this->subobjects.back()->lexem.value;
        }
        if (value1.length() == 1 && value2.length() == 1) {
            data->addedArguments(Lexem_ptr(new RangeLexem(value1[0],value2[0])));
        }
    } else {
        //error
        
        data->errorPool->addErrors(Error_ptr(new TextAnalyzerError(this->lexem.position, 2 , "RangeSyntacticObject" )));
    }
}

RangeSyntacticObject::RangeSyntacticObject(int priority):SyntacticObject("open_square_bracket","close_square_bracket",priority){
}

SyntacticResultObject_ptr RangeSyntacticObject::resultObject(string name,
                                                       list<SyntacticResultObject_ptr> subobjects,
                                                       list<SyntacticResultObject_ptr> headerObjects){
    return SyntacticResultObject_ptr((SyntacticResultObject*)new CurrentSyntacticResultObject (name, subobjects, headerObjects));
}