#pragma once

#include "../Rules/BarrierRule.h"
#include "../Rules/FieldRule.h"
#include "../Rules/KeyRule.h"
#include "../Rules/MedkitRule.h"
#include "../Rules/TrapRule.h"
#include "../Rules/WinStateRule.h"

template<typename... VariadicRules>
class FieldGenerator {
 private:
    template<typename T>
    void SetRules(Field& dest, T rule) {
        rule.SetRule(dest);
    }

    template<typename FirstRule, typename... OtherRules>
    void SetRules(Field& dest, FirstRule first_rule, OtherRules... other_rules) {
        first_rule.SetRule(dest);
        SetRules(dest, other_rules...);
    }
 public:
    Field GenerateField(VariadicRules... rules) {
        Field dest;
        SetRules(dest, rules...);
        return dest;
    }
};