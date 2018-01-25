module Dual_Clock(
	input [31:0]	 iData,
	input			iWrite,
					iW_Clock,
					iRead,
					iR_Clock,
					iRst_n,
	output			oFull,
					oEmpty,
	output	reg [10:0]	oWrusewd,// current data in FIFO
						oRdusewd,
	output	reg[31:0]	oData
	);
	reg [31:0] mem [0:1023];
	reg [10:0]	W_point =11'd0,
				R_point =11'd0;
	wire	[10:0]	data_use;
	wire	sosanh;
	/* always@(posedge iW_Clock)
		begin
			if(W_point <R_point)
				data_use <= 10'd1024-R_point+W_point;
			else
				data_use <= W_point-R_point;
		end */
	assign data_use = W_point-R_point;
	assign	sosanh	=   ((W_point[9]^	R_point[9]) 	|
						(W_point[8]	^	R_point[8]) 	|
						(W_point[7]	^	R_point[7]) 	|
						(W_point[6]	^	R_point[6]) 	|
						(W_point[5]	^	R_point[5]) 	|
						(W_point[4]	^	R_point[4]) 	|
						(W_point[3]	^	R_point[3]) 	|
						(W_point[2]	^	R_point[2]) 	|
						(W_point[1]	^	R_point[1]) 	|
						(W_point[0]	^	R_point[0]));
	assign oEmpty = !(W_point ^ R_point)&!sosanh;//Empty when W_point=R_point
	assign oFull  = (W_point ^ R_point)& !sosanh;//Full when W_point[9:0]=R_point[9:0] and W_point[10] != R_point[10]
	always@(posedge iW_Clock, negedge iRst_n)
		begin
			if(!iRst_n)
			begin
				W_point <= 11'd0;
				oWrusewd<= 11'd0;
			end
			else
				begin
					if(iWrite & !oFull)
					begin
						mem[W_point] <= iData;
						oWrusewd <= data_use +1'b1;
						W_point  <= W_point +1'b1;
					end
					else
					begin
						oWrusewd<= data_use;
						W_point	<= W_point;
					end
				end
		end
	always@(posedge iR_Clock, negedge iRst_n)
		begin
			if(!iRst_n)
			begin
				R_point <= 11'd0;
				oRdusewd<=11'd0;
			end
			else
				begin
					if(iRead & !oEmpty)
					begin
						oData <= mem [R_point];
						oRdusewd<= data_use -1'b1;
						R_point <= R_point +1'b1;
					end
					else
					begin
						oRdusewd<=data_use;
						R_point <= R_point;
					end
				end
		end
endmodule
/*---------------------------------------------------------*|
|						Kiet Nguyen							|		
|*---------------------------------------------------------*/