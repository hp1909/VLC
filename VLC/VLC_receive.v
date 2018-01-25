module VLC_receive(
	input					iClock,
	input					iRst_n,
	input					iStart,
	input					iWait_W,
	input					iRdata,
	input		[31:0]		iWrite_Addr,
	input		[31:0]		iLength,
	output		[31:0]		oWrite_Addr,
	output		[31:0]		oWrData,
	output					oDone,
	output					oWrite,
	output		[3:0]		oBurst_count
	);
	
	wire					FF_Empty,	//FIFO Empty
							FF_full,	//FIFO full
							FF_rd_req;
	wire		[7:0]		FF_used;
	wire					iClock_b,
							iClock_wd,
							iWrite_FF;
	wire 		[31:0]		iWdata_FF;
	clock_new clk(
		.iCLK		(iClock),
		.iReset_n		(iRst_n),
		.oCLOCK_b	(iClock_b),
		.oCLOCK_wd	(iClock_wd)
		);
		
	sync1_32(
		.iClk		(iClock_b),
		.iReset_n	(iRst_n),
		.iStart		(iStart),
		.iData		(iRdata),
		.oData		(iWdata_FF),
		.oWrite		(iWrite_FF)
		);	
	
	//Dual_Clock dual(
	//	.iData		(iWdata_FF),
	//	.iWrite		(iWrite_FF),
	//	.iW_Clock	(iClock_b),
	//	.iRead		(FF_rd_req),
	//	.iR_Clock	(iClock),
	//	.iRst_n		(iRst_n),
	//	.oFull		(FF_full),
	//	.oEmpty		(FF_Empty),	
	//	.oWrusewd	(FF_Wr_used),// current data in FIFO
	//	.oRdusewd	(FF_Rd_used),
	//	.oData		(oWrData)
	//);

	dcfifo1	fifo (
	.d_out					(oWrData),
	.f_full_flag			(FF_full),
	.f_half_full_flag		(),
	.f_empty_flag			(FF_Empty),
	.f_almost_full_flag		(),
	.f_almost_empty_flag	(),
	.d_in					(iWdata_FF),
	.r_en					(FF_rd_req),
	.w_en					(iWrite_FF),
	.r_clk					(iClock),
	.w_clk					(iClock_b),
	.reset					(!iRst_n),
	.data_num				(FF_used)	
	);
	
	write_burst	write(
		.iClk			(iClock),
		.iRst_n			(iRst_n),
		.iWait			(iWait_W),
		.iWrite_Addr	(iWrite_Addr),
		.Length			(iLength),
		.iStart			(iStart),
		.FF_Empty		(FF_Empty),
		.FF_used		(FF_used),
		.oWrite_Addr	(oWrite_Addr),
		.oWrite			(oWrite),
		.oBurst_count	(oBurst_count),
		.oDone			(oDone),
		.FF_rd_req		(FF_rd_req)
		);	
endmodule