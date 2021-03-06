/* 
	2015.09.16
	https://leetcode.com/problems/rank-scores/
*/

/* one solution */

select Score, 
    (select count(distinct Score) from Scores where Score >= s.Score) Rank 
from Scores s 
order by Score desc


/* better solution */

select Score, 
    @rank:= @rank + (@prev <> (@prev:=s.Score)) Rank 
from Scores s, (select @rank:=0, @prev:=-1) init
order by Score desc