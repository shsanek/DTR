//
//  DTRTokensAnalyzer.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRTokensAnalyzer.hpp"


DTRTokensAnalyzer::DTRTokensAnalyzer() {
    lexems = list<shared_ptr<Lexem>>();
}

void DTRTokensAnalyzer::addLexemWithKey(shared_ptr<Lexem> lexem,string key) {
    lexem->lexemName = key;
    this->lexems.push_back(lexem);
}

list<LexemString> DTRTokensAnalyzer::lexemsFromSting(string str) {
    list<LexemString> resultList = list<LexemString>();
    do {
        Lexem::LexemSting resultString = 0;
        shared_ptr<Lexem> resultLexem;
        for (list<shared_ptr<Lexem>>::iterator lx = lexems.begin(); lx != lexems.end(); ++lx){
            Lexem::LexemSting value = (*lx)->stringLexemFromString (str);
            if (value) {
                if (!resultString) {
                    resultString = value;
                    resultLexem = *lx;
                } else if (resultString.length() < value.length()) {
                    resultString = value;
                    resultLexem = *lx;
                }
            }
        }
        if (resultString) {
            resultList.push_back(LexemString(resultString.resultString,resultLexem->lexemName));
        }
        if (!resultString || resultString.length() == 0) {
            break;
        }
        if (str.length() > resultString.length()) {
            str = str.substr(resultString.length());
        } else {
            str = "";
        }
    } while (true);
    return resultList;
}