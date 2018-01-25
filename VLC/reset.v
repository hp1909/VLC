module reset(
	input		iClk,
	input		iRst_n,
	input		oDone,
	output	reg reset
	);
	reg	[1:0]	count;
	always@(posedge iClk)
	begin
		if( !iRst_n)
		begin
			reset	<=	1'd1;
			count	<=	2'd0;
		end
		else
			begin
			reset	<=	2'd0;
			if(oDone == 1'd1)
				begin
					if(count	== 	2'd1)
						begin
							count	<=	2'd0;
							reset	<=	1'd1;
						end
					else
						begin
							reset	<=	1'd0;
							count	<=	count +1'd1;
						end
				end
			else
				begin
					reset	<=	1'd0;
					count	<=	2'd0;
				end
			end
	end
endmodule
	