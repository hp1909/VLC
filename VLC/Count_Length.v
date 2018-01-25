module count_L(
	input				iClk,
	input				iRst_n,
	input				reset,
	input				iRead_Write,
	output	reg[31:0]	count_L
	);

	always@(posedge iClk)
	begin
		if( !iRst_n | reset)
			count_L	<=	32'd0;
		else
			begin
				if(iRead_Write == 1'd1)
					count_L		<=	count_L +1'd1;
				else
					count_L		<=	count_L;
			end
	end
endmodule
	