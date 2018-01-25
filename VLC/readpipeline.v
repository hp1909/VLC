module read_pipeline(
	input				iClk,
	input				iRst_n,
	input				iRd_Data_valid,
	input				iWait,
	input		[31:0]	iRead_Addr,
	input		[31:0]	Length,
	input				iStart,
	input				FF_full,
	output	reg [31:0]	oRead_Addr,
	output	reg			oRead,
	output		reg		oDone
	);
	
	wire	[31:0]	End_Addr;
	reg		[1:0]	select;
	wire				reset;
	wire		[31:0]	count_LR;
	reg			[3:0]	Num_Rq_send,
						Num_Re_get;
	wire		[3:0]	Current_Req;						
	assign 	End_Addr		=	iRead_Addr + Length - 3'd4;
	assign Current_Req	= Num_Rq_send - Num_Re_get;
	reset rst_r(
	.iClk		(iClk),
	.iRst_n		(iRst_n),
	.oDone		(oDone),
	.reset		(reset)
	);
	
	count_L	check_length(
	.iClk		(iClk),
	.iRst_n		(iRst_n),
	.reset		(reset),
	.iRead_Write(iRd_Data_valid),
	.count_L	(count_LR)
	); 
	
	always@(posedge iClk)
	begin
		if(!iRst_n)
			Num_Re_get <= 4'd0;
		else
			begin
				if(iRd_Data_valid)
					Num_Re_get <= Current_Req -1'b1;
				else
					Num_Re_get <= Current_Req;
			end
	end
	always@(posedge iClk)
	begin
		if(!iRst_n)
			begin
				oRead 		<= 	1'b0;
				oRead_Addr	<=	32'd0;
				oDone		<=	1'd0;
				Num_Rq_send	<=  4'd0;
			end
		else
     		begin
			if (oDone)
				begin
				oRead 		<= 	1'b0;
				oRead_Addr	<=	32'd0;
				Num_Rq_send	<=  4'd0;
				oDone		<=	1'd1;
				end
			else
			begin
			case(select)
				2'd0:	
					begin
					oDone	<=	1'd0;
						if(iStart)
							begin
								oRead_Addr	<=	iRead_Addr;
								select		<=	2'd1;
							end
						else
							select	<=	select;
					end
				2'd1:
					begin
					oDone	<=	1'd0;
					if(!FF_full)
						begin
							oRead	<=	1'd1;
							select	<=	2'd2;
						end
					else
						begin
							select	<=	select;
							oRead	<=	1'd1;
							oRead_Addr	<= oRead_Addr;
						end
					end
				2'd2:
					begin
					oDone	<=	1'd0;
						if(!iWait && (Current_Req < 4'd4))
							begin
								Num_Rq_send	<= Current_Req +1'b1;
								oRead_Addr	<=	oRead_Addr + 3'd4;		//for next data
								oRead		<=	1'd0;
								select		<=	2'd3;
							end
						else
							begin
								Num_Rq_send	<= Current_Req;
								select	<=	select;
								oRead	<=	1'd1;
								oRead_Addr	<= oRead_Addr;
							end
					end
				2'd3:
					begin
						if((oRead_Addr > End_Addr))
							begin
//								oRead		<=		1'd0;
								select		<=		2'd0;
								oDone		<=		1'd1;
							end
						else
							begin
								oDone		<=		1'd0;
//								oRead		<=		oRead;
								select		<=		2'd1;
							end
					end
				default: select	<=	2'd0;
				endcase
				end
			end
	end
endmodule