#include "rational.hpp"
#include <iostream>

int main(void)
{
    rational<int> zero(0,1);
    rational<int> uno(1,1);
    rational<int> inf_pos(1,0);
    rational<int> inf_neg(-1,0);
    rational<int> nan_v(0,0);

    std::cout << "SEMPLIFICAZIONE\n";
    std::cout << rational<int>(3,6)   << "\n";  // 1/2
    std::cout << rational<int>(-3,6)  << "\n";  // -1/2
    std::cout << rational<int>(3,-6)  << "\n";  // -1/2
    std::cout << rational<int>(-3,-6) << "\n";  // 1/2
    std::cout << rational<int>(7,1)   << "\n";  // 7/1
    std::cout << rational<int>(0,5)   << "\n";  // 0/1
    std::cout << rational<int>(5,0)   << "\n";  // +Inf
    std::cout << rational<int>(-5,0)  << "\n";  // -Inf
    std::cout << rational<int>(0,0)   << "\n";  // NaN

    std::cout << "\nSOMMA\n";
    std::cout << rational<int>(1,2) + rational<int>(1,3)  << "\n";  // 5/6
    std::cout << rational<int>(1,2) + rational<int>(-1,2) << "\n";  // 0/1
    std::cout << rational<int>(1,2) + zero                << "\n";  // 1/2
    std::cout << rational<int>(1,2) + inf_pos             << "\n";  // +Inf
    std::cout << rational<int>(1,2) + inf_neg             << "\n";  // -Inf
    std::cout << inf_pos            + inf_pos             << "\n";  // +Inf
    std::cout << inf_neg            + inf_neg             << "\n";  // -Inf
    std::cout << inf_pos            + inf_neg             << "\n";  // NaN
    std::cout << rational<int>(1,2) + nan_v               << "\n";  // NaN
    std::cout << inf_pos            + nan_v               << "\n";  // NaN

    std::cout << "\nSOTTRAZIONE\n";
    std::cout << rational<int>(3,4) - rational<int>(1,4)  << "\n";  // 1/2
    std::cout << rational<int>(1,2) - rational<int>(1,2)  << "\n";  // 0/1
    std::cout << rational<int>(1,2) - inf_pos             << "\n";  // -Inf
    std::cout << rational<int>(1,2) - inf_neg             << "\n";  // +Inf
    std::cout << inf_pos            - inf_pos             << "\n";  // NaN
    std::cout << inf_pos            - inf_neg             << "\n";  // +Inf
    std::cout << inf_neg            - inf_pos             << "\n";  // -Inf
    std::cout << rational<int>(1,2) - nan_v               << "\n";  // NaN

    std::cout << "\nMOLTIPLICAZIONE\n";
    std::cout << rational<int>(2,3) * rational<int>(3,4)  << "\n";  // 1/2
    std::cout << rational<int>(-2,3)* rational<int>(3,4)  << "\n";  // -1/2
    std::cout << rational<int>(-2,3)* rational<int>(-3,4) << "\n";  // 1/2
    std::cout << rational<int>(1,2) * zero                << "\n";  // 0/1
    std::cout << rational<int>(1,2) * inf_pos             << "\n";  // +Inf
    std::cout << rational<int>(-1,2)* inf_pos             << "\n";  // -Inf
    std::cout << inf_pos            * inf_pos             << "\n";  // +Inf
    std::cout << inf_pos            * inf_neg             << "\n";  // -Inf
    std::cout << inf_neg            * inf_neg             << "\n";  // +Inf
    std::cout << zero               * inf_pos             << "\n";  // NaN
    std::cout << rational<int>(1,2) * nan_v               << "\n";  // NaN

    std::cout << "\nDIVISIONE\n";
    std::cout << rational<int>(1,2) / rational<int>(1,4)  << "\n";  // 2/1
    std::cout << rational<int>(3,4) / rational<int>(3,8)  << "\n";  // 2/1
    std::cout << rational<int>(-1,2)/ rational<int>(1,4)  << "\n";  // -2/1
    std::cout << rational<int>(1,2) / zero                << "\n";  // +Inf
    std::cout << rational<int>(-1,2)/ zero                << "\n";  // -Inf
    std::cout << zero               / zero                << "\n";  // NaN
    std::cout << rational<int>(1,2) / inf_pos             << "\n";  // 0/1
    std::cout << inf_pos            / inf_pos             << "\n";  // NaN
    std::cout << inf_pos            / rational<int>(2,1)  << "\n";  // +Inf
    std::cout << inf_pos            / rational<int>(-2,1) << "\n";  // -Inf
    std::cout << rational<int>(1,2) / nan_v               << "\n";  // NaN

    std::cout << "\nOPERATORI COMPOSTI\n";
    rational<int> r(1,4);
    r += rational<int>(1,4);
    std::cout << r << "\n";  // 1/2
    r -= rational<int>(1,4);
    std::cout << r << "\n";  // 1/4
    r *= rational<int>(2,1);
    std::cout << r << "\n";  // 1/2
    r /= rational<int>(2,1);
    std::cout << r << "\n";  // 1/4

    return 0;
}
//File realizzato con l'aiuto di Gemini (per testare tutte le casistiche)