-- Ada Lab Ryan Edwards

with Ada.Text_IO, Ada.Integer_Text_IO;
use Ada.Text_IO, Ada.Integer_Text_IO;

procedure Number_Score is
-- Reading number and assigning the appropriate score

	  readNum: Integer;
	  score: Integer;

begin
	-- Checking conditions
	readNum := 0;
	score := 0;
	
	Get(readNum);
	if readNum mod 2 = 0 then
	   score := score + 5;
	else
	   score := score + 1;
	end if;

	if readNum < 0 then
	   score := score + 2;
	end if;

	if readNum > 100 then
	   score := score + 10;
	end if;

	Put(score, Width => 1);
	   

end Number_Score;
