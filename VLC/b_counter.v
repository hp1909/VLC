//==============================================================

//b_counter.v; 4 bit asynchronous binary up counter

//==============================================================

module b_counter(c_out,c_reset,c_clk,en);


parameter c_width=10; //counter width


output [c_width-1:0] c_out; reg [c_width-1:0] c_out;

input c_reset,c_clk,en;


always @(posedge c_clk or posedge c_reset)

if (c_reset)

c_out <= 0;

else if(en)

c_out <= c_out + 1;

endmodule

//========