% delrow.m
% function removes a row from matrix c which contains
% a reference number in the first row and references
% to that number possibly in the last row
% since the first row is consecutively labeled the function
% relabels the rows in this manner when done
% usage: a=delrow(rownum,c);
% where row number rownum is deleted in matrix c and the result is returned in a

function a=delrow(rownum,c)
  % first create a that is one less row than c
  [rows, cols]=size(c);
arows=rows-1;
  a=zeros(arows,cols);
  for i=1:rows
    if (i!=rownum)
      a_rowindex=i-(i>rownum);
      for j=1:cols
        a(a_rowindex,j)=c(i,j);
      end
    end
  end

  % now create new references to the first column
  % by changing all the references that point to
  % greater than or equal to the deleted row and
  % decrementing that reference so that it now points
  % in the correct spot

  for i=1:arows
	if (a(i,cols)>rownum)  % if the reference is to a row greater than the deleted row
                               % decrement the reference by one
	  a(i,cols) = a(i,cols) - 1;
        end
  end

  % finally reassign the first column to the number of that column

      for i=1:arows
	  a(i,1)=i;
      end
