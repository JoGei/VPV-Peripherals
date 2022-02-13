#ifndef _PULPISSIMO_UDMA_H_
#define _PULPISSIMO_UDMA_H_
#include "scc/tlm_target.h"

namespace pulpissimo {
namespace gen {
class udma_regs;
}

class udma : public sc_core::sc_module, public scc::tlm_target<> {
public:
    sc_core::sc_in<sc_core::sc_time> clk_i{"clk_i"};
    sc_core::sc_in<bool> rst_i{"rst_i"};
    udma(sc_core::sc_module_name nm);
    virtual ~udma() override;

protected:
    void clock_cb();
    void reset_cb();
    sc_core::sc_time clk;
    std::unique_ptr<gen::udma_regs> regs;
};

} /* namespace pulpissimo */

#endif /* _PULPISSIMO_UDMA_H_ */
