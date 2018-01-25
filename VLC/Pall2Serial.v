module Pall2Serial(
	input			iClk,
	input			iReset_n,
	input	[31:0]	iData,
	input			iRead,
	output	reg		oData,
	output	reg		oStart,
	output	reg [4:0]	Sync);

	reg [31:0] term;
	always@(posedge iClk, negedge iReset_n)
	begin
		if(!iReset_n)
			begin
				term <= 31'd0;
				oData <= 1'b0;
				oStart <=1'b0;
				Sync	<=5'd0;
			end
		else
			begin
				if(iRead)
				begin
					Sync <= Sync +1'b1;
				end
				else
				begin
					if(Sync ==5'd1)
						term <= iData;
					else
					begin
						if(Sync != 5'd0)
						begin
							oData <= term[0];
							term  <= term>>1;
							oStart <= 1'b1;
						end
						else
						begin
							term <=term;
							oStart <= oStart;
						end
					end
				end
			end
	end
endmodule 