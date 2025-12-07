#pragma once

#include "../Blind.h"

class ThePsychic : public Blind
{
public:
    ThePsychic() : Blind(2.0, "The Psychic") {}
    ~ThePsychic() override = default;
};