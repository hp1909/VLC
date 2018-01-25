module mem_config(
	input				clock,
	input				reset_n,
	input				cs,
	input				we,
	input				oe,
	input 		[1:0]	addr,
	input		[31:0]	datain,
	output	reg [31:0]	dataout,
	output 		[31:0]	oBase_Wr_add,
	output 		[31:0]	oBase_Rd_add,
	output 		[31:0] 	oSize,
	output 				oStart
	);
	parameter DATA_WIDTH = 32;
	parameter ADDR_WIDTH = 2;
	parameter LENGTH = 1<< ADDR_WIDTH;
	reg [DATA_WIDTH - 1:0] mem_4reg [0:LENGTH -1];
	
	always@(posedge clock)
	begin
		if(!reset_n)
		begin
			mem_4reg[0] <= 32'd0;
			mem_4reg[1] <= 32'd0;
			mem_4reg[2] <= 32'd0;
			mem_4reg[3] <= 32'd0;
		end
		else
		begin
			if(cs && we)
				begin
					mem_4reg[addr] <= datain;
				end
			if(cs && !we && oe)
				begin
					dataout <= mem_4reg[addr];
				end
		end
	end
	assign oBase_Rd_add 	= mem_4reg[0]; //write address
	assign oBase_Wr_add 	= mem_4reg[1]; //read address
	assign oStart 			= mem_4reg[2]; //Start
	assign oSize 			= mem_4reg[3]; //size
endmodule