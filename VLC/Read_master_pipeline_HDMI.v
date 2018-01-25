module Read_master_pipeline_HDMI (
	// Global Signals
	input				iClk,
	input				iReset,
	
	// Signals from/to CONTROL_SLAVE
	input				iRd_Data_valid,
	input				iStart,
	input		[31:0]	iStart_read_address,
	input		[31:0]	iLength,
	
	// Signals from/to AVALON_BUS
	input				iWait_request,
	output 				oRead,
	output	reg	[31:0]	oRead_address,
	
	// --- Signals from/to READ_MASTER_CORE ---
	input				FF_almost_full,
	output				oDone
);

// ADDRESS_INC = 4, 8, 16, 32 (bytes)
parameter			ADDRESS_INC 		= 4;

// ============================================
// Wire Declarations
// ============================================

wire	[31:0]		s1_oRead_address;

// ============================================
// Reg Declarations
// ============================================

reg					read_temp;
reg		[1:0]		state;
reg		[31:0]		end_read_address;
reg				stop;
reg			[3:0]	Num_Rq_send,
						Num_Re_get;
wire	[3:0]	Current_Req;	
assign Current_Req		= Num_Rq_send - Num_Re_get;
// ========================================================
// Main Process
// ========================================================
assign s1_oRead_address = oRead_address + ADDRESS_INC;
assign oRead = read_temp;
assign oDone  = (s1_oRead_address > end_read_address) & (state == 2'h1) & ~iWait_request;
//always@(posedge iClk)
//	begin
//		if(iReset)
//			Num_Re_get <= 4'd0;
//		else
//			begin
//				if(iStart && iRd_Data_valid)
//					Num_Re_get <= Current_Req -1'b1;
//				else
//					Num_Re_get <= Num_Re_get;
//			end
//	end
///// Main State Machine //////
always @ (posedge iClk)
begin
	if (iReset)
		begin
			read_temp			<= 1'b0;
			oRead_address 		<= 32'h0;	
			end_read_address 	<= 32'h0;
			state				<= 2'h0;
			stop 				<= 1'b0;
			Num_Rq_send			<= 4'd0;
			Num_Re_get <= 4'd0;
		end
	else
		begin
		if(oDone || stop)
			begin
			stop <= 1'b1;
			read_temp<=1'b0;
			oRead_address 		<= 32'h0;	
			end
		else
		begin
	Num_Rq_send 	<= Current_Req;	
		case (state)
			// Initialize config-registers if iStart has been asserted
			// Read request signal - read_temp is also asserted in this case
			2'h0:
				begin
					if(iStart)
						begin
							read_temp			<= 1'b1;
							oRead_address 		<= iStart_read_address;				
							end_read_address 	<= iStart_read_address + iLength - ADDRESS_INC;
							state				<= 2'h1;
						end
				end
			
			// Wait for until iWait_request is de-asserted
			// If (oRead_address + ADDRESS_INC) > end_read_address, jump to state = 0
			// Else if FF is full, jump to state = 2, and de-assert read_temp/oRead signal
			// Else stay where u are
			2'h1:
				begin
					if (~iWait_request)
						begin
							Num_Rq_send 	<= Current_Req +1'b1;						
							oRead_address	<= s1_oRead_address;
							read_temp		<= 1'b0;
							if (s1_oRead_address > end_read_address)
								state		<= 2'h0;
							else
							state		<= 2'h2;
//								begin
//								if(Current_Req < 4'd2)
//									state		<= 2'h3;
//								else 
//									state		<= 2'h2;
//								end
						end
					else
						begin
							state <= state;
						end
				end
			2'd2:
				begin
					if(Current_Req < 4'd1)
						begin
							if (~FF_almost_full)
							begin
							read_temp			<= 1'b1;
							state				<= 2'h1;
							end
						end
					else 
						state		<= 2'd2;
				end
			//2'h3:
			//	begin
			//		if (~FF_almost_full)
			//			begin
			//				read_temp			<= 1'b1;
			//				state				<= 2'h1;
			//			end
			//	end

			default: state <= 2'd0;
		endcase
				
				if(iStart && iRd_Data_valid)
					Num_Re_get <= 1'b1;
				else
					Num_Re_get <= 1'b0;
		end
		end
end

endmodule 