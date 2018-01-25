module sync32_1(
	input 			iClk,	//1.5khz
	input			iReset_n,
	input	[31:0]	iData,
	input			iRead,		//active FIFO read
	output reg		oData,
	output reg	[4:0]	count,
	output	reg		oStart
	);
	reg  [4:0] term;
	reg	 [31:0] Shift_Data;
	always@(posedge iClk)
		begin
			if(!iReset_n)
				begin
					term <= 1'b0;
					count <= 5'd0;
				end
			else
			if(iRead || (count!=5'd0))
				begin
					term <= count;
					count <= count + 1'b1;
				end
		end
	always@(posedge iClk)
	begin
		if(!iReset_n)
			begin
				oData <= 1'd0;	
				oStart<= 1'b0;
			end
		else
			begin
			if(iRead || (count!=5'd0))
				begin
					Shift_Data <= iData >> term;
					oData <= Shift_Data[0];
					oStart<=1'b1;
				end
			else
				begin
					oStart <= oStart;
				end;
			end
	end
endmodule 