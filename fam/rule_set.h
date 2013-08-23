//
//  rule_set.h
//  fam
//
//  Created by Chris Powell on 8/19/13.
//  Copyright (c) 2013 Prylis Inc. All rights reserved.
//

#ifndef __fam__rule_set__
#define __fam__rule_set__

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "rule.h"

class RuleSet {
private:
    std::string _name;
    std::string _implication;
    std::vector<Rule *> _rules;

public:
    RuleSet();
    RuleSet(std::string name, std::string implication);

    std::string name();
    void addRule(Rule * const r);
    double calculate(std::vector<double> values);

};

#endif /* defined(__fam__rule_set__) */