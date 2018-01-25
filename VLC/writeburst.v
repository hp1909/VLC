module write_burst	(
	input				iClk,
	input				iRst_n,
	input				iWait,
	input		[31:0]	iWrite_Addr,
	input		[31:0]	Length,
	input				iStart,
	input				FF_Empty,
	input		[7:0]	FF_used,
	output	reg	[31:0]	oWrite_Addr,
	output	reg			oWrite,
	output		[9:0]	oBurst_count,
	output		reg		oDone,
	output		reg		FF_rd_req	//FIFO read request ~ iRead of FIFO
	);

	reg			[9:0]	count;
	wire				Stop_Write;
	wire		[31:0]	End_Addr;
	reg			[2:0]	select;
	wire				reset;
	wire		[31:0]	count_LW,
						draft;

	assign	oBurst_count	=	9'd1;
	assign	End_Addr	=	iWrite_Addr + Length - {oBurst_count, 2'b0};//8*4 (burstNumber*AddrFor32bitData)
	
	delay(
	.iData	(End_Addr),
	.oData	(draft)
	);
	reset rst_w(
	.iClk		(iClk),
	.iRst_n		(iRst_n),
	.oDone		(oDone),
	.reset		(reset)
	);
	
	count_L	check_length(
	.iClk		(iClk),
	.iRst_n		(iRst_n),
	.reset		(reset),
	.iRead_Write(FF_rd_req),
	.count_L	(count_LW)
	); 
	
	always@(posedge iClk)
		begin
			if(!iRst_n)
				begin
					oWrite		<=	1'd0;
					oWrite_Addr	<=	32'd0;
					count		<=	9'd0;
					FF_rd_req	<=	1'd0;
					oDone		<=	1'd0;
				end
			else
			begin
			if(oDone)
				begin
					oWrite		<=	1'd0;
					oWrite_Addr	<=	32'd0;
					count		<=	9'd0;
					FF_rd_req	<=	1'd0;
					oDone		<=	1'd1;
				end
			else
			begin
			case( select)
				3'd0:
					begin
						oDone	<=	1'd0;
						if(iStart)
							begin
								oWrite_Addr 	<=	iWrite_Addr;
								select			<=	3'd1;
								count			<=	9'd0;
								FF_rd_req		<=	1'd0;
							end
						else
							select	<=	select;
					end
				3'd1:
					begin
						oDone	<=	1'd0;
						if( (FF_used < oBurst_count) || (FF_Empty))
							select	<=	3'd1;
						else
							begin
								select		<=	3'd2;
								FF_rd_req	<=	1'd1;
							end
					end
				3'd2:
					begin
						oDone		<=	1'd0;
						FF_rd_req	<=	1'd0;
						oWrite		<=	1'd1;
						select		<=	3'd3;
					end
				3'd3:
					begin
						oDone		<=	1'd0;
						if(!iWait)
							begin
								if(count == oBurst_count - 1'd1)
									begin
										count		<=	9'd0;
										oWrite		<=	1'd0;
										oWrite_Addr	<=	oWrite_Addr	+ {oBurst_count, 2'b0};
										select		<=	3'd5;
									end
								else
									begin
										count		<=	count +1'b1;
										oWrite		<=	1'd0;
										FF_rd_req	<=	1'd1;
										select		<=	3'd4;
									end
							end
						else
							begin
								oWrite		<=	1'd1;
								select		<=	select;
								FF_rd_req	<=	1'd0;
								count		<=	count;
							end
					end	
				3'd4:
					begin
						oDone	<=	1'd0;
						oWrite		<=	1'd1;
						FF_rd_req	<=	1'd0;
						select		<=	3'd3;
					end
				3'd5:
					begin
						if( oWrite_Addr > End_Addr)
							begin
//								oWrite	<=	1'd0;
								select	<=	3'd0;
								oDone	<=	1'd1;
							end
						else
							begin
//								oWrite	<=	oWrite;
								select	<=	3'd1;
								oDone	<=	1'd0;
							end
					end
				default: select	<= 3'd0;
			endcase
			end
			end
		end
endmodule
/*---------------------------------------------------------*|
|						Kiet Nguyen							|		
|*---------------------------------------------------------*/
	