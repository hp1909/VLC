module VLC_transmit(
	input					iClock,
	input					iRst_n,
	input					iStart,
	input					iWait_R,
	input					iRd_Data_valid,
	input		[31:0]		iLength,
	input		[31:0]		iRead_Addr,
	input		[31:0]		iRdata,
	output		[31:0]		oRead_Addr,
	output					oData,
	output					oDone,
	output					oRead,
	output					oStart
	);
	wire					FF_Empty,	//FIFO Empty
							FF_full,	//FIFO full
							FF_rd_req;
	wire		[7:0]		FF_usedw;
	wire					iClock_b,
							iClock_wd,
							iClock_30;
	wire		[31:0]		oWrData;
	wire		[4:0]		sync;	
	reg 					FF_Empty_15;

	clock_new clk(
		.iCLK				(iClock),
		.iReset_n		(iRst_n),
		.oCLOCK_b		(iClock_b),//iClock bit :1.5khz
		.oCLOCK_wd		(iClock_wd),//iClock word = iClock bit *32 (1 word =32 bit)
		.oCLOCK_30		(iClock_30)	//30MHz
		);
		
	always@(posedge iClock_b, negedge iRst_n)
	begin
		if(!iRst_n)
			FF_Empty_15 <= 1'd1;
		else
			FF_Empty_15 <= FF_Empty;
	end
//	assign FF_rd_req = 	FF_Empty_15? 1'd0:(sync == 5'd0)?1'd1:1'd0;
	assign FF_rd_req = FF_Empty_15?1'd0:(sync == 5'd0)?1'd1:1'd0;
	//read_pipeline	read(
	//	.iClk			(iClock),
	//	.iRst_n			(iRst_n),
	//	.iRd_Data_valid	(iRd_Data_valid),
	//	.iWait			(iWait_R),
	//	.iRead_Addr		(iRead_Addr),
	//	.Length			(iLength),
	//	.iStart			(iStart),
	//	.FF_full		(FF_full),
	//	.oRead_Addr		(oRead_Addr),
	//	.oRead			(oRead),
	//	.oDone			(oDone)
	//	);
Read_master_pipeline_HDMI read(	
	.iClk					(iClock),
	.iReset					(!iRst_n),
	.iRd_Data_valid			(iRd_Data_valid),
	.iStart					(iStart),
	.iStart_read_address	(iRead_Addr),
	.iLength				(iLength),
	.iWait_request			(iWait_R),
	.oRead					(oRead),	
	.oRead_address			(oRead_Addr),
	.FF_almost_full			(FF_full),
	.oDone					(oDone)
	);
//	Dual_Clock dual(
//		.iData		(iRdata),
//		.iWrite		(iRd_Data_valid),
//		.iW_Clock	(iClock),			//50MHz
//		.iRead		(FF_rd_req),
//		.iR_Clock	(iClock_b),			//1.5Khz
//		.iRst_n		(iRst_n),
//		.oFull		(FF_full),
//		.oEmpty		(FF_Empty),	
//		.oWrusewd	(FF_usedw),// current data in FIFO
//		.oRdusewd	(FF_usedw),
//		.oData		(oWrData)
//	);
	dcfifo1	fifo(
	.d_out					(oWrData),
	.f_full_flag			(FF_full),
	.f_half_full_flag		(),
	.f_empty_flag			(FF_Empty),
	.f_almost_full_flag		(),
	.f_almost_empty_flag	(),
	.d_in					(iRdata),
	.r_en					(FF_rd_req),
	.w_en					(iRd_Data_valid),
	.r_clk					(iClock_b),
	.w_clk					(iClock),
	.reset					(!iRst_n),
	.data_num				(FF_usedw)	
	);
	
	sync32_1(
	.iClk	(iClock_b),
	.iReset_n	(iRst_n),
	.iData	(oWrData),	//data word =32 bit
	.iRead	(FF_rd_req),
	.oData	(oData),
	.count	(sync),
	.oStart (oStart)
	);
	//Pall2Serial sync1_32(
	//.iClk	(iClock_b),
	//.iReset_n	(iRst_n),
	//.iData	(oWrData),	//data word =32 bit
	//.iRead	(FF_rd_req),
	//.oData	(oData),
	//.oStart (oStart),
	//.Sync	(sync)

	//);

		
endmodule