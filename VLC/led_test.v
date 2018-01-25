module led_test(
  input 			CLOCK_50,
  input		[3:0]	KEY,
  input		[17:0]	SW,
  inout		[31:0] 	DRAM_DQ,
  output	[12:0] 	DRAM_ADDR,
  output	[1:0]	DRAM_BA,
  output 			DRAM_CAS_N,
  output 			DRAM_RAS_N,
  output 			DRAM_WE_N,
  output 			DRAM_CKE,
  output 			DRAM_CS_N,
  output	[3:0]	DRAM_DQM,
  output			DRAM_CLK,
  inout	[19:0]	GPIO,
  input				UART_RXD,
  output				UART_TXD
  );
wire CLK_100;
 assign DRAM_CLK = !CLOCK_50;
  
 	nios u0 (
		.clk_clk                  						(CLOCK_50),  
		.reset_reset_n            						(KEY[0]),
	
		.sdram_wire_addr        						(DRAM_ADDR), 
		.sdram_wire_ba          						(DRAM_BA),   
		.sdram_wire_cas_n       						(DRAM_CAS_N),
		.sdram_wire_cke         						(DRAM_CKE),  
		.sdram_wire_cs_n        						(DRAM_CS_N), 
		.sdram_wire_dq          						(DRAM_DQ),   
		.sdram_wire_dqm         						(DRAM_DQM),  
		.sdram_wire_ras_n       						(DRAM_RAS_N),
		.sdram_wire_we_n        						(DRAM_WE_N),
		.switch_external_connection_export 				(SW[15:0]),
		.vlc_0_conduit_end_export 						(GPIO),
		.vlc_0_istart_export      						(SW[17]),
		.rs232_0_external_interface_RXD    			(UART_RXD),    // rs232_0_external_interface.RXD
		.rs232_0_external_interface_TXD    			(UART_TXD)
 
	);
	
	pll_clk  pll
	(
	.inclk0 (CLOCK_50),
	.c0		 (CLK_100));

endmodule
