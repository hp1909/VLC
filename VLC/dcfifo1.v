//==================================================

//a_fifo5.v; verilog code for asynchronous FIFO

//This module describes FIFO

//===================================================

module dcfifo1(d_out,f_full_flag,f_half_full_flag,f_empty_flag,

f_almost_full_flag,f_almost_empty_flag,d_in,r_en,w_en,r_clk,w_clk,reset,data_num);


parameter f_width=32; //FIFO width

parameter f_depth=1024; //FIFO depth

parameter f_ptr_width=10; //because depth =16;

parameter f_half_full_value=512;

parameter f_almost_full_value=1000;

parameter f_almost_empty_value=5;


output [f_width-1:0] d_out; reg [f_width-1:0] d_out; //outputs

output f_full_flag,f_half_full_flag,f_almost_full_flag,f_empty_flag,f_almost_empty_flag;


input [f_width-1:0] d_in;

input r_en,w_en,r_clk,w_clk;

input reset;
output [f_ptr_width-1:0] data_num;

//internal registers,wires

wire [f_ptr_width-1:0] r_ptr,w_ptr;

reg r_next_en,w_next_en;

reg [f_ptr_width-1:0] ptr_diff;


reg [f_width-1:0] f_memory[f_depth-1:0];

assign data_num = ptr_diff;

assign f_full_flag=(ptr_diff==(f_depth-100)); //assign FIFO status

assign f_empty_flag=(ptr_diff==0);

assign f_half_full_flag=(ptr_diff==f_half_full_value);

assign f_almost_full_flag=(ptr_diff==f_almost_full_value);

assign f_almost_empty_flag=(ptr_diff==f_almost_empty_value);


//---------------------------------------------------------

always @(posedge w_clk) //write to memory

begin

if(w_en) begin

if(!f_full_flag)

f_memory[w_ptr]<=d_in; end

end


//---------------------------------------------------------

always @(posedge r_clk) //read from memory

begin

if(reset)

d_out<=0; //f_memory[r_ptr];

else if(r_en) begin

if(!f_empty_flag)

d_out<=f_memory[r_ptr]; end

else d_out<=d_out;

end


//---------------------------------------------------------

always @(*) //ptr_diff changes as read or write clock change

begin

if(w_ptr>=r_ptr)
	ptr_diff<=w_ptr-r_ptr;
else 
	ptr_diff<=((f_depth-r_ptr)+w_ptr);
//if(w_ptr)

//begin
//end

//else ptr_diff<=0;

end


//---------------------------------------------------------

always @(*) //after empty flag activated fifo read counter should not increment;

begin if(r_en && (!f_empty_flag))

r_next_en=1;

else r_next_en=0;

end

//--------------------------------------------------------


always @(*) //after full flag activated fifo write counter should not increment;

begin if(w_en && (!f_full_flag))

w_next_en=1;

else w_next_en=0;

end


//---------------------------------------------------------

b_counter r_b_counter(
					.c_out(r_ptr),
					.c_reset(reset),
					.c_clk(r_clk),
					.en(r_next_en)
					);

b_counter w_b_counter(
					.c_out(w_ptr),
					.c_reset(reset),
					.c_clk(w_clk),
					.en(w_next_en)
					);

endmodule


