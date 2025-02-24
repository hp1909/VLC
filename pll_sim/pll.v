// pll.v

// Generated using ACDS version 16.1 196

`timescale 1 ps / 1 ps
module pll (
		input  wire        pll_powerdown,      //      pll_powerdown.pll_powerdown
		input  wire [0:0]  pll_refclk,         //         pll_refclk.pll_refclk
		input  wire        pll_fbclk,          //          pll_fbclk.pll_fbclk
		output wire        pll_clkout,         //         pll_clkout.pll_clkout
		output wire        pll_locked,         //         pll_locked.pll_locked
		output wire [0:0]  fboutclk,           //           fboutclk.fboutclk
		output wire [0:0]  hclk,               //               hclk.hclk
		input  wire [69:0] reconfig_to_xcvr,   //   reconfig_to_xcvr.reconfig_to_xcvr
		output wire [45:0] reconfig_from_xcvr  // reconfig_from_xcvr.reconfig_from_xcvr
	);

	wire    pll_inst_outclk; // port fragment
	wire    pll_inst_locked; // port fragment

	av_xcvr_plls #(
		.plls                                 (1),
		.pll_type                             ("CMU"),
		.pll_reconfig                         (0),
		.refclks                              (1),
		.reference_clock_frequency            ("125.0 MHz"),
		.reference_clock_select               ("0"),
		.output_clock_datarate                ("1250 Mbps"),
		.output_clock_frequency               ("0 ps"),
		.feedback_clk                         ("internal"),
		.sim_additional_refclk_cycles_to_lock (0),
		.duty_cycle                           (50),
		.phase_shift                          ("0 ps"),
		.enable_hclk                          (0),
		.enable_avmm                          (1),
		.use_generic_pll                      (0),
		.enable_mux                           (1)
	) pll_inst (
		.rst                (pll_powerdown),      //      pll_powerdown.pll_powerdown
		.refclk             (pll_refclk[0]),      //         pll_refclk.pll_refclk
		.fbclk              (pll_fbclk),          //          pll_fbclk.pll_fbclk
		.outclk             (pll_inst_outclk),    //         pll_clkout.pll_clkout
		.locked             (pll_inst_locked),    //         pll_locked.pll_locked
		.fboutclk           (fboutclk),           //           fboutclk.fboutclk
		.hclk               (hclk),               //               hclk.hclk
		.reconfig_to_xcvr   (reconfig_to_xcvr),   //   reconfig_to_xcvr.reconfig_to_xcvr
		.reconfig_from_xcvr (reconfig_from_xcvr)  // reconfig_from_xcvr.reconfig_from_xcvr
	);

	assign pll_clkout = { pll_inst_outclk };

	assign pll_locked = { pll_inst_locked };

endmodule
