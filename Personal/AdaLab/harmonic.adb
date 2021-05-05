-- Ada Harmonic Program
-- Ryan Edwards
-- don't forget exp for formatting

with Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
use Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;

procedure Harmonic is

	  readNum: Integer;
	  total: Float;

begin
	readNum := 0;
	total := 0.0;
	
	Get(readNum);

	if readNum <= 0 then
	   Put("Error: Number must be positive.");
	   return;
	end if;

	-- Even numbers subtracted from total
	-- odd numbers added to total
	for I in 1..readNum loop
	    if I mod 2 = 0 then
	       total := total - (Float(1)/Float(I));
	    else
	       total := total + (Float(1)/Float(I));
	    end if;
	end loop;
	
Put(total, Aft => 5, Exp => 0);
end Harmonic;