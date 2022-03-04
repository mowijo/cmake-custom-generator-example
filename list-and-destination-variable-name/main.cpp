#include <stdio.h>

#include <speakers_generated_during_build/Hercule.h>
#include <speakers_generated_during_build/LongFeng.h>
#include <speakers_generated_during_build/CaptainKirk.h>


int main(int, char**)
{
    Hercule hercule;
    hercule.speak();

    LongFeng longfeng;
    longfeng.speak();

    CaptainKirk captainkirk;
    captainkirk.speak();
}
