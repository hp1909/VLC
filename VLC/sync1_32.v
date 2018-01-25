module sync1_32(
	input 			iClk,
	input			iReset_n,
	input			iStart,
	input			iData,
	output	reg [31:0]	oData,
	output	reg		oWrite
	);
	reg [5:0] 	count;
	reg [5:0]	count_1delay;
	reg	[31:0] 	term;
	reg			nofirst_data;
	always@(posedge iClk)
	begin
		if(!iReset_n)
			begin
				count		 <=	6'd0;
				nofirst_data 	<= 1'b0;
//				count_1delay <= 5'd0;
			end
		else
			if(iStart)
				begin
					if(!nofirst_data)
						begin
							if(count >6'd1)
							begin
								term <= (iData<<(count-2)) | term;
								count <= count+1'b1;
								if(count == 6'd33)
									begin
									oData <= term|(iData<<(count-2));
									oWrite <= 1'd1;
									term <=32'd0;
									count<=6'd0;
									nofirst_data <= 1'b1;
									end
								else
									begin
									oData <= oData;
									oWrite <= 1'd0;
									end
							end
							else
								count <= count +1'b1;
						end
					else
						begin
							term <= (iData<<(count)) | term;
							count <= count+1'b1;
							if(count == 6'd31)
								begin
								if((term==32'h7FFFFFFF)&&(iData ==1'b1))
									begin
										oData<= 32'd0;
									end
									else
									begin
										oData<= term|(iData<<(count));
									end
									oWrite <= 1'd1;
									term <=32'd0;
									count<=6'd0;
								end
							else
								begin
								oData <= oData;
								oWrite <= 1'd0;
								end
						end

				end
			//if(iStart)
			//	begin
			//		count_1delay <= count;
			//		count <= count+1'b1;
			//		term <= (iData<<(count_1delay-1)) | term;
			//		if(count_1delay == 6'd32)
			//			begin
			//			oData <= term|(iData<<(count_1delay-1));
			//			oWrite <= 1'd1;
			//			term <=31'd0;
			//			count<=6'd1;
			//			end
			//		else
			//			begin
			//			oData <= oData;
			//			oWrite <= 1'd0;
			//			end
			//	end
	end

endmodule